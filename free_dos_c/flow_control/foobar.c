#include <stdio.h>

int main() {
  int i = 1;

  while (i <= 5) {
    printf("(while) i %d is less than or equal to 5\n", i);
    i++;
  }
  do {
    printf("(do while) i %d is less than or equal to 10\n", i);
    i++;
  }
  while (i <= 10);

  return 0;
}
