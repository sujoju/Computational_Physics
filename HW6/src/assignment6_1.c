/*Jun Sung*/

#include <stdio.h>
#include <stdlib.h>
#include "IsingLattice2D.h"
#include "magnetism.h"

#define NSWEEPS 2000

int main(int argc, char** argv) 
{
    unsigned seed = strtoul(argv[1],NULL,10); 
    srand(seed);
    double T = strtod(argv[2],NULL);
    double H = strtod(argv[3],NULL);

    IsingLattice2D* lattice = create2DIsingLattice( 100, 100, T, H );
    
    // warm up if not wanting timeseries data ...
    for( int i=0; i<1000; i++ ) { 
        sweep( lattice, boltzmannFlip );
    }

    double M=0;
    for( int i=0; i<NSWEEPS; i++ ) { 
        sweep( lattice, boltzmannFlip );
        M += getMagnetization(lattice)/NSWEEPS;
    }

    printf( "T: %lf\tM: %lf\n", T, M );
}
