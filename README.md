# IntegerSort
This package uses RAM based algorithm such as radix sort and counting sort and is designed to manipulate large data. For opposit targe,insertion sort algorithm is added to operate small data set. Such algorithms give more performance when it used with uniform data and are considered as low level tools (C/C++ ressources ) which leads more vigilance and good practice of user.

### Installation
IntegerSort package need compilation (basically written with Rcpp) and can be installed from  github using devtools :
```
devtools::install_github("EMacherki/IntegerSort")
```
After installation restart R sesssion and the package is running.

### Benchmarking
#### counting sort

```
> x<-sample(1:10000,10000000,TRUE)
> # x is a large integer vector with supported range 
> system.time(sort(x))
utilisateur     système      écoulé 
       0.58        0.05        0.62 
> system.time(countSort(x))
utilisateur     système      écoulé 
       0.05        0.02        0.07 
> all.equal(countSort(x),sort(x)) # return TRUE
[1] TRUE
> # in-place running
> system.time(countSort(x,inplace= TRUE)) 
utilisateur     système      écoulé 
       0.05        0.00        0.05 
> all.equal(sort(x),x)  #return TRUE
[1] TRUE
```
#### lsdSort

```
> x<-isample(10000000)
> # x is an uniform  sample of intgers
> system.time(sort(x))
utilisateur     système      écoulé 
       1.31        0.00        1.31 
> system.time(lsdSort(x))
utilisateur     système      écoulé 
       0.18        0.03        0.20 
> all.equal(sort(x),lsdSort(x)) # return TRUE
[1] TRUE
> system.time(lsdSort(x,TRUE))  # testing in-place
utilisateur     système      écoulé 
       0.14        0.00        0.16 
> all.equal(sort(x),x)          # return TRUE 
[1] TRUE
```

#### insertSort
For this example we use microbenchmark package:
```
> x<-isample(60)
> microbenchmark::microbenchmark(insertSort(x),lsdSort(x),sort(x))
Unit: microseconds
          expr    min      lq     mean median      uq     max neval
 insertSort(x)  2.994  3.4220  4.50364  3.850  5.5600   7.271   100
    lsdSort(x)  5.559  5.9880  7.21058  6.415  8.1260  25.659   100
       sort(x) 65.428 67.5665 70.04705 67.995 69.4915 160.791   100
```




