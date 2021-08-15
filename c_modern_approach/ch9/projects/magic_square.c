#include <stdio.h>

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int main()
{
  int n;

  printf("This program creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic square: ");
  scanf("%d", &n);

  int grid[n][n];

  create_magic_square(n, grid);
  print_magic_square(n, grid);

  return 0;
}

void create_magic_square(int n, int magic_square[n][n])
{
  int pos_x, pos_y = 0, tst_x, tst_y;

  // set grid up with 0's to start
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      magic_square[i][j] = 0;
  }
  pos_x = n / 2; // set starting value

  for (int i = 1; i <= n * n; i++)
  {
    magic_square[pos_y][pos_x] = i;
    tst_x = pos_x;
    tst_y = pos_y;
    if (pos_y - 1 < 0)
      pos_y = n - 1;
    else
      pos_y = pos_y - 1;
    if (pos_x + 1 >= n)
      pos_x = 0;
    else
      pos_x++;
    if (magic_square[pos_y][pos_x] != 0)
    {
      pos_x = tst_x;
      pos_y = tst_y + 1;
    }
  }
}

void print_magic_square(int n, int magic_square[n][n])
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      printf("%d ", magic_square[i][j]);
    printf("\n");
  }
}
