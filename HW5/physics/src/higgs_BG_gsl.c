#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>

#include "higgs_BG_gsl.h"

int bg_exp_f( const gsl_vector * x, void *data, gsl_vector * f ) {
    size_t n = ((struct data *)data)->n;
    double *t = ((struct data *)data)->t;
    double *y = ((struct data *)data)->y;

    double Ab = gsl_vector_get (x, 0);
    double tau = gsl_vector_get (x, 1);

    size_t i;

    for (i = 0; i < n; i++) {
        /* Model Yi = Ab * exp((t-x_0)/tau) */
        double Yi = Ab * exp ((t[i]-BG_X0)/tau);
        gsl_vector_set (f, i, Yi - y[i]);
    }

    return GSL_SUCCESS;
}

int bg_exp_df ( const gsl_vector * x, void *data, gsl_matrix * J ) {
    size_t n = ((struct data *)data)->n;
    double *t = ((struct data *)data)->t;

    double Ab = gsl_vector_get (x, 0);
    double tau = gsl_vector_get (x, 1);

    size_t i;

    for (i = 0; i < n; i++) {
        /* Jacobian matrix J(i,j) = dfi / dxj, */
        /* where fi = (Yi - yi)/sigma[i],      */
        /*       Yi = Ab * exp((t-x_0)/tau)  */
        /* and the xj are the parameters (Ab,tau,x_0) */
        double e = exp ((t[i]-BG_X0)/tau);
        gsl_matrix_set (J, i, 0, e);
        gsl_matrix_set (J, i, 1, - Ab * (( t[i] - BG_X0 ) / pow(tau, 2.0)) * e);
    }

    return GSL_SUCCESS;
}

