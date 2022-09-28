#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned long long ull;

int main() {
  ull v, n, half;
  ull curr_infected, next_infected, offset = 0;
  ull counter = 0;
  ull* nul_infected;
  ull* nul_sec_infected;
  unsigned char* buff;

  scanf("%llu%llu", &v, &n);

  buff = calloc(n / 16 + 3, sizeof(unsigned char));
  nul_infected = calloc(v, sizeof(uint64_t));
  nul_sec_infected = calloc(v, sizeof(uint64_t));
  half = n >> 1;

  /// Читаем нулевых пациентов
  for (size_t i = 0; i < v; ++i) {
    scanf("%llu", nul_infected + i);
  }

  /// Проход по первой половине
  for (ull i = 0; i < v; ++i) {
    for (ull j = 1; (next_infected = nul_infected[i] * j + offset) < half; ++j) {
      buff[next_infected / 8] += (((buff[next_infected / 8] >> (next_infected % 8)) % 2 == 1) ? 0 : 1 << next_infected % 8);
      offset += j - 1;
      nul_sec_infected[i] = j;
    }

    ++nul_sec_infected[i];
    offset = 0;
  }

  /// Подсчет первой половины
  for (ull i = 0; i < half; ++i) {
    if ((buff[i / 8] >> (i % 8)) % 2 == 1) {
      ++counter;
    }
  }

  /// Обнуление массива
  memset(buff, 0, (n / 16 + 3) * sizeof(unsigned char));

  /// Проход по второй половине
  for (ull i = 0; i < v; ++i) {
    curr_infected = nul_infected[i];

    offset = ((nul_sec_infected[i] - 1) * (nul_sec_infected[i] - 2)) >> 1;

    for (ull j = nul_sec_infected[i]; (next_infected = curr_infected * j + offset) < n; ++j) {
      next_infected -= half;
      buff[next_infected / 8] += (((buff[next_infected / 8] >> (next_infected % 8)) % 2 == 1) ? 0 : 1 << next_infected % 8);
      offset += j - 1;
    }
  }

  /// Подсчет второй половины
  for (ull i = 0; i < half + 1; ++i) {
    if ((buff[i / 8] >> (i % 8)) % 2 == 1) {
      ++counter;
    }
  }

  printf("%llu", counter);
  free(buff);
  free(nul_infected);
  free(nul_sec_infected);
}