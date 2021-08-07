#include <stdio.h>

int main(void)
{
  // variables
  int x;

  printf("This program prints a table of squares.\n");
  printf("Enter a number of entries in table: ");
  scanf("%d", &x);

  // print out square table up to x
  for (int i = 1; i <= x; i++)
  {
    printf("\t%-10d%-10d\n", i, i * i);
  }

  return 0;
}

