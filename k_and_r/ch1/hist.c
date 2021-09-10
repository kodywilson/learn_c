#include <stdio.h>

#define ALP 26 // number of characters in alphabet
#define IN  1 // inside a word
#define OUT 0 // outside a word
#define MAX 15 // maximum word size

int main(int argc, char *argv[])
{
  FILE *fp;
  int c, letters, state;
  int letter_count[MAX];
  int alphabet[ALP];

  for (int i = 0; i < MAX; i++) // initialize letter count array
    letter_count[i] = 0;
  for (int i = 0; i < ALP; i++) // initialize alphabet count array
    alphabet[i] = 0;

  state = OUT;
  letters = 0;
  fp = fopen(argv[1], "r");
  while ((c = fgetc(fp)) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      if ( letters >= 1 ) { // store length of word and then reset letters counter
        letter_count[letters - 1]++;
        letters = 0;
      }
    }
    else
      state = IN;
    if (state == IN) {
      letters++;
      if ( c >= 65 && c <= 90 )
        alphabet[c - 'A']++;
      else if ( c >= 97 && c <= 122 )
        alphabet[c - 'a']++;
    }
  }
  fclose(fp);

  printf("# Letters\tFrequency\n"); // print histogram of word size frequency
  for (int i = 0; i < MAX; i++) {
    printf("%d\t\t", i + 1);
    for (int j = 0; j < letter_count[i]; j++)
      printf("*");
    printf("\n");
  }
  printf("\n");

  printf("Letter\tFrequency\n"); // print histogram of letter frequency
  for (int i = 0; i < ALP; i++) {
    printf("%c:\t", (char) (i + 'A'));
    for (int j = 0; j < alphabet[i]; j++)
      printf("*");
    printf("\n");
  }

  return 0;
}

