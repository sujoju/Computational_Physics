#ifndef WAVE
#define WAVE


extern const double c;
extern const double dx;
extern const double dt;
extern const double r;

// these are defined in the library as : 
/*
const double c  = 300;
const double dx = 0.01;
const double dt = 0.0000333333333;
const double r  = c*dt/dx;
*/

void propagate(double ** yarr, int tlen, int xlen, double r  );
void initialize_with_wave(double ** yarr, int tlen, int xlen, double k, 
    double dx );
void initialize_with_gauss(double ** yarr, int tlen, int xlen, double k, 
    double mu, double dx );
void initialize_with_free_wave( double ** yarr, int tlen, int xlen, 
    double k, double dx, double omega, double dt );
void initialize_with_free_wave_sum( double ** yarr, int tlen, int xlen, 
    double k1, double k2, double dx, double omega1, double omega2, double dt );

#endif
