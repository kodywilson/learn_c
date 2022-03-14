#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int iter;
  int randomvalue;
  int hist[20];

  for (int i = 0; i < 20; i++) hist[i] = 0;

  // seed the random number generator

  srand(time(0));

  for (iter = 0; iter < 5000; iter++) {
    randomvalue = rand() % 20;
    hist[randomvalue] = hist[randomvalue] + 1;
    //printf("%d\n", randomvalue);
  }

  for (iter = 0; iter < 20; iter++) printf("[%d]: %d\n", iter, hist[iter]);
  printf("\n");

  return 0;
}
