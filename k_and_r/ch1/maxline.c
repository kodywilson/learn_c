#include <stdio.h>
#define MAXLINE 1000    // maximum input line length

int countline(char line[], int maxline);
void copy(char to[], char from[]);

// print the longest input line
int main(int argc, char *argv[])
{
  FILE *fp;               // pointer to file passed as argv[1]
  int len;                // current line length
  int max;                // maximum length seen so far
  char line[MAXLINE];     // current input line
  char longest[MAXLINE];  // longest line saved here

  max = 0;
  if (argc >= 2)
    fp = fopen(argv[1], "r");
  else {
    printf("Pass me the name of a file to parse\n");
    return 1;
  }

  while (fgets(line, sizeof(line), fp)) {
    printf("%s", line);
    len = countline(line, MAXLINE);
    printf("max is %d and len is %d\n", max, len);
      if (len > max) {
        max = len;
        copy(longest, line);
      }
  }

  if (max > 0)
    printf("\nLongest line: %s\n", longest);

  fclose(fp);

  return 0;
}

// countline: read a line into s, return length
int countline(char s[], int lim)
{
  int c, i;

  for (i = 0; (c = s[i]) != '\n' && c != '\0'; i++)
    ;
  /*if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';*/
  return i;
}

// copy biggest line into longest char array
void copy(char to[], char from[])
{
  int i = 0;

  while ((to[i] = from[i]) != '\0')
      ++i;
}

