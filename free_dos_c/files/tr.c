#include <stdio.h>

int trch(FILE *in, FILE *out, char from, char to) {
  int ch;
  int nchanges = 0;

  while ((ch = fgetc(in)) != EOF) {
    if (ch == from) {
      fputc(to, out);
      nchanges++;
    }
    else fputc(ch, out);
  }

  return nchanges;
}

int main(int argc, char **argv) {
  char from, to;

  if (argc != 3) {
    fprintf(stderr, "Incorrect command line.\n");
    fprintf(stderr, "Usage: %s c1 c2\n", argv[0]);
    return 1;
  }

  from = argv[1][0];
  to = argv[2][0];

  trch(stdin, stdout, from, to);

  return 0;
}
