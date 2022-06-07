/*Jun Sung*/

#include <stdio.h>

main() {
    int i, num;
    unsigned long long int fact;
    printf( "Please input an integer: ");
    scanf( "%d", &num);

    if ( num <= 0 ) {
        printf("INVALID\nPlease enter a valid integer.");
        return;
    }

    fact = num;
    for( i = num-1; i > 1; i-- ) {
        fact *= i;
    }
    printf( "The factorial of %d is %llu\n", num, fact);
}