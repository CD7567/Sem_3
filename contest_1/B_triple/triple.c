#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned long long dec_num = 0;
  unsigned long long triple_num;
  unsigned long long exp = 1;

  scanf("%llu", &triple_num);

  while (triple_num != 0) {
    dec_num += (triple_num % 10) * exp;
    exp *= 3;
    triple_num /= 10;
  }

  printf("%llu", dec_num);
}