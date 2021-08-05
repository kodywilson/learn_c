#include <stdio.h>

int main(void)
{
  char chr, initial;
  int marker = 1;

  printf("Enter a first and last name: ");
  do
  {
    chr = getchar();
    if (marker == 1) // store first letter
    {
      marker = 2;
      initial = chr;
    }
    else if (marker == 3 && chr != '\n') // skip rest of first name then print last name
      printf("%c", chr);

    // find spaces and the newline to complete the transformation
    if (chr == ' ')
      marker = 3;
    else if (chr == '\n')
      printf(", %c.", initial);
  }
  while (chr != '\n');
  printf("\n");

  return 0;

}

