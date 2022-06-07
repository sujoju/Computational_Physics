#ifndef PATTERN_HANDLING
#define PATTERN_HANDLING

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "IsingLattice2D.h"

#define clear() printf("\033[H\033[J")

typedef struct {
    double ** pattern_memory;
    int latsize;
} pattern;


pattern * readPatterns(FILE ** fsin, int M, int N);
void      writePattern(pattern * output, FILE * fout, int strip);
double    hammingDistance(pattern * p1, pattern * p2);


#endif
