\name{pth_pair}
\alias{pth_pair}

\title{Mean of pth element pair of integer vector }
\description{This function find the mean of pth element pair of integer vector if it is sorted.}

\usage{
pth_pair(x,p)
}

\arguments{
\item{x}{ integer vector}
\item{p}{ the index of the pair values to find}
          }
          
\details{
The algorithm used is unstable method to find the mean of pth element and pth-1 element. It uses two keys with 16 bit size to fit the result. The complexity of the algorithm is linear O(N). For small data, insertion sort and LSD sort are used with a helper buffer. NA values are considered as the lowest values of integer. User can utilize \code{\link{NA_rm}} for correction. 
        }
\value{
\item{Default}{ A numeric  value of the mean of pth  and pth-1 element.   }

}


\author{Med Ezzeddine MACHERKI}

\seealso{
\code{\link{median}}
\code{\link{imedian}}
\code{\link{pth}}
\code{\link{NA_rm}}
       }
\examples{
\dontrun{
N<-1e6L
x<-isample(N)
target<-5000 #find the mean of pth(target) and pth(target-1)
y<-(as.numeric(sort(x)[target])+as.numeric(sort(x)[target-1]))/2
all.equal(pth_pair(x,target),y)   #return TRUE
median.index<-(N/2)+1 # the index of median :N is pair
all.equal(pth_pair(x,median.index),median(x)) #return TRUE
}
}
\keyword{arith}
