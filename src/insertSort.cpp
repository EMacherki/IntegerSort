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



inline SEXP  isort_inplace(SEXP On){ 
    sort_insert(INTEGER(On),LENGTH(On));
  return On;
}

inline SEXP  isort(SEXP u){ 
  SEXP On=clone(u);
  sort_insert(INTEGER(On),LENGTH(On));
  return On;
}

//interface 

// [[Rcpp::export]]

SEXP insertSort(SEXP unsorted,
                bool inplace= false){
  
  if(inplace)return isort_inplace(unsorted);
  return isort(unsorted);
  
}




