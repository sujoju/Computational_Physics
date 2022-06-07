/*Jun Sung*/

#include <stdio.h>
#include <stdlib.h>
#include "IsingLattice2D.h"
#include "magnetism.h"

int main(int argc, char** argv) 
{

    if( argc < 7 ) {
        printf("usage: assignment6_5.exe <seed> <T> <H> <sweeps> <size> <path>\n");
        return -1;
    }

    unsigned seed =strtoul(argv[1],NULL,10); 
    double T = strtod(argv[2],NULL);
    double H = strtod(argv[3],NULL);
    unsigned nsweeps = strtoul(argv[4],NULL,10);
    unsigned size    = strtoul(argv[5],NULL,10);
    char * path = argv[6];

    srand(seed);
    fprintf(stderr, "making lattice ...\n");
    IsingLattice2D* lattice = create2DIsingLattice( size, size, T, H );
    fprintf(stderr, "lattice made...\n");  
    int i;

    // warm up
    for( i=0; i<1000; i++ ) { 
        fprintf(stderr, "warm up %d\n", i);
        sweep( lattice, boltzmannFlip );
    }

    double M=0;
    for( i=0; i<nsweeps; i++ ) { 
        sweep( lattice, boltzmannFlip );
        dumpLatticeToFile(lattice, path, i);
        printf("i: %d\tM: %f\n", i, getMagnetization(lattice));
    }
}
