#include <stdio.h>

int main() {
  char ch;

  puts("Press Enter to continue...");

  // loop until newline

  do {
    ch = getchar();

    // debugging
    printf("DEBUG: (%c)\n", ch);

  } while (ch != '\n');

  puts("Ok");

  return 0;
}
