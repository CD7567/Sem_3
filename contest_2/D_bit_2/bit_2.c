#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

int main() {
  char* CODE = getenv("CODE");
  ull characteristic;

  characteristic = strtoll(CODE, NULL, 16);

  printf("%s", ((characteristic >> 2) % 2) ? "ha" : "nh");
}