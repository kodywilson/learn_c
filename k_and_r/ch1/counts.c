// count digits, white space, others
#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int c, i, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0; // initialize counts
  for (i = 0; i < 10; i++) // initialize array
    ndigit[i] = 0;

  fp = fopen(argv[1], "r");
  while ((c = fgetc(fp)) != EOF) {
    if (c >= '0' && c <= '9')
      ++ndigit[c-'0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;
  }
  fclose(fp);

  printf("digits =");
  for (i = 0; i < 10; i++)
    printf(" %d", ndigit[i]);
  printf(", white space = %d, other = %d\n", nwhite, nother);

  return 0;
}

