/*Jun Sung*/

#include <stdio.h>
#define ARRAY_SIZE 255

main() {
    printf( "\nPlease input some characters ...\n\n");

    char carray[ARRAY_SIZE];

    while ( fgets(carray, ARRAY_SIZE, stdin) != NULL ) {
        printf( "You input: %s\n", carray);
    }
    printf( "\nfini!\n");
}