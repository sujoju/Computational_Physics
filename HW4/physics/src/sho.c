#include <math.h>
#include "TwoComponent.h"

double ftheta(TwoComponent* x, double dt, double* parameters  ) {
    double omega = x->B;
    double fval = omega;
    return fval;
}

double fomega(TwoComponent* x, double dt, double* parameters  ) {
    double theta = x->A;
    double g = parameters[0];
    double l = parameters[1];
    double fval = -(g/l)*theta;
    return fval;
}

double fomega_NL( TwoComponent* x, double dt, double* parameters ) {
    double theta = x->A;
    double g = parameters[0];
    double l = parameters[1];
    double fval = -(g/l)*sin(theta);
    return fval;
}

double fdamp( TwoComponent* x, double dt, double* parameters ) {
    double omega = x->B;
    double q = parameters[2];
    double fval = - q*omega;
    return fval;
}

double fdrive( TwoComponent* x, double dt, double* parameters ) {
    double t = dt;
    double Omega_D = parameters[3];
    double F_D = parameters[4];
    double fval = F_D*sin(Omega_D*t);
    return fval;
}

double f_damped( TwoComponent* x, double dt, double* parameters ) {
    double damp = fdamp(x, dt, parameters);
    double fval = fomega(x, dt, parameters) + damp;
    return fval;
}

double f_damped_driven(TwoComponent* x, double dt, double* parameters) {
    double damp = fdamp(x, dt, parameters);
    double drive = fdrive(x, dt, parameters);
    double fval = fomega(x, dt, parameters) + damp + drive;
    return fval;
}

double f_damped_driven_NL( TwoComponent* x, double dt, double* parameters ) {
    double damp = fdamp(x, dt, parameters);
    double drive = fdrive(x, dt, parameters);
    double fval = fomega_NL(x, dt, parameters) + damp + drive;
    return fval;
}

double total_energy(TwoComponent* x, double * parameters ) { 
    double dy = parameters[1]*(1-cos(x->A)); /* assuming m=1kg */
    double V = parameters[0]*dy;

    double I = parameters[1]*parameters[1]; /* assuming m=1kg */
    double T = I*x->B*x->B/2;
    
    return T+V;
}