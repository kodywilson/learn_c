// Find phone number from text version
#include <stdio.h>

int main()
{
  char chr;

  printf("Enter a phone number: ");
  do
  {
    chr = getchar();
    if (chr == 'A' || chr == 'B' || chr == 'C')
      putchar('2');
    else if (chr == 'D' || chr == 'E' || chr == 'F')
      putchar('3');
    else if (chr == 'G' || chr == 'H' || chr == 'I')
      putchar('4');
    else if (chr == 'J' || chr == 'K' || chr == 'L')
      putchar('5');
    else if (chr == 'M' || chr == 'N' || chr == 'O')
      putchar('6');
    else if (chr == 'P' || chr == 'R' || chr == 'S')
      putchar('7');
    else if (chr == 'T' || chr == 'U' || chr == 'V')
      putchar('8');
    else if (chr == 'W' || chr == 'X' || chr == 'Y')
      putchar('9');
    else
      putchar(chr);
  }
  while (chr != '\n');
  printf("\n");

  return 0;
}

