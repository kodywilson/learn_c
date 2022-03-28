#include <stdio.h>

void showfile(FILE *from) {
  int ch;

  while ( (ch = fgetc(from)) != EOF  ) {
    putchar(ch);
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
      showfile(fileptr);
      fclose(fileptr);
    }
  }

  return 0;
}
