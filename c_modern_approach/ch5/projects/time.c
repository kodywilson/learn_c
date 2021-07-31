#include <stdio.h>

int main(void)
{
  int hours, minutes;
  char am_pm;
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hours, &minutes);
  
  am_pm = hours > 11 ? 'P' : 'A';
  if (hours > 12)
    hours = 12 - (24 - hours);
  else if (hours == 0)
    hours = 12;

  printf("Equivalent 12-hour time: %d:%d %cM\n", hours, minutes, am_pm);

  return 0;
}

