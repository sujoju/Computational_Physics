/*Jun Sung*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "euler.h"
#include "rkO2.h"
#include "rkO4.h"
#include "decay.h"

int
main (int argc, char** argv)  { 

    int xmax = strtod(argv[1],NULL);
    double dt = strtod(argv[2],NULL);

    int i=0;
    double maxerr = 0.0;

    TwoComponent n[xmax];
    double t[xmax];
    double fparams[] = {1.,1.}; /* tc */

    /* set intial values */
    n[0].A=1000., n[0].B=0, t[0]=0;

    if( atoi(argv[3]) == 0 ) { 
        euler_solver_2component_fp(n,t,&fA,&fB,fparams,dt,xmax);
    } else if ( atoi(argv[3]) == 1 ) { 
        rkO2_solver_2component_fp(n,t,&fA,&fB,fparams,dt,xmax);
    } else {
        rkO4_solver_2component_fp(n,t,&fA,&fB,fparams,dt,xmax);
    }
    
    if ( argc < 5 ) {
        for( i=0; i<xmax; i++ ) { 
            double solA_Analytical = AnalyticalA(n[0].A, t[i], fparams);
            double err = fabs(solA_Analytical - n[i].A);

            if ( maxerr < err || i == 0 ) {
                maxerr = err;
            }

            printf( "%lf\t%lf\t%lf\t%lf\t%0.16f\n", t[i], n[i].A, n[i].B, solA_Analytical, err);
        }

        printf( "#%lf\t%d\t%0.16f", dt, xmax, maxerr);
    }
}