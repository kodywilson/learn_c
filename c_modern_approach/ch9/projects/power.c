#include <stdio.h>

int power(int n, int pow);

int main(void)
{
  int n, pow;
  printf("Enter a number and power to calculate (3 2): ");
  scanf("%d %d", &n, &pow);

  printf("%d to the power of %d is %d\n", n, pow, power(n, pow));

  return 0;
}

int power(int n, int pow)
{
  if (pow == 0)
    return 1;
  else if (pow % 2 == 0)
    return power(n, pow/2) * power(n, pow/2);
  else
    return n*power(n, pow/2) * power(n, pow/2);
}

