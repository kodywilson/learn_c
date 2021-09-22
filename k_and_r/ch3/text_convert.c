// convert characters to show escape and vice versa
#include <stdio.h>

void escape(char t[]);

int main(int argc, char *argv[])
{
  char t[] = "This  is a test     try newline \
    \
              maybe it works";

  printf("Original string: %s\n", t);
  printf("Altered string: ");
  escape(t);

  return 0;
}

void escape(char t[])
{
  char c;
  for (int i = 0; (c = t[i]) != '\0'; i++) {
    switch (c) {
      case '\n':
      case '\t': printf("\\%c", c); break;
      default: printf("%c", c); break;
    }
  }
}

