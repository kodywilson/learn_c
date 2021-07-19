#include <stdio.h>

int main(void)
{
  char letter;
  int num1, num2;
  // Get info from user
  printf("Enter any one keyboard character: ");
  scanf("%c", &letter);
  printf("Enter two numbers separated by a space: ");
  scanf("%d %d", &num1, &num2);
  printf("Numbers input: %d and %d\n", num1, num2);
  printf("Letter input: %c", letter);
  printf(" Stored at %p\n", &letter);
  return 0;
}

