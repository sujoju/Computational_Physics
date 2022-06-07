#include <stdio.h>
#include <math.h>
#include "IsingLattice2D.h"
#include "magnetism.h"

double 
energyFunction( IsingSpin * obj, IsingLattice2D* lptr ) 
{
    int i = 0;
    double E = 0;
    double H = lptr->H;
    double spin = obj->spin;
    double * JmatrixRow = lptr->Jmatrix[obj->ID];
    IsingSpin * neighbor[4] = { obj->right, obj->left, obj->above, obj->below };

    for ( i = 0; i < 4; i++ )
    {
        E += -1*JmatrixRow[neighbor[i]->ID]*( spin*neighbor[i]->spin );
    }

    E += -mu*H*spin;

    return E;   
}

void
boltzmannFlip(IsingSpin* obj, IsingLattice2D* lptr )
{
    double Eflip = -2.0*energyFunction( obj, lptr );
    if ( Eflip <= 0 )
    {
        flipSpin(obj);
    } else 
    {
        double T = lptr->T;
        double fB = exp( -Eflip/(kB*T) );
        double rval = (double)rand()/RAND_MAX;
        if ( rval <= fB ) 
        {
            flipSpin(obj);
        } 
    }
}

double 
getMagnetization( IsingLattice2D* lptr )
{
    IsingSpin *ptr = *(lptr->spinarray);
    IsingSpin *start_ptr = *(lptr->spinarray);
    
    double M = 0;
    int xsize = lptr->xsize;
    int ysize = lptr->ysize;

    while ( ptr->next != start_ptr )
    {
        M += ptr->spin;
        ptr = ptr->next;
    }
    M += ptr->spin; 

    double M_scaled = M/(xsize*ysize);
    return M_scaled;
}

double 
getEnergy( IsingLattice2D* lptr )
{
    IsingSpin *ptr = *(lptr->spinarray);
    IsingSpin *start_ptr = *(lptr->spinarray);

    double E = 0;
    int xsize = lptr->xsize;
    int ysize = lptr->ysize;

    while ( ptr->next != start_ptr )
    {
        E += energyFunction( ptr, lptr );
        ptr = ptr->next;
    }
    E += energyFunction( ptr, lptr ); 

    return E/2;
}

double 
getEnergySquared( IsingLattice2D* lptr )
{
    double Etot = getEnergy(lptr);
    double ESquared = pow(Etot, 2.0);

    return ESquared;
}

void 
getCorrelationInfo(IsingLattice2D* lptr, CorrelationInfo* info )
{
    int i = 0;
    IsingSpin *ptr = (*(lptr->spinarray))->right;
    IsingSpin *start_ptr = *(lptr->spinarray);
    int xsize = lptr->xsize;

    for ( i = 0; i < xsize - 1; i++ )
    {
        info->spinsums[i] += ptr->spin;
        info->spinprodsums[i] += start_ptr->spin * ptr->spin;
        ptr = ptr->right;
    }
    info->tests++;
}