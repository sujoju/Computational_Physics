#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "IsingLattice2D.h"

//-----------------------------------------------------------------
//
//-----------------------------------------------------------------
void 
flipSpin( IsingSpin * obj ) 
//-----------------------------------------------------------------
{ 
    obj->spin *= -1;
}


//-----------------------------------------------------------------
//
//-----------------------------------------------------------------
IsingLattice2D * 
create2DIsingLattice( int xsize, int ysize, double T, double H ) 
//-----------------------------------------------------------------
{ 
    int count=0,  i, j;
    IsingLattice2D * lptr = (IsingLattice2D*)(malloc(sizeof(IsingLattice2D)));
    IsingSpin** ptr = (IsingSpin**)(calloc(ysize, xsize*sizeof(IsingSpin*)));
    lptr->spinarray = ptr; 
    lptr->T = T; 
    lptr->H = H; 
    lptr->xsize = xsize; 
    lptr->ysize = ysize; 

    for( i=0; i<ysize; i++ ) {
      ptr[i] = (IsingSpin*)(calloc(xsize, sizeof(IsingSpin) ));
      for( j=0; j<xsize; j++ ) {  
        ptr[i][j].ID = count;
        ptr[i][j].spin = SPIN;
        count++;
      }
    }

    lptr->Jmatrix = (double**)(calloc(xsize*ysize, xsize*ysize*sizeof(double)));
    for( i=0; i<xsize*ysize; i++ ) { 
      lptr->Jmatrix[i] = (double*)(calloc(xsize*ysize, sizeof(double)));
      for( j=0; j<xsize*ysize; j++ ) { 
        lptr->Jmatrix[i][j] = 1.;
      }
    }
    initialize2DLinks(lptr);
    initialize2DSpins(lptr);
    return lptr;
}


//-----------------------------------------------------------------
//
//-----------------------------------------------------------------
void 
initialize2DLinks( IsingLattice2D*  lattice) 
//-----------------------------------------------------------------
{ 
  int i,j;

  IsingSpin ** array = lattice->spinarray;

  /* set links for the interior bulk */
  for( i=0; i<lattice->ysize; i++ ) {
    for( j=0; j<lattice->xsize; j++ ) {
      array[i][j].left   = &(array[i][j-1]);
      array[i][j].right  = &(array[i][j+1]);
      array[i][j].below  = &(array[i-1][j]);
      array[i][j].above  = &(array[i+1][j]);
      array[i][j].next   = array[i][j].right;
    }
  }
  
  /* deal w/ the left & right boundaries */
  for( i=0; i<lattice->ysize; i++ ) {
    array[i][0].left        = &(array[i][lattice->xsize-1]);
    array[i][lattice->xsize-1].right = &(array[i][0]);
    array[i][0].next        = &(array[i][1]);
    if( i<lattice->ysize-1)
      array[i][lattice->xsize-1].next  = &(array[i+1][0]);
    else
      array[i][lattice->xsize-1].next  = &(array[0][0]);      
  }

  /* deal w/ the top & bottom boundaries */
  for( j=0; j<lattice->xsize; j++ ) {
    array[0][j].below       = &(array[lattice->ysize-1][j]);
    array[lattice->ysize-1][j].above = &(array[0][j]);
  }

}


//-----------------------------------------------------------------
//
//-----------------------------------------------------------------
void 
initialize2DSpins( IsingLattice2D*  lattice ) 
//-----------------------------------------------------------------
{ 
  IsingSpin * start_ptr=*(lattice->spinarray);
  IsingSpin * ptr = *(lattice->spinarray);
  while( ptr->next != start_ptr ) { 
    ptr->spin = SPIN; 
    ptr = ptr->next;
  }
  ptr->spin = SPIN; 
}


//-----------------------------------------------------------------
//
//-----------------------------------------------------------------
void 
initialize2DSpinsRandom( IsingLattice2D*  lattice, unsigned seed) 
//-----------------------------------------------------------------
{ 
  srand(seed);
  
  IsingSpin * start_ptr=*(lattice->spinarray);
  IsingSpin * ptr = *(lattice->spinarray);
  while( ptr->next != start_ptr ) { 
    int sign = 1 - 2*(rand()%2); // gives 1 or -1
    ptr->spin = SPIN*sign; 
    ptr = ptr->next;
  }
  int sign = 1 - 2*(rand()%2); // gives 1 or -1
  ptr->spin = SPIN*sign; 
}


//-----------------------------------------------------------------
//
//-----------------------------------------------------------------
void 
sweep( IsingLattice2D* lattice, void (*flipfunc)(IsingSpin*, IsingLattice2D* lptr) )
{

  IsingSpin *ptr = *(lattice->spinarray);
  IsingSpin *start_ptr = *(lattice->spinarray);
  while( ptr->next != start_ptr ) { 
    flipfunc(ptr, lattice);
    ptr = ptr->next;
  }
  flipfunc(ptr, lattice);
}


//-----------------------------------------------------------------
//
//-----------------------------------------------------------------
void 
dumpLattice( IsingLattice2D* lattice )
//-----------------------------------------------------------------
{
  int i,j;
  IsingSpin ** array = lattice->spinarray;
  for( i=0; i<lattice->ysize; i++ ) {
    for( j=0; j<lattice->xsize; j++ ) {
      IsingSpin is = array[i][j];
      printf( "ID: %d\tx: %d\ty: %d\tspin: %f\n",
	      is.ID,j,i,is.spin);
    }
  }
}

//-----------------------------------------------------------------
//
//-----------------------------------------------------------------
void 
dumpLatticeToFile( IsingLattice2D* lattice, char* path, int sweep )
//-----------------------------------------------------------------
{

  char fname[512];
  sprintf(fname, "%s/sweep_%d.dat", path, sweep);
  FILE* f  = fopen(fname, "w");

  int i,j;
  IsingSpin ** array = lattice->spinarray;
  for( i=0; i<lattice->ysize; i++ ) {
    for( j=0; j<lattice->xsize; j++ ) {
      IsingSpin is = array[i][j];
      fprintf( f, "ID: %d\tx: %d\ty: %d\tspin: %f\n",
	       is.ID,j,i,is.spin);
    }
  }
  fclose(f);
}






