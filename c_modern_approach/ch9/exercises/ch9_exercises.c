#include <stdio.h>

int check(int x, int y, int n); // ex2
int gcd(int m, int n); // ex3

int main(void)
{
  int x = 15, y = 25, n = 100;

  if (check(x, y, n) == 1 )
    printf("Both %d and %d are between 0 and %d\n", x, y, n);
  else
    printf("Both %d and %d are not between 0 and %d\n", x, y, n);

  printf("The GCD of %d and %d is %d\n", x, y, gcd(x, y));

  return 0;
}

int check(int x, int y, int n)
{
  if ( x >= 0 && y >= 0 && x <= n - 1 && y <= n - 1)
    return 1;
  else
    return 0;
}

int gcd(int m, int n)
{
  int a, b, c;
  if (m >= n) // set a to largest number
  {
    a = m;
    b = n;
  }
  else
  {
    a = n;
    b = m;
  }
  // Find the greatest common denominator
  while (a != 0 || b != 0 || c != 0)
  {
    c = a % b;
    a = b;
    if (c == 0)
      break;
    b = c;
  }

  return a;
}

