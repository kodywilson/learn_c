#include <stdio.h>

int main(void)
{
  // ex 4
  int i = 1, j = 1;
  printf("%d\n", (i > j) - (i < j));
  // ex 7
  i = -17;
  printf("%d\n", i >= 0 ? i : -i);
  // ex 10
  i = 1;
  switch (i % 3) {
    case 0: printf("zero\n");
    case 1: printf("one\n");
    case 2: printf("two\n");
  }

  return 0;
}

