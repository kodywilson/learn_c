#include <stdio.h>

void print_count(int n)
{
  printf("T minus %d and counting\n", n);
}

int main(void)
{
  int i;
  printf("Enter a number: ");
  scanf("%d", &i);

  for (int j = i;j > 0;j--)
    print_count(j);

  return 0;
}

