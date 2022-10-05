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