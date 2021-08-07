#include <stdio.h>
#include <ctype.h>

int main(void)
{
  char chr;
  int count = 0;

  printf("Enter a sentence: ");
  do
  {
    chr = toupper(getchar());
    switch (chr)
    {
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U': count++; break;
    }
  }
  while (chr != '\n');

  printf("Your sentence contains %d vowels.\n", count);

  return 0;
}

