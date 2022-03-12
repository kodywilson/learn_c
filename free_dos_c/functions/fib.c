#include <stdio.h>

int fib(int i) {
  // fib(n) = fib(n-1) + fib(n-2)
  // fib(0) = 0, fib(1) = 1, fib(2) = 1
  // fib(3) = fib(2) + fib(1) = 1 + 1 = 2
  // fib(4) = 2 + 1 = 3
  // fib(5) = 3 + 2 = 5

  switch (i) {
    case 0: return 0;
    case 1: return 1;
    default: return (fib(i-1) + fib(i-2));
  }
}

int main() {
  // get Fib
  int n, result;

  puts("Enter a number to start the Fib. seq (greater than or equal to 0)");
  scanf("%d", &n);

  if ( n >= 0 ) {
    result = fib(n);
    printf("The fib of %d is %d\n", n, result);
  }
  else puts("Number must be greater than or equal to 0");

  return 0;

}
