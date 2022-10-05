#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  size_t n, logical_adr;
  uint64_t* page_adrs;

  scanf("%lu", &n);
  page_adrs = calloc(n, sizeof(uint64_t));

  for (size_t i = 0; i < n; ++i) {
    scanf("%lx", &page_adrs[i]);
  }

  scanf("%lx", &logical_adr);

  if ((logical_adr >> 26) < n) {
    printf("%lx", page_adrs[logical_adr >> 26] + (logical_adr & (1 << 26) - 1));
  } else {
    printf("error");
  }

  free(page_adrs);
}