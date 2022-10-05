#include <stdio.h>
#include <stdint.h>

typedef uint8_t byte;
typedef uint16_t word;
typedef uint16_t adr;

byte mem[64 * 1024] = {};

byte b_read(adr a) {
  return mem[a];
}

word w_read(adr a) {
  return (word) mem[a] + (((word) mem[a + 1]) << 8);
}

void b_write(adr a, byte val) {
  mem[a] = val;
}

void w_write(adr a, word val) {
  mem[a] = (byte) (val & 0b11111111);
  mem[a + 1] = (byte) (val >> 8);
}

void load_file() {
  adr beg, size;
  byte byte_in;

  while (scanf("%hx%hx", &beg, &size) != EOF) {
    for (adr i = 0; i < size; ++i) {
      scanf("%hhx", &byte_in);
      b_write(beg + i, byte_in);
    }
  }
}

void mem_dump(adr start, word n) {
  for (word i = 0; i < n; i += 2) {
    printf("%06o : %06o\n", start + i, w_read(start + i));
  }
}