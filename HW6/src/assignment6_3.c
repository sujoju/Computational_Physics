/*Jun Sung*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "IsingLattice2D.h"
#include "magnetism.h"

#define NSWEEPS 20000

int main(int argc, char** argv) 
{
    unsigned seed=strtoul(argv[1],NULL,10); 
    double T = strtod(argv[2],NULL);
    double H = strtod(argv[3],NULL);
    int size = strtoul(argv[4],NULL,10);

    srand(seed);

    IsingLattice2D* lattice = create2DIsingLattice( size, size, T, H );
    double xsize = lattice->xsize;
    double ysize = lattice->ysize;

    // warm up
    int i;
    for( i=0; i<1000; i++ ) { 
        sweep( lattice, boltzmannFlip );
    }

    double Etot=0, ESquared=0;
    for( i=0; i<NSWEEPS; i++ ) { 
        sweep( lattice, boltzmannFlip );
        Etot  += getEnergy(lattice);
        ESquared += getEnergySquared(lattice);
    }
    double E_avg = Etot/NSWEEPS;
    double ESquared_avg = ESquared/NSWEEPS;
    double Delta_E = ESquared_avg - (E_avg*E_avg);

    printf("E2: %f\tE*E: %lf\n", ESquared_avg, E_avg*E_avg);
    double s2 = Delta_E; 
    double CperSpin  = s2/(T*T*xsize*ysize);

    printf( "T: %lf\tC: %lf\n", T, CperSpin );
}
