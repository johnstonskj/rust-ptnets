/*!
Provides the crate's Error and Result types as well as helper
functions.

 */

use std::fmt::{Debug, Display};

// ------------------------------------------------------------------------------------------------
// Public Types
// ------------------------------------------------------------------------------------------------

///
/// The Error type for this crate.
///
#[derive(Debug)]
pub enum Error {
    /// An error was signaled by the standard library I/O functions.
    IoError { source: std::io::Error },
}

///
/// A Result type that specifically uses this crate's Error.
///
pub type Result<T> = std::result::Result<Error, T>;

// ------------------------------------------------------------------------------------------------
// Public Functions
// ------------------------------------------------------------------------------------------------

/// Construct an Error from the provided source.
#[inline]
pub fn io_error(source: std::io::Error) -> Error {
    Error::IoError { source }
}

// ------------------------------------------------------------------------------------------------
// Implementations
// ------------------------------------------------------------------------------------------------

impl Display for Error {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{}",
            match self {
                Error::IoError { source } => format!("An I/O error occurred; source: {}", source),
            }
        )
    }
}

impl std::error::Error for Error {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        #[allow(unreachable_patterns)]
        match self {
            Error::IoError { source } => Some(source),
            _ => None,
        }
    }
}

impl From<std::io::Error> for Error {
    fn from(source: std::io::Error) -> Self {
        io_error(source)
    }
}
