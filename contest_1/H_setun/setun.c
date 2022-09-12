#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char first_tr[1001];
  char second_tr[1001];
  short result[1002] = {};

  scanf("%s%s", first_tr, second_tr);

  int first_offset = 0, second_offset = 0;
  int first_len = strlen(first_tr) - 1;
  int second_len = strlen(second_tr) - 1;

  while(first_tr[first_offset] == '0') {
    ++first_offset;
  }
  while(second_tr[second_offset] == '0') {
    ++second_offset;
  }
  for (size_t i = 0; i <= first_len; ++i) {
    if (first_tr[i] == '$') {
      first_tr[i] = 47;
    }
  }
  for (size_t i = 0; i <= second_len; ++i) {
    if (second_tr[i] == '$') {
      second_tr[i] = 47;
    }
  }

  int i;
  short shift = 0;
  char printed = 0;
  for (i = 0; first_len >= first_offset || second_len >= second_offset; ++i, --first_len, --second_len) {
    if (first_len < first_offset) {
      result[i] = second_tr[second_len] + shift - 48;
    } else if (second_len < second_offset) {
      result[i] = first_tr[first_len] + shift - 48;
    } else {
      result[i] = first_tr[first_len] + second_tr[second_len] + shift - 96;
    }

    if (result[i] > 1) {
      result[i] = result[i] % 2 - 1;
      shift = 1;
    } else if (result[i] < -1) {
      result[i] = result[i] % 2 + 1;
      shift = -1;
    } else {
      shift = 0;
    }
  }

  if (shift != 0 || i == 0) {
    result[i] = shift;
  } else {
    --i;
  }

  while(i >= 0 && result[i] == 0) {
    --i;
  }

  while (i >= 0) {
    if (result[i] == -1) {
      printf("%c", '$');
    } else {
      printf("%d", result[i]);
    }
    printed = 1;
    --i;
  }

  if (!printed) {
    printf("%d", 0);
  }
}