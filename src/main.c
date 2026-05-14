#include <stdio.h>
#include "../lib/kadane.h"

int main(void) {
    int M[4][4] = {
        {1, 0, -2, 1},
        {1, 1, +7, 1},
        {0, 1, -1, 9},
        {1, 0, +2, 1},
    };
    printf("%d\n", kadane_2d(4, 4, M));
    return 0;
}
