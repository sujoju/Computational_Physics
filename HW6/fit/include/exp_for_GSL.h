#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>

struct data {
    size_t n;
    double * t;
    double * y;
};

int expb_f ( const gsl_vector * x, void *data, gsl_vector * f );
int expb_df ( const gsl_vector * x, void *data, gsl_matrix * J );
