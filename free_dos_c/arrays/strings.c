#include <stdio.h>

int main() {
  char hello[] = "Hi there!";

  puts(hello);

  printf("<%s>\n", hello);

  puts("<123456789> -- counting characters");
  puts("<012345678> -- positions in the array");

  return 0;
}
