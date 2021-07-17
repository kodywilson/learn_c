#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main()
{
  string text = "Amazing Grace";
  printf("%s\n", text);
  int i = 0;
  do {
    i++;
  }
  while (text[i] != '\0');
  printf("There are %i characters in '%s'\n", i, text);
  printf("Here is an easier way to do it.\n");
  printf("Character count is: %li\n", strlen(text));
}

