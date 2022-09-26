#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef unsigned long long ull;

int main() {
  ull divider = 2;
  ull counter = 0;
  float f_real = 0.5f;
  double d_real = 0.5;
  long double ld_real = 0.5l;
  char type;

  scanf("%c", &type);

  switch (type) {
    case 'f':
      do {
        f_real += 1.0f / (float) divider;
        divider <<= 1;
        ++counter;
      } while (f_real + 1.0f / (float) divider != f_real);
      break;

    case 'd':
      do {
        d_real += 1.0 / (double) divider;
        divider <<= 1;
        ++counter;
      } while (d_real + 1.0 / (double) divider != d_real);
      break;

    case 'l':
      do {
        ld_real += 1.0l / (long double) divider;
        divider <<= 1;
        ++counter;
      } while (ld_real + 1.0l / (long double) divider != ld_real);
      break;
  }

  printf("%llu", counter - 1);
}