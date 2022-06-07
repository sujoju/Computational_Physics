/*Jun Sung*/

#include <stdio.h>

main() {
    char a[] = "hello";
    char b[] = "there";

    printf("The output for a is: %s\n", a);
    printf("The output for b is: %s\n", b);

    printf("Addresses of elements:\n");
    int i;
    for( i = 0; i <= 17; i++ ) {
        printf("&a[%d]: 0x%x\n", i, &(a[i]) );
        printf("&b[%d]: 0x%x\n", i, &(b[i]) );
    }

    printf("After assignment of 'j' to b (Positions 6-17):\n");
    int j;
    for( j = 6; j <= 17; j++ ) {
        b[j] = 'j';
    }

    printf("The new output for a is: %s\n", a);
    printf("The new output for b is: %s\n", b);
}