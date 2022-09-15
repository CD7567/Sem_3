#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

int main() {
  FILE* input;
  FILE* output;
  char characteristic[3];
  ull dec_characteristic;

  input = fopen("bit_3.dat", "r");
  fscanf(input, "%s", characteristic);
  fclose(input);

  dec_characteristic = strtoll(characteristic, NULL, 16);

  output = fopen("bit_3.ans", "w");

  switch ((dec_characteristic >> 4) % 4) {
    case 0:
      fprintf(output, "%s", "bn");
      break;
    case 1:
      fprintf(output, "%s", "rd");
      break;
    case 2:
      fprintf(output, "%s", "bw");
      break;
    case 3:
      fprintf(output, "%s", "bk");
      break;
  }

  fclose(output);
}