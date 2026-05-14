#include <stddef.h>

void print_matrix(size_t m, size_t n, int M[m][n]);
void* deref_tensor(size_t size, size_t n, size_t dim[n], size_t index[n], void* p);
