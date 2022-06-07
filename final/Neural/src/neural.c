#include "IsingSpin.h"
#include "IsingLattice2D.h"
#include "Jmatrix.h"
#include <math.h>


// Energy Function 
double energyFunction( IsingSpin * obj, IsingLattice2D * lattice)
{
    double E = 0.0;
    int i = 0, j = 0;
    int xsize = lattice->xsize;
    int ysize = lattice->ysize;
    double spin = obj->spin;
    double * JmatrixRow = lattice->Jmatrix[obj->ID];

    for ( i = 0; i < xsize; i++ )
    {
        for ( j = 0; j < ysize; j++ )
        {
            int interactionID = ((lattice->spinarray)[i][j]).ID;
            double interactionSpin = ((lattice->spinarray)[i][j]).spin;
            E += -1*JmatrixRow[interactionID]*(spin*interactionSpin);
        }
    }

    return E;   
}


// flipfunction
void neuralFlip( IsingSpin * obj, IsingLattice2D * lattice)
{
    double T = lattice->T;
    double Eflip = -2*energyFunction( obj, lattice );
    if ( Eflip < 0.0 )
    {
        flipSpin(obj);
    } else if ( T != 0.0 ) {
        double fB = exp( -Eflip/T );
        double rval = (double)rand()/RAND_MAX;
        if ( rval <= fB ) 
        {
            flipSpin(obj);
        } 
    }
}


//get the total energy of the lattice
double getTotalEnergy(IsingLattice2D * lattice)
{
    IsingSpin *ptr = *(lattice->spinarray);
    IsingSpin *start_ptr = *(lattice->spinarray);

    double E = 0.0;

    while ( ptr->next != start_ptr )
    {
        E += energyFunction( ptr, lattice );
        ptr = ptr->next;
    }
    E += energyFunction( ptr, lattice ); 

    return E/2;
}