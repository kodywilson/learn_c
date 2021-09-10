#include <stdio.h>

int main(void)
{
  printf("%d\n", getchar() != EOF);
  printf("EOF is %d\n", EOF);

  return 0;
}

