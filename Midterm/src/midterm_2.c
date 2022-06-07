#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wave.h"

#define MAX_TSAMPLE 800
#define MAX_XSAMPLE 1600


int
main (int argc, char** argv)  { 

  if( argc != 3 ) { 
    printf("usage: main_wave_beat.exe <k1> <k2>\n");
    printf("\twhere k1, k2 are multipliers of 2PI\n");
    return -1;
  }
  double kmult1 = strtod(argv[1],NULL);
  double kmult2 = strtod(argv[2],NULL);
  double k1  = (2*M_PI)*kmult1;//1.1*8*(2*M_PI);
  double k2  = (2*M_PI)*kmult2;//8*(2*M_PI);

  /* c = lambda*f = omega/k */
  /* omega = 2PI*f */

  double omega1 = c*k1;
  double omega2 = c*k2;

  double f1 = c*k1/(2*M_PI); 
  double f2 = c*k2/(2*M_PI); 

  
  double ** yarr1 = malloc(MAX_TSAMPLE*sizeof(double*)); // each element holds y,x
  double ** yarr2 = malloc(MAX_TSAMPLE*sizeof(double*)); // each element holds y,x
  double ** yarr3 = malloc(MAX_TSAMPLE*sizeof(double*)); // each element holds y,x
  for ( int i=0; i<MAX_TSAMPLE; i++ ) {
    *(yarr1+i) = malloc(MAX_XSAMPLE*sizeof(double));
    *(yarr2+i) = malloc(MAX_XSAMPLE*sizeof(double));
    *(yarr3+i) = malloc(MAX_XSAMPLE*sizeof(double));
    for ( int j=0; j<MAX_XSAMPLE; j++ ) {
      yarr1[i][j] = 0;
      yarr2[i][j] = 0;
      yarr3[i][j] = 0;
    }
  }

  // init with full waves ...
  initialize_with_free_wave(yarr1, MAX_TSAMPLE, MAX_XSAMPLE, k1, dx, omega1, dt);
  initialize_with_free_wave(yarr2, MAX_TSAMPLE, MAX_XSAMPLE, k2, dx, omega2, dt);
  initialize_with_free_wave_sum(yarr3, MAX_TSAMPLE, MAX_XSAMPLE, k1, k2, dx, omega1, omega2, dt);

  propagate( yarr1, MAX_TSAMPLE, MAX_XSAMPLE, r);
  propagate( yarr2, MAX_TSAMPLE, MAX_XSAMPLE, r);
  propagate( yarr3, MAX_TSAMPLE, MAX_XSAMPLE, r);



  char fname[256];
  for( int i=0; i<MAX_TSAMPLE; i++ ) { 
    sprintf( fname, "data/beat_t_%d.dat", i );
    FILE * f = fopen(fname, "w");
    for( int j=0; j<MAX_XSAMPLE-1; j++ ) {
      fprintf( f, "t: %lf\tx: %lf\ty1: %lf\ty2: %lf\tsum: %lf\n",i*dt,j*dx,
	       yarr1[i][j],yarr2[i][j],
	       yarr1[i][j]+yarr2[i][j]);

    }
    fclose(f);
  }

  sprintf(fname, "./data/timeseries_at_x_0.05_k1_%.1lf_k2_%.1lf.dat", kmult1, kmult2);
  FILE * fts = fopen(fname, "w");
  for( int i=0; i<MAX_TSAMPLE; i++ ) {
    fprintf( fts, "t: %f\tx: %f\ty1: %f\ty2: %f\tsum: %f\n",i*dt,5*dx,
	     yarr1[i][5],yarr2[i][5],
	     yarr1[i][5]+yarr2[i][5]);
  }
  fclose(fts);

  for( int i=0; i<MAX_TSAMPLE; i++ ) { 
    sprintf( fname, "data/beat_sum_t_%d.dat", i );
    FILE * f = fopen(fname, "w");
    for( int j=0; j<MAX_XSAMPLE-1; j++ ) {
      fprintf( f, "t: %lf\tx: %lf\ty: %lf\n",i*dt,j*dx,
	       yarr3[i][j]);

    }
    fclose(f);
  }

  sprintf(fname, "./data/timeseries_sum_at_x_0.05_k1_%.1lf_k2_%.1lf.dat", kmult1, kmult2);
  FILE * fts_sum = fopen(fname, "w");
  for( int i=0; i<MAX_TSAMPLE; i++ ) {
    fprintf( fts_sum, "t: %f\tx: %f\ty: %f\n",i*dt,5*dx,
	     yarr3[i][5]);
  }
  fclose(fts_sum);


  printf("f1: %lf\n", f1);
  printf("f2: %lf\n", f2);

}
