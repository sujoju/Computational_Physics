#include <stdio.h>
#include "TwoComponent.h"
#include "FourComponent.h"

/* for a single dependent variable */
void 
rkO2_step(double* x, double* t, double f, double dt) {
    *(x+1) = *x + f*dt;
    *(t+1) = *t + dt;
}

void 
rkO2_solver_fp(double* x, double* t, 
    double (*dxdt)(double, double, double*), 
    double* dxdt_parameters, double dt, int steps) {
    int i = 0;

    for ( i = 0; i < steps - 1; i++ ) {
        double x_1 = *(x+i);
        double t_1 = *(t+i);
        double f_1 = (*dxdt)(x_1, t_1, dxdt_parameters);

        double x_2 = x_1 + (1.0/2.0)*f_1*dt;
        double t_2 = t_1 + (1.0/2.0)*dt;
        double f_2 = (*dxdt)(x_2, t_2, dxdt_parameters);

        rkO2_step(x+i, t+i, f_2, dt );
    }
}

/* for two dependent variables */
void 
rkO2_step_2component(TwoComponent* x, double* t, double fA, double fB, 
    double dt) {
    (x+1)->A = x->A + fA*dt;  
    (x+1)->B = x->B + fB*dt;  
    *(t+1) = *t + dt;
}

void 
rkO2_solver_2component_fp(TwoComponent* x, double* t, 
    double (*dxAdt)(TwoComponent*,double,double*), 
    double (*dxBdt)(TwoComponent*,double,double*), 
    double* dxdt_parameters, 
    double dt, int steps) {
    int i = 0;

    for( i = 0; i < steps - 1; i++ ) { 
        TwoComponent * x_1 = (x+i);
        double t_1 = *(t+i);
        double fA_1 = (*dxAdt)(x_1, t_1, dxdt_parameters);
        double fB_1 = (*dxBdt)(x_1, t_1, dxdt_parameters);

        double xA_2 = x_1->A + (1.0/2.0)*fA_1*dt;
        double xB_2 = x_1->B + (1.0/2.0)*fB_1*dt;
        TwoComponent x_2 = { .A = xA_2, .B = xB_2 };
        double t_2 = t_1 + (1.0/2.0)*dt;
        double fA_2 = (*dxAdt)(&x_2, t_2, dxdt_parameters);
        double fB_2 = (*dxBdt)(&x_2, t_2, dxdt_parameters);

        rkO2_step_2component(x+i, t+i, fA_2, fB_2, dt);
    }
}

/* four dependent variables */
void 
rkO2_step_4component(FourComponent* x, double* t, 
    double fA, double fB, double fC, double fD,  
    double dt) {
    (x+1)->A = x->A  + fA*dt;  
    (x+1)->B = x->B  + fB*dt;  
    (x+1)->C = x->C  + fC*dt;  
    (x+1)->D = x->D  + fD*dt;  
    *(t+1) = *t + dt;
}

void 
rkO2_solver_4component_fp(FourComponent* x, double* t, 
    double (*dxAdt)(FourComponent*,double,double*),
    double (*dxBdt)(FourComponent*,double,double*),
    double (*dxCdt)(FourComponent*,double,double*),
    double (*dxDdt)(FourComponent*,double,double*),
    double* dxdt_parameters, double dt, int steps) {
    int i = 0;

    for( i = 0; i < steps - 1; i++ ) { 
        FourComponent * x_1 = (x+i);
        double t_1 = *(t+i);
        double fA_1 = (*dxAdt)(x_1, t_1, dxdt_parameters);
        double fB_1 = (*dxBdt)(x_1, t_1, dxdt_parameters);
        double fC_1 = (*dxCdt)(x_1, t_1, dxdt_parameters);
        double fD_1 = (*dxDdt)(x_1, t_1, dxdt_parameters);

        double xA_2 = x_1->A + (1.0/2.0)*fA_1*dt;
        double xB_2 = x_1->B + (1.0/2.0)*fB_1*dt;
        double xC_2 = x_1->C + (1.0/2.0)*fC_1*dt;
        double xD_2 = x_1->D + (1.0/2.0)*fD_1*dt;
        FourComponent x_2 = { .A = xA_2, .B = xB_2, .C = xC_2, .D = xD_2 };
        double t_2 = t_1 + (1.0/2.0)*dt;
        double fA_2 = (*dxAdt)(&x_2,t_2,dxdt_parameters);
        double fB_2 = (*dxBdt)(&x_2,t_2,dxdt_parameters);
        double fC_2 = (*dxCdt)(&x_2,t_2,dxdt_parameters);
        double fD_2 = (*dxDdt)(&x_2,t_2,dxdt_parameters);

        rkO2_step_4component(x+i, t+i, fA_2, fB_2, fC_2, fD_2, dt);
    }
}
