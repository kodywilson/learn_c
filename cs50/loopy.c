#include <stdio.h>

int main(void)
{
  int i = 0;
  while (i < 10)
  {
    printf("%i ", i);
    i++;
  }
  printf("\n");

  for (int x = 50; x > 0; x--)
  {
    printf("%i ", x);
  }
  printf("\n");
}

