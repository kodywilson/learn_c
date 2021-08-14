#include <stdio.h>

int main(void)
{
  int n;

  printf("How many numbers would you like to sort? ");
  scanf("%d", &n);

  int a[n];

  printf("Enter %d numbers: ", n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  return 0;
}

