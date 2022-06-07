#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_multifit_nlinear.h>

#include "exp_for_GSL.h"

int expb_f ( const gsl_vector * x, void *data, gsl_vector * f ) {
    size_t n = ((struct data *)data)->n;
    double *t = ((struct data *)data)->t;
    double *y = ((struct data *)data)->y;

    double A = gsl_vector_get (x, 0);
    double lambda = gsl_vector_get (x, 1);
    double b = gsl_vector_get (x, 2);

    size_t i;

    for (i = 0; i < n; i++) {
        /* Model Yi = A * exp(-t_i / lambda ) + b */
        double Yi = A * exp (- t[i] / lambda) + b;
        gsl_vector_set (f, i, Yi - y[i]);
    }

    return GSL_SUCCESS;
}

int expb_df ( const gsl_vector * x, void *data, gsl_matrix * J ) {
    size_t n = ((struct data *)data)->n;
    double *t = ((struct data *)data)->t;

    double A = gsl_vector_get (x, 0);
    double lambda = gsl_vector_get (x, 1);

    size_t i;

    for (i = 0; i < n; i++) {
        /* Jacobian matrix J(i,j) = dfi / dxj, */
        /* where fi = (Yi - yi)/sigma[i],      */
        /*       Yi = A * exp(- t[i] / lambda) + b  */
        /* and the xj are the parameters (A,lambda,b) */
        double e = exp(- t[i] / lambda);
        gsl_matrix_set (J, i, 0, e);
        gsl_matrix_set (J, i, 1, ( t[i] / (lambda*lambda) ) * A * e);
        gsl_matrix_set (J, i, 2, 1.0);
    }

    return GSL_SUCCESS;
}

