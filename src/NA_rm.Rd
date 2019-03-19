\name{NA_rm}
\alias{NA_rm}

\title{Remove NA value from integer vector }
\description{This function is NA handler for integer  vector useful to align  many function of this package witch consider NA as the lowest integer value.     }

\usage{
NA_rm(x)
}

\arguments{
\item{x}{ integer vector}
          }
          

\value{
\item{Default}{ An integer vector with no NA  }

}


\author{Med Ezzeddine MACHERKI}

\seealso{
\code{\link{pth_pair}}
\code{\link{imedian}}
\code{\link{pth}}

       }
\examples{

x<-as.integer(c(NA,NA,88))
NA_rm(x) #return 88
}
\keyword{arith}
