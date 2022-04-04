#include <stdio.h>

int minimum(int a, int b) {
  return (a < b ? a : b);
}

int main() {
  int a = 1;
  int b = 2;

  printf("a is %d\n", a);
  printf("b is %d\n", b);

  printf("The minimum is %d\n", minimum(a, b));

  return 0;
}
