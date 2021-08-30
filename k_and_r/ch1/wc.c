#include <stdio.h>

#define IN  1 // inside a word
#define OUT 0 // outside a word

int main(int argc, char *argv[])
{
  FILE *fp;
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  fp = fopen(argv[1], "r");
  while ((c = fgetc(fp)) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  fclose(fp);

  printf("Lines: %d  Characters: %d  Words: %d\n", nl, nw, nc);

  return 0;
}

