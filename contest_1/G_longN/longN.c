#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char *dig;	// массив для хранения числа:
// a[0] * 100^0 + a[1] * 100^1 + .. + a[n - 1] * 100^(n-1)
  int n; 			// размер числа в разрядах
  char sign;	// знак числа
}LongN;

LongN getLongN(char* s) {
  LongN result;
  size_t len = strlen(s);
  size_t offset = 0;

  if (len == 0) {
    result.dig = malloc(1 * sizeof(char));
    result.dig[0] = 0;
    result.n = 1;
    result.sign = 0;
  } else {
    while(s[offset] == '0') {
      ++offset;
    }

    if (offset == len) {
      result.dig = malloc(1 * sizeof(char));
      result.dig[0] = 0;
      result.n = 1;
      result.sign = 0;
    } else {
      if (s[offset] == '-') {
        result.sign = 1;
        ++offset;
      } else {
        if (s[offset] == '+') {
          ++offset;
        }

        result.sign = 0;
      }
      result.n = (len - offset + 1) / 2;
      result.dig = malloc(result.n * sizeof(char));

      for (int s_pos = len - 1, n_pos = 0; s_pos >= (int)offset; ++n_pos) {
        result.dig[n_pos] = s[s_pos] - 48;
        if (s_pos > offset) {
          result.dig[n_pos] += 10 * (s[s_pos - 1] - 48);
        }
        s_pos -= 2;
      }
    }
  }

  return result;
}

int main(){
  LongN result = getLongN("000000000000000000000000-1111111111");

  if (result.sign) {
    printf("%c", '-');
  } else {
    printf("%c", '+');
  }

  for (int i = result.n - 1; i >= 0; --i) {
    printf("%d", result.dig[i]);
  }

  free(result.dig);
}