/*Jun Sung*/
typedef struct tempStruct MyTempStruct;

struct tempStruct {
    int date;
    float avgTemp;
    MyTempStruct * next;
};

void initializeStruct( FILE * input, MyTempStruct * tempStructPtr );
void swap( MyTempStruct * ptr1, MyTempStruct * ptr2 );
void qsortTD( MyTempStruct * left, MyTempStruct * right );
void writeSortedData( FILE * output, MyTempStruct * tempStructPtr );