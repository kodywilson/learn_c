#include <stdio.h>

int main(void)
{
  int date1, day1, month1, year1, day2, month2, year2;

  printf("Enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &month1, &day1, &year1);
  printf("Enter second date (mm/dd/yy): ");
  scanf("%d/%d/%d", &month2, &day2, &year2);

  // find earliest date
  if (year1 < year2)
  {
    date1 = 1;
  }
  else if (year1 == year2 && month1 < month2)
  {
    date1 = 1;
  }
  else if (year1 == year2 && month1 == month2 && day1 < day2)
  {
    date1 = 1;
  }
  else
  {
    date1 = 0;
  }

  // print results
  if (date1 == 1)
  {
    printf("%d/%d/%d is earlier than %d/%d/%d\n", month1, day1, year1, month2, day2, year2);
  }
  if (date1 == 0)
  {
    printf("%d/%d/%d is earlier than %d/%d/%d\n", month2, day2, year2, month1, day1, year1);
  }

  return 0;
}

