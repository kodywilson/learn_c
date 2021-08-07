#include <stdio.h>

#define I 5 // Interest rate table array length
#define VALUE 100.00f

int main(void)
{
  float compound, columns[I] = {VALUE, VALUE, VALUE, VALUE, VALUE};
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
      else if (i > 0 && j == 0)
        printf("%d\t", i);
      else if (i == 0 && j > 0)
        printf("%d%%\t\t", rate - 1 + j);
      else
      {
        compound = columns[j-1];
        for (int x = 1; x <= 12; x++)
          compound += compound * (((double) (rate - 1 + j) / 12) / 100);
        columns[j-1] = compound;
        printf("%.2f\t\t", columns[j-1]);
      }
    }
    printf("\n");
  }

  return 0;
}

