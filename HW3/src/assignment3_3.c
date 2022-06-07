/*Jun Sung*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h> /* for strtod */

#include "euler.h"
#include "rkO2.h"
#include "rkO4.h"
#include "sho.h"

#ifndef MAX
#define MAX 400
#endif

#ifndef TSTEP
#define TSTEP 0.04
#endif


int main(int argc, char ** argv) { 

    int i=0;
    TwoComponent x[MAX]; /* Na = theta, Nb = omega */
    double t[MAX];
    double dt=TSTEP;
    double fparams[] = { 9.81, /* g */
            1.0   /* l */
    }; 
    double errsum=0;

    if( argc != 3 ) {
      fprintf(stderr, "error: argument is <theta_i>\n");
      return -1;
    }

    /* radians */
    x[0].A=strtod(argv[1],NULL), x[0].B=0.;
    t[0]=0;

    if( atoi(argv[2]) == 0 ) { 
        euler_solver_2component_fp(x,t,&ftheta,&fomega,fparams,dt,MAX); 
    } else if ( atoi(argv[2]) == 1 ){ 
        rkO2_solver_2component_fp(x,t,&ftheta,&fomega,fparams,dt,MAX); 
    } else {
        rkO4_solver_2component_fp(x,t,&ftheta,&fomega,fparams,dt,MAX); 
    }

    for( i=0; i<MAX; i++ ) { 
      printf( "%lf\t%lf\t%lf\t%lf\n", 
        t[i], x[i].A, x[i].B, total_energy((x+i),fparams) );
    }

}
