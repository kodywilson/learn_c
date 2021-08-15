// check if words are anagrams
#include <stdio.h>
#include <stdbool.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main()
{
  int counts1[26] = {0}, counts2[26] = {0};

  printf("Enter first word: ");
  read_word(counts1);
  printf("Enter second word: ");
  read_word(counts2);

  equal_array(counts1, counts2) == true ? printf("Anagrams\n") : printf("Not anagrams\n");

  return 0;
}

void read_word(int counts[26])
{
  char chr;

  do
  {
    chr = getchar();
    if (chr != '\n')
      counts[chr - 'a']++;
  }
  while (chr != '\n');
}

bool equal_array(int counts1[26], int counts2[26])
{
  for (int i = 0; i < 26; i++)
    if (counts1[i] != counts2[i])
      return false;
  return true;
}

