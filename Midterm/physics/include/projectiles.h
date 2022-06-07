#include "TwoComponent.h"
#include "FourComponent.h"

double fx_drag(FourComponent* x, double dt, double* parameters); 
double fy_drag(FourComponent* x, double dt, double* parameters); 
double fvx_drag(FourComponent* x, double dt, double* parameters);
double fvy_drag(FourComponent* x, double dt, double* parameters);

double fvx_drag_adiabatic(FourComponent* x, double dt, double* parameters);
double fvy_drag_adiabatic(FourComponent* x, double dt, double* parameters);
