#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

char GetHexDigit(int decimal) {
  char hex;

  if (decimal < 10) {
    hex = decimal + 48;
  } else {
    hex = decimal + 87;
  }

  return hex;
}

int main() {
  char characteristic[3];
  char delimiter;
  int desc[6] = {-1, -1, -1, -1, -1, -1};

  do {
    scanf("%s", characteristic);

    if (characteristic[0] == 'm' && characteristic[1] == 'a') {
      if (desc[0] == -1) {
        desc[0] = 1;
      }
    } else if (characteristic[0] == 'f' && characteristic[1] == 'e') {
      if (desc[0] == -1) {
        desc[0] = 0;
      }
    } else if (characteristic[0] == 'c' && characteristic[1] == 'l') {
      if (desc[1] == -1) {
        desc[1] = 1;
      }
    } else if (characteristic[0] == 'd' && characteristic[1] == 'u') {
      if (desc[1] == -1) {
        desc[1] = 0;
      }
    } else if (characteristic[0] == 'h' && characteristic[1] == 'a') {
      if (desc[2] == -1) {
        desc[2] = 1;
      }
    } else if (characteristic[0] == 'n' && characteristic[1] == 'h') {
      if (desc[2] == -1) {
        desc[2] = 0;
      }
    } else if (characteristic[0] == 't' && characteristic[1] == 'r') {
      if (desc[3] == -1) {
        desc[3] = 1;
      }
    } else if (characteristic[0] == 's' && characteristic[1] == 'k') {
      if (desc[3] == -1) {
        desc[3] = 0;
      }
    } else if (characteristic[0] == 'b' && characteristic[1] == 'n') {
      if (desc[4] == -1) {
        desc[4] = 0;
      }
    } else if (characteristic[0] == 'r' && characteristic[1] == 'd') {
      if (desc[4] == -1) {
        desc[4] = 1;
      }
    } else if (characteristic[0] == 'b' && characteristic[1] == 'w') {
      if (desc[4] == -1) {
        desc[4] = 2;
      }
    } else if (characteristic[0] == 'b' && characteristic[1] == 'k') {
      if (desc[4] == -1) {
        desc[4] = 3;
      }
    } else if (characteristic[0] == 'b' && characteristic[1] == 'u') {
      if (desc[5] == -1) {
        desc[5] = 0;
      }
    } else if (characteristic[0] == 'g' && characteristic[1] == 'e') {
      if (desc[5] == -1) {
        desc[5] = 1;
      }
    } else if (characteristic[0] == 'g' && characteristic[1] == 'y') {
      if (desc[5] == -1) {
        desc[5] = 2;
      }
    } else if (characteristic[0] == 'd' && characteristic[1] == 'a') {
      if (desc[5] == -1) {
        desc[5] = 3;
      }
    }

    delimiter = getchar();
  } while (delimiter != '\n' && delimiter != '\0');

  characteristic[0] = GetHexDigit(desc[4] % 2 + ((desc[4] >> 1) << 1) + ((desc[5] % 2) << 2) + ((desc[5] >> 1) << 3));
  characteristic[1] = GetHexDigit(desc[0] % 2 + (desc[1] << 1) + (desc[2] << 2) + (desc[3] << 3));
  printf("%s", characteristic);
}