#include <stdio.h>

#define S 5 // size of square array

int main(void)
{
  int column_sum = 0, row_sum = 0, a[S][S];

  for (int i = 0; i < S; i++)
  {
    printf("Enter row %d: ", i + 1);
    for (int j = 0; j < S; j++)
      scanf("%d", &a[i][j]);
  }

  // calculate row totals
  printf("\nRow totals:\t");
  for (int i = 0; i < S; i++)
  {
    for (int j = 0; j < S; j++)
      row_sum += a[i][j];
    printf("%d ", row_sum);
    row_sum = 0;
  }

  // calculate column totals
  printf("\nColumn totals: ");
  for (int i = 0; i < S; i++)
  {
    for (int j = 0; j < S; j++)
      column_sum += a[j][i];
    printf("%d ", column_sum);
    column_sum = 0;
  }
  printf("\n");

  return 0;
}

