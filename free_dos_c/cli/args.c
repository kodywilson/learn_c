#include <stdio.h>
#include <stdlib.h>

void red() {
  printf("\033[1;31m");
}

void green() {
  printf("\033[1;32m");
}

void reset() {
  printf("\033[0m");
}

int main(int argc, char **argv) {
  int total = 0;
  printf("argc = %d\n", argc);

  if (argc < 2) {
    red();
    printf("Not enough arguments\n");
    return 1;
  }
  
  puts("Let's see what is in argv\n");

  for (int i = 1; i < argc; i++) {
    printf("argv[%d]: ", i);
    green();
    printf("%s\n", argv[i]);
    reset();
    total += atoi(argv[i]);
  }

  printf("The total is ");
  green();
  printf("%d\n", total);

  return 0;
}
