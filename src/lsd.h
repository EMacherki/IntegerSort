#include <Rcpp.h>




using namespace Rcpp;






inline void olsd( 
    unsigned   *arr_begin,   //iterator
    unsigned   *arr_end      
){
  
  int N=arr_end-arr_begin;
  if(N<2)return;
  unsigned *i;int tmp;
  
  unsigned int *arr=arr_begin;
  
  int count1[0x100]={0};   
  int count2[0x100]={0};   
  int count3[0x100]={0};   
  int count4[0x100]={0};  
  
  for(i=arr;i!=arr+N;i++)
  {   
    count1[ (*i^= INT_MIN)&0XFF]++; // this sign is reversed
    count2[ (*i>>0X8)  &  0XFF]++;
    count3[ (*i>>0X10) &  0XFF]++;
    count4[ (*i>>0X18) &  0XFF]++;
  }
  
  
  int  used =0; // a bit mask to get which count array is in use 
  
  for(int j=0;j<0X100;j++) if(count1[j]==N) {used+=0X8;break;}
  for(int j=0;j<0X100;j++) if(count2[j]==N) {used+=0X4;break;}
  for(int j=0;j<0x100;j++) if(count3[j]==N) {used+=0X2;break;}
  for(int j=0;j<0X100;j++) if(count4[j]==N) {used+=0X1;break;}
  
  
  
  used=0XF-used; // flip bit
  
  
  
  
  if(!used){                           // no data to be sorted
    for(i=arr_begin;i!=arr_end;i++) *i^= INT_MIN;
    return;
  }
  int index1[0x100];
  int index2[0x100];
  int index3[0x100];
  int index4[0x100];
  
  index1[0]=0;tmp=0;for(int i=1;i<0x100;i++) index1[i]=tmp+=count1[i-1];
  index2[0]=0;tmp=0;for(int i=1;i<0x100;i++) index2[i]=tmp+=count2[i-1];
  index3[0]=0;tmp=0;for(int i=1;i<0x100;i++) index3[i]=tmp+=count3[i-1];
  index4[0]=0;tmp=0;for(int i=1;i<0x100;i++) index4[i]=tmp+=count4[i-1];
  
  
  // a helper array is required
  unsigned int *stack =new unsigned int [N];
  // iterator
  unsigned *sta_begin=stack;
  unsigned *sta_end=stack+N;
  // we manage each case alone
  switch(used){
  // cas mono
  case 0X8:
    for(i=arr_begin;i!=arr_end;i++)  stack[index1[ *i     & 0XFF]++]=*i;
    for(int j=0;j<N;j++) arr[j]=stack[j]^INT_MIN;
    delete stack;return;
    break;
  case 0X4:
    for(i=arr_begin;i!=arr_end;i++)  stack[index2[ (*i>>0X8)     & 0XFF]++]=*i;
    for(int j=0;j<N;j++) arr[j]=stack[j]^INT_MIN;
    delete stack;return;
    break;
  case 0X2:
    for(i=arr_begin;i!=arr_end;i++)  stack[index3[ (*i>>0X10)& 0XFF]++]=*i;
    for(int j=0;j<N;j++) arr[j]=stack[j]^INT_MIN;
    delete stack;return;
    break;
  case 0X1:
    for(i=arr_begin;i!=arr_end;i++)  stack[index4[ (*i>>0X18)     & 0XFF]++]=*i;
    for(int j=0;j<N;j++) arr[j]=stack[j]^INT_MIN;
    delete stack;return;
    break;
    //cas bis
  case 0XC:
    for(i=arr_begin;i!=arr_end;i++)  stack[index1[ *i     & 0XFF]++]=*i;
    for(i=sta_begin;i!=sta_end;i++)  arr[index2[(*i>>0X8)&  0XFF]++]=*i^INT_MIN;
    delete stack;return;
    break;
  case 0XA:
    for(i=arr_begin;i!=arr_end;i++)  stack[index1[ *i     & 0XFF]++]=*i;
    for(i=sta_begin;i!=sta_end;i++)  arr[index3[(*i>>0X10)&  0XFF]++]=*i^INT_MIN;
    delete stack;return;
    break;
  case 0X9:
    for(i=arr_begin;i!=arr_end;i++)  stack[index1[ *i     & 0XFF]++]=*i;
    for(i=sta_begin;i!=sta_end;i++)  arr[index4[(*i>>0X18)&  0XFF]++]=*i^INT_MIN;
    delete stack;return;
    break;
    
  case 0X6:
    for(i=arr_begin;i!=arr_end;i++)  stack[index2[ (*i>>0X8) & 0XFF]++]=*i;
    for(i=sta_begin;i!=sta_end;i++)  arr[index3[(*i>>0X10)&  0XFF]++]=*i^INT_MIN;
    delete stack;return;
    break;
  case 0X5:
    for(i=arr_begin;i!=arr_end;i++)  stack[index2[ (*i>>0X8) & 0XFF]++]=*i;
    for(i=sta_begin;i!=sta_end;i++)  arr[index4[(*i>>0X18)&  0XFF]++]=*i^INT_MIN;
    delete stack;return;
    break;
  case 0X3:
    for(i=arr_begin;i!=arr_end;i++)  stack[index3[ (*i>>0X10) & 0XFF]++]=*i;
    for(i=sta_begin;i!=sta_end;i++)  arr[index4[(*i>>0X18)&  0XFF]++]=*i^INT_MIN;
    delete stack;return;
    break;
    
    // cas trio
  case 0XE:
    for(i=arr_begin;i!=arr_end;i++)  stack[index1[ *i & 0XFF]++]=*i;
    for(i=sta_begin;i!=sta_end;i++)  arr[index2[(*i>>0X8)&  0XFF]++]=*i;
    for(i=arr_begin;i!=arr_end;i++)  stack[index3[ (*i>>0X10) & 0XFF]++]=*i;
    for(int j=0;j<N;j++) arr[j]=stack[j]^INT_MIN;
    delete stack;return;
    break;
  case 0XD:
    for(i=arr_begin;i!=arr_end;i++)  stack[index1[ *i & 0XFF]++]=*i;
    for(i=sta_begin;i!=sta_end;i++)  arr[index2[(*i>>0X8)&  0XFF]++]=*i;
    for(i=arr_begin;i!=arr_end;i++)  stack[index4[ (*i>>0X18) & 0XFF]++]=*i;
    for(int j=0;j<N;j++) arr[j]=stack[j]^INT_MIN;
    delete stack;return;
    break;
  case 0XB:
    for(i=arr_begin;i!=arr_end;i++)  stack[index1[ *i & 0XFF]++]=*i;
    for(i=sta_begin;i!=sta_end;i++)  arr[index3[(*i>>0X10)&  0XFF]++]=*i;
    for(i=arr_begin;i!=arr_end;i++)  stack[index4[ (*i>>0X18) & 0XFF]++]=*i;
    for(int j=0;j<N;j++) arr[j]=stack[j]^INT_MIN;
    delete stack;return;
    break;
  case 0X7:
    for(i=arr_begin;i!=arr_end;i++)  stack[index2[ (*i>>0X8) & 0XFF]++]=*i;
    for(i=sta_begin;i!=sta_end;i++)  arr[index3[(*i>>0X10)&  0XFF]++]=*i;
    for(i=arr_begin;i!=arr_end;i++)  stack[index4[ (*i>>0X18) & 0XFF]++]=*i;
    for(int j=0;j<N;j++) arr[j]=stack[j]^INT_MIN;
    delete stack;return;
    break;
  case 0XF:
    for(i=arr_begin;i!=arr_end;i++)  stack[index1[ *i & 0XFF]++]=*i;
    for(i=sta_begin;i!=sta_end;i++)  arr[index2[(*i>>0X8)&  0XFF]++]=*i;
    for(i=arr_begin;i!=arr_end;i++)  stack[index3[ (*i>>0X10) & 0XFF]++]=*i;
    for(i=sta_begin;i!=sta_end;i++)  arr[index4[(*i>>0X18)&  0XFF]++]=*i^INT_MIN;
    delete stack;return;
    break;
    
    
    
  }
  
  
  
}


inline SEXP lsdSort_default(
    SEXP input  //only INTEGER vector are supported
)
{
  
  SEXP x=clone(input);   
  unsigned  *array =(unsigned  *)INTEGER(x);
  const int N=Rf_length(input);
  
  olsd(array,array+N);
  return(x);
  
}

inline SEXP lsdSort_inplace(
    SEXP input  //only INTEGER vector are supported
)
{
  
  unsigned  *array =(unsigned  *)INTEGER(input);
  const int N=Rf_length(input);
  
  olsd(array,array+N);
  
  
  
  return(input);
  
}