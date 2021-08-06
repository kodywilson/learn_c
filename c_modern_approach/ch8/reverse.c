// reverse numbers in array
#include <stdio.h>

#define N 10 // array size

int main(void)
{
  int a[N], i;
  print("Enter %d numbers: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  printf("In reverse order: ");
  for (i = N - 1; i >= 0; i--)
    printf("%d ", i);
  printf("\n");

  return 0;
}

