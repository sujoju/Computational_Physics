#ifndef J_MATRIX
#define J_MATRIX

#include <stdlib.h>
#include <math.h>

#include "pattern.h"

typedef struct {
    double ** J;
    int latsize;
} Jmatrix;

Jmatrix * createJ(int N, pattern * inputs, int M);
Jmatrix * createJperceptron( pattern * inputs, pattern * outputs, int M, int N, int P);
Jmatrix * learnJ(Jmatrix * Jold, double alpha, double beta, pattern * inputs, int M);

void      IsingFromPattern( IsingLattice2D * lattice, pattern * input, Jmatrix * Jmat);
pattern * PatternFromIsing( IsingLattice2D * lattice);

#endif
