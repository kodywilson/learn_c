#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char **argv) {
  int option;
  int cflag = 0, fflag = 0;

  while ((option = getopt(argc, argv, "cf")) != -1) {
    switch (option) {
      case 'c': 
        if (cflag) {
          printf("Only one option\n");
          exit(1);
        } else {
          cflag++;
          fflag++;
        }
        printf("You want centigrade\n"); break;
      case 'f': 
        if (fflag) {
          printf("Only one option\n");
          exit(1);
        } else {
          fflag++;
          cflag++;
        }
        printf("You want fahrenheit\n"); break;
      default: printf("Usage: %s -c or -f temp_to_convert\n", argv[0]);
    }
  }

  return 0;
}
