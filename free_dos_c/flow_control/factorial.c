#include <stdio.h>

int main() {
  int fact, iter, number;

  puts("Please enter a number:");
  scanf("%d", &number);

  fact = iter = number;
  while (iter > 1) {
    fact = fact * (iter - 1);
    iter--;
  }

  if (number <= 1) fact = 1;

  printf("The factorial of %d is %d\n", number, fact);

  return 0;
}
