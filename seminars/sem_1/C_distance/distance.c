#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

int main(int argc, char* argv[]) {
  size_t n = argc / 2;

  long double* lhs = malloc(n * sizeof(long double));
  long double* rhs = malloc(n * sizeof(long double));
  long double sqr_distance = 0;

  for (size_t i = 1, j = 0; i <= n; ++i, ++j) {
    lhs[j] = strtold(argv[j], NULL);	  
  }

  for (size_t i = n + 1, j = 0; i <= 2 * n; ++i, ++j) {
    rhs[j] = strtold(argv[j], NULL);
  }

  for (size_t i = 0; i < n; ++i) {
    sqr_distance += (lhs[i] - rhs[i]) * (lhs[i] - rhs[i]);
  }

  printf("%Lf", sqrtl(sqr_distance));

  free(lhs);
  free(rhs);
}
