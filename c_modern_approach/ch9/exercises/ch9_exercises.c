#include <stdio.h>

int check(int x, int y, int n); // ex2
int gcd(int m, int n); // ex3
int day_of_year(int month, int day, int year); // ex4
int num_digits(int n); // ex5
int digit(int n, int k); // ex6
int largest(int n, int a[n]); // ex10
int average(int n, int a[n]); // ex10
int positives(int n, int a[n]); // ex10
float compute_GPA(int n, char grades[]); // ex11
double inner_product(int n, double a[], double b[]); // ex12

int main(void)
{
  int x = 15, y = 25, n = 100, month = 6, day = 24, year = 2020;
  int a[] = {1, 100, 1000, 50, 673, 445};
  double ad[] = {1, 100, 1000, 50, 673, 445};
  double bd[] = {5, 200, 2000, 70, 773, 145};
  char grades[] = {'A', 'B', 'C', 'C', 'B', 'A'};

  if (check(x, y, n) == 1 )
    printf("Both %d and %d are between 0 and %d\n", x, y, n);
  else
    printf("Both %d and %d are not between 0 and %d\n", x, y, n);

  printf("The GCD of %d and %d is %d\n", x, y, gcd(x, y)); // ex3

  printf("%d/%d/%d is the %d day of the year\n", month, day, year, day_of_year(month, day, year)); // ex4

  printf("There are %d digits in %d\n", num_digits(year), year); // ex5

  printf("%d is digit #%d in %d\n", digit(year, 3), 3, year); // ex6

  printf("The largest element is %d\n", largest(month, a)); // ex10

  printf("The average value of all elements is %d\n", average(month, a)); // ex10

  printf("Number of positive elements: %d\n", positives(month, a)); // ex10

  printf("Average grade is %f\n", compute_GPA(month, grades)); // ex11

  printf("Double sum is %f\n", inner_product(month, ad, bd)); // ex12

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
  for (int i = 1; i < k; i++)
    n /= 10;

  return n % 10;
}

int largest(int n, int a[n])
{
  int big = 0;
  for (int i = 0; i < n; i++)
    if (a[i] > big)
      big = a[i];

  return big;
}

int average(int n, int a[n])
{
  int sum;
  for (int i = 0; i < n; i++)
    sum += a[i];

  return sum / n;
}

int positives(int n, int a[n])
{
  int count = 0;
  for (int i = 0; i < n; i++)
    if (a[i] > 0)
      count++;

  return count;
}

float compute_GPA(int n, char grades[])
{
  float total = .0f;
  for (int i = 0; i < n; i++)
  {
    switch (grades[i])
    {
      case 'A': total += 4.0f; break;
      case 'B': total += 3.0f; break;
      case 'C': total += 2.0f; break;
      case 'D': total += 1.0f; break;
      case 'F': total += 0.0f; break;
    }
  }

  return total / n;
}

double inner_product(int n, double a[], double b[]) // ex12
{
  double sum;
  for (int i = 0; i < n; i++)
    sum += a[i] * b[i];

  return sum;
}
