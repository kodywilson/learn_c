#include <stdio.h>

int main(void)
{
  // variables
  int day, month, year;

  // get date in mm/dd/yy form
  printf("Enter date (mm/dd/yy): ");
  scanf("%d/%d/%d", &month, &day, &year);

  // print in legal form
  printf("Dated this %d", day);
  switch (day)
  {
    case 1: case 21: case 31:
      printf("st"); break;
    case 2: case 22:
      printf("nd"); break;
    case 3: case 23:
      printf("rd"); break;
    default:
      printf("th"); break;
  }

  return 0;
}

