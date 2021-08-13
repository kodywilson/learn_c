#include <stdio.h>

int main(void)
{
  // variables
  char times[8][7] = {
                       {' ', '8', ':', '0', '0', 'A', 'M'},
                       {' ', '9', ':', '4', '3', 'A', 'M'},
                       {'1', '1', ':', '1', '9', 'A', 'M'},
                       {'1', '2', ':', '4', '7', 'P', 'M'},
                       {' ', '2', ':', '0', '0', 'P', 'M'},
                       {' ', '3', ':', '4', '5', 'P', 'M'},
                       {' ', '7', ':', '0', '0', 'P', 'M'},
                       {' ', '9', ':', '4', '5', 'P', 'M'}
                     };

  int departures[7] = {531, 630, 725, 805, 882, 1045, 1220};
  int hours, minutes, total_mins;

  // get desired departure time
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hours, &minutes);

  // total_mins is the number of minutes after midnight
  total_mins = hours * 60 + minutes;

  for (int i = 0; i < 7; i++)
  {
    if (total_mins < departures[i])
    {
      printf("Closest departure is: ");
      for (int j = 0; j < 7; j++)
        printf("%c", times[i][j]);
      printf("\n");
      return 0;
    }
    else if (total_mins > 1220)
    {
      printf("Closest departure is: ");
      for (int j = 0; j < 7; j++)
        printf("%c", times[7][j]);
      printf("\n");
      return 0;
    }
  }

  // Display closest flight
  /*
  printf("Closest departure time is ");
  if (total_mins < 531)
  {
    printf("8:00 a.m., arriving at 10:16 a.m.");
  }
  else if (total_mins < 630)
  {
    printf("9:43 a.m., arriving at 11:52 a.m.");
  }
  else if (total_mins < 725)
  {
    printf("11:19 a.m., arriving at 1:31 p.m.");
  }
  else if (total_mins < 805)
  {
    printf("12:47 p.m., arriving at 3:00 p.m.");
  }
  else if (total_mins < 882)
  {
    printf("2:00 p.m., arriving at 4:08 p.m.");
  }
  else if (total_mins < 1045)
  {
    printf("3:45 p.m., arriving at 5:55 p.m.");
  }
  else if (total_mins < 1220)
  {
    printf("7:00 p.m., arriving at 9:20 p.m.");
  }
  else
  {
    printf("9:45 p.m., arriving at 11:58 p.m.");
  }

  printf("\n");*/

  return 0;
}

