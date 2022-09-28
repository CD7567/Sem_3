#include <stdio.h>
#include <malloc.h>

typedef long double Lf;

Lf sum_double(Lf* bias, Lf lhs, Lf rhs) {
  Lf sum = lhs + rhs;
  Lf r_bias = sum - lhs;
  Lf l_bias = sum - r_bias;

  *bias = (lhs - l_bias) + (rhs - r_bias);

  return sum;
}

Lf sum_double_array(Lf* array, size_t length) {
  Lf single_bias, total_bias = 0.0, sum = 0.0;

  for (size_t i = 0; i < length; ++i) {
    sum = sum_double(&single_bias, sum, array[i]);
    total_bias += single_bias;
  }

  return sum + total_bias;
}

int main() {
  Lf* double_array = malloc(10000000 * sizeof(long double));
  size_t len = 0;

  while (scanf("%Lf", double_array + len) != EOF) {
    ++len;
  }

  printf("%.20LF", sum_double_array(double_array, len));

  free(double_array);
}