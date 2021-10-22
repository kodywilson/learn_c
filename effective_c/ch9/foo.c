#include <stdio.h>
#include "bar.h"
#include "bar.h" // normally duplicate inclusion is not so obvious
#define FOO (1 + 1)

int main(void) {
  int i = FOO;
  int j = BAR(10);

  printf("i = %d  and  j = %d\n", i, j);

  return func();
}

