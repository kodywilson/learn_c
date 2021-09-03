#include <stdio.h>

#define TAB 4 // replace each tab with 4 spaces

int main(int argc, char *argv[])
{
  FILE *fp;
  int c;

  fp = fopen(argv[1], "r");
  while ((c = fgetc(fp)) != EOF) {
    if (c == '\t')
      for (int i = 0; i < TAB; i++)
        printf(" ");
    else
      printf("%c", c);
  }

  fclose(fp);

  return 0;
}

