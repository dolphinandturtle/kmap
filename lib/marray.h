#include <stddef.h>

void print_row(size_t n, size_t a[n]);
void print_matrix(size_t m, size_t n, size_t M[m][n]);

void* marray_coord(size_t size, size_t n, size_t dim[n], size_t index[n], void* p);
void marray_uniform(size_t size, size_t n, size_t dim[n], void* p, void (*uniform)(void* p, void* args), void* args);
void marray_reduce(size_t size, size_t n, size_t dim[n], void* p1, void* p2, void (*reduce)(void* p1, void* p2, void* args), void* args);
