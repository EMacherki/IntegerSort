// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// NA_rm
SEXP NA_rm(SEXP x);
RcppExport SEXP _IntegerSort_NA_rm(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(NA_rm(x));
    return rcpp_result_gen;
END_RCPP
}
// countSort
SEXP countSort(SEXP unsorted, bool inplace);
RcppExport SEXP _IntegerSort_countSort(SEXP unsortedSEXP, SEXP inplaceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type unsorted(unsortedSEXP);
    Rcpp::traits::input_parameter< bool >::type inplace(inplaceSEXP);
    rcpp_result_gen = Rcpp::wrap(countSort(unsorted, inplace));
    return rcpp_result_gen;
END_RCPP
}
// insertSort
SEXP insertSort(SEXP unsorted, bool inplace);
RcppExport SEXP _IntegerSort_insertSort(SEXP unsortedSEXP, SEXP inplaceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type unsorted(unsortedSEXP);
    Rcpp::traits::input_parameter< bool >::type inplace(inplaceSEXP);
    rcpp_result_gen = Rcpp::wrap(insertSort(unsorted, inplace));
    return rcpp_result_gen;
END_RCPP
}
// isample
IntegerVector isample(int size);
RcppExport SEXP _IntegerSort_isample(SEXP sizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type size(sizeSEXP);
    rcpp_result_gen = Rcpp::wrap(isample(size));
    return rcpp_result_gen;
END_RCPP
}
// lsdSort
SEXP lsdSort(SEXP unsorted, bool inplace);
RcppExport SEXP _IntegerSort_lsdSort(SEXP unsortedSEXP, SEXP inplaceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type unsorted(unsortedSEXP);
    Rcpp::traits::input_parameter< bool >::type inplace(inplaceSEXP);
    rcpp_result_gen = Rcpp::wrap(lsdSort(unsorted, inplace));
    return rcpp_result_gen;
END_RCPP
}
// imedian
double imedian(SEXP x);
RcppExport SEXP _IntegerSort_imedian(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(imedian(x));
    return rcpp_result_gen;
END_RCPP
}
// pth
int pth(SEXP x, int p);
RcppExport SEXP _IntegerSort_pth(SEXP xSEXP, SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type p(pSEXP);
    rcpp_result_gen = Rcpp::wrap(pth(x, p));
    return rcpp_result_gen;
END_RCPP
}
// pth_pair
double pth_pair(SEXP x, int p);
RcppExport SEXP _IntegerSort_pth_pair(SEXP xSEXP, SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type p(pSEXP);
    rcpp_result_gen = Rcpp::wrap(pth_pair(x, p));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_IntegerSort_NA_rm", (DL_FUNC) &_IntegerSort_NA_rm, 1},
    {"_IntegerSort_countSort", (DL_FUNC) &_IntegerSort_countSort, 2},
    {"_IntegerSort_insertSort", (DL_FUNC) &_IntegerSort_insertSort, 2},
    {"_IntegerSort_isample", (DL_FUNC) &_IntegerSort_isample, 1},
    {"_IntegerSort_lsdSort", (DL_FUNC) &_IntegerSort_lsdSort, 2},
    {"_IntegerSort_imedian", (DL_FUNC) &_IntegerSort_imedian, 1},
    {"_IntegerSort_pth", (DL_FUNC) &_IntegerSort_pth, 2},
    {"_IntegerSort_pth_pair", (DL_FUNC) &_IntegerSort_pth_pair, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_IntegerSort(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
