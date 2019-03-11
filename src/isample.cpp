#include <Rcpp.h>



using namespace Rcpp; 

//--------------------------isample using sugar ---------------------------


// [[Rcpp::export]]

   IntegerVector isample(int size=1 ){
  return wrap(runif(size,-2147483647,2147483647)); 
} 