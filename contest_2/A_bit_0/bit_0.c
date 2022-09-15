#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

int main() {
  char lhs_hex[3], rhs_hex[3];
  ull lhs, rhs, result = 0, exp = 1;

  scanf("%s %s", lhs_hex, rhs_hex);

  lhs = strtoll(lhs_hex, NULL, 16);
  rhs = strtoll(rhs_hex, NULL, 16);
  result = lhs ^ rhs;

  return result;
}