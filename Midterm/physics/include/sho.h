#include "TwoComponent.h"

double ftheta( TwoComponent* x, double dt, double* parameters );

/* for the SHO (linear/non) */
double fomega( TwoComponent* x, double dt, double* parameters );
double fomega_NL( TwoComponent* x, double dt, double* parameters );

/* partial terms for damping and driving  */ 
double fdamp( TwoComponent* x, double dt, double* parameters );
double fdrive( TwoComponent* x, double dt, double* parameters );

/* full terms for damped and damped/driven HO */
double f_damped( TwoComponent* x, double dt, double* parameters );
double f_damped_driven( TwoComponent* x, double dt, double* parameters );
double f_damped_driven_NL( TwoComponent* x, double dt, double* parameters );

double total_energy( TwoComponent* x, double * parameters );
