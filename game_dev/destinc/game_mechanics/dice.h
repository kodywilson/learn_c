#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int die(int sides) {
  int roll;
  roll = (rand() % sides) + 1;
  //printf("Rolled a %d\n", roll); // DEBUG

  return roll;;
}

int dice(int how_many, int sides) {
  int roll = 0;
  for (int i = 0; i < how_many; i++) roll = roll + die(sides);
  return roll;
}
