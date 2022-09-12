#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char first_bin[1001];
  char second_bin[1001];
  short result[1002] = {};

  scanf("%s%s", first_bin, second_bin);

  int first_offset = 0, second_offset = 0;
  int first_len = strlen(first_bin) - 1;
  int second_len = strlen(second_bin) - 1;

  while(first_bin[first_offset] == '0') {
    ++first_offset;
  }
  while(second_bin[second_offset] == '0') {
    ++second_offset;
  }

  size_t i;
  short shift = 0;
  for (i = 0; first_len >= first_offset || second_len >= second_offset; ++i, --first_len, --second_len) {
    if (first_len < first_offset) {
      result[i] = second_bin[second_len] + shift - 48;
    } else if (second_len < second_offset) {
      result[i] = first_bin[first_len] + shift - 48;
    } else {
      result[i] = first_bin[first_len] + second_bin[second_len] + shift - 96;
    }

    shift = result[i] / 2;
    result[i] %= 2;
  }

  if (shift != 0 || i == 0) {
    result[i] = shift;
  } else {
    --i;
  }

  while (i > 0) {
    printf("%d", result[i]);
    --i;
  }

  printf("%d", result[0]);
}