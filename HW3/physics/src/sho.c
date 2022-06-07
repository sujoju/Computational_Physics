#include <math.h>
#include "TwoComponent.h"

double ftheta(TwoComponent* x, double dt, double* parameters  ) {
    double fval = x->B;
    return fval;
}

double fomega(TwoComponent* x, double dt, double* parameters  ) {
    double fval = -(parameters[0]/parameters[1])*x->A;
    return fval;
}

double f_damped_driven(TwoComponent* x, double dt, double* parameters) {
    double g = parameters[0];
    double q = parameters[2];
    double Omega_D = parameters[3];
    double F_D = parameters[4];
    double theta = x->A;
    double omega = x->B;
    double t = dt;
    double fval = -g*sin(theta) - q*omega + F_D*sin(Omega_D*t);
    return fval;
}

double total_energy(TwoComponent* x, double * parameters ) { 
    double dy = parameters[1]*(1-cos(x->A)); /* assuming m=1kg */
    double V = parameters[0]*dy;

    double I = parameters[1]*parameters[1]; /* assuming m=1kg */
    double T = I*x->B*x->B/2;
    
    return T+V;
}