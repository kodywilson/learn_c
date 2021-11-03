#include <stdio.h>
#include "bar.h"
#include "bar.h" // normally duplicate inclusion is not so obvious
#define FOO (6 + 6)

int main(void) {
  int i = FOO;
  int j = BAR_sq(100);
  int k = BAR_sq(3 + 3);
  int a[26];

  printf("i = %d  and  j = %d  and  k = %d\n", i, j, k);
  printf("The value of func is %d\n", func());
  printf("k * 3 = %d\n", BAR_triple(k));

  for (int m = 1; m < 11; m++)
    a[m - 1] = BAR_sq(m);

  printf("The first letter of the alphabet is %c\n", letter());
  printf("We saw above that i is %d. That would be %c on the alphabet\n", i, 'A' + a[i - 1]);


  return 1;
}

