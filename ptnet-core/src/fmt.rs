/*!
This module provides traits for producing formatted representations of nets.

- [`NetFormatter`] : Format the structure of a net.
- [`MarkedNetFormatter`] : Format a marking of a net, with or without a list of enabled transitions.

An implementation of the [`NetFormatter`], [`NetMatrixFormatter`], is provided that is independent of
the specific net implementation as it generates only a simple table of net connectivity.

Additionally, the following helper functions take a net, or net and marking, with a formatter.

- [`net_to_file`] - write the formatted representation to the named file;
  and [`marked_net_to_file`].
- [`net_to_string`] - produce a formatted string representation of the net;
  and [`marked_net_to_string`].
- [`print`] - print the formatted representation to stdout;
  and [`print_marked_net`].

*/

use crate::error::Error;
use crate::net::{Arc, Net, Place, Transition};
use crate::sim::{Marking, Tokens};
use crate::NodeId;
use std::fs::OpenOptions;
use std::io::Write;
use std::marker::PhantomData;
use std::path::Path;

// ------------------------------------------------------------------------------------------------
// Public Types
// ------------------------------------------------------------------------------------------------

///
/// Implementations of this trait will write a representation of the given `net`.
///
pub trait NetFormatter {
    type Place: Place;
    type Transition: Transition;
    type Arc: Arc;
    type Net: Net<Place = Self::Place, Transition = Self::Transition, Arc = Self::Arc>;

    ///
    /// Format the given `net`.
    ///
    fn fmt_net<W: Write>(&self, w: &mut W, net: &Self::Net) -> Result<(), Error>;
}

///
/// Implementations of this trait will write a representation of the given marked `net`.
///
pub trait MarkedNetFormatter {
    type Place: Place;
    type Transition: Transition;
    type Arc: Arc;
    type Net: Net<Place = Self::Place, Transition = Self::Transition, Arc = Self::Arc>;
    type Tokens: Tokens;
    type Marking: Marking<Tokens = Self::Tokens>;

    ///
    /// Format the given `net`, marked with `marking` and optionally a list of currently `enabled`
    /// transitions.
    ///
    fn fmt_marked_net<W: Write>(
        &self,
        w: &mut W,
        net: &Self::Net,
        marking: &Self::Marking,
        enabled: Option<&[NodeId]>,
    ) -> Result<(), Error>;
}

///
/// Write a matrix with all nodes showing the arcs that connect them. This outputs the table in the
/// markdown/org-mode format.
///
/// ## Example
///
/// Given the simple net \\(\circ\rightarrow\rule[-1pt]{3pt}{0.75em}\rightarrow\circ\\), the matrix
/// is as follows:
///
/// |      |   p0 |   p1 |   t0 |
/// |------|------|------|------|
/// | p0   |      |      |   ↗︎  |
/// | p1   |      |      |      |
/// | t0   |      |   ↗︎  |      |
///
#[derive(Debug)]
pub struct NetMatrixFormatter<P, T, A, N>
where
    P: Place,
    T: Transition,
    A: Arc,
    N: Net<Place = P, Transition = T, Arc = A>,
{
    nothing: PhantomData<N>,
}

// ------------------------------------------------------------------------------------------------
// Public Functions
// ------------------------------------------------------------------------------------------------

///
/// Helper function that writes a representation of the given `net` to a file. If `append` is
/// `true` the representation is appended to the file, else the file is truncated.
///
pub fn net_to_file<F: NetFormatter, P: AsRef<Path>>(
    net: &F::Net,
    path: P,
    append: bool,
    formatter: &mut F,
) -> Result<(), Error> {
    let mut file = OpenOptions::new()
        .write(true)
        .create(true)
        .append(append)
        .open(path)?;
    formatter.fmt_net(&mut file, net)
}

///
/// Helper function that will return a representation of the given `net` as a string value.
///
pub fn net_to_string<F: NetFormatter>(net: &F::Net, formatter: &mut F) -> Result<String, Error> {
    let mut buffer = Vec::new();
    formatter.fmt_net(&mut buffer, net)?;
    let string = String::from_utf8(buffer)?;
    Ok(string)
}

///
/// Helper function that  writes a representation of the given `net` to `std::io::stdout`.
///
pub fn print_net<F: NetFormatter>(net: &F::Net, formatter: &mut F) -> Result<(), Error> {
    let stdout = std::io::stdout();
    let mut handle = stdout.lock();
    formatter.fmt_net(&mut handle, net)
}

// ------------------------------------------------------------------------------------------------

///
/// Helper function that writes a representation of the given `net` and `marking` to a file. If
///  `append` is `true` the representation is appended to the file, else the file is truncated.
///
pub fn marked_net_to_file<F: MarkedNetFormatter, P: AsRef<Path>>(
    net: &F::Net,
    marking: &F::Marking,
    enabled: Option<&[NodeId]>,
    path: P,
    append: bool,
    formatter: &mut F,
) -> Result<(), Error> {
    let mut file = OpenOptions::new()
        .write(true)
        .create(true)
        .append(append)
        .open(path)?;
    formatter.fmt_marked_net(&mut file, net, marking, enabled)
}

///
/// Helper function that will return a representation of the given `net` and `marking` as a
/// string value.
///
pub fn marked_net_to_string<F: MarkedNetFormatter>(
    net: &F::Net,
    marking: &F::Marking,
    enabled: Option<&[NodeId]>,
    formatter: &mut F,
) -> Result<String, Error> {
    let mut buffer = Vec::new();
    formatter.fmt_marked_net(&mut buffer, net, marking, enabled)?;
    let string = String::from_utf8(buffer)?;
    Ok(string)
}

///
/// Helper function that  writes a representation of the given `net` and `marking` to
/// `std::io::stdout`.
///
pub fn print_marked_net<F: MarkedNetFormatter>(
    net: &F::Net,
    marking: &F::Marking,
    enabled: Option<&[NodeId]>,
    formatter: &mut F,
) -> Result<(), Error> {
    let stdout = std::io::stdout();
    let mut handle = stdout.lock();
    formatter.fmt_marked_net(&mut handle, net, marking, enabled)
}

// ------------------------------------------------------------------------------------------------
// Implementations
// ------------------------------------------------------------------------------------------------

const FORMAT_FIELD_WIDTH: usize = 6;
const MATRIX_ARROW: &str = "-^";

impl<P, T, A, N> Default for NetMatrixFormatter<P, T, A, N>
where
    P: Place,
    T: Transition,
    A: Arc,
    N: Net<Place = P, Transition = T, Arc = A>,
{
    fn default() -> Self {
        Self {
            nothing: Default::default(),
        }
    }
}

impl<P, T, A, N> NetFormatter for NetMatrixFormatter<P, T, A, N>
where
    P: Place,
    T: Transition,
    A: Arc,
    N: Net<Place = P, Transition = T, Arc = A>,
{
    type Place = P;
    type Transition = T;
    type Arc = A;
    type Net = N;

    fn fmt_net<W: Write>(&self, w: &mut W, net: &Self::Net) -> Result<(), Error> {
        let mut places: Vec<NodeId> = net.places().iter().map(|place| place.id()).collect();
        places.sort();
        let mut transitions: Vec<NodeId> = net
            .transitions()
            .iter()
            .map(|transition| transition.id())
            .collect();
        transitions.sort();

        writeln!(
            w,
            "| {:>FORMAT_FIELD_WIDTH$} | {} |",
            "",
            places
                .iter()
                .map(|id| format!("{:>FORMAT_FIELD_WIDTH$}", id.as_place_string()))
                .chain(
                    transitions
                        .iter()
                        .map(|id| format!("{:>FORMAT_FIELD_WIDTH$}", id.as_transition_string()))
                )
                .collect::<Vec<String>>()
                .join(" | ")
        )?;

        let fields = places.len() + transitions.len();
        let width = FORMAT_FIELD_WIDTH + 2; // for pad spaces.
        writeln!(
            w,
            "|{}|",
            (0..=fields)
                .map(|_| format!("{:-<width$}", ""))
                .collect::<Vec<String>>()
                .join("+")
        )?;

        let arcs: Vec<(NodeId, NodeId)> = net
            .arcs()
            .iter()
            .map(|arc| (arc.source(), arc.target()))
            .collect();

        for place in &places {
            writeln!(
                w,
                "| {:>FORMAT_FIELD_WIDTH$} | {} |",
                place.as_place_string(),
                places
                    .iter()
                    .map(|_| format!("{:>FORMAT_FIELD_WIDTH$}", ""))
                    .chain(transitions.iter().map(|id| format!(
                        "{:>FORMAT_FIELD_WIDTH$}",
                        if arcs.contains(&(*place, *id)) {
                            MATRIX_ARROW
                        } else {
                            ""
                        }
                    )))
                    .collect::<Vec<String>>()
                    .join(" | ")
            )?;
        }

        for transition in &transitions {
            writeln!(
                w,
                "| {:>FORMAT_FIELD_WIDTH$} | {} |",
                transition.as_transition_string(),
                places
                    .iter()
                    .map(|id| format!(
                        "{:>FORMAT_FIELD_WIDTH$}",
                        if arcs.contains(&(*id, *transition)) {
                            MATRIX_ARROW
                        } else {
                            ""
                        }
                    ))
                    .chain(
                        transitions
                            .iter()
                            .map(|_| format!("{:>FORMAT_FIELD_WIDTH$}", ""))
                    )
                    .collect::<Vec<String>>()
                    .join(" | ")
            )?;
        }

        Ok(())
    }
}
