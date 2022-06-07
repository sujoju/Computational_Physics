#include <math.h>

const double c  = 300;
const double dx = 0.01;
const double dt = 0.0000333333333;
const double r  = 1.0;
// Supposed to be r = c*dt/dx, but was getting compiler error that 
// "initializer element is not constant"

void propagate(double ** yarr, int tlen, int xlen, double r ) {
    int t = 1;
    int x = 1;

    // Note that we have t == 0 and t == 1 to be the initialized wave; this 
    // will guarantee that we have enough initial conditions to propagate
    // the wave.
    for ( t = 1; t < tlen - 1; t++ ) {
        for ( x = 1; x < xlen - 1; x++ ) {
            yarr[t+1][x] = 2*(1-pow(r, 2.0))*yarr[t][x] - yarr[t-1][x] 
            + pow(r, 2.0)*(yarr[t][x+1] + yarr[t][x-1]);
        }
    }
}

void initialize_with_wave(double ** yarr, int tlen, int xlen, double k, 
    double dx ) {
    int t = 0;
    int x = 1;
    
    for ( t = 0; t < tlen; t++ ) {
        yarr[t][0] = 0;
        yarr[t][xlen-1] = 0;

        if ( t == 0 || t == 1 ) {
            for ( x = 1; x < xlen - 1; x++ ) {
                double xval = x*dx;
                yarr[t][x] = sin(k*xval);
            }
        }
    }
}

void initialize_with_gauss(double ** yarr, int tlen, int xlen, double k, 
    double mu, double dx ) {
    int t = 0;
    int x = 1;
    
    for ( t = 0; t < tlen; t++ ) {
        yarr[t][0] = 0;
        yarr[t][xlen-1] = 0;

        if ( t == 0 || t == 1 ) {
            for ( x = 1; x < xlen - 1; x++ ) {
                double xval = x*dx;
                yarr[t][x] = exp(-k*pow(xval-mu, 2.0));
            }
        }
    }
}