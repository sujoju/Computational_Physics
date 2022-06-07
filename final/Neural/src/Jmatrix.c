
#include "Jmatrix.h"
#include "pattern.h"

// ------------------------------------------------------
// ------------------------------------------------------
Jmatrix * 
createJ(int N, pattern * inputs, int M) 
// ------------------------------------------------------
{
    int i; //first counter
    int j; //second counter
    int k; //pattern counter

    //Allocate memory for (N^2)x(N^2) J
    double ** J;
    Jmatrix * Jmat;
    Jmat = (Jmatrix *)malloc(sizeof(Jmatrix));
    J = (double **)calloc(N*N, sizeof(double *));
    for (i = 0; i < N*N; i++) {
      J[i] = (double *)calloc(N*N, sizeof(double));
    }
    Jmat->J = J;
    Jmat->latsize = N;

    //Initialize each J value to 0
    for(i = 0; i < N*N; i++) {
        for (j = 0; j < N*N; j++) {
            J[i][j] = 0;
        }
    }

    //Create J value for each combination of spins for each input pattern  
    for (k = 0; k < M; k++) {
        for (i = 0; i < N*N; i++) {
            for (j = 0; j < N*N; j++) {
                int row1 = i/N;
                int col1 = i%N;
                int row2 = j/N;
                int col2 = j%N;
                double si = (inputs[k].pattern_memory)[row1][col1];
                double sj = (inputs[k].pattern_memory)[row2][col2];
                J[i][j] += si*sj;
            }
        }
    }

    //Divide by number of input patterns
    for (i = 0; i < N*N; i++) {
        for (j = 0; j < N*N; j++) {
            J[i][j] /= M;
        }
    }

    return Jmat;
}


// ------------------------------------------------------
// ------------------------------------------------------
Jmatrix * 
createJperceptron( pattern * inputs, pattern * outputs, int M, int N, int P) 
// ------------------------------------------------------
{
    int i;
    int j;
    int k;
    int l;

    Jmatrix * Jmat;
    double ** J;
      
    Jmat = (Jmatrix *)malloc(sizeof(Jmatrix));
    J = (double **)calloc(N*N, sizeof(double *));
    for (i = 0; i < N*N; i++) {
      J[i] = (double *)calloc(N*N, sizeof(double));
    }
    Jmat->J = J;
    Jmat->latsize = N;

    //Initialize each J value to 0
    for(i = 0; i < N*N; i++) {
      for (j = 0; j < N*N; j++) {
        J[i][j] = 0;
      }
    }
    fprintf(stderr, "initialized J ... \n");

    for (l = 0; l < P; l++) {
        for (k = l; k < M; k+=2 ) {
            fprintf(stderr, "l: %d, k: %d\n", l, k);

            for (i = 0; i < N*N; i++) {
                for (j = 0; j < N*N; j++) {
                  int row1 = i/N;
                  int col1 = i%N;
                  int row2 = j/N;
                  int col2 = j%N;

                  J[i][j] += (inputs[k].pattern_memory)[row1][col1]*(outputs[l].pattern_memory)[row2][col2];
                }
            }
        }
    }


    for (i = 0; i < N*N; i++) {
        for (j = 0; j < N*N; j++) {
          J[i][j] /= M*P;
        }
    }

    return Jmat;
}

// ------------------------------------------------------
// Learn new patterns
// Note: remember to dealloc Jold if no longer going to be used
// ------------------------------------------------------
Jmatrix * 
learnJ(Jmatrix * Jold, double alpha, double beta, pattern * inputs, int M) 
// ------------------------------------------------------
{
    int i;
    int j;

    int N = Jold->latsize;
    Jmatrix * Jnew = createJ(N, inputs, M);

    for (i = 0; i < N*N; i++) {
        for (j = 0; j < N*N; j++) {
            (Jnew->J)[i][j] = beta*(Jold->J)[i][j] + alpha*(Jnew->J)[i][j];
        }
    }
    return Jnew;
}


// -------------------------------------------------------
// -------------------------------------------------------
void 
IsingFromPattern( IsingLattice2D * lattice, pattern * input, Jmatrix * Jmat) 
// -------------------------------------------------------
{
    int N = input->latsize;
    int i;
    int j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            ((lattice->spinarray)[i][j]).spin = (float)((input->pattern_memory)[i][j]);
        }
    }
    lattice->Jmatrix = Jmat->J;
}


// -------------------------------------------------------
// -------------------------------------------------------
pattern * 
PatternFromIsing( IsingLattice2D * lattice) 
// -------------------------------------------------------
{
    int N = lattice->xsize;
    int i;
    int j;
    pattern * input = (pattern *)malloc(sizeof(pattern));
    input->pattern_memory = (double **)calloc(N, sizeof(double *));
    for (i = 0; i < N; i++) {
        (input->pattern_memory)[i] = (double *)calloc(N, sizeof(double));
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            ((input->pattern_memory)[i][j]) = (double)((lattice->spinarray)[i][j]).spin;
        }
    }
    input->latsize = N;

    return input;
}


