#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

uint64_t gcd(uint64_t lhs, uint64_t rhs) {
  while (lhs != 0 && rhs != 0) {
    lhs %= rhs;

    if (lhs != 0) {
      rhs %= lhs;
    }
  }

  return (lhs ? lhs : rhs);
}

int main() {
  uint64_t numerator = 0, denominator = 1, _gcd, len;
  char input[20] = {};
  char* num;

  scanf("%s", input);

  for (size_t i = 0; i < 20; ++i) {
    if (input[i] == '.') {
      input[i] = '\0';
      num = input + i + 1;
      break;
    }
  }

  len = strlen(num);
  numerator = strtoll(num, NULL, 10);

  for (uint64_t i = (num[0] == '0' ? 1 : 0); i < len; ++i) {
    denominator *= 10;
  }

  _gcd = gcd(numerator, denominator);
  numerator /= _gcd;
  denominator /= _gcd;

  printf("%s (%lld/%lld)", input, numerator, denominator);
}