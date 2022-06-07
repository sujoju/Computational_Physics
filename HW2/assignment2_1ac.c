/*Jun Sung*/
#include <stdio.h>
#include "assignment2_1ac_Int.h"

#define ARRAY_SIZE 365
int dateArray[ARRAY_SIZE];
float avgTempArray[ARRAY_SIZE];

main () {
    
    FILE * input = fopen("chicago_temps_2012.csv", "r");
    FILE * output = fopen("chicago_tempsSorted_2012.csv", "w+");

    initializeArrays( input, avgTempArray, dateArray );

    qsortTD( avgTempArray, avgTempArray + ARRAY_SIZE - 1, 
        dateArray, dateArray + ARRAY_SIZE - 1 );

    writeSortedData( output, avgTempArray, dateArray );
}

#include "assignment2_1ac_Imp.h"