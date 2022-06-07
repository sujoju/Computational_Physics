#include <gsl/gsl_multifit_nlinear.h>

// exp
void 
callback(const size_t iter, void *params, 
    const gsl_multifit_nlinear_workspace *w);

// for higgs
void 
callbackBG(const size_t iter, void *params, 
    const gsl_multifit_nlinear_workspace *w);
void 
callbackSIG(const size_t iter, void *params, 
    const gsl_multifit_nlinear_workspace *w);
void 
callbackSIGBG2(const size_t iter, void *params, 
    const gsl_multifit_nlinear_workspace *w);
void 
callbackSIGBG3(const size_t iter, void *params, 
    const gsl_multifit_nlinear_workspace *w);
