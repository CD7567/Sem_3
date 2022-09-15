#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

int main() {
  char characteristic[3];
  ull dec_characteristic;

  scanf("%s", characteristic);

  dec_characteristic = strtoll(characteristic, NULL, 16);

  printf("%s", (dec_characteristic % 2) ? "ma " : "fe ");
  dec_characteristic >>= 1;
  printf("%s", (dec_characteristic % 2) ? "cl " : "du ");
  dec_characteristic >>= 1;
  printf("%s", (dec_characteristic % 2) ? "ha " : "nh ");
  dec_characteristic >>= 1;
  printf("%s", (dec_characteristic % 2) ? "tr " : "sk ");
  dec_characteristic >>= 1;

  switch (dec_characteristic % 4) {
    case 0:
      printf("%s", "bn ");
      break;
    case 1:
      printf("%s", "rd ");
      break;
    case 2:
      printf("%s", "bw ");
      break;
    case 3:
      printf("%s", "bk ");
      break;
  }

  dec_characteristic >>= 2;

  switch (dec_characteristic % 4) {
    case 0:
      printf("%s", "bu");
      break;
    case 1:
      printf("%s", "ge");
      break;
    case 2:
      printf("%s", "gy");
      break;
    case 3:
      printf("%s", "da");
      break;
  }
}