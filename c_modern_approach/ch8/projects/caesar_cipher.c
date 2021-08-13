#include <stdio.h>

int main(void)
{
  char chr, punc_mark, sentence[128];
  int i, sequence = 0, shift = 0;

  // ask user for a sentence and feed into array
  printf("Enter message to be encrypted: ");
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

  // ask for shift amount
  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift);

  // print enctryped message
  for (i = 0; i < sequence; i++)
  {
    if (sentence[i] == ' ' || sentence[i] == ',')
      printf("%c", sentence[i]);
    else if (sentence[i] > 64 && sentence[i] < 91)
      printf("%c", ((sentence[i] - 'A') + shift) % 26 + 'A');
    else if (sentence[i] > 96 && sentence[i] < 123)
      printf("%c", ((sentence[i] - 'a') + shift) % 26 + 'a');
  }
  printf("%c\n", punc_mark); // add on the punctuation mark

  return 0;
}

