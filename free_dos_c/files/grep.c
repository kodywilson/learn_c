// Find word in file
#include <stdio.h>
#include <string.h>

int find_str_file(char *string, FILE *fileptr) {
  char linefromfile[1000];
  char *foundstr;
  int numfound = 0;

  // loop through the file and look for string

  while ( (fgets(linefromfile, 1000, fileptr)) != NULL ) {
    foundstr = strstr(linefromfile, string);

    if (foundstr != NULL) {
      printf("%s", linefromfile);
      numfound++;
    }
  }

  return numfound;
}

int main(int argc, char **argv) {
  // variables
  FILE *filey;

  // check if arguments were passed
  if (argc < 3) {
    fprintf(stderr, "Wrong number of arguments\n");
    fprintf(stderr, "Usage: grep search_term file_to_search1 file_to_search2, etc.\n");
    return 1;
  }

  // open each file and look for string
  for (int i = 2; i < argc; i++) {
    filey = fopen(argv[i], "r");

    if (filey == NULL) {
      fprintf(stderr, "Unable to open file %s for searching\n", argv[i]);
      return 2;
    } else {
      find_str_file(argv[1], filey);
      fclose(filey);
    }

  }

  return 0;

}
