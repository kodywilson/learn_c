#include <stdio.h>

int main() {
  int iter;
  int num;

  // Tell user if number is even or odd
  puts("Enter a number (0 to quit)");

  do {
    scanf("%d", &num);

    if (num % 2 == 0) printf("%d is even\n", num);
    else printf("%d is odd\n", num);
  } while (num != 0);

  // loop through iter from 1 to 20
  // print even for even numbers, odd for odd numbers

  for (iter = 1; iter <= 20; iter++) {
    if ( iter % 2 == 0 ) printf("%d is even\n", iter);
    if ( iter % 2 != 0 ) printf("%d is odd\n", iter);
  }

  return 0;
}
