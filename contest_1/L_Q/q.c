#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  long long base;
  long long base_cube;
  long long max_num;

  scanf("%Ld", &base);

  base_cube = base * base * base;
  max_num = (base - 1) * (base * base + base + 1);

  while (max_num * (max_num - 1) % base_cube != 0) {
    --max_num;
  }

  printf("%Ld", max_num);
}