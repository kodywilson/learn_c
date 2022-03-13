#include <stdio.h>

int sequence(int start, int stop) {
  
  for (int i = start; i <= stop; i++) printf("%d ", i);
  printf("\n");

  return 0;
}

int main() {

  for (int i = 1; i <= 7; i++) sequence(i, i + 10);

  return 0;
}
