#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
  char* filename = argv[1];
  FILE* input = fopen(filename, "r");

  char buffer[2048];

  while (fread(buffer, 1, 2048, input) > 0) {
    printf("%s", buffer);
  }
}
