#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  char characteristic[50] = {};
  int desc[6] = {-1, -1, -1, -1, -1, -1};

  scanf("%[^\n]%*c", characteristic);

  for (size_t i = 0; i < 49; i += 2) {
    if (characteristic[i] == 'm' && characteristic[i + 1] == 'a') {
      if (desc[0] == -1) {
        desc[0] = 1;
      }
    } else if (characteristic[i] == 'f' && characteristic[i + 1] == 'e') {
      if (desc[0] == -1) {
        desc[0] = 0;
      }
    } else if (characteristic[i] == 'c' && characteristic[i + 1] == 'l') {
      if (desc[1] == -1) {
        desc[1] = 1;
      }
    } else if (characteristic[i] == 'd' && characteristic[i + 1] == 'u') {
      if (desc[1] == -1) {
        desc[1] = 0;
      }
    } else if (characteristic[i] == 'h' && characteristic[i + 1] == 'a') {
      if (desc[2] == -1) {
        desc[2] = 1;
      }
    } else if (characteristic[i] == 'n' && characteristic[i + 1] == 'h') {
      if (desc[2] == -1) {
        desc[2] = 0;
      }
    } else if (characteristic[i] == 't' && characteristic[i + 1] == 'r') {
      if (desc[3] == -1) {
        desc[3] = 1;
      }
    } else if (characteristic[i] == 's' && characteristic[i + 1] == 'k') {
      if (desc[3] == -1) {
        desc[3] = 0;
      }
    } else if (characteristic[i] == 'b' && characteristic[i + 1] == 'n') {
      if (desc[4] == -1) {
        desc[4] = 0;
      }
    } else if (characteristic[i] == 'r' && characteristic[i + 1] == 'd') {
      if (desc[4] == -1) {
        desc[4] = 1;
      }
    } else if (characteristic[i] == 'b' && characteristic[i + 1] == 'w') {
      if (desc[4] == -1) {
        desc[4] = 2;
      }
    } else if (characteristic[i] == 'b' && characteristic[i + 1] == 'k') {
      if (desc[4] == -1) {
        desc[4] = 3;
      }
    } else if (characteristic[i] == 'b' && characteristic[i + 1] == 'u') {
      if (desc[5] == -1) {
        desc[5] = 0;
      }
    } else if (characteristic[i] == 'g' && characteristic[i + 1] == 'e') {
      if (desc[5] == -1) {
        desc[5] = 1;
      }
    } else if (characteristic[i] == 'g' && characteristic[i + 1] == 'y') {
      if (desc[5] == -1) {
        desc[5] = 2;
      }
    } else if (characteristic[i] == 'd' && characteristic[i + 1] == 'a') {
      if (desc[5] == -1) {
        desc[5] = 3;
      }
    } else {
      if (characteristic[i] != '\0') {
        --i;
      } else {
        break;
      }
    }
  }

  characteristic[0] = GetHexDigit(desc[4] % 2 + ((desc[4] >> 1) << 1) + ((desc[5] % 2) << 2) + ((desc[5] >> 1) << 3));
  characteristic[1] = GetHexDigit(desc[0] % 2 + (desc[1] << 1) + (desc[2] << 2) + (desc[3] << 3));
  characteristic[2] = '\0';
  printf("%s", characteristic);
}