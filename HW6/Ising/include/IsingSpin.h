#ifndef ISING_SPIN
#define ISING_SPIN

#define SPIN 1.0

typedef struct spinStruct IsingSpin; 

struct spinStruct 
{ 
    /* We can assign each spin a unique ID, which will 
      help verify that we've setup the lattice correctly */
    int ID;     

    double spin;  /* spin value */
    double E;    /* energy for this spin */

    /* nearest neighbors */
    IsingSpin * left;
    IsingSpin * right;
    IsingSpin * above;
    IsingSpin * below;

    /* for 3d ... */
    IsingSpin * backward;
    IsingSpin * forward;

    /* for linked-list traversal */ 
    IsingSpin * next;
}; 

#endif
