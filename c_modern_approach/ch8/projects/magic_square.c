#include <stdio.h>

int main()
{
  int n, pos_x, pos_y = 0, tst_x, tst_y;

  printf("This program creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic square: ");
  scanf("%d", &n);

  int grid[n][n];
  // set grid up with 0's to start
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      grid[i][j] = 0;
  }
  pos_x = n / 2; // set starting value

  for (int i = 1; i <= n * n; i++)
  {
    grid[pos_y][pos_x] = i;
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
    if (grid[pos_y][pos_x] != 0)
    {
      pos_x = tst_x;
      pos_y = tst_y + 1;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      printf("%d ", grid[i][j]);
    printf("\n");
  }

  return 0;
}

