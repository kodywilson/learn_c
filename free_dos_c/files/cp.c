#include <stdio.h>

void copyfile(FILE *from, FILE *to) {
  int ch;

  while ( (ch = fgetc(from)) != EOF  ) {
    fputc(ch, to);
  }
}

int main(int argc, char **argv) {
  FILE *src;
  FILE *dst;

  // check for valid arguments
  
  if (argc != 3) {
    fprintf(stderr, "Wrong number of command line arguments\n");
    fprintf(stderr, "usage: cp source destination\n");
    return 1;
  }

  // open the files

  src = fopen(argv[1], "r");

  if (src == NULL) {
    fprintf(stderr, "Cannot open file %s for reading\n", argv[1]);
    return 1;
  }

  dst = fopen(argv[2], "w");

  if (dst == NULL) {
    fprintf(stderr, "Cannot open file %s for writing\n", argv[2]);
    fclose(src);
    return 2;
  }
  
  // copy the file
  copyfile(src, dst);

  // close files
  fclose(dst);
  fclose(src);

  return 0;
}
