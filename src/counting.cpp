
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


using namespace Rcpp; 





 inline bool count_sort(  int  *arr ,
                          int * m_count,
                          const int N 
                            ){
  
 // true mean an error is occured
  
  if(N<2)return false;
  
  int Max,Min;
  Max=Min=arr[0];
  
  for(int *i=arr+1;i!=arr+N;i++) {
    if(Max<*i)Max=*i;
    if(Min>*i)Min=*i;
    }
  
   int Range=Max-Min+1;
  
  if(Range>0x10000 || Range <0) return true;
  
  for(int *i=arr;i!=arr+N;i++) m_count[*i-Min]++;                           
  for(int i=0,*j=m_count;i<Range;i++){
    while((*j)--) *(arr++)=i+Min;
    *j++=0; // ===> allowing generic code (reset m_count to 0)
    }
   return false; 
}






inline SEXP CS_inplace(SEXP x){
  const int N=LENGTH(x);
  int * arr=INTEGER(x);
  
  int m_count[0x10000]={0}; 
if(count_sort(arr,m_count,N))
  Rf_error("too big range of data ::  must be less then 0x10000");

  return x;
}

 
 
 
 inline SEXP CS_helper(SEXP u){
  
   const int N=LENGTH(u);
   int * arr=INTEGER(u);
   if(N<2)return u;
   
   int Max,Min;
   Max=Min=arr[0];
   
   for(int *i=arr+1;i!=arr+N;i++) {
     if(Max<*i)Max=*i;
     if(Min>*i)Min=*i;
   }
   
   
   
   int Range=Max-Min+1;
   if(Range>0x10000 || Range <0) 
     Rf_error("too big range of data ::  must be less then 0x10000");
   
   
   int m_count[0x10000]={0};
   SEXP x=clone(u);
   int *aux=INTEGER(x);
   for(int *i=arr;i!=arr+N;i++) m_count[(*i)-Min]++;                           
   for(int i=0,*j=m_count;i<Range;i++){
     while((*j)--) *(aux++)=i+Min;
     *j++=0; 
   }
   
     return x;
 }
 
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
  
