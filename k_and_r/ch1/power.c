#include <stdio.h>
#include <stdlib.h>

int power(int x, int y);

int main(int argc, char *argv[])
{
  printf("%d\n", power(atoi(argv[1]), atoi(argv[2])));

  return 0;
}

int power(int x, int y)
{
  int sum = 1;
  for(int i = 0; i < y; i++)
    sum *= x;
  return sum;
}

