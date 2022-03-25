#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 8

void showfile(FILE *pfile) {
  char buf[BUFSIZE];
  int len;

  while (!feof(pfile)) {
    len = fread(buf, sizeof(char), BUFSIZE, pfile);

    fwrite(buf, sizeof(char), len, stdout);
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
