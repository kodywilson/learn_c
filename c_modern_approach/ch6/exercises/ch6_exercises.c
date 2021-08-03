#include <stdio.h>

int main(void)
{
  int i = 1, j;
  
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

  // ex3
  for (i = 5, j = i - 1; j > 0; --i, j = i - 1)
  {
    printf("%d ", i);
  }
  printf("\n");

  // ex6
  for (i = 1; i <= 128; i *= 2)
    printf("%d ", i);
  printf("\n");

  // ex7
  for (i = 9384; i > 0; i /= 10)
    printf("%d ", i);
  printf("\n");

  // ex8
  for (i = 10; i > 1; i /= 2)
    printf("%d ", i++);
  printf("\n");

  // ex9
  i = 10;
  while (i > 1)
  {
    printf("%d ", i++);
    i /= 2;
  }
  printf("\n");

  // ex10
  for (i = 1; i < 11; i++)
  {
    if (i % 2 == 0)
      continue;
    printf("%d is odd\n", i);
  }

  // now use goto in place of continue
  for (i = 1; i < 11; i++)
  {
    if (i % 2 == 0)
      goto skip;
    printf("%d is odd\n", i);
    skip: ;
  }

  return 0;
}

