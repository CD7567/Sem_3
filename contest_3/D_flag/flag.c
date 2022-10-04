#include <stdio.h>

#ifndef REGISTERS
#define REGISTERS 4
#endif

int main() {
  unsigned char regs[4] = {};
  int com, lhs, rhs, flag = 0;

  scanf("%d", &com);

  while (com != 0) {
    if (com >> 7 & 1 && !flag) {
      scanf("%*d%*d");
      scanf("\n%d", &com);
      continue;
    }

    com &= (1 << 7) - 1;

    switch (com) {
      case 1:
        scanf("%d%d", &lhs, &rhs);

        if (lhs - 5 < REGISTERS && rhs - 5 < REGISTERS) {
          regs[lhs - 5] += regs[rhs - 5];
          flag = regs[lhs - 5] == 0;
        } else {
          com = 0;
          printf("\n%d", -1);
          continue;
        }
        break;

      case 2:
        scanf("%d%d", &lhs, &rhs);

        if (lhs - 5 < REGISTERS && rhs - 5 < REGISTERS) {
          regs[lhs - 5] -= regs[rhs - 5];
          flag = regs[lhs - 5] == 0;
        } else {
          com = 0;
          printf("\n%d", -1);
          continue;
        }
        break;

      case 3:
        scanf("%d%d", &lhs, &rhs);

        if (lhs - 5 < REGISTERS) {
          regs[lhs - 5] = rhs;
          flag = regs[lhs - 5] == 0;
        } else {
          com = 0;
          printf("\n%d", -1);
          continue;
        }
        break;

      case 4:
        printf("\n");

        for (size_t i = 0; i < REGISTERS; ++i) {
          printf("%d ", regs[i]);
        }
        break;
    }

    scanf("\n%d", &com);
  }
}