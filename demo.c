#include <stdio.h>
#include "lib/marray.h"
#include "lib/kadane.h"

struct Args {
    size_t n;
    size_t* a;
};

void times2(void* p, void* args) {
    *(int*)p *= 2;
    print_row(((struct Args*)args)->n, ((struct Args*)args)->a);
    return;
}

void add(void* p1, void* p2, void* args) {
    *(int*)p1 += *(int*)p2;
    print_row(((struct Args*)args)->n, ((struct Args*)args)->a);
    return;
}

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
    struct Args args = {3 * 3 * 2, (size_t*)tensor};
    printf("Uniform multiplication by 2:\n");
    marray_uniform(sizeof(size_t), 3, (size_t []){3, 3, 2}, tensor, times2, (void*)&args);
    printf("\n");

    printf("Adding two multi-arrays together:\n");
    marray_reduce(sizeof(size_t), 3, (size_t []){3, 3, 2}, tensor, tensor2, add, (void*)&args);
    printf("\n");

    int M[6][6] = {
        { +1,  +1,  +1,  +1,  +1,  +1},
        { +1, -10, -10, -10, -10,  +1},
        { +1, -10, +10, +10, -10,  +1},
        { +1, -10, +10, +10, -10,  +1},
        { +1, -10, -10, -10, -10,  +1},
        { +1,  +1,  +1,  +1,  +1,  +1},
    };
    printf("Greatest boxed sum: %d\n", kadane_2d(6, 6, M));

    return 0;
}
