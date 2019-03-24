\name{insertSort}
\alias{insertSort}

\title{Insertion Sort  Algorithm}
\description{This function  uses insertion sort algorithm for small or quasi sorted integer vector. }

\usage{
insertSort( unsorted, inplace=FALSE )
}

\arguments{
\item{unsorted}{ Unsorted integer vector}
\item{inplace}{ If true the input will sorted in-place,which require memory usage  }
          }
          
\details{
Insertion sort belong to the kind of algorithm designed for small or quasi sorted data set (less then 100 values).
Despite the higher complexity, it is very efficient and rapid  in the sphere of its application. We used a non standard  algorithm with three step, that exploit infinite small value added in the vector head to do only one comparison and finalized by a correction step.
Non finite values are added in the front of returned vector and only increasing sens is provided. The algorithm used don't check if the data is already sorted. 
        }
\value{
\item{Default}{  A sorted integer values}
\item{Inplace}{   The returned value is the input vector with sorted values  }
}
\note{
This function do note pass a busy state check. User must utilize this function carefully and avoid to use it when the size of vector is not known by default.
     }

\author{Med Ezzeddine MACHERKI}

\seealso{
\code{\link{sort}}
\code{\link{sort.int}}
\code{\link{lsdSort}}
\code{\link{countSort}}
       }
\examples{
\dontrun{
x<-isample(20)
# x is a sample of integer
print(x)
all.equal(insertSort(x),sort(x))
# return TRUE 
# in-place processing 
insertSort(x,inplace=TRUE)
#
print(x)
all.equal(x,sort(x))
# return TRUE
}
}
\keyword{arith}
