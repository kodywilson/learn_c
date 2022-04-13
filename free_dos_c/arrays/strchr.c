#include <stdio.h>

int is_charstring(char *bigstring, char c) {
  int i = 0;
  while ( bigstring[i] != '\0' ) {
    if ( bigstring[i] == c ) return 1;
    i++;
  }

  return 0;
}

int main(int argc, char **argv) {
  //char string[] = argv[1];
  char c = argv[2][0];

  if ( is_charstring(argv[1], c)) puts("Found it!");

  return 0;
}
