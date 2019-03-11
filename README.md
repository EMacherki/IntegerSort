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





