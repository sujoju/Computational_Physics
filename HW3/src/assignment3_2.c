/*Jun Sung*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h> /* for strtod */

#include "euler.h"
#include "projectiles.h"

#ifndef MAX
#define MAX 1300
#endif

#ifndef TSTEP
#define TSTEP 0.5
#endif 

int main(int argc, char ** argv) { 

    int i=0;
    FourComponent proj[MAX]; /* A = x, B = vx */
                            /* C = y, D = vy */
    double t[MAX];
    double dt=TSTEP;
    double fparams[] = { 9.81,   /* g */
      4e-5,   /*  B2/m */
      6.5e-3, /* a */
      300,    /* T0 */
      2.5     /* alpha */
    };
    double errsum=0;

    if( argc != 4 ) {
      fprintf(stderr, "error: arguments are <vx> <vy> <simple drag (0) | adiabatic (1)> \n");
      return -1;
    }

    proj[0].A=0., proj[0].B=strtod(argv[1],NULL);
    proj[0].C=0., proj[0].D=strtod(argv[2],NULL);
    t[0] = 0;

    if( atoi(argv[3]) ) { 
      euler_solver_4component_fp(proj,t,&fx_drag,&fvx_drag_adiabatic,&fy_drag,&fvy_drag_adiabatic,fparams,dt,MAX); 
    } else { 
      euler_solver_4component_fp(proj,t,&fx_drag,&fvx_drag,&fy_drag,&fvy_drag,fparams,dt,MAX); 
    }

    for( i=0; i<MAX; i++ ) { 
      printf( "%f\t%f\t%f\t%f\t%f\n", t[i], 
              proj[i].A, proj[i].C,
              proj[i].B, proj[i].D );
    }
}
