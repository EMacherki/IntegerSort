\name{pth_pair}
\alias{pth_pair}

\title{Mean of pth element pair of integer vector }
\description{This function find the mean of pth element pair of integer vector if it is sorted.It works like  the median calculation of the nth element.     }

\usage{
pth_pair(x,p)
}

\arguments{
\item{x}{ integer vector}
\item{p}{ the index of the vector to get}
          }
          
\details{
The algorithm used is unstable method to find the mean of pth element and pth-1 element. It uses two keys with 16 bit size to fit the result.The complexity of the algorithm is linear O(N).For small data,insertion sort and LSD sort are used with a helper buffer.
This function don't fit exactly R \code{\link{median}} function. Indeed, NA values are considered as the lowest values of integer. User can utilize \code{\link{NA_rm}} for correction. 
        }
\value{
\item{Default}{ A Numeric  value of the mean of pth  and pth-1 element.   }

}


\author{Med Ezzeddine MACHERKI}

\seealso{
\code{\link{median}}
\code{\link{imedian}}
\code{\link{pth}}
\code{\link{NA_rm}}
       }
\examples{

x<-isample(1e6)
y<-(as.numeric(sort(x)[5000-1])+as.numeric(sort(x)[5000]))/2
all.equal(pth_pair(x,5000),y)

}
\keyword{arith}
