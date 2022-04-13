#include <stdio.h>
#include <stdlib.h>

ssize_t getline(char **buf, size_t *bufsize, FILE *fp);

int main() {
  char *string = NULL;
  size_t string_size = 0;
  size_t nchars;

  // read a long string

  puts("Enter a really long string:");

  nchars = getline(&string, &string_size, stdin);

  if (nchars < 1) {
    fprintf(stderr, "Error on getline\n");
    free(string);
    return 1;
  }

  // print out results
  printf("read %lu chars\n", nchars);
  printf("The string is size %lu\n", string_size);

  printf("the string is <%s>\n", string);

  free(string);

  return 0;
}
