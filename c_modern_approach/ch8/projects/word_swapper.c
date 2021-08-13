#include <stdio.h>

int main(void)
{
  char chr, punc_mark, sentence[128];
  int j, i, sequence = 0, shift = 1, word = 0;

  // ask user for a sentence and feed into array
  printf("Enter a sentence: ");
  do
  {
    chr = getchar();
    if (chr == '.' || chr == '?' || chr == '!')
    {
      punc_mark = chr;
      break;
    }
    else if (chr == '\n')
      break;
    sentence[sequence] = chr;
    sequence++;
  }
  while (chr != '\n');

  // print reversal of sentence
  for (i = sequence - 1; i >= 0; i--)
  {
    word++;
    if (sentence[i] == ' ' || i == 0)
    {
      if (i == 0)
        shift = 0;
      for (j = i + shift; j <= i + word; j++)
        if (sentence[j] != ' ')
          printf("%c", sentence[j]);
      if (i > 0)
        printf(" ");
      word = 0;
    }
  }
  printf("%c\n", punc_mark); // add on the punctuation mark

  return 0;
}

