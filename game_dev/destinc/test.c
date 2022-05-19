#include <stdio.h>

int main() {

  for (int i = 2; i < 22; i++) {
    printf("(%d - 10) / 2 = %d\n", i, (i - 10) / 2);
    printf("(float) (%d - 10) / 2 = %f\n", i, ( (float) (i - 10)) / 2);
  }

  return 0;
}

