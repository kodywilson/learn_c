#include <stdio.h>

#define I 5 // Interest rate table array length

int main(void)
{
  float row[I];
  int rate, years;

  printf("Enter interest rate: ");
  scanf("%d", &rate);

  printf("Enter number of years: ");
  scanf("%d", &years);

  for (int i = 0; i <= years; i++)
  {
    for (int j = 0; j <= I; j++)
    {
      if (i == 0 && j == 0)
        printf("Years\t");
      else
        printf("%d%%\t", rate - 1 + j);
    }
    printf("\n");
  }

  return 0;
}

