#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

int main(int argc, char* argv[]) {
  ull characteristic;

  characteristic = strtoll(argv[1], NULL, 16);

  printf("%s", (characteristic % 2) ? "ma" : "fe");
}