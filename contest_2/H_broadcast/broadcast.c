#include <stdio.h>
#include <stdlib.h>

int main() {
  int ip[4], mask[4], address[4] = {};
  unsigned long long pc_ip_bits_count = 0;

  scanf("%d.%d.%d.%d", ip, ip + 1, ip + 2, ip + 3);
  scanf("%d.%d.%d.%d", mask, mask + 1, mask + 2, mask + 3);

  for (int i = 3; i >= 0; --i) {
    if (mask[i] == 0) {
      pc_ip_bits_count += 8;
    } else {
      for (size_t j = 0; j < 8; ++j) {
        if ((mask[i] >> j) % 2 == 0) {
          ++pc_ip_bits_count;
        }
      }

      break;
    }
  }

  for (int i = 3; i >= 0; --i) {
    if (pc_ip_bits_count > 7) {
      address[i] = 255;
      pc_ip_bits_count -= 8;
    } else if (pc_ip_bits_count > 0) {
      for (size_t j = 0; j < 8; ++j) {
        if (pc_ip_bits_count > 0) {
          address[i] += 1 << j;
          --pc_ip_bits_count;
        } else {
          address[i] += ((ip[i] >> j) % 2) << j;
        }
      }
    } else {
      address[i] = ip[i];
    }
  }

  printf("%d.%d.%d.%d", address[0], address[1], address[2], address[3]);
}