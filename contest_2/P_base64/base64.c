#include <stdio.h>
#include <stdint.h>

union BitBase {
  char base128[3000];
  uint8_t u_base128[3000];
} bit_base;

char Recode(uint8_t old_char) {
  if (old_char < 26) {
    return old_char + 65;
  } else if (old_char < 52) {
    return old_char + 71;
  } else if (old_char < 62) {
    return old_char - 4;
  } else if (old_char == 62) {
    return '+';
  } else {
    return '/';
  }
}

int main() {
  uint64_t triples_read;
  FILE* in;
  FILE* out;
  char recodedString[4001] = "";

  in = fopen("data", "r");
  out = fopen("base64", "w");

  while ((triples_read = fread(bit_base.base128, 1, 3000, in) / 3) > 1) {
    for (uint64_t i = 0; i < triples_read; ++i) {
      recodedString[4 * i] = Recode(bit_base.u_base128[3 * i] >> 2);
      recodedString[4 * i + 1] = Recode((bit_base.u_base128[3 * i] % 4 << 4) + (bit_base.u_base128[3 * i + 1] >> 4));
      recodedString[4 * i + 2] = Recode((bit_base.u_base128[3 * i + 1] % 16 << 2) + (bit_base.u_base128[3 * i + 2] >> 6));
      recodedString[4 * i + 3] = Recode(bit_base.u_base128[3 * i + 2] % 64);
    }

    recodedString[triples_read * 4] = '\0';
    fprintf(out, "%s", recodedString);
  }

  fclose(in);
  fclose(out);
}