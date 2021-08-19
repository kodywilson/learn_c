// Craps dice game

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
  char keep_playing;
  int wins = 0, losses = 0;
  srand((unsigned) time (NULL));

  do
  {
    if (play_game() == true)
    {
      printf("You win!\n\n");
      wins++;
    }
    else
    {
      printf("You lose!\n\n");
      losses++;
    }

    printf("Play again? ");
    scanf("%c", &keep_playing);
    while(getchar() != '\n');
  }
  while (keep_playing != 'n');

  printf("\nWins: %d   Losses: %d\n", wins, losses);

  return 0;
}

int roll_dice(void)
{
  //srand((unsigned) time (NULL));
  return (rand() % 6) + (rand() % 6);
}

bool play_game(void)
{
  int point, roll;

  point = roll_dice();

  printf("You rolled: %d\nYour point is %d\n", point, point);
  if (point == 7 || point == 11)
   return true; 
  else if (point == 2 || point == 3 || point == 12)
   return false;
 
  for(;;)
  {
    roll = roll_dice();
    printf("You rolled: %d\n", roll);
    if (roll == point)
      return true;
    else if (roll == 7)
      return false;
  }
}

