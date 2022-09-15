#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char* string = argv[1];
  char* substr = argv[2];
  size_t candidate_pos;
  size_t len_str, len_sub;

  len_str = strlen(string);
  len_sub = strlen(substr);

  for (size_t it = 0, sub_it = 0; it < len_str; ++it) {
    if (sub_it < len_sub) {
      if (string[it] == substr[sub_it]) {
	if (sub_it == 0) {
	  candidate_pos = it;
	}

	++sub_it;
      } else {
        sub_it = 0;
      }
    } else {
      printf("%lu\n", candidate_pos);
      sub_it = 0;      
    }
  }  
}
