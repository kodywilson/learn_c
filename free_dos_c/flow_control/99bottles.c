#include <stdio.h>

int main() {
  int bottles;

  for (bottles = 99; bottles > 0; bottles--) {
    printf("%d bottles of beer on the wall, %d bottles of beer, ", bottles, bottles);
    printf("take one down, pass it around, %d bottles of beer on the wall.", bottles - 1);
    printf("\n");
  }

  return 0;
}

