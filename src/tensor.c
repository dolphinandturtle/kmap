#include <assert.h>
#include <stdio.h>
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
    assert(0 && "This function hasn't been implemented yet.");
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

void zero(size_t n, size_t a[n]) {
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    return;
}

void reduce_tensor(size_t size, size_t n, size_t dim[n], void* p1, void* p2, void (*reduce)(void* p1, const void* p2)) {
    int i = 0;
    size_t index[n];
    reduce(deref_tensor(size, n, dim, index, p1), deref_tensor(size, n, dim, index, p2));
    while (1) {
        if (index[i] < dim[i]) {
            index[(i > 0) ? --i : i]++;
        }
        else {
            zero(++i, index);
            index[i]++;
        }
    }
    // 02
    return;
}


int main(void) {
    int n = 2;
    size_t index[n];
    zero(2, index);


    int i = 0;
    while (i < n) {

        for (int i = 0; i < n - 1; i++) {
            printf("%d, ", index[i]);
        }
        printf("%d\n", index[n-1]);

        if (index[i] < 9) {
            index[(i > 0) ? i-- : i]++;
        }
        else {
            zero(++i, index);
            // index[(i > 0) ? i-- : i]++;
            // index[i]++;
        }
    }

    return 0;
}
