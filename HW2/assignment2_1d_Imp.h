/*Jun Sung*/
void initializeStruct( FILE * input, MyTempStruct * tempStructPtr ) {
    float highT, avgT, lowT;
    int day, month, year;

    fscanf( input, "%*s" );

    while( fscanf( input, "%d-%d-%d,%f,%f,%f",
        &year, &month, &day, &highT, &avgT, &lowT ) != EOF ) {
        tempStructPtr -> date = (1000000*day) + (10000*month) + year;
        tempStructPtr -> avgTemp = avgT;
        tempStructPtr -> next = tempStructPtr + 1;
        tempStructPtr++;
    }
    (tempStructPtr - 1) -> next = NULL;

    fclose(input);
}

void swap( MyTempStruct * ptr1, MyTempStruct * ptr2 ) {
    int tmpDate = ptr1 -> date;
    float tmpTemp = ptr1 -> avgTemp;
    // MyTempStruct * tmpNext = ptr1 -> next;

    ptr1 -> date = ptr2 -> date;
    ptr1 -> avgTemp = ptr2 -> avgTemp;
    // ptr1 -> next = ptr2 -> next;
    
    ptr2 -> date = tmpDate;
    ptr2 -> avgTemp = tmpTemp;
    // ptr2 -> next = tmpNext;
}

void qsortTD( MyTempStruct * left, MyTempStruct * right ) {

    MyTempStruct * ptr = NULL, * last = NULL, * middle = NULL;

    if ( left >= right ) {
        return;
    }

    middle = left + ( right - left ) / 2;
    swap( left, middle );
    last = left;

    for ( ptr = left + 1; ptr <= right; ptr++ ) {
        float ptrT = ptr -> avgTemp;
        float leftT = left -> avgTemp;
        if ( ptrT < leftT ) {
            swap( ++last, ptr );
        }
    }

    swap( left, last );

    qsortTD( left, last - 1 );
    qsortTD( last + 1, right );
}

void writeSortedData( FILE * output, MyTempStruct * tempStructPtr ) {
    int day, month, year;

    MyTempStruct * ptr;
    for ( ptr = tempStructPtr; ptr != NULL ; ptr = ptr ->next ) {
        float avgT = ptr -> avgTemp;
        int date = ptr ->date;

        day = date / 1000000;
        month = ( date / 10000 ) % 100;
        year = date % 10000;

        fprintf( output, "%d,%d,%d,%.0f\n", day, month, year, avgT );
    }

    fclose(output);
}