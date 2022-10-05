#include <stdlib.h>

char* whatisyourname() {
  char* name = malloc(257 * sizeof(char));

  for (size_t i = 0; i < 256; ++i) {
    name[i] = 's';
  }

  name[256] = '\0';
  return name;
}