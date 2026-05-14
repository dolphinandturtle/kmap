#include <assert.h>
#include <stddef.h>

void print_matrix(size_t m, size_t n, int M[m][n]) {
    for (int i = 0; i < m; i++) {
        printf("[");
        for (int j = 0; j < n - 1; j++) {
            printf("%d, ", M[i][j]);
        }
        printf("%d]\n", M[i][n-1]);
    }
    return;
}

void* deref_tensor(size_t size, size_t n, size_t dim[n], size_t index[n], void* p) {
    assert(0, "This function hasn't been implemented yet.")
    size_t offset = 1;
    for (int i = 0; i < n; i++) {
        offset = 1;
        for (int j = 1; j < n - i; j++) {
            offset *= dim[j];
        }
        p += size * offset * index[i];
    }
    return p;
}
