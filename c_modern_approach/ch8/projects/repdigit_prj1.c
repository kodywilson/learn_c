// find numbers with duplicate digits
#include <stdio.h>
#include <stdbool.h>

#define N 10

int main(void)
{
  bool digit_seen[N] = {false};
  bool digit_repeat[N] = {false};
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0)
  {
    digit = n % 10;
    if (digit_seen[digit])
      digit_repeat[digit] = true;
    digit_seen[digit] = true;
    n /= 10;
  }
  printf("Repeated digit(s): "); // find and print repeats
  for (int i = 0; i < 10; i++)
  {
    if (digit_repeat[i])
      printf("%d", i);
  }
  printf("\n");

  return 0;
}

