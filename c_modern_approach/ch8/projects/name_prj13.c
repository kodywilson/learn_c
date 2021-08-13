#include <stdio.h>

int main(void)
{
  char chr, initial, name[20];
  int marker = 1, sequence = 0;

  printf("Enter a first and last name: ");
  do
  {
    chr = getchar();
    if (marker == 1) // store first letter
    {
      marker = 2;
      initial = chr;
    }
    else if (marker == 3 && chr != '\n') // skip rest of first name then store last name
    {
      name[sequence] = chr;
      sequence++;
    }

    // find spaces and the newline to determine what to skip and what to save
    if (chr == ' ')
      marker = 3;
  }
  while (chr != '\n');

  // print results
  printf("You entered the name: ");
  for (int i = 0; i <= sequence; i++)
    printf("%c", name[i]);
  printf(", %c.", initial);
  printf("\n");

  return 0;

}

