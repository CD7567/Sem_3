#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int number;

  scanf("%d", &number);

  for (int i = 7; i >= 0; --i) {
    printf("%d", (number >> i) & 1);
  }
}