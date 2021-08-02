#include <stdio.h>

int main(void)
{
  // variables
  int i = 1, x;

  printf("This program prints a table of squares.\n");
  printf("Enter a number of entries in table: ");
  scanf("%d", &x);

  // print out square table up to x
  while (i <= x)
  {
    printf("\t\t%d\t\t%d\n", i, i * i);
    i++;
  }

  return 0;
}

