/*
 MIT License

Copyright (c) [2019] [Med Ezzeddine Macherki]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#include <Rcpp.h>
#include "median.h"
using namespace Rcpp;




 // [[Rcpp::export]]
double imedian (SEXP x){ 
  unsigned int *a=(unsigned int *)INTEGER(x);
  int N=LENGTH(x);
  if(N==1)return *a;
  if(N==2)return ((double)*a+(double)*(a+1))/(double)2;
  if(N%2) return p_int_odd(a,a+N,(N/2));
          return p_int_pair(a,a+N,N/2);
  
}
// [[Rcpp::export]]
int pth (SEXP x,int p){ 
  unsigned int *a=(unsigned int *)INTEGER(x);
  int N=LENGTH(x);
  if(N<1) return INT_MIN;
  if(N==1)return *a;
  if(p<1 || p>N-1)Rf_error("p value over the range of the vector");
  return p_int_odd(a,a+N,p-1);
  
}

// [[Rcpp::export]]
double pth_pair (SEXP x,int p){ 
  unsigned int *a=(unsigned int *)INTEGER(x);
  int N=LENGTH(x);
  if(N<1) return INT_MIN;
  if(N==1)return *a;
  if(p<2 || p>N-1)Rf_error("p value over the range of the vector");
  return p_int_pair(a,a+N,p-1);
  
}


