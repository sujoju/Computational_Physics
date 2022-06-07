#ifndef NEURAL_FLIP
#define NEURAL_FLIP


#include "IsingSpin.h"
#include "IsingLattice2D.h"
#include "Jmatrix.h"
#include <math.h>


// Energy Function 
double energyFunction( IsingSpin * obj, IsingLattice2D * lattice);
// double energyFunctionPerceptron( IsingSpin * obj, IsingLattice2D * lattice);

// flipfunction 
void neuralFlip( IsingSpin * obj, IsingLattice2D * lattice);
// void neuralFlipPerceptron( IsingSpin * obj, IsingLattice2D *lattice);

//get the total energy of the lattice
double getTotalEnergy(IsingLattice2D * lattice);
// double getTotalEnergyPerceptron(IsingLattice2D * lattice1, IsingLattice2D * lattice2);

// special sweep function for perceptrons 
// void sweepNeuralPerceptron( IsingLattice2D* lattice1, IsingLattice2D* lattice2, void (*flipfunc)(IsingSpin*, IsingLattice2D*) );

#endif
