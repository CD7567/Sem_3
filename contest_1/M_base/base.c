#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned long long ull;

ull ToDecimal(char* string, ull base) {
  ull decimal = 0;
  ull exp = 1;

  for (int i = strlen(string) - 1; i >= 0 && decimal != ULLONG_MAX; --i) {
    if (string[i] >= 48 && string[i] <= 57) {
      if (exp > ULLONG_MAX / (string[i] - 48)) {
        decimal = ULLONG_MAX;
      } else if (decimal > ULLONG_MAX - exp * (string[i] - 48)) {
        decimal = ULLONG_MAX;
      } else {
        decimal += exp * (string[i] - 48);
      }
    } else if (string[i] >= 97 && string[i] <= 122) {
      if (exp > ULLONG_MAX / (string[i] - 87)) {
        decimal = ULLONG_MAX;
      } else if (decimal > ULLONG_MAX - exp * (string[i] - 87)) {
        decimal = ULLONG_MAX;
      } else {
        decimal += exp * (string[i] - 87);
      }
    }

    if (exp > ULLONG_MAX / base) {
      return ULLONG_MAX;
    }

    exp *= base;
  }

  return decimal;
}

int main() {
  char x[100];
  char y[100];
  char z[100];

  size_t x_len = 0;
  size_t y_len = 0;
  size_t z_len = 0;

  char sign;
  char max_digit;

  ull bases[1228] = {};
  ull min_base;
  size_t bases_size = 0;

  ull x_dec;
  ull y_dec;
  ull z_dec;

  size_t n;

  scanf("%lu ", &n);

  for (size_t i = 0; i < n; ++i) {
    max_digit = '0';

    if (i == n - 1) {
      scanf("%[0-9a-z]%c%[0-9a-z]=%[0-9a-z]", x, &sign, y, z);
    } else {
      scanf("%[0-9a-z]%c%[0-9a-z]=%[0-9a-z] ", x, &sign, y, z);
    }

    x_len = strlen(x);
    y_len = strlen(y);
    z_len = strlen(z);

    for (size_t j = 0; j < x_len; ++j) {
      if (x[j] > max_digit) {
        max_digit = x[j];
      }
    }
    for (size_t j = 0; j < y_len; ++j) {
      if (y[j] > max_digit) {
        max_digit = y[j];
      }
    }
    for (size_t j = 0; j < z_len; ++j) {
      if (z[j] > max_digit) {
        max_digit = z[j];
      }
    }

    if (max_digit <= 57) {
      if (i == 0 || min_base < max_digit - 48) {
        min_base = max_digit - 48;
      }
    } else {
      if (i == 0 || min_base < max_digit - 86) {
        min_base = max_digit - 86;
      }
    }

    if (i == 0) {
      for (ull base = min_base; base < 1227; ++base) {
        x_dec = ToDecimal(x, base);
        y_dec = ToDecimal(y, base);
        z_dec = ToDecimal(z, base);

        if (sign == '+' && (x_dec > ULLONG_MAX - y_dec || x_dec + y_dec != z_dec)) {
          continue;
        } else if (sign == '*' && (x_dec > ULLONG_MAX / y_dec || x_dec * y_dec != z_dec)) {
          continue;
        }

        if (sign == '+' && x_dec + y_dec == z_dec) {
          bases[bases_size++] = base;
        } else if (sign == '*' && x_dec * y_dec == z_dec) {
          bases[bases_size++] = base;
        }
      }
    } else if (bases_size > 0) {
      for (size_t k = 0; k < bases_size; ++k) {
        if (bases[k] < min_base) {
          bases[k] = 0;
          continue;
        }

        x_dec = ToDecimal(x, bases[k]);
        y_dec = ToDecimal(y, bases[k]);
        z_dec = ToDecimal(z, bases[k]);

        if (sign == '+' && (x_dec > ULLONG_MAX - y_dec || x_dec + y_dec != z_dec)) {
          bases[k] = 0;
        } else if (sign == '*' && (x_dec > ULLONG_MAX / y_dec || x_dec * y_dec != z_dec)) {
          bases[k] = 0;
        }
      }
    } else {
      continue;
    }
  }

  size_t bases_count = 0;
  ull answer = 0;


  for (size_t i = 0; i < bases_size && bases_count < 2; ++i) {
    if (bases[i] >= min_base && bases[i] != 0) {
      ++bases_count;
      answer = bases[i];
    }
  }


  if (bases_count == 0) {
    printf("%d", 0);
  } else if (bases_count == 1) {
    printf("%llu", answer);
  } else {
    printf("%d", -1);
  }
}