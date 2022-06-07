/*Jun Sung*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wave.h"

#define MAX_TSAMPLE 1000
#define MAX_XSAMPLE 100

const double k = 1000;

int
main ()  { 
  
    double ** yarr = malloc(MAX_TSAMPLE*sizeof(double*)); // each element holds y,x
    for ( int i=0; i<MAX_TSAMPLE; i++ ) {
        *(yarr+i) = malloc(MAX_XSAMPLE*sizeof(double));
        for ( int j=0; j<MAX_XSAMPLE; j++ ) {
        yarr[i][j] = 0;
        }
    }

    // init with gaussian pluck ...
    initialize_with_gauss(yarr, MAX_TSAMPLE, MAX_XSAMPLE, k, 0.5, dx );

    // generate wave data ...
    propagate( yarr, MAX_TSAMPLE, MAX_XSAMPLE, r);


    // save waveform snapshots ...
    char fname[256];
    for ( int i=0; i<MAX_TSAMPLE; i++ ) {
        sprintf(fname, "data/wavedata_pulse_t_%d.dat", i);
        FILE* f = fopen(fname, "w");
        for ( int j=0; j<MAX_XSAMPLE; j++ ) {
        fprintf( f, "t: %lf\tx: %lf\ty: %lf\n", i*dt, j*dx, yarr[i][j]);
        }
        fclose(f);
    }

    FILE * fts = fopen("data/timeseries_pulse_at_x_0.05.dat", "w");
    for( int i=0; i<MAX_TSAMPLE; i++ ) { 
        fprintf( fts, "t: %f\tx: %f\ty: %f\n",i*dt,5*dx,yarr[i][5]);
    }
    fclose(fts);

}
