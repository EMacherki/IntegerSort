\name{insertSort}
\alias{insertSort}

\title{Insertion Sort  Algorithm}
\description{Sorting Integer vector using insertion sort.}

\usage{
insertSort( unsorted, inplace=FALSE )
}

\arguments{
\item{unsorted}{ Unsorted integer vector}
\item{inplace}{ If true the input will sorted in-place,decreasing memory usage  }
          }
          
\details{
Insertion sort belong to the kind of algorithm designed for small data set(less then 100 values).
Despite the higher complexity, it is very efficient and rapid for small vector. We used a modified algorithm allowing only one check of vector. 
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
\keyword{arith}
