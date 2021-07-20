#include <stdio.h>

void meow(int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("Meeeooow\n");
  }
}

int main(void)
{
  meow(3);
}

