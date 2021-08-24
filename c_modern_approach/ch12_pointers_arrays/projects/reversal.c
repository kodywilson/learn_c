#include <stdio.h>

int main(void)
{
  char chr = 'A', message[256], *ptr = message;

  printf("Enter a message: ");
  do
  {
    chr = getchar();
    if (chr == '\n')
      break;
    *ptr++ = chr;
  }
  while (chr != '\n');

  for (; ptr >= message; ptr--)
    printf("%c", *ptr);
  printf("\n");

  return 0;
}

