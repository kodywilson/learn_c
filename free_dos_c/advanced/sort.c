// does not work, numbers get changed
// see qsort.c for a working example
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int compare_num(const void *a, const void *b) {
  int a1, b1;

  a1 = *(int *) a;
  b1 = *(int *) b;

  if (a1 < b1) return -1;
  else if (a1 > b1) return 1;
  else return 0;

  return (a1 - b1);
}

int main() {
  int array[ARRAY_SIZE];

  // store random numbers
  srand(13374);

  for (int i = 0; i < ARRAY_SIZE; i++) array[i] = (int) random() % 100;

  puts("This is what we put in the array <before sorting>");
  for (int i = 0; i < ARRAY_SIZE; i++) array[i] = printf("%d ", array[i]);
  putchar('\n');

  // now sort the array
  qsort(array, ARRAY_SIZE, sizeof(int), *compare_num);

  // print sorted values
  puts("After sorting:");
  for (int i = 0; i < ARRAY_SIZE; i++) array[i] = printf("%d ", array[i]);
  putchar('\n');

  return 0;

}
