#include <stdio.h>
#include "bar.h"
#include "bar.h" // normally duplicate inclusion is not so obvious
#define FOO (35 + 35)
#define ALF 26

int main(void) {
  int i = FOO;
  int j = BAR_sq(100);
  int k = BAR_sq(3 + 3);
  int a[ALF];

  char c;

  printf("i = %d  and  j = %d  and  k = %d\n", i, j, k);
  printf("The value of func is %d\n", func());
  printf("k * 3 = %d\n", BAR_triple(k));

  for (int m = 1; m < ALF + 1; m++)
    a[m - 1] = BAR_sq(m);

  printf("The first letter of the alphabet is %c\n", letter());

  c = i + '0';
  printf("We saw above that i is %d. That would be %c on the alphabet\n", i, c);
  printf("You can add %d to %c to get %c\n", 3, c, (char) c + 3);
  printf("We can subtract too. %c - %d gives %c\n", c, 5, (char) c - 5);
  
  for (int n = 0; n < ALF; n++)
    printf("%d ", a[n] * a[n]);
  printf("\n");

  return 1;
}

