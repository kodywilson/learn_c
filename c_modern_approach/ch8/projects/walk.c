// Randomly walk across 10 x 10 grid

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// srand((unsigned) time (NULL));

int main(void)
{
  char grid[SIZE][SIZE];
  int i, j;
  srand((unsigned) time (NULL));

  // initialize grid with .'s
  for (i = 0; i < SIZE; i++)
  {
    for (j = 0; j < SIZE; j++)
      grid[i][j] = '.';
  }

  // walk around the grid leaving letters behind

  // print out final grid
  for (i = 0; i < SIZE; i++)
  {
    for (j = 0; j < SIZE; j++)
      printf("%c ", grid[i][j]);
    printf("\n");
  }

  return 0;
}

