#include <stdio.h>

int main(void)
{
  int answer, x;
  printf("Enter a value for x: ");
  scanf("%d", &x);
  answer = (3 * x * x * x * x * x) + (2 * x * x * x * x) - (5 * x * x * x) - (x * x) + (7 * x) - 6;
  printf("The answer is: %d\n", answer);
  return 0;
}

