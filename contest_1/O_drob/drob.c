#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned long long ull;

struct _Rational {
  ull integral;
  ull num;
  ull den;
} typedef Rational;

ull GCD(ull lhs, ull rhs) {
  while(lhs != 0 && rhs != 0) {
    rhs %= lhs;
    if (rhs != 0) {
      lhs %= rhs;
    }
  }

  return (lhs == 0 ? rhs : lhs);
}

void Normalize(Rational* rational) {
  ull gcd = GCD(rational->num, rational->den);

  rational->num /= gcd;
  rational->den /= gcd;

  rational->integral += rational->num / rational->den;
  rational->num %= rational->den;
}
Rational Sum(Rational lhs, Rational rhs) {
  Rational result;

  result.integral = lhs.integral + rhs.integral;
  result.num = lhs.num * rhs.den + rhs.num * lhs.den;
  result.den = lhs.den * rhs.den;

  Normalize(&result);

  return result;
}

Rational ToRational(const char number[50]) {
  Rational result;
  ull integral = 0, integral_length = 0;
  ull non_periodic = 0, non_periodic_exp = 1;
  ull periodic = 0, periodic_exp = 1;
  bool is_integral = true;
  bool is_periodic = false;

  for (size_t i = 0; i < 50 && number[i] != '\0'; ++i) {
    if (number[i] == '.') {
      is_integral = false;
    } else if (number[i] == '(') {
      is_periodic = true;
    } else if (number[i] != ')') {
      if (is_integral) {
        integral = integral * 10 + (number[i] - 48);
        //++integral_length;
      } else if (is_periodic) {
        periodic = periodic * 10 + (number[i] - 48);
        periodic_exp *= 10;
      } else {
        non_periodic = non_periodic * 10 + (number[i] - 48);
        non_periodic_exp *= 10;
      }
    }
  }

  result.integral = integral;

  if (non_periodic == false && periodic == false) {
    result.num = 0;
    result.den = 1;
  } else if (periodic == false) {
    result.num = non_periodic;
    result.den = non_periodic_exp;
  } else {
    result.num = non_periodic * periodic_exp + periodic - non_periodic;
    result.den = periodic_exp * non_periodic_exp - non_periodic_exp;
  }

  Normalize(&result);

  return result;
}

void PrintRational(Rational rational) {
  printf("%llu", rational.integral);

  if (rational.num != 0) {
    ull remainders[50];
    ull num = rational.num;
    ull den = rational.den;
    size_t len = 0, period_begin;
    bool is_periodic = false;

    printf("%c", '.');

    do {
      num %= den;
      remainders[len] = num;

      for (size_t i = 0; i < len; ++i) {
        if (remainders[i] == remainders[len]) {
          period_begin = i;
          is_periodic = true;
          break;
        }
      }

      num *= 10;
      ++len;
    } while (num != 0 && is_periodic == false);

    --len;

    if (is_periodic) {
      for (size_t i = 0; i < period_begin; ++i) {
        printf("%llu", remainders[i] * 10 / den);
      }

      printf("%c", '(');

      for (size_t i = period_begin; i < len; ++i) {
        printf("%llu", remainders[i] * 10 / den);
      }

      printf("%c", ')');
    } else {
      for (size_t i = 0; i < len; ++i) {
        printf("%llu", remainders[i] * 10 / den);
      }
    }
  }
}

int main() {
  char lhs[50], rhs[50];
  ull remainders[50];

  scanf("%s%s", lhs, rhs);

  PrintRational(Sum(ToRational(lhs), ToRational(rhs)));
}