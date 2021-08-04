// generate a calendar
#include <stdio.h>

int main(void)
{
  int days, start;

  printf("Enter number of days in month: ");
  scanf("%d", &days);
  printf("Enter starting day of the week (1=Sun, 7=Sat): ");
  scanf("%d", &start);
  printf("\nSun\tMon\tTue\tWed\tThur\tFri\tSat\n");
  
  for (int i = 1; i < start; i++)
    printf("\t");
  for (int i = 1; i <= days; i++)
  {
    printf("%d\t", i);
    if ((start + i - 1) % 7 == 0)
      printf("\n");
  }
  printf("\n");

  return 0;
}

