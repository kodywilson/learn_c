#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void print_usage() {
  printf("Usage: temp.out -c <temp> | temp.out -f <temp> \n");
  exit(2);
}

int main(int argc, char **argv) {
  int option;
  int cflag = 0, fflag = 0;

  while ((option = getopt(argc, argv, "cf")) != -1) {
    switch (option) {
      case 'c': 
        if (cflag) print_usage();
        else {
          cflag++;
          fflag++;
        }
        printf("You want centigrade\n"); break;
      case 'f': 
        if (fflag) print_usage();
        else {
          fflag++;
          cflag++;
        }
        printf("You want fahrenheit\n"); break;
      default: printf("Usage: %s -c or -f temp_to_convert\n", argv[0]);
    }
  }

  return 0;
}
