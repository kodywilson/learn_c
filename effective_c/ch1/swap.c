#include <stdio.h>

// prototypes
void swap(int *, int *);

int main(void) {
  int a = 24;
  int b = 17;

  printf("original values:  a = %d  b = %d\n", a, b);
  swap(&a, &b);
  printf("swapped values: a = %d, b = %d\n", a, b);

  return 0;
}

void swap(int *pa, int *pb) {
  int t = *pa;
  *pa = *pb;
  *pb = t;
}

