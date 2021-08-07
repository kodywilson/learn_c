#include <stdio.h>
#include <ctype.h>

int main(void)
{
  // variables
  char meridiem;
  int hours, minutes ;

  // get 12-hour time
  printf("Enter a 12-hour time (1:15pm): ");
  scanf("%d:%d%c", &hours, &minutes, &meridiem);

  // convert to 24-hour format
  if (toupper(meridiem) == 'P' && hours != 12)
    hours = 12 + hours;

  printf("Equivalent 24-hour time: %d:%d\n", hours, minutes);

  return 0;
}

