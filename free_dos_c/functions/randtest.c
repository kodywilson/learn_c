#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int iter;
  int randomvalue;

  // seed the random number generator

  srand(time(0));

  for (iter = 0; iter < 20; iter++) {
    randomvalue = (rand() % 20) + 1;
    printf("%d\n", randomvalue);
  }

  return 0;
}
