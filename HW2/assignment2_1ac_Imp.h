/*Jun Sung*/
#include <stdio.h>

void initializeArrays( FILE * input, float * avgTempPtr, int * datePtr ) {
    float highTemp, avgTemp, lowTemp;
    int day, month, year, date;

    fscanf( input, "%*s" );

    while( fscanf( input, "%d-%d-%d,%f,%f, %f",
        &year, &month, &day, &highTemp, &avgTemp, &lowTemp ) != EOF ) {
        date = (1000000*day) + (10000*month) + year;
        *avgTempPtr = avgTemp;
        *datePtr = date;
        avgTempPtr++;
        datePtr++;
    }

    fclose(input);
}

void swapD( int * ptr1, int * ptr2 ) {
    int tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

void swapT( float * ptr1, float * ptr2 ) {
    float tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

void qsortTD( float * leftT, float * rightT, int * leftD, int * rightD ) {

    float *avgTempPtr = NULL, *avgTempLast = NULL, *avgTempMiddle = NULL;
    int *datePtr = NULL, *dateLast = NULL, *dateMiddle = NULL;

    if ( leftT >= rightT ) {
        return;
    }

    avgTempMiddle = leftT + ( rightT - leftT ) / 2;
    dateMiddle = leftD + ( rightD - leftD ) / 2;
    swapT( leftT, avgTempMiddle );
    swapD( leftD, dateMiddle );
    avgTempLast = leftT;
    dateLast = leftD;

    for ( avgTempPtr = leftT + 1, datePtr = leftD + 1; 
        avgTempPtr <= rightT; avgTempPtr++, datePtr++ ) {
        if ( *avgTempPtr < *leftT ) {
            swapT( ++avgTempLast, avgTempPtr );
            swapD( ++dateLast, datePtr );
        }
    }

    swapT( leftT, avgTempLast );
    swapD( leftD, dateLast );

    qsortTD( leftT, avgTempLast - 1, leftD, dateLast - 1 );
    qsortTD( avgTempLast + 1, rightT, dateLast + 1, rightD );
}

void writeSortedData( FILE * output, float * avgTempPtr, int * datePtr ) {
    int day, month, year, i;

    for ( i= 0; i < ARRAY_SIZE; i++ ) {
        float avgTemp = avgTempArray[i];
        int date = dateArray[i];

        day = date / 1000000;
        month = ( date / 10000 ) % 100;
        year = date % 10000;

        fprintf( output, "%d,%d,%d,%.0f\n", day, month, year, avgTemp );
    }

    fclose(output);
}