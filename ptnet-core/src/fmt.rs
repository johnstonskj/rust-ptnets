/*!
This module provides traits for producing formatted representations of nets.

- [`NetFormatter`] : Format the structure of a net.
- [`MarkedNetFormatter`] : Format a marking of a net, with or without a list of enabled transitions.

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
use std::path::Path;

// ------------------------------------------------------------------------------------------------
// Public Types
// ------------------------------------------------------------------------------------------------

pub trait NetFormatter {
    type Place: Place;
    type Transition: Transition;
    type Arc: Arc;
    type Net: Net<Place = Self::Place, Transition = Self::Transition, Arc = Self::Arc>;

    fn fmt<W: Write>(&self, w: &mut W, net: &Self::Net) -> Result<(), Error>;
}

pub trait MarkedNetFormatter {
    type Place: Place;
    type Transition: Transition;
    type Arc: Arc;
    type Net: Net<Place = Self::Place, Transition = Self::Transition, Arc = Self::Arc>;
    type Tokens: Tokens;
    type Marking: Marking<Tokens = Self::Tokens>;

    fn fmt<W: Write>(
        &self,
        w: &mut W,
        net: &Self::Net,
        marking: &Self::Marking,
        enabled: Option<&[NodeId]>,
    ) -> Result<(), Error>;
}

// ------------------------------------------------------------------------------------------------
// Public Functions
// ------------------------------------------------------------------------------------------------

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
    formatter.fmt(&mut file, net)
}

pub fn net_to_string<F: NetFormatter>(net: &F::Net, formatter: &mut F) -> Result<String, Error> {
    let mut buffer = Vec::new();
    formatter.fmt(&mut buffer, net)?;
    let string = String::from_utf8(buffer)?;
    Ok(string)
}

pub fn print_net<F: NetFormatter>(net: &F::Net, formatter: &mut F) -> Result<(), Error> {
    let stdout = std::io::stdout();
    let mut handle = stdout.lock();
    formatter.fmt(&mut handle, net)
}

// ------------------------------------------------------------------------------------------------

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
    formatter.fmt(&mut file, net, marking, enabled)
}

pub fn marked_net_to_string<F: MarkedNetFormatter>(
    net: &F::Net,
    marking: &F::Marking,
    enabled: Option<&[NodeId]>,
    formatter: &mut F,
) -> Result<String, Error> {
    let mut buffer = Vec::new();
    formatter.fmt(&mut buffer, net, marking, enabled)?;
    let string = String::from_utf8(buffer)?;
    Ok(string)
}

pub fn print_marked_net<F: MarkedNetFormatter>(
    net: &F::Net,
    marking: &F::Marking,
    enabled: Option<&[NodeId]>,
    formatter: &mut F,
) -> Result<(), Error> {
    let stdout = std::io::stdout();
    let mut handle = stdout.lock();
    formatter.fmt(&mut handle, net, marking, enabled)
}
