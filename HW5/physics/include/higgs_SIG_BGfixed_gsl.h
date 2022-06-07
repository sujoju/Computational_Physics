#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>

#define N      60    /* number of data points to fit */
#define TMAX   (159.5)  /* time variable in [0,TMAX] */
#define BIN_OFFSET 100

/* best-fit values from BG-only exp fit */
/*
Ab     = 1693.24964 +/- 20.35516
tau    = -20.34237 +/- 0.22290
*/
#define BG_AB  1693.24964
#define BG_TAU -20.34237 
#define BG_X0  100.000
// nparams for signal 
#define NPARAMS 3     


struct data {
  size_t n;
  double * t;
  double * y;
};

int gaus_fixedExp_f( const gsl_vector * x, void *data, gsl_vector * f );
int gaus_fixedExp_df( const gsl_vector * x, void *data, gsl_matrix * J );
