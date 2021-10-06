#include <stdio.h>

#define A_SIZE 1000 // array size

// prototypes
int binsearch(int x, int v[], int n);

int main(void)
{
  int v[A_SIZE], x = 751, y; // setting x to 501 creates infinite loop, figure out why

  for (int i = 1; i <= A_SIZE; i++) // initialize array
    v[i - 1] = i;

  if ( (y = binsearch(x, v, A_SIZE)) >= 0 )
    printf("%d found at position %d.\n", x, y);
  else
    printf("%d not found.\n", x);

  return 0;
}

int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0; // array position, low
  high = n - 1; // array position, high
  while (low <= high) {
    printf("Low: %d  High: %d\n", low, high);
    printf("Val at low: %d  Val at high: %d\n", v[low], v[high]);
    mid = (low + high)/2;
    printf("mid: %d  x: %d\n", mid, x);
    if (x < v[mid] && x != v[low])
      high = mid + 1;
    else if (x > v[mid] && x != v[low])
      low = mid + 1;
    else if (x == v[low])
      return low;
    else
      return mid;
  }
  return -1; // no match
}

