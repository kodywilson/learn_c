#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(0));

  for (int i = 0; i < 5; i++) printf("Random number is %d\n", rand());

  printf("The square root of %d is %lf\n", 49, sqrt(49));

  return 0;
}

