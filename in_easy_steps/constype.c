#include <stdio.h>
#include <limits.h>

int main(void)
{
  enum SNOOKER
  {RED=1,YELLOW,GREEN,BROWN,BLUE,PINK,BLACK};
  enum SNOOKER pair = RED + BLACK;
  printf("Pair value: %d\n", pair);
  // Custom data type
  typedef unsigned short int USINT;
  USINT num = 16;
  printf("Unsigned short int value: %d\n", num);
  printf("Size of USINT: %ld bytes\n", sizeof(USINT));
  return 0;
}

