#include <stdio.h>

int main(void)
{
  // variables
  long int i = 1, x;

  printf("This program prints a table of squares.\n");
  printf("Enter a number of entries in table: ");
  scanf("%ld", &x);

  // print out square table up to x
  for (i = 1; i <= x; i++)
  {
    printf("\t%-10ld%-10ld\n", i, i * i);
  }

  return 0;
}

