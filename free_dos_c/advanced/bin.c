// show numbers in binary form
#include <stdio.h>

void showbin(int num) {
  int shift;
  int mask;

  for (shift = 7; shift >= 0; shift--) {
    mask = 1 << shift;
    if (num & mask) putchar('1');
    else putchar('0');
  }

  putchar('\n');
}

int main() {
  for (int i = 0; i <= 8; i++) {
    printf("%d\n", i);
    showbin(i);
  }

  return 0;
}
