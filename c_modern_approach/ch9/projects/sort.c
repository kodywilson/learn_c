#include <stdio.h>

void selection_sort(int n, a[n]);

int main(void)
{
  int n;

  printf("How many numbers would you like to sort? ");
  scanf("%d", &n);

  int a[n];

  printf("Enter %d numbers: ", n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  selection_sort();

  printf("Here are the %d numbers sorted least to greatest: ", n);
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);

  return 0;
}

int selection_sort(int n, a[n])
{
  int big = 0, position = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] > big)
    {
      big = a[i];
      position = i;
    }
  }
  a[position] = a[n - 1];
  a[n - 1] = big;
  return n - 1 < 2 ? 0 : selection_sort(n - 1, a[n]);
}

