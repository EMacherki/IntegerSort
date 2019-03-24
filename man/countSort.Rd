\name{countSort}
\alias{countSort}
\title{Counting Sort}

\description{This function sort integer with counting sort algorithm which require small data range.}

\usage{ countSort( unsorted, inplace=FALSE )}

\arguments{
\item{unsorted}{ Unsorted integer vector}
\item{inplace}{ If true the input will sorted in-place, decreasing memory usage}
          }
          
\details{
Counting sort is one of the most used algorithm for small range vector of data. This function sort array into increasing sens if the maximum - minimum is lesser then 2 ^16. In case of range overflow, this function return an error. Preferably, user must avoid NA values in the unsorted  array because it considered as the lowest values of integer.
NA values are added in the front of returned vector and only increasing sens is provided. The algorithm used don't check if the data is already sorted. 
        }

\value{
\item{Default}{A sorted integer values}
\item{Inplace}{The returned value is the input vector with sorted values}
      }

\author{Med Ezzeddine MACHERKI}


\seealso{
\code{\link{sort}}
\code{\link{sort.int}}
\code{\link{lsdSort}}
\code{\link{isample}}
        }

\examples{
\dontrun{
x<-sample(1:10000,10000000,TRUE)
# x is a large integer vector with supported range 
system.time(sort(x))
system.time(countSort(x))
all.equal(countSort(x),sort(x)) # return TRUE
# in-place running
system.time(countSort(x,inplace= TRUE)) 
all.equal(sort(x),x)  #return TRUE
   }
        }

\keyword{arith}
