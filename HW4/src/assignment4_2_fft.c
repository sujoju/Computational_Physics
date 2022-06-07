#include <stdio.h>
#include <fftw3.h>
#include <math.h>
#include "wave.h"

#define FFT_FORWARD 1
#define FFT_ESTIMATE 1


int main() { 

  double *in;
  fftw_complex *out;
  fftw_plan p;
  
  int N = 1000;
  
  in = (double*) fftw_malloc(sizeof(double) * N);
  out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
  p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);
  
  
  
  /* read in the dat file  */
  FILE * f = fopen("./data/timeseries_pulse_at_x_0.05.dat", "r");
  int i=0;
  double tmpt, tmpx, tmpy;
  while( fscanf( f, "t: %lf\tx: %lf\ty: %lf\n", &tmpt, &tmpx, &tmpy ) > 0  ) { 
    in[i++] = tmpy;
  }
  
  fftw_execute(p); 
  
  for(i=0; i<N; i++ ) { 
    printf( "i: %d\tt: %f\tin: %f\tor: %f\toi: %f\n", i,
	    (i*dt),
	    in[i],out[i][0], out[i][1]);
  } 
  
  fftw_destroy_plan(p);
  fftw_free(in); fftw_free(out);

}
