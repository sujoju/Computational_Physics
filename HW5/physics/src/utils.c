#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_multifit_nlinear.h>

void
callback( const size_t iter, void *params, const gsl_multifit_nlinear_workspace *w ) {
    gsl_vector *f = gsl_multifit_nlinear_residual(w);
    gsl_vector *x = gsl_multifit_nlinear_position(w);
    double rcond;

    /* compute reciprocal condition number of J(x) */
    gsl_multifit_nlinear_rcond(&rcond, w);

    fprintf( stderr, 
        "iter %2zu: Ab = %.4f, lambda = %.4f,  cond(J) = %8.4f, |f(x)| = %.4f\n",
        iter,
        gsl_vector_get(x, 0),
        gsl_vector_get(x, 1),
        1.0 / rcond,
        gsl_blas_dnrm2(f)
    );
}

void
callbackBG( const size_t iter, void *params, const gsl_multifit_nlinear_workspace *w ) {
    gsl_vector *f = gsl_multifit_nlinear_residual(w);
    gsl_vector *x = gsl_multifit_nlinear_position(w);
    double rcond;

    /* compute reciprocal condition number of J(x) */
    gsl_multifit_nlinear_rcond(&rcond, w);

    fprintf(stderr, 
        "iter %2zu: Ab = %.4f, lambda = %.4f, x0 = %.4f,  cond(J) = %8.4f, \
        |f(x)| = %.4f\n",
        iter,
        gsl_vector_get(x, 0),
        gsl_vector_get(x, 1),
        gsl_vector_get(x, 2),
        1.0 / rcond,
        gsl_blas_dnrm2(f)
    );
}

void
callbackSIG( const size_t iter, void *params, const gsl_multifit_nlinear_workspace *w) {
    gsl_vector *f = gsl_multifit_nlinear_residual(w);
    gsl_vector *x = gsl_multifit_nlinear_position(w);
    double rcond;

    /* compute reciprocal condition number of J(x) */
    gsl_multifit_nlinear_rcond(&rcond, w);

    fprintf( stderr, 
        "iter %2zu: As = %.4f, mu = %.4f, sigma = %.4f,  cond(J) = %8.4f, \
        |f(x)| = %.4f\n",
        iter,
        gsl_vector_get(x, 0),
        gsl_vector_get(x, 1),
        gsl_vector_get(x, 2),
        1.0 / rcond,
        gsl_blas_dnrm2(f)
    );
}

void
callbackSIGBG2( const size_t iter, void *params, 
    const gsl_multifit_nlinear_workspace *w) {
    gsl_vector *f = gsl_multifit_nlinear_residual(w);
    gsl_vector *x = gsl_multifit_nlinear_position(w);
    double rcond;

    /* compute reciprocal condition number of J(x) */
    gsl_multifit_nlinear_rcond(&rcond, w);

    fprintf( stderr, 
        "iter %2zu: As = %.4f, mu = %.4f, sigma = %.4f, Ab = %.4f, tau = %.4f,  \
        cond(J) = %8.4f, |f(x)| = %.4f\n",
        iter,
        gsl_vector_get(x, 0),
        gsl_vector_get(x, 1),
        gsl_vector_get(x, 2),
        gsl_vector_get(x, 3),
        gsl_vector_get(x, 4),
        1.0 / rcond,
        gsl_blas_dnrm2(f)
    );
}

void
callbackSIGBG3( const size_t iter, void *params,
    const gsl_multifit_nlinear_workspace *w) {
    gsl_vector *f = gsl_multifit_nlinear_residual(w);
    gsl_vector *x = gsl_multifit_nlinear_position(w);
    double rcond;

    /* compute reciprocal condition number of J(x) */
    gsl_multifit_nlinear_rcond(&rcond, w);

    fprintf( stderr, 
        "iter %2zu: As = %.4f, mu = %.4f, sigma = %.4f, Ab = %.4f, tau = %.4f, \
        x0 = %.4f  cond(J) = %8.4f, |f(x)| = %.4f\n",
        iter,
        gsl_vector_get(x, 0),
        gsl_vector_get(x, 1),
        gsl_vector_get(x, 2),
        gsl_vector_get(x, 3),
        gsl_vector_get(x, 4),
        gsl_vector_get(x, 5),
        1.0 / rcond,
        gsl_blas_dnrm2(f)
    );
}
