/*Jun Sung*/
// Are we allowed to use if/else statements?

#include <stdio.h>

#define HEIGHT  5
#define BASE    9

main() {
    int row, column;
    int midL = 4, midR = 14;

    for ( row = 0 ; row < 2*HEIGHT ; row++ ) {
        for ( column = 0 ; column <= 2*BASE ; column++ ) {
            if ( row < HEIGHT ) {
                int midM;
                midM = ( midL + midR ) / 2;
                if ( column >= midM - row && column <= midM + row ) {
                    putchar('*');
                } else {
                    putchar(' ');
                }
            } else {
                if ( column >= midL - ( row % 5 ) && column <= midL + ( row % 5 ) ) {
                    putchar('*');
                } else if ( column >= midR - ( row % 5 ) && column <= midR + ( row % 5 ) ) {
                    putchar('*');
                } else {
                    putchar(' ');
                }
            }
        }
        putchar('\n');
    }
}