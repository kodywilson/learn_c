#include <stdio.h>

int isodd(int a) {
  if (a % 2 != 0) return 1;
  return 0;
}

int main() {
  int a = 3, b = 16, c = 33, d = 44;

  puts("1 = true, 0 = false");

  printf("%d is odd?  %d\n", a, isodd(a));

  return 0;
}
