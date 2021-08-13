#include <stdio.h>

int summer(int n, int a[n]);

int main(void)
{
  int n;

  printf("How many numbers to sum? ");
  scanf("%d", &n);

  int a[n];

  printf("Enter %d numbers: ", n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("The total is: %d\n", summer(n, a));

  return 0;
}

int summer(int n, int a[n])
{
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += a[i];

  return sum;
}

