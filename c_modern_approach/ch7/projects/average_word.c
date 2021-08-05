#include <stdio.h>

int main(void)
{
  char chr;
  int letters = 0, words = 1;

  printf("Enter a sentence: ");
  do
  {
    chr = getchar();
    if (chr != ' ' && chr != '\n')
      letters++;
    if (chr == ' ')
      words++;
  }
  while (chr != '\n');

  printf("There are %d letters and %d words in that sentence.\n", letters, words);
  printf("Average word length: %.1f\n", (float) letters / words);

  return 0;
}

