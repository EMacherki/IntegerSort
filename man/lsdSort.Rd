\name{lsdSort}
\alias{lsdSort}
\title{Radix Sort Using Least Significant Digit (LSD) Algorithm}
\description{
This function uses a hybrid radix-32 sort which divides integer value to 4 key of 8 bit and chooses the best case for using counting sort passe. Monomer case (vector contains only one repeated value ) is also checked.    }
\usage{lsdSort( unsorted, inplace=FALSE )}
\arguments{
\item{unsorted}{ Unsorted integer vector}
\item{inplace}{ If true the input will sorted in-place,decreasing memory usage  }
          }
\details{
The algorithm uses 8 KB  buffer and a helper array. Therefore it hold
 3.N+8 Kb as memory buffer (2.N for in_place), counting the cloning of the input. This function is used preferably for large data (N>128). User must check memory before running algorithm.
Non finite values are added in the front of returned vector and only increasing sens is provided. The algorithm used don't check if the data is already sorted. 
       }
\value{
\item{Default}{  A sorted integer values. All Non finite values are placed in the beginning of the vector.}
\item{Inplace}{   The returned value is the input vector with sorted values.  }
}
\author{Med Ezzeddine MACHERKI}


\seealso{
\code{\link{sort}}
\code{\link{sort.int}}
\code{\link{countSort}}
\code{\link{isample}}
}
\examples{
  \dontrun{
x<-isample(10000000)
# x is an uniform  sample of intgers
system.time(sort(x))
system.time(lsdSort(x))
all.equal(sort(x),lsdSort(x)) # return TRUE
system.time(lsdSort(x,TRUE))  # testing in-place
all.equal(sort(x),x)          # return TRUE 
}
}
\keyword{arith}
