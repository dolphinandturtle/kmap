#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

struct Rect {
    size_t xi;
    size_t xf;
    size_t yi;
    size_t yf;
};

static bool is_pow2(int x) {
    return (x & (x - 1)) == 0;
}

void is_valid_kmap(size_t m, size_t n, bool kmap[m][n]) {
    assert(is_pow2(m));
    assert(is_pow2(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            assert(kmap[m][n] == 0 || kmap[m][n] == 1);
        }
    }
    return;
}

int count_max_rects(size_t m, size_t n) {
    return m * n / 2;
}

void opt(size_t m, size_t n, bool kmap[m][n], struct Rect* rects) {
    is_valid_kmap(m, n, kmap);
    // O(m, n) expected runtime
    return;
}

void print_kmap(size_t m, size_t n, bool kmap[m][n]) {
    for (int i = 0; i < m; i++) {
        printf("[");
        for (int j = 0; j < n - 1; j++) {
            printf("%d, ", kmap[i][j]);
        }
        printf("%d]\n", kmap[i][n-1]);
    }
    return;
}

int main(void) {
    bool kmap[4][2] = {
        {1, 0},
        {1, 1},
        {0, 1},
        {1, 0},
    };

    struct Rect rects[count_max_rects(4, 2)];
    is_valid_kmap(4, 2, kmap);
    opt(4, 2, kmap, rects);

    print_kmap(4, 2, kmap);
    return 0;
}
