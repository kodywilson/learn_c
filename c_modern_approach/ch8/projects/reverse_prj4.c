// reverse numbers in array
#include <stdio.h>

#define N 5
#define SIZE (int) (sizeof(a) / sizeof(a[0])) // array size

int main(void)
{
  int a[N], i;
  printf("Enter %d numbers: ", SIZE);
  for (i = 0; i < SIZE; i++)
    scanf("%d", &a[i]);

  printf("In reverse order: ");
  for (i = SIZE - 1; i >= 0; i--)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}

