#include "TwoComponent.h"

double f(double N, double dt, double* parameters  );
double Analytical(double Ni, double t, double* parameters );
double fA(TwoComponent* n, double dt, double* parameters );
double fB(TwoComponent* n, double dt, double* parameters );
double AnalyticalA( double Ni, double t, double* parameters );
double AnalyticalB( double Ni, double t, double* parameters );
