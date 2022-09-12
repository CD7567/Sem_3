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
    case 'I':
      return 1;
  }
}

int main() {
  char roman[31];
  char* dot_ptr;
  long long int_part;
  long double result;

  scanf("%s", roman);

  int i;
  for (i = 0; roman[i] != '.' && roman[i] != '\0'; ++i) {
  }

  dot_ptr = roman + i;
  result = strtoll(roman, &dot_ptr, 2);

  if (*dot_ptr != '\0') {
    ++dot_ptr;

    long double exp = 2.0;
    while (*dot_ptr != '\0') {
      result += ((long double)(*dot_ptr - 48)) / exp;
      exp *= 2;
      ++dot_ptr;
    }
  }

  printf("%.12Lf", result);
}