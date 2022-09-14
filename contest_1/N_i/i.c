#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned long long ull;

enum Roman {
  I = 0,
  V = 1,
  X = 2,
  L = 3,
  C = 4,
  D = 5,
  M = 6
};

int main() {
  char input[100001];
  size_t available_count[7] = {};
  size_t required_count[7] = {};
  size_t len, rom_len = 0, max_len = 0, longest_number = 0;
  bool is_possible = true;

  scanf("%s", input);
  len = strlen(input);

  for (size_t i = 0; i < len; ++i) {
    switch (input[i]) {
      case 'm':
      case 'M':
        ++available_count[M];
        break;

      case 'd':
      case 'D':
        ++available_count[D];
        break;

      case 'c':
      case 'C':
        ++available_count[C];
        break;

      case 'l':
      case 'L':
        ++available_count[L];
        break;

      case 'x':
      case 'X':
        ++available_count[X];
        break;

      case 'v':
      case 'V':
        ++available_count[V];
        break;

      case 'i':
      case 'I':
        ++available_count[I];
        break;
    }
  }

  for (ull i = 3999, j = 3999; i > 0; --i, j = i) {
    while (j != 0)
      if (j >= 1000) {
        j -= 1000;
        ++required_count[M];
      } else if (j >= 900) {
        j -= 900;
        ++required_count[M];
        ++required_count[C];
      } else if (j >= 500) {
        j -= 500;
        ++required_count[D];
      } else if (j >= 400) {
        j -= 400;
        ++required_count[C];
        ++required_count[D];
      } else if (j >= 100) {
        j -= 100;
        ++required_count[C];
      } else if (j >= 90) {
        j -= 90;
        ++required_count[C];
        ++required_count[X];
      } else if (j >= 50) {
        j -= 50;
        ++required_count[L];
      } else if (j >= 40) {
        j -= 40;
        ++required_count[L];
        ++required_count[X];
      } else if (j >= 10) {
        j -= 10;
        ++required_count[X];
      } else if (j >= 9) {
        j -= 9;
        ++required_count[X];
        ++required_count[I];
      } else if (j >= 5) {
        j -= 5;
        ++required_count[V];
      } else if (j >= 4) {
        j -= 4;
        ++required_count[V];
        ++required_count[I];
      } else if (j >= 1) {
        j -= 1;
        ++required_count[I];
      }

    for (size_t k = 0; k < 7; ++k) {
      rom_len += required_count[k];

      if (required_count[k] > available_count[k]) {
        is_possible = false;
      }

      required_count[k] = 0;
    }

    if (is_possible && rom_len > max_len) {
      max_len = rom_len;
      longest_number = i;
    }

    rom_len = 0;
    is_possible = true;
  }

  while (longest_number != 0)
    if (longest_number >= 1000) {
      longest_number -= 1000;
      printf("%s", "M");
    } else if (longest_number >= 900) {
      longest_number -= 900;
      printf("%s", "CM");
    } else if (longest_number >= 500) {
      longest_number -= 500;
      printf("%s", "D");
    } else if (longest_number >= 400) {
      longest_number -= 400;
      printf("%s", "CD");
    } else if (longest_number >= 100) {
      longest_number -= 100;
      printf("%s", "C");
    } else if (longest_number >= 90) {
      longest_number -= 90;
      printf("%s", "XC");
    } else if (longest_number >= 50) {
      longest_number -= 50;
      printf("%s", "L");
    } else if (longest_number >= 40) {
      longest_number -= 40;
      printf("%s", "XL");
    } else if (longest_number >= 10) {
      longest_number -= 10;
      printf("%s", "X");
    } else if (longest_number >= 9) {
      longest_number -= 9;
      printf("%s", "IX");
    } else if (longest_number >= 5) {
      longest_number -= 5;
      printf("%s", "V");
    } else if (longest_number >= 4) {
      longest_number -= 4;
      printf("%s", "IV");
    } else if (longest_number >= 1) {
      longest_number -= 1;
      printf("%s", "I");
    }
}