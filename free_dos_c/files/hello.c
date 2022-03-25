#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char **argv) {
  int i;

  while ((i = getopt(argc, argv, "hHqQ")) != EOF) {
    switch(i) {
      case 'h':
      case 'H': puts("You chose help"); break;
      case 'q':
      case 'Q': puts("You chose to quit"); break;
      default: puts("Unable to detemine what you want.");
    }
  }

  for (int i = optind; i < argc; i++) {
    printf("%d: %s\n", i, argv[i]);
  }

  return 0;
}

