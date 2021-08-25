#include <stdio.h>
#include <string.h>

#define MSG 64

int read_line(char str[], int n);

int main(void)
{
  char msg[MSG];
  read_line(msg, MSG);

  puts(msg);

  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0, nsp_char = 0;

  while ((ch = getchar()) != '\n')
    if (i < n && ch != ' ')
    {
      str[i++] = ch;
      nsp_char = 1;
    }
    else if (i < n && ch == ' ' && nsp_char == 1)
      break;
  str[i] = '\0';
  return i;
}

