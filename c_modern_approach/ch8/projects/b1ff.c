#include <stdio.h>
#include <ctype.h>

#define M 32
#define SIZE (int) sizeof(msg) / sizeof(msg[0])

int main()
{
  char chr, letter, msg[M];
  int position = 0;

  printf("Enter message: ");
  for (;;)
  {
    chr = getchar();
    if (chr == '\n')
    {
      msg[position] = '\0';
      break;
    }
    msg[position] = chr;
    position++;
  }
  for (int i = 0; i < SIZE; i++)
  {
    if (msg[i] != '\0')
    {
      letter = toupper(msg[i]);
      switch (letter)
      {
        case 'E': letter = '3'; break;
        case 'I': letter = '1'; break;
        case 'O': letter = '0'; break;
        case 'S': letter = '5'; break;
      }
      putchar(letter);
    }
    else
      break;
  }
  printf("!!!!!!!!\n");

  return 0;
}

