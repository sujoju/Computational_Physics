/*Jun Sung*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wave.h"

#define MAX_TSAMPLE 400
#define MAX_XSAMPLE 1600

int
main (int argc, char** argv)  { 
  
    if( argc != 2 ) { 
        printf("usage: main_wave_standing.exe <k>\n");
        printf( "\twhere k is a multiple of 2*PI\n");
        return -1;
    }
    double kmultiplier = strtod(argv[1],NULL);
    double k = kmultiplier*(2*M_PI);
    double f = c*k/(2*M_PI);

    double ** yarr = malloc(MAX_TSAMPLE*sizeof(double*)); // each element holds y,x
    for ( int i=0; i<MAX_TSAMPLE; i++ ) {
        *(yarr+i) = malloc(MAX_XSAMPLE*sizeof(double));
        for ( int j=0; j<MAX_XSAMPLE; j++ ) {
        yarr[i][j] = 0;
        }
    }

    // init with full wave ...
    initialize_with_wave(yarr, MAX_TSAMPLE, MAX_XSAMPLE, k, dx );

    // generate the wave data
    propagate( yarr, MAX_TSAMPLE, MAX_XSAMPLE, r);

    // print timeseries for all x ...
    char fname[256];
    for( int i=0; i<MAX_TSAMPLE; i++ ) { 
        sprintf( fname, "data/standing_t_%d.dat", i );
        FILE * f = fopen(fname, "w");
        for( int j=0; j<MAX_XSAMPLE; j++ ) { 
        fprintf( f, "%f\t%f\t%f\n",i*dt,j*dx,yarr[i][j]);
        }
        fclose(f);
    }

}