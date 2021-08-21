#include <stdio.h>

#define N 10
// prototypes
void max_min(int a[], int n, int *max, int *min);

int main(void)
{
  int b[10] = { 45, 87, 34, 675, 3, 54, 88, 101, 434, 201 };
  int big, small;

  max_min(b, N, &big, &small); // send references so we can update

  printf("The largest value is %d and the smallest is %d\n", big, small);

  return 0;
}

void max_min(int a[], int n, int *max, int *min)
{
  *max = *min = a[0];
  for (int i = 0; i < n; i++)
  {
    if (a[i] > *max)
      *max = a[i]; 
    if (a[i] < *min)
      *min = a[i];
  }
}

