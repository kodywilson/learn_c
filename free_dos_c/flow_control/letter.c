#include <stdio.h>

int main() {

  char ch;

  puts("Please enter a letter (enter Q or q to quit)");

  do {
    scanf("%c", &ch);
    printf(" -> %c\n", ch);
  }
  while ((ch != 'Q') && (ch != 'q'));

  return 0;
}
