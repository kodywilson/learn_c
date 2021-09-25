#include <stdio.h>

// prototypes
void swap(int, int);

int main(void) {
  int a = 21;
  int b = 17;
  int c = 34;

  swap(a, b);
  printf("main: a = %d, b = %d\n", a, b);
  swap(b, c);

  return 0;
}
