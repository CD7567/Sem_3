#include <stdio.h>
#include <stdint.h>

union BitDouble {
  float f;
  double d;
  long double ld;
  uint8_t bytes[16];
} bit_double;

int main() {
  char type[7];

  scanf("%s", type);

  switch (type[0]) {
    case 'f':
      scanf("%f", &bit_double.f);

      for (int i = 3; i >= 0; --i) {
        for (size_t j = 0; j < 4; ++j) {
          printf("%d", (bit_double.bytes[i] >> (7 - j)) % 2);
        }

        printf("%c", ' ');

        for (size_t j = 4; j < 8; ++j) {
          printf("%d", (bit_double.bytes[i] >> (7 - j)) % 2);
        }

        printf("%c", ' ');
      }
      break;

    case 'd':
      scanf("%lf", &bit_double.d);

      for (int i = 7; i >= 0; --i) {
        for (size_t j = 0; j < 4; ++j) {
          printf("%d", (bit_double.bytes[i] >> (7 - j)) % 2);
        }

        printf("%c", ' ');

        for (size_t j = 4; j < 8; ++j) {
          printf("%d", (bit_double.bytes[i] >> (7 - j)) % 2);
        }

        printf("%c", ' ');
      }
      break;

    case 'l':
      scanf("%s", type);
      scanf("%Lf", &bit_double.ld);

      for (int i = 15; i >= 0; --i) {
        for (size_t j = 0; j < 4; ++j) {
          printf("%d", (bit_double.bytes[i] >> (7 - j)) % 2);
        }

        printf("%c", ' ');

        for (size_t j = 4; j < 8; ++j) {
          printf("%d", (bit_double.bytes[i] >> (7 - j)) % 2);
        }

        printf("%c", ' ');
      }
      break;
  }
}