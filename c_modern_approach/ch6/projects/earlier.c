#include <stdio.h>

int main(void)
{
  int date1, day1, month1, year1, day2, month2, year2;

  printf("Enter a date (mm/dd/yy): ");
  scanf("%d/%d/%d", &month1, &day1, &year1);
  for (;;)
  {
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month2, &day2, &year2);

    if (month2 == 0)
      break;

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
    if (date1 == 0)
    {
      day1 = day2;
      month1 = month2;
      year1 = year2;
    }
  }

  // print results
  printf("%02d/%02d/%02d is the earliest date\n", month1, day1, year1);

  return 0;
}

