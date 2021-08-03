// generate a calendar
#include <stdio.h>

int main(void)
{
  int day_of_week, days, start;

  printf("Enter number of days in month: ");
  scanf("%d", &days);
  printf("Enter starting day of the week (1=Sun, 7=Sat): ");
  scanf("%d", &start);
  printf("\nSun\tMon\tTue\tWed\tThur\tFri\tSat\n");
  
  day_of_week = start;
  for (int i = 1; i < start; i++)
    printf("\t");
  for (int i = 1; i <= days; i++)
  {
    printf("%d\t", i);
    if (day_of_week == 7)
    {
      printf("\n");
      day_of_week = 1;
    }
    else
      day_of_week++;
  }
  printf("\n");

  return 0;
}

