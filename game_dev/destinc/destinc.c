#include "dice.h"
#include "text.h"

#define ROLLS 1000

int main() {
  srand(time(0));
  int min = 24, max = 0, roll;

  for(int i = 0; i < ROLLS; i++) {
    roll = dice(4, 6);
    if ( roll > max ) max = roll;
    if ( roll < min ) min = roll;
  }
  printf("We rolled four d6 a %d times and got the following\n", ROLLS);
  printf("Min: %d\t\tMax: %d\n", min, max);

  printf("Test text is %s \n", rand_move_text[dice(1, 4) - 1]);

  return 0;
}
