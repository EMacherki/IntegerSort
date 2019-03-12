\name{isample}
\alias{isample}

\title{ Random Uniform Sample Of Integer  }
\description{
This function provides a  random uniform integer vector ranged form -2147483647 to 2147483647.
            }
\usage{isample( size=1L )}
\arguments{
\item{size}{ the size of generated vector}
}

\value{
\item{Default}{  A random values integer vector }
      }


\author{Med Ezzeddine MACHERKI}


\seealso{
\code{\link{sort}}
\code{\link{sort.int}}
\code{\link{countSort}}
\code{\link{lsdSort}}
}

\examples{
## only one value 
print(isample())
## 10 values
print(isample(10))
         }
         
\keyword{arith}

