\name{pth}
\alias{pth}

\title{Pth element of a vector }
\description{This function find the pth element of an integer vector if it is sorted.    }

\usage{
pth(x,p)
}

\arguments{
\item{x}{ integer vector}
\item{p}{ the index of the vector to get}
          }
          
\details{
For large data,the algorithm used is unstable method to find pth element. It uses two keys with 16 bit size to fit the result. The complexity of the algorithm is linear O(N). NA values are considered as the lowest values of integer. User can utilize \code{\link{NA_rm}} for correction. For small data, insertion sort and LSD sort are used with a helper buffer.
        }
\value{
\item{Default}{ An integer value of the pth element  }

}


\author{Med Ezzeddine MACHERKI}

\seealso{
\code{\link{median}}
\code{\link{imedian}}
\code{\link{pth_pair}}
 \code{\link{NA_rm}}
       }
\examples{
\dontrun{
x<-isample(1e6)
target<-5000
all.equal(pth(x,target),sort(x)[target])
}
}
\keyword{arith}
