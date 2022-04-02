#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20

int main() {
  int array[ARRAY_SIZE];

  // store random numbers
  srand(13374);

  for (int i = 0; i < ARRAY_SIZE; i++) array[i] = (int) random() % 100;

  puts("This is what we put in the array <before sorting>");
  for (int i = 0; i < ARRAY_SIZE; i++) array[i] = printf("%d ", array[i]);
  putchar('\n');

  return 0;

}
