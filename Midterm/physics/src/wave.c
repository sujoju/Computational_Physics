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

void initialize_with_free_wave( double ** yarr, int tlen, int xlen, 
    double k, double dx, double omega, double dt ) {
    int t = 0;
    
    for ( t = 0; t < tlen; t++ ) {
        double tval = t*dt;
        double x_left = 0.0;
        double x_right = ( xlen - 1 )*dx;
        yarr[t][0] = sin( k*x_left - omega*tval );
        yarr[t][xlen-1] = sin( k*x_right - omega*tval );
    }
}

void initialize_with_free_wave_sum( double ** yarr, int tlen, int xlen, 
    double k1, double k2, double dx, double omega1, double omega2, double dt ) {
    int t = 0;
    
    for ( t = 0; t < tlen; t++ ) {
        double tval = t*dt;
        double x_left = 0.0;
        double x_right = ( xlen - 1 )*dx;
        yarr[t][0] = sin( k1*x_left - omega1*tval ) + sin( k2*x_left - omega2*tval );
        yarr[t][xlen-1] = sin( k1*x_right - omega1*tval ) + sin( k2*x_right - omega2*tval );
    }
}