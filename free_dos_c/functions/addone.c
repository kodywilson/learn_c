#include <stdio.h>

int addone(int i) {
  int n;

  n = i++;
  printf("n is %d\n", n);

  return n;
}

int main() {
  addone(1);
  addone(1);
  addone(2);
  addone(3);

  return 0;
}
