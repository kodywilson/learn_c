#include <stdio.h>

int main(void)
{
  int i = 1;
  
  // ex1
  while (i <= 128)
  {
    printf("%d ", i);
    i *= 2;
  }
  printf("\n");

  // ex2
  i = 9384;
  do
  {
    printf("%d ", i);
    i /= 10;
  }
  while (i > 0);
  printf("\n");


  return 0;
}

