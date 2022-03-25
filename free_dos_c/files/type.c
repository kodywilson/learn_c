#include <stdio.h>
#include <stdlib.h>

void showfile(FILE *pfile) {
  int ch;

  while ( (ch = fgetc(pfile)) != EOF ) {
    putchar(ch);
  }
}

int main(int argc, char **argv) {
  int exitcode, i;
  FILE *pfile;

  // scan command line, print file contents

  for (i = 1; i < argc; i++) {
    pfile = fopen(argv[i], "r");

    if (pfile != NULL) {
      showfile(pfile);
      fclose(pfile);
      exitcode = 0;
    }
    else {
      fprintf(stderr, "could not open file: %s\n", argv[i]);
      exitcode = 1;
    }
  }

  if (argc == 1) {
    showfile(stdin);
    exitcode = 0;
  }

  exit(exitcode);
}
