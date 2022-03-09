#include <stdio.h>

int main() {
  int i = 1;
  int a = 2;

  if (i == 1) puts("i is equal to one");
  if (i == a) {
    puts("i is equal to a");
  } else {
    puts("i is not equal to a");
  }

  return 0;
}
