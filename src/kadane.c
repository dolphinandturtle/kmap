#include <assert.h>
#include <stddef.h>
#include <limits.h>

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int kadane_1d(size_t n, int a[n]) {
    int xmax = INT_MIN;
    int xi = 0;
    int xf = 0;
    for (int i = 0; i < n; i++) {
        xf = xi + a[i];
        xi = max(xf, a[i]);
        xmax = max(xmax, xi);
    }
    return xmax;
}

static void zero1d(size_t n, int a[n]) {
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    return;
}

static void add1d(size_t n, int a[n], const int b[n]) {
    for (int i = 0; i < n; i++) {
        a[i] += b[i];
    }
    return;
}

#include <stdio.h>

int kadane_2d(size_t m, size_t n, int M[m][n]) {
    int xmax = INT_MIN;
    int acc[n];
    for (int l = 0; l < m; l++) {
        zero1d(n, acc);
        for (int r = l; r < m; r++) {
            add1d(n, acc, M[r]);
            xmax = max(kadane_1d(n, acc), xmax);
        }
    }
    return xmax;
}

int kadane_nd(size_t n, size_t dim[n], int* T) {
    assert(0 && "This function hasn't been implemented yet.");
    return 0;
}
