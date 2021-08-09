// Find  tile values for Scrabble game
#include <stdio.h>
#include <ctype.h>

int main()
{
  char chr;
  int value = 0;
  int values[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

  printf("Enter a word: ");
  do
  {
    chr = toupper(getchar());
    if (chr != '\0' || chr != '\n')
      value += values[chr - 'A'];
  }
  while (chr != '\n');
  printf("Scrabble value: %d\n", value);

  return 0;
}

