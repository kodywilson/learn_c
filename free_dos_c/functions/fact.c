#include <stdio.h>

int fact(int i);

//int factr(int i);

int main() {
  int numby = 5;

  printf("The factorial of %d is %d\n", numby, fact(numby));
  //printf("Using recursive function, the factorial of %d is %d\n", numby, factr(numby));

  return 0;
}

int fact(int i) {
  int fact = i;

  for (i = fact; i > 1; i--) fact = fact * (i - 1);

  return fact;
}
