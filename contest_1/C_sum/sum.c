#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  long double x, y, z;
  char str_y[30];

  scanf("%Lf%s", &x, &str_y);
  y = (long double) strtoll(str_y, NULL, 16);
  z = (long double) strtoll(argv[1], NULL, 27);

  printf("%.3Lf", x + y + z);
}