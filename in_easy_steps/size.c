#include <stdio.h>

int main(void)
{
  int num = 1234567890;
  printf("Size of int data type is %ld bytes\n", sizeof(int));
  printf("Size of int variable, num, is %ld bytes\n", sizeof(num));
  printf("Size of an int arary is %ld bytes\n", sizeof(int[3]));
  struct { int score; char grade; } result;
  printf("Size of a structure is %ld bytes\n", sizeof(result));
  return 0;
}

