#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_copy(char *dest, char *source, int maxsize) {

  int i;
  // fill dest array with nulls
  for (i = 0; i < maxsize; i++) dest[i] = '\0';

  // copy source to dest
  i = 0;
  while ( (source[i] != '\0') && (i < maxsize) ) {
    dest[i] = source[i];
    i++;
  }

  return i;

}

int main() {
  char *string;
  int string_size = 80;
  int string_len;

  // allocate memory
  string = (char *) malloc(string_size * sizeof(char));

  if (string == NULL) {
    puts("could not allocate memory with malloc");
    return 1;
  }

  string_copy(string, "Hello world", string_size);

  puts(string);

  string_len = strlen(string);
  printf("<%s> is %d characters long\n", string, string_len);

  // free memory
  free(string);

  return 0;
}
