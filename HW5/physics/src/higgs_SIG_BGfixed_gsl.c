#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>

#include "higgs_SIG_BGfixed_gsl.h"

int gaus_fixedExp_f( const gsl_vector * x, void *data, gsl_vector * f ) {
    size_t n = ((struct data *)data)->n;
    double *t = ((struct data *)data)->t;
    double *y = ((struct data *)data)->y;

    double As = gsl_vector_get (x, 0);
    double mu = gsl_vector_get (x, 1);
    double sigma = gsl_vector_get (x, 2);

    size_t i;

    for (i = 0; i < n; i++) {
        /* Model Yi = As * exp(- (1 / (2 * pow(sigma, 2.0))) * pow((t[i] - mu), 2.0)) 
        + Ab * exp((t[i]-x_0)/tau) */
        double Yi = As * exp( - (1 / (2 * pow(sigma, 2.0))) * pow((t[i] - mu), 2.0)) \
            + BG_AB * exp( (t[i] - BG_X0) / BG_TAU );
        gsl_vector_set (f, i, Yi - y[i]);
    }

    return GSL_SUCCESS;
}

int gaus_fixedExp_df( const gsl_vector * x, void *data, gsl_matrix * J ) {
    size_t n = ((struct data *)data)->n;
    double *t = ((struct data *)data)->t;

    double As = gsl_vector_get (x, 0);
    double mu = gsl_vector_get (x, 1);
    double sigma = gsl_vector_get (x, 2);

    size_t i;

    for (i = 0; i < n; i++) {
        /* Jacobian matrix J(i,j) = dfi / dxj, */
        /* where fi = (Yi - yi)/sigma[i],      */
        /*       Yi = As * exp(- (1 / (2 * pow(sigma, 2.0))) * pow((t[i] - mu), 2.0)) 
            + Ab * exp((t[i]-x_0)/tau)  */
        /* and the xj are the parameters (As,mu,sigma) */
        double e = exp( - (1 / (2 * pow(sigma, 2.0))) * pow((t[i] - mu), 2.0));
        gsl_matrix_set (J, i, 0, e);
        gsl_matrix_set (J, i, 1, As * (t[i] - mu) / pow(sigma, 2.0) * e );
        gsl_matrix_set (J, i, 2, As * pow((t[i] - mu), 2.0) / pow(sigma, 3.0) * e );
    }

    return GSL_SUCCESS;
}

