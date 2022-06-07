/*Jun Sung*/
void initializeArrays( FILE * input, float * avgTempPtr, int * datePtr );
void swapD( int * ptr1, int * ptr2 );
void swapT( float * ptr1, float * ptr2 );
void qsortTD( float * leftT, float * rightT, int * leftD, int * rightD );
void writeSortedData( FILE * output, float * avgTempPtr, int * datePtr );