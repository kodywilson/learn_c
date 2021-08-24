// reverse numbers in variable length array C99+
#include <stdio.h>

int main(void)
{
  int n, *p;

  printf("How many numbers do you want to reverse? ");
  scanf("%d", &n);

  int a[n];

  printf("Enter %d numbers: ", n);
  for (p = a; p < a + n; p++)
    scanf("%d", p);

  printf("In reverse order: ");
  for (p = a + n - 1; p >= a; p--)
    printf("%d ", *p);
  printf("\n");

  return 0;
}

