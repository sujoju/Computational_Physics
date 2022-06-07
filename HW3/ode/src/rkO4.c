#include <stdio.h>
#include "TwoComponent.h"
#include "FourComponent.h"

/* for a single dependent variable */
void 
rkO4_step(double* x, double* t, double f, double dt) {
    *(x+1) = *x + f*dt;
    *(t+1) = *t + dt;
}

void 
rkO4_solver_fp(double* x, double* t, 
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

        double x_3 = x_1 + (1.0/2.0)*f_2*dt;
        double t_3 = t_1 + (1.0/2.0)*dt;
        double f_3 = (*dxdt)(x_3, t_3, dxdt_parameters);

        double x_4 = x_1 + f_3*dt;
        double t_4 = t_1 + dt;
        double f_4 = (*dxdt)(x_4, t_4, dxdt_parameters);

        double f_weighted = (1.0/6.0)*(f_1 + 2*f_2 + 2*f_3 + f_4);
        rkO4_step(x+i, t+i, f_weighted, dt );
    }
}

/* for two dependent variables */
void 
rkO4_step_2component(TwoComponent* x, double* t, double fA, double fB, 
    double dt) {
    (x+1)->A = x->A + fA*dt;  
    (x+1)->B = x->B + fB*dt;  
    *(t+1) = *t + dt;
}

void 
rkO4_solver_2component_fp(TwoComponent* x, double* t, 
    double (*dxAdt)(TwoComponent*, double, double*), 
    double (*dxBdt)(TwoComponent*, double, double*), 
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

        double xA_3 = x_1->A + (1.0/2.0)*fA_2*dt;
        double xB_3 = x_1->B + (1.0/2.0)*fB_2*dt;
        TwoComponent x_3 = { .A = xA_3, .B = xB_3 };
        double t_3 = t_1 + (1.0/2.0)*dt;
        double fA_3 = (*dxAdt)(&x_3, t_3, dxdt_parameters);
        double fB_3 = (*dxBdt)(&x_3, t_3, dxdt_parameters);

        double xA_4 = x_1->A + fA_3*dt;
        double xB_4 = x_1->B + fB_3*dt;
        TwoComponent x_4 = { .A = xA_4, .B = xB_4 };
        double t_4 = t_1 + dt;
        double fA_4 = (*dxAdt)(&x_4, t_4, dxdt_parameters);
        double fB_4 = (*dxBdt)(&x_4, t_4, dxdt_parameters);

        double fA_weighted = (1.0/6.0)*(fA_1 + 2*fA_2 + 2*fA_3 + fA_4);
        double fB_weighted = (1.0/6.0)*(fB_1 + 2*fB_2 + 2*fB_3 + fB_4);
        rkO4_step_2component(x+i, t+i, fA_weighted, fB_weighted, dt);
    }
}

/* four dependent variables */
void 
rkO4_step_4component(FourComponent* x, double* t, 
    double fA, double fB, double fC, double fD,  
    double dt) {
    (x+1)->A = x->A  + fA*dt;  
    (x+1)->B = x->B  + fB*dt;  
    (x+1)->C = x->C  + fC*dt;  
    (x+1)->D = x->D  + fD*dt;  
    *(t+1) = *t + dt;
}

void 
rkO4_solver_4component_fp(FourComponent* x, double* t, 
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

        double xA_3 = x_1->A + (1.0/2.0)*fA_2*dt;
        double xB_3 = x_1->B + (1.0/2.0)*fB_2*dt;
        double xC_3 = x_1->C + (1.0/2.0)*fC_2*dt;
        double xD_3 = x_1->D + (1.0/2.0)*fD_2*dt;
        FourComponent x_3 = { .A = xA_3, .B = xB_3, .C = xC_3, .D = xD_3 };
        double t_3 = t_1 + (1.0/2.0)*dt;
        double fA_3 = (*dxAdt)(&x_3,t_3,dxdt_parameters);
        double fB_3 = (*dxBdt)(&x_3,t_3,dxdt_parameters);
        double fC_3 = (*dxCdt)(&x_3,t_3,dxdt_parameters);
        double fD_3 = (*dxDdt)(&x_3,t_3,dxdt_parameters);

        double xA_4 = x_1->A + fA_3*dt;
        double xB_4 = x_1->B + fB_3*dt;
        double xC_4 = x_1->C + fC_3*dt;
        double xD_4 = x_1->D + fD_3*dt;
        FourComponent x_4 = { .A = xA_4, .B = xB_4, .C = xC_4, .D = xD_4 };
        double t_4 = t_1 + dt;
        double fA_4 = (*dxAdt)(&x_4,t_4,dxdt_parameters);
        double fB_4 = (*dxBdt)(&x_4,t_4,dxdt_parameters);
        double fC_4 = (*dxCdt)(&x_4,t_4,dxdt_parameters);
        double fD_4 = (*dxDdt)(&x_4,t_4,dxdt_parameters);

        double fA_weighted = (1.0/6.0)*(fA_1 + 2*fA_2 + 2*fA_3 + fA_4);
        double fB_weighted = (1.0/6.0)*(fB_1 + 2*fB_2 + 2*fB_3 + fB_4);
        double fC_weighted = (1.0/6.0)*(fC_1 + 2*fC_2 + 2*fC_3 + fC_4);
        double fD_weighted = (1.0/6.0)*(fD_1 + 2*fD_2 + 2*fD_3 + fD_4);
        rkO4_step_4component(x+i, t+i, 
            fA_weighted, fB_weighted, fC_weighted, fD_weighted, dt);
    }
}
