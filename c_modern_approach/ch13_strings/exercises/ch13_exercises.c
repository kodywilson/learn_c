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
  int ch, i = 0;

  do
  {
    ch = getchar();
    if (i < n)
      str[i++] = ch;
  }
  while (ch != '\n');
  str[i] = '\0';
  return i;
}

