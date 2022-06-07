/*Jun Sung*/

#include <stdlib.h>
#include <unistd.h>

#include "IsingLattice2D.h"
#include "pattern.h"
#include "Jmatrix.h"
#include "neural.h"


#define SWEEP_MAX 50
#define STRIP 1
#define SLEEP 0

int main(int argc, char** argv) { 

    int M = argc - 5;
    unsigned seed = strtoul(argv[1],NULL,10);
    float randomization = strtof(argv[2],NULL);
    float damage = strtof(argv[3],NULL);

    int N=10;
    float T=0.0;

    FILE ** fsin = (FILE **)calloc(M, sizeof(FILE *));
    FILE ** ftest = (FILE **)malloc(1*sizeof(FILE *));
    pattern * inputs;
    pattern * test;
    pattern * out;

    double prevenergy = 0.0;
    double currenergy = -5.0;
    double r;
    double hamming;
    int i,j;
    

    srand(seed);

    //
    // Load input patterns into a Jmatrix
    //
    for (i = 0; i < M; i++) {
      fsin[i] = fopen(argv[5+i], "r");
    }
    inputs = readPatterns(fsin, M, N);
    for (i = 0; i < M; i++) {
      fclose(fsin[i]);
    }

    Jmatrix * Jmat;
    Jmat = createJ(N, inputs, M);
    clear();
    for (i = 0; i < M; i++) {
      printf("Loaded Network patterns, memory : %d\n\n", i);
      writePattern(&(inputs[i]), stdout, STRIP);
      sleep(SLEEP);
      clear();
    }



    //
    // open the test pattern
    //
    ftest[0] = fopen(argv[4], "r");
    test = readPatterns(ftest, 1, N);
    fclose(ftest[0]); //test pattern is loaded in by the ftest and test initialization
    clear();
    printf("pristine test pattern : \n\n");
    writePattern(test, stdout, STRIP);
    sleep(SLEEP);
    clear();


    //
    // Randomize the test pattern based on specification
    //
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        r = (float)rand()/RAND_MAX;
        if (r <= randomization) {
          (test->pattern_memory)[i][j] *= -1;
        }
      }
    }
    printf("randomized test pattern : \n\n");
    writePattern(test, stdout, STRIP);
    sleep(SLEEP);
    clear();


    //
    // constuct a lattice using the test pattern and Jmatrix
    //
    IsingLattice2D * lattice = create2DIsingLattice( N, N, T, 0);
    int sweeps = 0;
    IsingFromPattern(lattice, test, Jmat);
    clear();


    //
    // Simulate neuron damage, this comes after lattice creating
    //
    for (i = 0; i < N*N; i++) {
      for (j = 0; j < N*N; j++) {
        r = (float)rand()/RAND_MAX;
        if (r <= damage) {
          ((lattice->Jmatrix))[i][j] = 0;
        }
      }
    }


    //
    // sweep until we settle into a minimum
    //
    while(prevenergy != currenergy && sweeps < SWEEP_MAX) {
      printf("sweep: %d\n\n", sweeps);
      out = PatternFromIsing(lattice);
      writePattern(out, stdout, STRIP);

      prevenergy = getTotalEnergy(lattice);

      sweep(lattice, &neuralFlip);

      currenergy = getTotalEnergy(lattice);

      if (currenergy != prevenergy) {
        sweeps++;
      }

      sleep(SLEEP);
      clear();
    }  

    printf("recalled: \n");
    out = PatternFromIsing(lattice);
    writePattern(out, stdout, STRIP);
    //  clear();
    fflush(stdout);



    // compare against test patterns
    printf("\nChecking Hamming distances ...\n");
    int minIndex;
    double minHD=999;
    for( i=0; i<M; i++ ) {

      double tmpHD = hammingDistance(out, &(inputs[i]));
      printf("index: %d\t pattern: %s\t hammingDistance: %f\n\n", i, argv[5+i], tmpHD);
      if( tmpHD < minHD) { 
        minHD = tmpHD;
        minIndex = i;
      }
    }

    printf("nearest match: %d\thammingDistance: %f\n\n", minIndex, minHD);
    writePattern(&(inputs[minIndex]), stdout, STRIP);

    printf("\n");

    return minIndex;
}
