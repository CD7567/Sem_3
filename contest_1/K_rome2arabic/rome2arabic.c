#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toDec(char* roman) {
  switch (*roman) {
    case 'M':
      return 1000;
    case 'D':
      return 500;
    case 'C':
      return 100;
    case 'L':
      return 50;
    case 'X':
      return 10;
    case 'V':
      return 5;
    case 'I':
      return 1;
  }
}

int main() {
  char roman[4001];
  int curr_digit = 0;
  int prev_digit = 0;
  int result = 0;

  scanf("%s", roman);

  for (int i = strlen(roman) - 1; i >= 0; --i) {
    curr_digit = toDec(roman + i);

    if (curr_digit < prev_digit) {
      result -= curr_digit;
    } else {
      result += curr_digit;
    }

    prev_digit = curr_digit;
  }

  printf("%d", result);
}