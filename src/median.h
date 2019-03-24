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


#include "insertSort.h"
#include "lsd.h"


/* DONE
 * more effecient where the size of data is greater then 1e4
 * 
 * 
 */
int p_int_odd (unsigned *l, unsigned *r, int k){
  
  if(r-l<128){
    unsigned tmp[r-l];
    unsigned *it=tmp;
    for(unsigned *i=l;i!=r;i++) *it++=*i;
    sort_insert((int*)tmp,r-l);
    return tmp[k];
    
    
  }
  if(r-l<0x10000){
    unsigned tmp[r-l];
    unsigned *it=tmp;
    for(unsigned *i=l;i!=r;i++) *it++=*i;
    olsd(tmp,tmp+(r-l));
    return tmp[k];
    
    
  }
  
  
  int count[0x10000]={0};
  for(unsigned *i=l;i!=r;i++) count[(*i-INT_MIN) >>16]++;
  unsigned f=0;int pos=k+1;
  while(count[f]<pos) pos-=count[f++];
  
  for(int i=0;i<0x10000;i++)count[i]=0; // reset count to 0
  for(unsigned *i=l;i!=r;i++)
    if((*i-INT_MIN)>>16==f)count[(*i-INT_MIN)& 0xffff]++;
    unsigned b=0;
    while(count[b]<pos) pos-=count[b++];
    return ((f<<16)+b)+INT_MIN;
    
    
}

double p_int_pair (unsigned *l, unsigned *r, int k){
  if(r-l<128){
    unsigned tmp[r-l];
    unsigned *it=tmp;
    for(unsigned *i=l;i!=r;i++) *it++=*i;
    sort_insert((int*)tmp,r-l);
    double v1=(int)tmp[k];
    double v2=(int)tmp[k-1];
    
    
    return (v1+v2)/2.0;
    
    
  }
  if(r-l<0x10000){
    unsigned tmp[r-l];
    unsigned *it=tmp;
    for(unsigned *i=l;i!=r;i++) *it++=*i;
    olsd(tmp,tmp+(r-l));
    double v1=(int)tmp[k];
    double v2=(int)tmp[k-1];
    return (v1+v2)/2.0; 
    
  }
  
  int count[0x10000]={0};
  for(unsigned *i=l;i!=r;i++) count[(*i-INT_MIN) >>16]++;
  unsigned f=0;int pos=k;
  while(count[f]<pos) pos-=count[f++];
  unsigned f1=0; int pos1=k+1;
  while(count[f1]<pos1) pos1-=count[f1++];
 
  if(f==f1){
    
    for(int i=0;i<0x10000;i++)count[i]=0; // reset count to 0
    for(unsigned *i=l;i!=r;i++)
      if((*i-INT_MIN)>>16==f)count[(*i-INT_MIN)& 0xffff]++;
      
      unsigned b=0;
      while(count[b]<pos) pos-=count[b++];
      unsigned b1=0;
      while(count[b1]<pos1) pos1-=count[b1++];
      
      int v1=(f<<16)+b+INT_MIN;
      int v2=(f<<16)+b1+INT_MIN;
      
      return  ((double)v1+(double)v2)/(double)2; // double convertion is needed to avoid overflow
  }
  
  for(int i=0;i<0x10000;i++)count[i]=0; // reset count to 0
  for(unsigned *i=l;i!=r;i++)
    if((*i-INT_MIN)>>16==f)count[(*i-INT_MIN)& 0xffff]++;
    
    unsigned b=0;
    while(count[b]<pos) pos-=count[b++];
    
    for(int i=0;i<0x10000;i++)count[i]=0; // reset count to 0
    for(unsigned *i=l;i!=r;i++)
      if((*i-INT_MIN)>>16==f1)count[(*i-INT_MIN)& 0xffff]++;
      
      
      unsigned b1=0;
      while(count[b1]<pos1) pos1-=count[b1++];
      int v1=(f<<16)+b+INT_MIN;
      int v2=(f1<<16)+b1+INT_MIN;
      return  ((double)v1+(double)v2)/(double)2;
      
      
}

