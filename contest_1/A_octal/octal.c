#include <stdio.h>
#include <stdlib.h>

const unsigned long long k_max_octal_fit = 100000000000;

int main() {
  unsigned long long dec_num;
  unsigned long long octal_f_part = 0;
  unsigned long long octal_s_part = 0;
  unsigned long long exp_f = 1;
  unsigned long long exp_s = 1;

  FILE* inFile = fopen("input.txt", "r");

  fscanf(inFile, "%llu", &dec_num);
  fclose(inFile);

  FILE* outFile = fopen("output.txt", "w");

  while (dec_num != 0) {
    if (octal_f_part > k_max_octal_fit) {
      octal_s_part += (dec_num % 8) * exp_s;
      exp_s *= 10;
    } else {
      octal_f_part += (dec_num % 8) * exp_f;
      exp_f *= 10;
    }

    dec_num /= 8;
  }

  if (octal_f_part > k_max_octal_fit) {
    fprintf(outFile, "%llu", octal_s_part);
  }

  fprintf(outFile, "%llu", octal_f_part);

  fclose(outFile);
}