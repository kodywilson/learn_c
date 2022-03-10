#include <stdio.h>

int main() {
  int i = 1;
  int iter;

  while (i <= 5) {
    printf("(while) i %d is less than or equal to 5\n", i);
    i++;
  }
  do {
    printf("(do while) i %d is less than or equal to 10\n", i);
    i++;
  }
  while (i <= 10);

  for (i = 0; i <= 10; i++) {
    puts("Huzzah!");
  }

  for (iter = 1; iter <= 20; iter++) {
    printf("%d ", iter);
    if ( iter % 3 == 0 ) printf("foo");
    if ( iter % 5 == 0 ) printf("bar");
    printf("\n");
  }

  return 0;
}
