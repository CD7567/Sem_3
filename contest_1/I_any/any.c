#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n, k;
  char buffer[32];
  unsigned long long decimal_help;

  scanf("%d%s%d", &n, buffer, &k);

  decimal_help = strtoull(buffer, NULL, n);

  if (decimal_help == 0) {
    printf("%d", 0);
  } else {
    int i = 0;
    while (decimal_help != 0) {
      buffer[i] = decimal_help % k;
      decimal_help /= k;
      ++i;
    }

    for (--i; i >= 0; --i) {
      if (buffer[i] < 10) {
        printf("%d", buffer[i]);
      } else {
        buffer[i] += 55;
        printf("%c", buffer[i]);
      }
    }
  }
}