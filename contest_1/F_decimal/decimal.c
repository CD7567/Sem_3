#include <stdio.h>

#define N 100
struct _Decimal {
  char a[N];   // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
  unsigned int n;       // наибольшая степень десяти
};
typedef struct _Decimal Decimal;

Decimal add(Decimal a, Decimal b) {
  Decimal result;
  char shift = 0;

  result.n = (a.n > b.n) ? a.n : b.n;

  for (unsigned int i = 0; i <= a.n || i <= b.n; ++i) {
    if (i > a.n) {
      result.a[i] = b.a[i] + shift;
    } else if (i > b.n) {
      result.a[i] = a.a[i] + shift;
    } else {
      result.a[i] = a.a[i] + b.a[i] + shift;
    }

    shift = result.a[i] / 10;
    result.a[i] %= 10;
  }

  if (shift != 0) {
    ++result.n;
    result.a[result.n] = shift;
  }

  return result;
}

int main(){
  Decimal a = {{9, 9, 9}, 2};  // set number 147
  Decimal b = {{9, 9}, 1};     // set number 13
  Decimal res;

  res = add(a, b);             // res = a+b = 147+13 = 160
  for (size_t i = res.n; i > 0; --i) {
    printf("%d", res.a[i]);
  }
  printf("%d", res.a[0]);

  return 0;
}