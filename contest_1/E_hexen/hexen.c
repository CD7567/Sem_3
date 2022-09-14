#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* hex;
  char* bin;
  size_t len, it = 0;

  hex = (char*) malloc(1000001 * sizeof(char));
  bin = (char*) malloc(4000001 * sizeof(char));

  scanf("%s", hex);
  len = strlen(hex);
  bin[4 * len] = '\0';

  for (size_t i = 0; i < len; ++i, it += 4) {
    switch (hex[i]) {
      case '0':
        bin[it] = '0';
        bin[it + 1] = '0';
        bin[it + 2] = '0';
        bin[it + 3] = '0';
        break;

      case '1':
        bin[it] = '0';
        bin[it + 1] = '0';
        bin[it + 2] = '0';
        bin[it + 3] = '1';
        break;

      case '2':
        bin[it] = '0';
        bin[it + 1] = '0';
        bin[it + 2] = '1';
        bin[it + 3] = '0';
        break;

      case '3':
        bin[it] = '0';
        bin[it + 1] = '0';
        bin[it + 2] = '1';
        bin[it + 3] = '1';
        break;

      case '4':
        bin[it] = '0';
        bin[it + 1] = '1';
        bin[it + 2] = '0';
        bin[it + 3] = '0';
        break;

      case '5':
        bin[it] = '0';
        bin[it + 1] = '1';
        bin[it + 2] = '0';
        bin[it + 3] = '1';
        break;

      case '6':
        bin[it] = '0';
        bin[it + 1] = '1';
        bin[it + 2] = '1';
        bin[it + 3] = '0';
        break;

      case '7':
        bin[it] = '0';
        bin[it + 1] = '1';
        bin[it + 2] = '1';
        bin[it + 3] = '1';
        break;

      case '8':
        bin[it] = '1';
        bin[it + 1] = '0';
        bin[it + 2] = '0';
        bin[it + 3] = '0';
        break;

      case '9':
        bin[it] = '1';
        bin[it + 1] = '0';
        bin[it + 2] = '0';
        bin[it + 3] = '1';
        break;

      case 'a':
      case 'A':
        bin[it] = '1';
        bin[it + 1] = '0';
        bin[it + 2] = '1';
        bin[it + 3] = '0';
        break;

      case 'b':
      case 'B':
        bin[it] = '1';
        bin[it + 1] = '0';
        bin[it + 2] = '1';
        bin[it + 3] = '1';
        break;

      case 'c':
      case 'C':
        bin[it] = '1';
        bin[it + 1] = '1';
        bin[it + 2] = '0';
        bin[it + 3] = '0';
        break;

      case 'd':
      case 'D':
        bin[it] = '1';
        bin[it + 1] = '1';
        bin[it + 2] = '0';
        bin[it + 3] = '1';
        break;

      case 'e':
      case 'E':
        bin[it] = '1';
        bin[it + 1] = '1';
        bin[it + 2] = '1';
        bin[it + 3] = '0';
        break;

      case 'f':
      case 'F':
        bin[it] = '1';
        bin[it + 1] = '1';
        bin[it + 2] = '1';
        bin[it + 3] = '1';
        break;

      default:
        break;
    }
  }

  bin[it] = '\0';

  size_t shift = 0;
  while (shift != 4 * len - 1 && bin[shift] == '0') {
    ++shift;
  }

  printf("%s", bin + shift);

  free(bin);
  free(hex);
}