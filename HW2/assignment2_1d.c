/*Jun Sung*/
#include <stdio.h>
#include "assignment2_1d_Int.h"
#define ARRAY_SIZE 365

main () {

    MyTempStruct tempData[365];

    FILE * input = fopen("chicago_temps_2012.csv", "r");
    FILE * output = fopen("chicago_tempsSortedStruct_2012.csv", "w+");

    initializeStruct( input, tempData );

    qsortTD( tempData, tempData + ARRAY_SIZE - 1 ); 

    writeSortedData( output, tempData );
}

#include "assignment2_1d_Imp.h"