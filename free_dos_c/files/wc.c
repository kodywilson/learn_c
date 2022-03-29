#include <stdio.h>

int countlines(FILE *file) {
  int ch, count = 0;

  while ((ch = fgetc(file)) != EOF) if (ch == '\n') count++;

  return count;
}

int main(int argc, char **argv) {
  int i, count = 0;
  FILE *fileptr;

  // check that arguments were passed
  if (argc < 2) {
    puts("Pass files you wish to line count");
    return 1;
  }

  // loop through argv

  for (i = 1; i < argc; i++) {
    fileptr = fopen(argv[i], "r");

    if (fileptr == NULL) fprintf(stderr, "Cannot open file %s\n", argv[i]);
    else {
      count = countlines(fileptr);
      fclose(fileptr);
      if (count > 0) printf("%d %s\n", count, argv[i]);
      else printf("%s contains no lines\n", argv[i]);
    }
  }

  return 0;
}
