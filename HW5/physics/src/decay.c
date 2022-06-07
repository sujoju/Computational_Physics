#include <stdio.h>
#include <math.h>
#include "TwoComponent.h"

double 
f(double N, double dt, double* parameters ) {
    double fval = -N/parameters[0];
    return fval;
}

double
Analytical(double Ni, double t, double* parameters ) {
    double fval = Ni*exp(-t/parameters[0]);
    return fval;
}

double 
fA(TwoComponent* n, double dt, double* parameters ) {
    double fval = -(n->A/parameters[0]) + (n->B/parameters[1]);
    return fval;
}

double 
fB(TwoComponent* n, double dt, double* parameters ) {
    double fval = -(n->B/parameters[1]) + (n->A/parameters[0]);
    return fval;
}

double 
AnalyticalA( double Ni, double t, double* parameters ) {
    double tauA = parameters[0];
    double fval = (Ni/2)*(exp(-2*t/tauA) + 1);
    return fval;
}

double 
AnalyticalB( double Ni, double t, double* parameters ) {
    double tauB = parameters[1];
    double fval = (Ni/2)*(1 - exp(-2*t/tauB));
    return fval;
}