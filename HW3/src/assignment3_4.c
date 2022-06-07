/*Jun Sung*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h> /* for strtod */

#include "rkO4.h"
#include "sho.h"

#ifndef MAX
#define MAX 1000
#endif

#ifndef TSTEP
#define TSTEP 0.04
#endif


int main(int argc, char ** argv) { 

  int i=0;
  TwoComponent x[MAX]; /* Na = theta, Nb = omega */
  double t[MAX];
  double dt=TSTEP;
  double scan_param = 0.0;
  double max_ampl = 0.0;
  double fparams[] = { 9.81, /* g */
                       1.0,  /* l */
                       1.0,  /* q */ 
                       0.667,  /* Omega_D */ 
                       0.2   /* F_D */ 
  }; 
  double errsum=0;

  if( argc != 6 ) {
    fprintf(stderr, "error: argument is <theta_i> <q> <Omega_D> <F>\n");
    return -1;
  }

  /* radians */
  x[0].A=strtod(argv[1],NULL), x[0].B=0.;
  t[0]=0;

  /* update q,Omega_D,F in fparams with input values */
  fparams[2] = strtod(argv[2],NULL);
  fparams[3] = strtod(argv[3],NULL);
  fparams[4] = strtod(argv[4],NULL);

  rkO4_solver_2component_fp(x,t,&ftheta,&f_damped_driven,fparams,dt,MAX); 

  if( atoi(argv[5]) ) { 
    scan_param = fparams[2];
  } else {
    scan_param = fparams[3];
  }
  for( i=500; i<MAX; i++ ) { 
    if ( i == 500 ) {
      max_ampl = x[i].A;
    } else if ( max_ampl < x[i].A ) {
      max_ampl = x[i].A;
    }
  }
  printf( "%lf\t%lf\t\n", scan_param, max_ampl );

}
