#include <stdio.h>

#define S 5 // size of square array

int main(void)
{
  int column_sum = 0, high, low = 100, row_sum = 0, a[S][S];

  for (int i = 0; i < S; i++)
  {
    printf("Enter scores for quiz #%d: ", i + 1);
    for (int j = 0; j < S; j++)
      scanf("%d", &a[i][j]);
  }
  printf("\n");

  // calculate quiz stats
  for (int i = 0; i < S; i++)
  {
    for (int j = 0; j < S; j++)
    {
      row_sum += a[i][j];
      if (a[i][j] > high)
        high = a[i][j];
      if (a[i][j] < low)
        low = a[i][j];
    }
    printf("Quiz %d Stats:  Average Score: %d  High Score: %d  Low Score: %d\n", i + 1, row_sum / S, high, low);
    row_sum = 0;
    high = 0;
    low = 100;
  }
  printf("\n");

  // calculate student stats
  for (int i = 0; i < S; i++)
  {
    for (int j = 0; j < S; j++)
      column_sum += a[j][i];
    printf("Student %d Stats:  Total Score: %d  Average Score: %d\n", i + 1, column_sum, column_sum / S);
    column_sum = 0;
  }
  printf("\n");

  return 0;
}

