#include <stdio.h>
#define MAXLINE 1000    // maximum input line length

//int getline(char line[], int maxline);
//void copy(char to[], char from[]);

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
  }

  fclose(fp);

  return 0;
}

