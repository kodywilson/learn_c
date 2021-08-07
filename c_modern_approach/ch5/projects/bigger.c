#include <stdio.h>

int main(void)
{
  // variables
  int a, b, c, d, largest, smallest;

  // get input from user
  printf("Enter four integers: ");
  scanf("%d%d%d%d", &a, &b, &c, &d);

  // determine largest and smallest
  if (a > b && a > c && a > d)
  {
    largest = a;
  }
  else if (a < b && a < c && a < d)
  {
    smallest = a;
  }
  if (b > a && b > c && b > d)
  {
    largest = b;
  }
  else if (b < a && b < c && b < d)
  {
    smallest = b;
  }
  if (c > a && c > b && c > d)
  {
    largest = c;
  }
  else if (c < a && c < b && c < d)
  {
    smallest = c;
  }
  if (d > a && d > b && d > c)
  {
    largest = d;
  }
  else if (d < a && d < b && d < c)
  {
    smallest = d;
  }

  // now print out the largest and the smallest of the 4 numbers
  printf("Largest: %d\n", largest);
  printf("Smallest: %d\n", smallest);

  return 0;
}

