#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int total = 0;
  printf("argc = %d\n", argc);
  puts("Let's see what is in argv\n");

  if (argc < 2) {
    printf("Not enough arguments\n");
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    printf("argv[%d]: %s\n", i, argv[i]);
    total += atoi(argv[i]);
  }

  printf("The total is %d\n", total);

  return 0;
}
