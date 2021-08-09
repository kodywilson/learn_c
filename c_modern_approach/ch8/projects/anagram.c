// check if words are anagrams
#include <stdio.h>

int main()
{
  char chr;
  int letters[26] = {0};

  printf("Enter first word: ");
  do
  {
    chr = getchar();
    if (chr != '\n')
      letters[chr - 'a']++;
  }
  while (chr != '\n');

  printf("Enter second word: ");
  do
  {
    chr = getchar();
    if (chr != '\n')
      letters[chr - 'a']--;
  }
  while (chr != '\n');

  for (int i = 0; i < 26; i++)
  {
    if (letters[i] > 0)
    {
      printf("The words are not anagrams.\n");
      break;
    }
    else if (i == 25 && letters[i] == 0)
      printf("The words are anagrams.\n");
  }


  return 0;
}

