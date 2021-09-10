#include <stdio.h>
#define MAXLINE 1000    // maximum input line length

int format_line(char line[], int maxline);

// print the longest input line
int main(int argc, char *argv[])
{
  FILE *fp;               // pointer to file passed as argv[1]
  char line[MAXLINE];     // current input line
  int len;                // length of line

  if (argc >= 2)
    fp = fopen(argv[1], "r");
  else {
    printf("Pass me the name of a file to parse\n");
    return 1;
  }

  while (fgets(line, sizeof(line), fp)) {
    len = format_line(line, sizeof(line));
    //printf("Line length: %d\n", len);
    if (len > 0)
      printf("%s\n", line);
  }

  fclose(fp);

  return 0;
}

// format_line: remove trailing blanks and tabs
int format_line(char s[], int lim)
{
  int c, i;

  for (i = lim - 1; i >= 0 && s[i] != '\n'; i--)  // find string end
    ;
  for (; i >= 0 && (c = s[i]) != EOF && c <= 32; i--)
  s[i] = '\0';

  return i;
}

