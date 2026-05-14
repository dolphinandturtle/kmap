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

int kadane_2d(size_t m, size_t n, int M[m][n]) {
    int xmax = INT_MIN;
    int temp[m];
    for (int left = 0; left < n; left++) {
        // Zero temp
        for (int i = 0; i < m; i++) {
            temp[i] = 0;
        }
        for (int right = left; right < n; right++) {
            // Summing the column
            for (int i = 0; i < m; i++) {
                temp[i] += M[i][right];
            }
            xmax = max(kadane_1d(m, temp), xmax);
        }
    }
    return xmax;
}

int kadane_nd(size_t n, size_t dim[n], int* T) {
    assert(0 && "This function hasn't been implemented yet.");
    return 0;
}
