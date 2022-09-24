#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long llu;

int main() {
  llu x, counter = 0;
  unsigned char* buff;

  scanf("%llu", &x);

  buff = calloc(x / 8 + 1, sizeof(unsigned char));

  for (llu i = 2; i <= x; ++i) {
    if ((buff[i / 8] >> (i % 8)) % 2 == 0) {
      for (llu j = i * i; j <= x; j += i) {
        buff[j / 8] += (((buff[j / 8] >> (j % 8)) % 2 == 1) ? 0 : 1 << j % 8);
      }
    }
  }

  for (llu i = 2; i <= x; ++i) {
    if ((buff[i / 8] >> (i % 8)) % 2 == 0) {
      ++counter;
    }
  }

  printf("%llu", counter);
  free(buff);
}