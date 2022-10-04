#include <stdio.h>
#include <stdint.h>

const uint32_t thr_unit = 32;
const uint32_t reg_unit = 2;
const uint32_t mem_unit = 128;

const uint32_t thr_av = 1536;
const uint32_t reg_av = 32768;
const uint32_t mem_av = 49152;

uint32_t min(uint32_t a, uint32_t b, uint32_t c) {
  a = (a < b) ? a : b;
  return (a < c) ? a : c;
}

int main() {
  FILE* in;
  FILE* out;
  uint32_t thr, reg, mem;
  uint32_t act_thr, act_reg, act_mem = 1;
  uint32_t thr_limit, reg_limit, mem_limit;

  in = fopen("cuda.in", "r");
  fscanf(in, "%d%d%d", &thr, &reg, &mem);
  fclose(in);

  act_thr = thr + (thr_unit - thr % thr_unit) % thr_unit;
  act_reg = reg + (reg_unit - reg % reg_unit) % reg_unit;
  if (mem != 0) {
    act_mem = mem + (mem_unit - mem % mem_unit) % mem_unit;
  }

  thr_limit = thr_av / act_thr;
  reg_limit = reg_av / (act_thr * act_reg);
  mem_limit = mem_av / act_mem;

  out = fopen("cuda.out", "w");
  fprintf(out, "%d", (int) (((long double) thr * min(thr_limit, reg_limit, mem_limit)) / (long double) thr_av * 100 + 0.5));
  fclose(out);
}