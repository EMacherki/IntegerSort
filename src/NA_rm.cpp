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


       using namespace Rcpp;


// [[Rcpp::export]]
SEXP NA_rm(SEXP x){
int *ptr=INTEGER(x);
int N=LENGTH(x);
int nNA=0;
  for(int *i=ptr;i!=ptr+N;i++)nNA+=*i==NA_INTEGER;
  if(nNA==0) return x;
  SEXP res=Rf_allocVector(INTSXP,N-nNA);
  int *ptr_res=INTEGER(res);
  for(int *i=ptr;i!=ptr+N;i++) 
    if(*i!=NA_INTEGER)*ptr_res++ =*i;
  return res;
}




