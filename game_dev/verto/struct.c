#include <stdio.h>

typedef struct
{
  char *name;
  int x, y;
  short life;
} Player;

void structs()
{
  Player hero;
  hero.x = 50;
  hero.y = 50;
  hero.life = 100;
  hero.name = "Sedona";

  printf("Name of hero: %s\n", hero.name);
  printf("Health: %d\n", hero.life);
}

int main(void)
{
  structs();

  return 0;
}

