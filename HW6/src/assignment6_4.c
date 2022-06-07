/*Jun Sung*/

#include <stdio.h>
#include <stdlib.h>
#include "IsingLattice2D.h"
#include "magnetism.h"

int main(int argc, char** argv) 
{
    if( argc < 6 ) {
        printf("usage: assignment6_4.exe <seed> <T> <H> <sweeps> <size>\n");
        return -1;
    }

    unsigned seed =strtoul(argv[1],NULL,10); 
    double T = strtod(argv[2],NULL);
    double H = strtod(argv[3],NULL);
    unsigned nsweeps = strtoul(argv[4],NULL,10);
    unsigned size    = strtoul(argv[5],NULL,10);

    srand(seed);

    IsingLattice2D* lattice = create2DIsingLattice( size, size, T, H );
    
    int i;

    // warm up
    for( i=0; i<1000; i++ ) { 
        sweep( lattice, boltzmannFlip );
    }


    double M=0;
    CorrelationInfo info;
    info.spinsums = (double*)(calloc(size, sizeof(double)));
    info.spinprodsums = (double*)(calloc(size, sizeof(double)));

    for( i=0; i<nsweeps; i++ ) { 
        sweep( lattice, boltzmannFlip );
        getCorrelationInfo(lattice, &info);
    }
    
    for( int i=1; i<size; i++ ) {
        double f_minus_avgS2 = (info.spinprodsums[i])/info.tests
        - (info.spinsums[0]/info.tests)*(info.spinsums[0]/info.tests);
        printf( "%d\t %f\n", i, f_minus_avgS2);
    }
}
