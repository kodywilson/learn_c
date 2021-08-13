#include <stdio.h>

int check(int x, int y, int n); // ex2
int gcd(int m, int n); // ex3
int day_of_year(int month, int day, int year); // ex4
int num_digits(int n);
int digit(int n, int k);

int main(void)
{
  int x = 15, y = 25, n = 100, month = 6, day = 24, year = 2020;

  if (check(x, y, n) == 1 )
    printf("Both %d and %d are between 0 and %d\n", x, y, n);
  else
    printf("Both %d and %d are not between 0 and %d\n", x, y, n);

  printf("The GCD of %d and %d is %d\n", x, y, gcd(x, y)); // ex3

  printf("%d/%d/%d is the %d day of the year\n", month, day, year, day_of_year(month, day, year)); // ex4

  printf("There are %d digits in %d\n", num_digits(year), year); // ex5

  printf("%d is digit #%d in %d\n", digit(year, 3), 3, year); // ex6

  return 0;
}

int check(int x, int y, int n)
{
  return ( x >= 0 && y >= 0 && x <= n - 1 && y <= n - 1);
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

int day_of_year(int month, int day, int year)
{
  int days = 0;
  int months[12] = {31, 24, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  for (int i = 0; i < month - 1; i++)
    days += months[i];
  // handle leap years
  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    days++;

  return days + day;
}

int num_digits(int n)
{
  int count = 1;
  while (n != 0)
  {
    n /= 10;
    if (n != 0)
      count++;
  }

  return count;
}

int digit(int n, int k)
{
  int digit, num;
  num = num_digits(n);
  if (k > num)
    return 0;
  for (int i = 0; i < k; i++)
  {
    digit = n % 10;
    n /= 10;
  }

  return digit;
}

