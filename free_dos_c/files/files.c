#include <stdio.h>

int main() {
  char filename[] = "test.txt";
  FILE *fileptr;

  // try to open the file

  fileptr = fopen(filename, "r");

  if (fileptr == NULL) {
    puts("Cannot open the file");
    return 1;
  }

  puts("The file is open");

  // close the file
  fclose(fileptr);

  puts("The file is closed");

  return 0;

}
