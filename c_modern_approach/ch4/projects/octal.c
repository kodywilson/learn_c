#include <stdio.h>

int main(void)
{
  int x = 1953;

  printf("In octal, your number is: %d%d%d%d\n", (x / 8 / 8 / 8) % 8, (x / 8 / 8) % 8, (x / 8) % 8, x % 8);
}

