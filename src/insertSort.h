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


inline 
  void 
      sort_insert( int *A,
                   const int N
) {
        
  if(N<2)return;
  int *j,*k,*i,x,tmp;
  
 tmp=*A;*A= INT_MIN; x=*(A+1);                  // starting
  
  for(i=A+1; i!=A+N;*k=x,i++,x=*i)
    for(j=i-1,k=i;*j>x;j--,k--)*k =*j;
  
  for(i=A+1,k=A; *i<tmp && i!=A+N ;i++,k++)*k=*i; // finalizer 
  
  *k=tmp;
  
}


 // R Api
inline SEXP  isort_inplace(SEXP On){ 
    sort_insert(INTEGER(On),LENGTH(On));
  return On;
}

inline SEXP  isort(SEXP u){ 
  SEXP On=clone(u);
  sort_insert(INTEGER(On),LENGTH(On));
  return On;
}





