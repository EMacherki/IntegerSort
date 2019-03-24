\name{imedian}
\alias{imedian}

\title{Median arithmetic}
\description{This function performs median calculation of integer vector.}

\usage{
imedian(x)
}

\arguments{
\item{x}{ integer vector}
          }
          
\details{
The algorithm used is unstable method for median calculation. It uses two keys with 16 bit size to fit the result. The complexity of the algorithm is linear O(N). For small data, insertion sort and LSD sort are used with a helper buffer. This function don't fit exactly \R \code{\link{median}} function. Indeed, NA values are considered as the lowest values of integer. User can utilize \code{\link{NA_rm}} for correction.      
        }
\value{
\item{Default}{ A numeric scalar value  }

}


\author{Med Ezzeddine MACHERKI}

\seealso{
\code{\link{median}}
 \code{\link{NA_rm}}
       }
\examples{
\dontrun{

x<-isample(1e6)
all.equal(median(x),imedian(x))
}
}
\keyword{arith}
