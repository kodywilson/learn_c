#include <stdio.h>

int isodd(int a) {
  return (a & 1);
}

int main() {
  int numbers[] = {3,16,33,448762};

  for (int i = 0; i < 4; i++) {
    if (isodd(numbers[i])) printf("%d is odd!\n", numbers[i]);
    else printf("%d is even!\n", numbers[i]);
  }

  return 0;
}
