#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
  FILE *fp; // pointer to file
  char c;   // char to read content
  long nb, nc, nl, nt;  // various counts
  nb = nc = nl = nt = 0;  // start all counts at 0
  
  if (argc <= 2) // show help text
    puts("Options are cc (char count), lc (line count), wc (word count), or cat (display file) followed by file name");
  else if (argc == 3)
  {
    fp = fopen(argv[2], "r");
    if (strcmp(argv[1], "cat") == 0) {
      while ((c = fgetc(fp)) != EOF)
        printf("%c", c);
    } else if (strcmp(argv[1], "cc") == 0) {
      for (nc = 0; fgetc(fp) != EOF; ++nc);
      printf("%s has %ld characters\n", argv[2], nc);
    } else if (strcmp(argv[1], "lc") == 0) {
      while ((c = fgetc(fp)) != EOF)
        if (c == '\n')
          ++nl;
      printf("%s has %ld lines\n", argv[2], nl);
    } else if (strcmp(argv[1], "count") == 0) {
      while ((c = fgetc(fp)) != EOF)
        switch (c)
        {
          case ' ': ++nb; break;
          case '\n': ++nl; break;
          case '\t': ++nt; break;
        }
      printf("%s has %ld lines %ld blanks and %ld tabs\n", argv[2], nl, nb, nt);
    }

    fclose(fp);
  }
  else {
    puts("Too many arguments! Please specify command followed by file name");
    //printf("Cannot open file %s\n", *argv[2]);
    //return 1;
  }

  return 0;
}

