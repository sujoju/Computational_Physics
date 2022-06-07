#ifndef ISING_LATTICE_2D
#define ISING_LATTICE_2D

#include <stdlib.h>
#include "IsingSpin.h"

typedef struct { 
  IsingSpin** spinarray;
  double T, H;
  int xsize, ysize;
  IsingSpin *external_l, *external_r;
  IsingSpin *external_u, *external_d;
  double ** Jmatrix;
} IsingLattice2D;


typedef struct corrStruct CorrelationInfo ; 

struct corrStruct { 
  unsigned long tests;
  double * spinsums;
  double * spinprodsums;
}; 


/* create the array with calloc/malloc */
IsingLattice2D * create2DIsingLattice( int xsize, int ysize, double T, double H );
//IsingLattice2D * create2DIsingLatticeForMPI( int xsize, int ysize, double T, double H );

/* the initializeX functions are called during creation */
void initialize2DSpins( IsingLattice2D* lattice);
void initialize2DSpinsRandom( IsingLattice2D* lattice, unsigned seed);
void initialize2DLinks( IsingLattice2D*  lattice);
//void initialize2DSpinsForMPI( IsingLattice2D* lattice);
//void initialize2DLinksForMPI( IsingLattice2D*  lattice);

/* loop over the spins, calling the function pointer 
   flipfunction to determine whether to flip 
*/
void sweep( IsingLattice2D*  lattice, void (*flipfunc)(IsingSpin*, IsingLattice2D* lptr));
//void sweepNeural( IsingLattice2D*  lattice, void (*flipfunc)(IsingSpin*, IsingLattice2D*));
//void sweepNeuralPerceptron( IsingLattice2D*  lattice1, IsingLattice2D*  lattice2, void (*flipfunc)(IsingSpin*, IsingLattice2D*));

/* simple utility to spin flip */
void flipSpin(IsingSpin* obj);

/* dump coordinates and spin values for all lattice sites */
void dumpLattice( IsingLattice2D* lattice );
void dumpLatticeToFile( IsingLattice2D* lattice, char* path, int sweep );
#endif
