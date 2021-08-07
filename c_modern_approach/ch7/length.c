#include <stdio.h>

int main(void)
{
  int count = 0;

  printf("Enter a message: ");
  while (getchar() != '\n')
    count++;

  printf("Your message was %d character(s) long.\n", count);

  printf("Size of int: %ld\n", sizeof(int));

  return 0;
}

