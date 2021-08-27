#include <stdio.h>



int main(int argc, char *argv[])
{
  FILE *fp; // pointer to file
  char c;   // char to read content
  
  if (argc <= 2) // show help text
    puts("Options are lc (line count), wc (word count), or cat (display file) followed by file name");
  else if (argc == 3)
  {
    fp = fopen("exercises.c", "r");
    while ((c = fgetc(fp)) != EOF)
      printf("%c", c);
    fclose(fp);
    //if (argv[1] == "cat")
    //  puts("Meow");
  }
  else {
    puts("Too many arguments! Please specify command followed by file name");
    //printf("Cannot open file %s\n", *argv[2]);
    //return 1;
  }

  return 0;
}

