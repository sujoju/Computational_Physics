//Functions for pattern handling

#include "pattern.h"

// -------------------------------------------------------
// M patterns, NxN lattice 
// -------------------------------------------------------
pattern * 
readPatterns(FILE ** fsin, int M, int N) 
// -------------------------------------------------------
{
    int i;
    int j;
    int k;

    //Alloc memory for inputs
    pattern * inputs;
    inputs = (pattern *)calloc(M, sizeof(pattern));  
    for (k = 0; k < M; k++) {
        inputs[k].latsize = N;
        inputs[k].pattern_memory = (double **)calloc(N, sizeof(double *));
        
        for (i = 0; i < N; i++) {
            (inputs[k].pattern_memory)[i] = (double *)calloc(N, sizeof(double));
        }

        for (i = 0; i < N; i++) {
          for (j = 0; j < N; j++) {
              char plusminus;
              fscanf(fsin[k], "%c ", &plusminus);

              if (plusminus == '+') {
                  (inputs[k].pattern_memory)[i][j] = 1;
            #ifdef DEBUG
                printf("+ ");
            #endif
              }
              else {
                  (inputs[k].pattern_memory)[i][j] = -1;
            #ifdef DEBUG
                printf("  ");
            #endif
              }
          }
      #ifdef DEBUG
          printf("\n");
      #endif
        }
    }
    return inputs;
}


// -------------------------------------------------------
// Output a single pattern given the address of the pattern
// -------------------------------------------------------
void 
writePattern(pattern * output, FILE* fout, int strip) 
// -------------------------------------------------------
{
    int N = output->latsize;
    int i;
    int j;
      
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            char plusminus;
            if (output->pattern_memory[i][j] == 1) {
                plusminus = '+';
            }
            else {
                if (strip) plusminus = ' '; 
                else plusminus = '-';
            }
            fprintf(fout, "%c", plusminus);
            if (j == N-1 && i != N-1) {
                /* 	fprintf(fout, "\n"); */
            }
            else {
                fprintf(fout, " ");
            }
        }
        fprintf(fout, "\n");
    }
}


// -------------------------------------------------------
// -------------------------------------------------------
double 
hammingDistance(pattern * input1, pattern * input2) 
// -------------------------------------------------------
{
    // using the definition of N used elsewhere in program and book
    // Note that Hamming Formula's N is this N squared.                                                                                                       
    int N = input1->latsize; 

    int i;
    int j;
    double distance = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            distance += pow((input1->pattern_memory)[i][j] - (input2->pattern_memory)[i][j], 2);
        }
    }

    // Divide by N^2
    distance /= (N*N);

    return distance;
}



