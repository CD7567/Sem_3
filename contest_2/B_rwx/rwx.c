#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned short dec_input;
  char input[4];
  char output[10] = {};

  scanf("%s", input);

  dec_input = (short) strtoull(input, NULL, 8);

  for (int i = 8; i >= 0; --i) {
    switch (i % 3) {
      case 2:
        if (dec_input % 2) {
          output[i] = 'x';
        } else {
          output[i] = '-';
        }
        break;

      case 1:
        if (dec_input % 2) {
          output[i] = 'w';
        } else {
          output[i] = '-';
        }
        break;

      case 0:
        if (dec_input % 2) {
          output[i] = 'r';
        } else {
          output[i] = '-';
        }
        break;
    }

    dec_input >>= 1;
  }

  printf("%s", output);
}