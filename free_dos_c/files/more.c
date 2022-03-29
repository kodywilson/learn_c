// simple more program
#include <stdio.h>

void getenter(void) {
  int ch;

  do ch = getchar();
  while (ch != '\n');
}

int more(FILE *file, int maxlines) {
  int ch, count = 0;

  while ((ch = fgetc(file)) != EOF) {
    putchar(ch);
    if (ch == '\n') {
      count++;
      //printf("%d ", count); // DEBUG
      if (count == maxlines) {
        fprintf(stderr, "<Press Enter for more>");
        getenter();

        count = 0;
      }
    }
  }

  fprintf(stderr, "Press Enter to end>");
  getenter();

  return count;
}

int main(int argc, char **argv) {
  int i;
  FILE *fileptr;

  // check that arguments were passed
  if (argc < 2) {
    puts("No files given...");
    return 1;
  }

  // loop through argv

  for (i = 1; i < argc; i++) {
    fileptr = fopen(argv[i], "r");

    if (fileptr == NULL) fprintf(stderr, "Cannot open file %s\n", argv[i]);
    else {
      more(fileptr, 24);
      fclose(fileptr);
    }
  }

  return 0;
}
