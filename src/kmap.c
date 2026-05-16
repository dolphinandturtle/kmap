#include <assert.h>
#include <stddef.h>
#include <stdbool.h>

static bool is_pow2(int x) {
    return (x & (x - 1)) == 0;
}

void is_valid_kmap(size_t m, size_t n, bool kmap[m][n]) {
    assert(is_pow2(m));
    assert(is_pow2(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            assert(kmap[i][j] == 0 || kmap[i][j] == 1);
        }
    }
    return;
}

int count_max_rects(size_t m, size_t n) {
    return m * n / 2;
}

void kadane_kmap(size_t m, size_t n, bool kmap[m][n], int kadane[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // The kadane encoding is not unique.
            // This encoding is NOT space-optimal,
            // but IS time-optimal being that it
            // is of the local kind.
            kadane[i][j] = (kmap[i][j]) ? 1 : -(m + n);
        }
    }
    return;
}
