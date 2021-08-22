#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void)
{
  int a[10] = { 34, 424, 7777, 22, 9, 345, 8875, 234, 42, 9701 };
  int largest = 0, second_largest = 0;

  find_two_largest(a, 10, &largest, &second_largest);

  printf("%d and %d are the biggest numbers\n", largest, second_largest);
}

void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
  int second;
  for (int i = 0; i < n; i++)
  {
    if (a[i] > *largest)
    {
      second = *largest;
      *largest = a[i];
      if (second > *second_largest)
        *second_largest = second;
    }
  }
}

