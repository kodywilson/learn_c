#include <stdio.h>
#include "bar.h"
#include "bar.h" // normally duplicate inclusion is not so obvious
#define FOO (1 + 1)

int main(void) {
  int i = FOO;
  int j = BAR_sq(10);
  int k = BAR_sq(3 + 3);

  printf("i = %d  and  j = %d  and  k = %d\n", i, j, k);
  printf("The value of func is %d\n", func());

  return 1;
}

