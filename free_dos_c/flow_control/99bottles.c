#include <stdio.h>

int main() {
  int bottles;

  for (bottles = 99; bottles > 2; bottles--) {
    printf("%d bottles of beer on the wall, %d bottles of beer,\n", bottles, bottles);
    printf("take one down, pass it around, %d bottles of beer on the wall.\n\n", bottles - 1);
  }

  puts("2 bottles of beer on the wall, 2 bottles of beer,");
  puts("take one down, pass it around, 1 bottle of beer on the wall.");
  printf("\n");
  puts("1 bottle of beer on the wall, 1 bottle of beer,");
  puts("take one down, pass it around, no more bottles of beer on the wall.");
  printf("\n");

  return 0;
}

