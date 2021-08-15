// Randomly walk across 10 x 10 grid

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIRECTIONS 4
#define SIZE 10

void generate_random_walk(char grid[SIZE][SIZE]);
void print_array(char grid[SIZE][SIZE]);

// srand((unsigned) time (NULL));

int main(void)
{
  char grid[SIZE][SIZE];

  generate_random_walk(grid);
  print_array(grid);

  return 0;
}

void generate_random_walk(char grid[SIZE][SIZE])
{
  char letter = 'A';
  int direction, i, j, pos_x = 0, pos_y = 0, valid_move = 0;
  srand((unsigned) time (NULL));

  // initialize grid with .'s
  for (i = 0; i < SIZE; i++)
  {
    for (j = 0; j < SIZE; j++)
      grid[i][j] = '.';
  }

  // walk around the grid leaving letters behind
  grid[pos_y][pos_x] = letter; // start with A
  while (valid_move < 20 && letter != 'Z' )
  {
    direction = rand() % DIRECTIONS; // pick a random direction
    switch (direction)
    {
      case 0:
        if (pos_y - 1 >= 0 && grid[pos_y - 1][pos_x] == '.')
        {
          pos_y = pos_y - 1;
          letter++;
          grid[pos_y][pos_x] = letter;
          valid_move = 0;
        }
        break;
      case 1:
        if (pos_x + 1 < SIZE && grid[pos_y][pos_x + 1] == '.')
        {
          pos_x = pos_x + 1;
          letter++;
          grid[pos_y][pos_x] = letter;
          valid_move = 0;
        }
        break;
      case 2:
        if (pos_y + 1 < SIZE && grid[pos_y + 1][pos_x] == '.')
        {
          pos_y = pos_y + 1;
          letter++;
          grid[pos_y][pos_x] = letter;
          valid_move = 0;
        }
        break;
      case 3:
        if (pos_x - 1 >= 0 && grid[pos_y][pos_x - 1] == '.')
        {
          pos_x = pos_x - 1;
          letter++;
          grid[pos_y][pos_x] = letter;
          valid_move = 0;
        }
      default:
        valid_move++;
    }
  }
}

void print_array(char grid[SIZE][SIZE])
{
  // print out final grid
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
      printf("%c ", grid[i][j]);
    printf("\n");
  }
}

