#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char **argv) {
  int option;

  while ((option = getopt(argc, argv, "cf")) != -1) {
    switch (option) {
      case 'c': printf("You want centigrade\n"); break;
      case 'f': printf("You want fahrenheit\n"); break;
      default: printf("Usage: %s -c or -f temp_to_convert\n", argv[0]);
    }
  }

  return 0;
}
