// reverse numbers in variable length array C99+
#include <stdio.h>

int main(void)
{
  int i, n, *p;

  printf("How many numbers do you want to reverse? ");
  scanf("%d", &n);

  int a[n];

  printf("Enter %d numbers: ", n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("In reverse order: ");
  for (p = a + n - 1; p >= a; p--)
    printf("%d ", *p);
  printf("\n");

  return 0;
}

