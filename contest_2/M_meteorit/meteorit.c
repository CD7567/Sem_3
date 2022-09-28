#include <stdint.h>

union data
  uint64_t u64;
  uint8_t arr[8];
  uint32_t a32[2];
};

union data convert(union data x) {
  x.u64 = __builtin_bswap64(x.u64);
  return x;
}