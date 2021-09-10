#include <stdio.h>
#define MAXLINE 1000    // maximum input line length

void reverse_line(char line[], int maxline);

// print the longest input line
int main(int argc, char *argv[])
{
  FILE *fp;               // pointer to file passed as argv[1]
  char line[MAXLINE];     // current input line

  if (argc >= 2)
    fp = fopen(argv[1], "r");
  else {
    printf("Pass me the name of a file to parse\n");
    return 1;
  }

  while (fgets(line, sizeof(line), fp))
    reverse_line(line, sizeof(line));

  fclose(fp);

  return 0;
}

// reverse_line: print line ion reverse
void reverse_line(char s[], int lim)
{
  int i;

  for (i = 0; i < lim - 1 && s[i] != '\0'; i++);
  for (; i >= 0; i--)
    putchar(s[i]);
}

