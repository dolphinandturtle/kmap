#include <stdio.h>
#include "src/loop.h"
#include "src/kadane.h"

int main(void) {

    size_t tensor[3][3][2] = {
        {{1, 2}, {3, 4}, {5, 6}},
        {{7, 8}, {9, 10}, {11, 12}},
        {{13, 14}, {15, 16}, {17, 18}}
    };
    size_t tensor2[3][3][2] = {
        {{17, 2}, {3, 4}, {5, 6}},
        {{7, 8}, {9, 10}, {11, 12}},
        {{13, 14}, {15, 16}, {17, 18}}
    };

    for (
        struct MultiIndex loop = multi_index_init(3, (size_t[]){0, 0, 0}, (size_t[]){3, 3, 2});
        multi_index_conditional(&loop);
        multi_index_iteration(&loop)
    ) {
        print_row(3, loop.index);
    }

    int M[6][6] = {
        { +1,  +1,  +1,  +1,  +1,  +1},
        { +1, -10, -10, -10, -10,  +1},
        { +1, -10, +10, +10, -10,  +1},
        { +1, -10, +10, +10, -10,  +1},
        { +1, -10, -10, -10, -10,  +1},
        { +1,  +1,  +1,  +1,  +1,  +1},
    };
    printf("Greatest boxed sum: %d\n", kadane_2d(6, 6, M));
    printf("Greatest boxed sum: %d\n", kadane_nd(2, (size_t []){6, 6}, (int*)M));

    int T[4][4][4] = {
        {{-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}},
        {{-1, -1, -1, -1}, {-1, +1, +1, -1}, {-1, +1, +1, -1}, {-1, -1, -1, -1}},
        {{-1, -1, -1, -1}, {-1, +1, +1, -1}, {-1, +1, +1, -1}, {-1, -1, -1, -1}},
        {{-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}},
    };
    printf("Greatest boxed sum: %d\n", kadane_nd(3, (size_t []){4, 4, 4}, (int*)T));

    return 0;
}
