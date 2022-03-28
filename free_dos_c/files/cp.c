#include <stdio.h>

void copyfile(FILE *from, FILE *to) {
  int ch;

  while ( (ch = fgetc(from)) != EOF  ) {
    fputc(ch, to);
  }
}

int main(int argc, char **argv) {
  int i;
  FILE *fileptr;

  // loop through argv

  for (i = 1; i < argc; i++) {
    fileptr = fopen(argv[i], "r");

    if (fileptr == NULL) fprintf(stderr, "Cannot open file %s\n", argv[i]);
    else {
      copyfile(fileptr, stdout);
      fclose(fileptr);
      printf("\n");
    }
  }

  return 0;
}
