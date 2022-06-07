#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

double mpi_to_pi(double x) { 
  while (x >= M_PI) x -= 2*M_PI;
  while (x < -M_PI) x += 2*M_PI;
  return x;
}
