#include <stdio.h>

// tests if number is even
int is_even(int i) {
  return (i % 2 == 0);
}

int main() {
  int num;

  // Tell user if number is even or odd
  puts("Enter a number (0 to quit)");

  do {
    scanf("%d", &num);

    if (is_even(num)) printf("%d is even\n", num);
    else printf("%d is odd\n", num);
  } while (num != 0);

  return 0;
}
