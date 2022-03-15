#include <stdio.h>

int main() {

  int numlist[10];
  int tenlist[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // print contents of tenlist
  for (int i = 0; i < 10; i++) {
    numlist[i] = tenlist[i];
    printf("numlist[%d] = %d\n", i, numlist[i]);
  }

  return 0;
}
