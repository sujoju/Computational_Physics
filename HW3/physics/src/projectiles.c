#include <math.h>
#include "TwoComponent.h"
#include "FourComponent.h"

double fx_drag(FourComponent* x, double dt, double* parameters  ) {
    double vx = x->B;
    return vx;
}

double fy_drag(FourComponent* x, double dt, double* parameters) {
    double vy = x->D;
    return vy;
}

double fvx_drag(FourComponent* x, double dt, double* parameters) {
    double B2m = parameters[1];
    double vx = x->B;
    double vy = x->D;
    double v = sqrt(pow(vx, 2.0) + pow(vy, 2.0));
    double fval = - B2m*v*vx;
    return fval;
}

double fvy_drag(FourComponent* x, double dt, double* parameters) {
    double g = parameters[0];
    double B2m = parameters[1];
    double vx = x->B;
    double vy = x->D;
    double v = sqrt(pow(vx, 2.0) + pow(vy, 2.0));
    double fval = - g - B2m*v*vy;
    return fval;
}

double fvx_drag_adiabatic(FourComponent* x, double dt, double* parameters) {
    double B2m = parameters[1];
    double a = parameters[2];
    double T0 = parameters[3];
    double alpha = parameters[4];
    double y = x->C;
    double vx = x->B;
    double vy = x->D;
    double v = sqrt(pow(vx, 2.0) + pow(vy, 2.0));
    double fval = - pow(1-a*y/T0, alpha)*B2m*v*vx;
    return fval;
}

double fvy_drag_adiabatic(FourComponent* x, double dt, double* parameters) {
    double g = parameters[0];
    double B2m = parameters[1];
    double a = parameters[2];
    double T0 = parameters[3];
    double alpha = parameters[4];
    double y = x->C;
    double vx = x->B;
    double vy = x->D;
    double v = sqrt(pow(vx, 2.0) + pow(vy, 2.0));
    double fval = - g - pow(1-a*y/T0, alpha)*B2m*v*vy;
    return fval;
}