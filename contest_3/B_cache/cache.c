#include <stdio.h>
#include <stdlib.h>

int32_t gcd(int32_t lhs, int32_t rhs) {
  while(lhs != 0 && rhs != 0) {
    rhs %= lhs;
    if (rhs != 0) {
      lhs %= rhs;
    }
  }

  return (lhs == 0 ? rhs : lhs);
}

int main() {
  int32_t n, d, prod, result = 0;
  int* A;
  int* B;

  scanf("%d%d", &n, &d);

  A = calloc(n * n, sizeof(int32_t));
  B = calloc(n * n, sizeof(int32_t));

  for (int32_t i = 0; i < n; ++i) {
    for (int32_t j = 0; j < n; ++j) {
      A[i * n + j] = (i > j) ? A[j * n + i] : gcd(i + 1, j + 1);
      B[i * n + j] = (i > j) ? B[j * n + i] : gcd(n - i + 1, n - j + 1);
    }
  }

  for (int32_t i = 0; i < n; ++i) {
    for (int32_t j = 0; j < n; ++j) {
      prod = 0;

      for (int32_t k = 0; k < n; ++k) {
        prod += A[i * n + k] * B[j * n + k];
      }

      result += (prod % d == 0);
    }
  }

  printf("%d", result);

  free(A);
  free(B);
}