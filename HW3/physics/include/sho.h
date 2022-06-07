#include "TwoComponent.h"

double ftheta(TwoComponent* x, double dt, double* parameters);
double fomega(TwoComponent* x, double dt, double* parameters);
double f_damped_driven(TwoComponent* x, double dt, double* parameters);
double total_energy(TwoComponent* x, double * parameters);
