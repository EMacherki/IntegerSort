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
/* 
  
 This file adapt an implimentation of counting sort of integers
 with 16 bit range (max-min< 2^16).The algorithm used calculate
 maxima and  minima to fit a tranformation function of data into 
 a counting bucket.While filling the output , the counting bucket
 is reset allowing generic behavour. In case of range overflow,
 the counting algorithm is managed to avoid create extra memory
 if a new vector is needed for the result.Only finite values are
 managed by this code into increasing order. 
 
 */




#include <Rcpp.h>
#include "counting.h" 


using namespace Rcpp; 





 





 
 
 
 
// interface
 
 // [[Rcpp::export]]
 
 SEXP countSort(SEXP unsorted,
         bool inplace=false 
           )
   {
   
   if(inplace)
   return CS_inplace(unsorted);
   return CS_helper(unsorted);
 }
  
