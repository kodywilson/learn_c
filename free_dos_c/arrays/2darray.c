#include <stdio.h>
#include <stdlib.h>

int main() {
  int **array;
  int rows = 3;
  int cols = 4;
  int x, y;

  // allocate memory for multidimensional array
  array = (int **) malloc(rows * sizeof(int *));

  if (array == NULL) {
    puts("Could not allocate array");
    return 1;
  }

  for (y = 0; y < rows; y++) {
    array[y] = (int *) malloc(cols * sizeof(int));

    if (array[y] == NULL) {
      puts("Unable to allocate row");
      return 1;
    }
  }

  // store data in each cell (in each [y][x])
  for (y = 0; y < rows; y++)
    for (x = 0; x < cols; x++) {
      array[y][x] = 100 + (y * 10) + x;
      printf("[%d][%d] is now %d\n", y, x, array[y][x]);
    }

  // free memory
  for (y = 0; y < rows; y++) free(array[y]);
  free(array);

  return 0;
}
