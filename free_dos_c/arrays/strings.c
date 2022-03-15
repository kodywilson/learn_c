#include <stdio.h>

int string_length(char string[]) {
  int len = 0;

  // find null character
  while (string[len] != '\0') len++;

  return len;
}

int main() {
  char hello[] = "Hello world!";

  puts(hello);

  printf("<%s>\n", hello);

  puts("<123456789> -- counting characters");
  puts("<012345678> -- positions in the array");

  printf("The string is %d characters long\n", string_length(hello));

  return 0;
}
