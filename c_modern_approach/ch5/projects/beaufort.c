#include <stdio.h>

int main(void)
{
  // variables
  int wind_speed;

  // get current wind speed in knots
  printf("Enter wind speed in knots: ");
  scanf("%d", &wind_speed);

  // print chart header
  printf("\nSpeed (knots)\t\tDescription\n");
  // determine scale of wind
  if (wind_speed < 1)
  {
    printf("Less than 1\t\tCalm\n");
  }
  else if (wind_speed < 4)
  {
    printf("1-3\t\t\tLight air\n");
  }
  else if (wind_speed < 28)
  {
    printf("4-27\t\t\tBreeze\n");
  }
  else if (wind_speed < 48)
  {
    printf("28-47\t\t\tGale\n");
  }
  else if (wind_speed < 64)
  {
    printf("48-63\t\t\tStorm\n");
  }
  else
  {
    printf("Above 63\t\tHurricane\n");
  }

  return 0;
}

