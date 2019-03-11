\name{countSort}
\alias{countSort}
\title{Counting Sort}

\description{Sorting integer vector using counting sort.}
\usage{ countSort( unsorted, inplace=FALSE )}

\arguments{
\item{unsorted}{ Unsorted integer vector}
\item{inplace}{ If true the input will sorted in-place,decreasing memory usage}
          }
          
\details{
Counting sort is one of the most used algorithm for small range vector of data.This function sort array into increasing sens if the maximum - minimum is lesser then 2 ^16. In case of range overflow,this function return an error. Preferably, user must avoid NA values in the unsorted  array because it considered as the lowest values of integer.
        }

\value{
\item{Default}{A sorted integer values}
\item{Inplace}{The returned value is the input vector with sorted values}
      }

\author{M. E. MACHERKI}


\seealso{
\code{\link{sort}}
\code{\link{sort.int}}
\code{\link{lsdSort}}
\code{\link{isample}}
        }

\examples{

x<-sample(1:10000,10000000,TRUE)
# x is a large integer vector with supported range 
system.time(sort(x))
system.time(countSort(x))
all.equal(countSort(x),sort(x)) # return TRUE
# in-place running
system.time(countSort(x,inplace= TRUE)) 
all.equal(sort(x),x)  #return TRUE
        }

\keyword{arith}