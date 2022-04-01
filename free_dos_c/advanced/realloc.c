#include <stdio.h>
#include <stdlib.h>

int main() {
  int *array;
  int size = 100;

  int *newarray;
  int newsize;

  // allocate the array
  array = (int *) malloc(size * sizeof(int));

  if (array == NULL) {
    fprintf(stderr, "Could not allocate memory with malloc\n");
    return 1;
  }

  printf("The array is now %d long\n", size);

  // store some data
  for (int i = 0; i < size; i++) {
    array[i] = i + 100;
    printf("%d ", array[i]);
  }
  printf("\n");

  // make the array bigger

  newsize = size + 50;

  newarray = (int *) realloc(array, newsize * sizeof(int));

  if (newarray == NULL) {
    fprintf(stderr, "Could not allocate memory with realloc\n");
    fprintf(stderr, "...but the old pointer is still ok\n");
  } else {
    array = newarray;
    size = newsize;
  }

  printf("the array is now %d size\n", size);

  // store some data
  for (int i = 0; i < size; i++) {
    array[i] = i + 1000;
    printf("%d ", array[i]);
  }
  printf("\n");

  free(array); // release memory

  return 0;
}
