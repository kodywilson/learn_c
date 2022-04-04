#include <stdio.h>

int minimum(int a, int b) {
  if (a > b) return b;
  return a;
}

int main() {
  int a = 1;
  int b = 2;

  printf("a is %d\n", a);
  printf("b is %d\n", b);

  printf("The minimum is %d\n", minimum(a, b));

  return 0;
}
