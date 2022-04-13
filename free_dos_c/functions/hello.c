#include <stdio.h>

int hello() {
  puts("Hello world");
  return 0;
}

int loophello() {
  int iter;

  for (iter = 1; iter <= 3; iter++) printf("%d - Hello!\n", iter);

  return 0;
}

int main() {
  int iter;

  hello();

  for (iter = 1; iter <= 3; iter++) {
    printf("Loop %d\n", iter);
    loophello();
  }

  return 0;
}
