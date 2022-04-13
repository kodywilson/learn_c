#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE_INCR 100

int getlongstr(char **string, int *stringsize, FILE *input) {
  char *str;
  char *newstr;
  int strsize;
  int newsize;
  int nchars = 0;
  int ch;

  // check if we need to allocate the string
  if ((*string == NULL) || (stringsize == 0)) {
    fprintf(stderr, "[malloc]"); // DEBUG
    strsize = STR_SIZE_INCR;
    str = (char *) malloc(strsize * sizeof(char));

    if (str == NULL) {
      fprintf(stderr, "Unable to allocate memory!\n");
      return -1;
    }
  } else {
    strsize = *stringsize;
    str = *string;
  }

  // read from the input until we reach the newline or end of file
  while (((ch = fgetc(input)) != '\n') && (ch != EOF)) {
    // put the ch into the string
    str[nchars] = ch;

    // check if we need more memory
    if (nchars == strsize) {
      fprintf(stderr, "[realloc]"); // DEBUG
      newsize = strsize + STR_SIZE_INCR;
      newstr = (char *) realloc(str, newsize * sizeof(char));

      // check if realloc worked
      if (newstr == NULL) {
        *string = str;
        *stringsize = strsize;
        return nchars;
      }

      str = newstr;
      strsize = newsize;

    }

    nchars++;
  }

  str[nchars] = '\0';

  // done
  *string = str;
  *stringsize = strsize;
  return nchars;
}

int main() {
  char *string = NULL;
  int size = 0;
  int nchars;

  // read a long line
  puts("Enter a really long string:");
  nchars = getlongstr(&string, &size, stdin);

  if (nchars < 0) {
    fprintf(stderr, "Error calling getlongstr\n");
    free(string);
    return 1;
  }

  // print the string
  printf("read %d chars\n", nchars);
  printf("the string is size %d\n", size);
  printf("the string is <%s>\n", string);

  free(string);

  return 0;

}
