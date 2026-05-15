#include <assert.h>
#include <stdio.h>
#include <stddef.h>

void print_row(size_t n, size_t a[n]) {
    printf("{");
    for (int i = 0; i < n - 1; i++) {
        printf("%d, ", a[i]);
    }
    printf("%d}\n", a[n - 1]);
    return;
}

void print_matrix(size_t m, size_t n, size_t M[m][n]) {
    for (int i = 0; i < m; i++) {
        printf("[");
        for (int j = 0; j < n - 1; j++) {
            printf("%d, ", M[i][j]);
        }
        printf("%d]\n", M[i][n-1]);
    }
    return;
}

static void zero(size_t n, size_t a[n]) {
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    return;
}

void* marray_coord(size_t size, size_t n, size_t dim[n], size_t index[n], void* p) {
    size_t offset = 1;
    for (int i = 0; i < n; i++) {
        offset = 1;
        for (int j = i + 1; j < n; j++) {
            offset *= dim[j];
        }
        p += size * offset * index[i];
    }
    return p;
}

void marray_uniform(size_t size, size_t n, size_t dim[n], void* p, void (*uniform)(void* p, void* args), void* args) {
    size_t index[n];
    zero(n, index);
    int i = n - 1;
    while (i >= 0) {
        if (index[i] == dim[i]) {
            index[i] = 0;
            index[--i]++;
        }
        else if (i == n - 1) {
            uniform(marray_coord(size, n, dim, index, p), args);
            index[i]++;
        }
        else {
            i++;
        }
    }
    return;
}

void marray_reduce(size_t size, size_t n, size_t dim[n], void* p1, void* p2, void (*reduce)(void* p1, void* p2, void* args), void* args) {
    size_t index[n];
    zero(n, index);
    int i = n - 1;
    while (i >= 0) {
        if (index[i] == dim[i]) {
            index[i] = 0;
            index[--i]++;
        }
        else if (i == n - 1) {
            reduce(marray_coord(size, n, dim, index, p1), marray_coord(size, n, dim, index, p2), args);
            index[i]++;
        }
        else {
            i++;
        }
    }
    return;
}
