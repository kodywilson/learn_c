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
    // printf("%s", line); // ch1 exe1.16
    len = countline(line, MAXLINE);
    if (len > 40)
      printf("Over 40: %s", line);
    //printf("max is %d and len is %d\n", max, len); // ch1 exe1.16
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
    // the count really isn't accurate. To be accurate, you'd have to
    // count each tab as 2-8 characters, depending on tab stop
    if (c == '\t')
      i += 3; // each tab is worth 4 (3 + the one from i incrementing)

  return i;
}

// copy biggest line into longest char array
void copy(char to[], char from[])
{
  int i = 0;

  while ((to[i] = from[i]) != '\0')
      ++i;
}

