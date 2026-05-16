#include <stdbool.h>
#include <stddef.h>

void is_valid_kmap(size_t m, size_t n, bool kmap[m][n]);
int count_max_rects(size_t m, size_t n);

// Karnaugh map reduction rules are encoded into a kind
// of maximum sub-matrix problem, that is solved with
// the use of 'Kadane's Algorithm for a Torus'.
void kadane_kmap(size_t m, size_t n, bool kmap[m][n], int kadane[m][n]);
