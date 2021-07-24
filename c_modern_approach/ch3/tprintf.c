// See various printf formats

#include <stdio.h>

int main(void)
{
  int i;
//  float x;

  i = 40;
//  x = 839.21f;
  printf("|%d|%5d|%-5d\n", i , i, i);
  return 0;
}

