#include "dice.h"
#define MOVE_TEXT 6
#include "text.h"
#include <ncurses.h>

//#define MOVE_TEXT 4
#define ROLLS 1000
#define STARS 100

int main() {
  srand(time(0));
  //int min = 24, max = 0, roll;
  int maxY, maxX, starsY[STARS], starsX[STARS];

  initscr();
  getmaxyx(stdscr, maxY, maxX);
  curs_set(0);

  // generate randomly located stars
  for (int i = 0; i < STARS; i++) {
    starsY[i] = dice(1, maxY);
    starsX[i] = dice(1, maxX);
    mvaddch(starsY[i], starsX[i], '*');
    refresh();
    napms(dice(1, 100));
  }

  napms(3000);

  for (int a = 1; a < 4; a++) {
    for (int i = 0; i < STARS; i++) {
      mvaddch(starsY[i], starsX[i], ' ');
      starsY[i] = starsY[i] + a;
      mvaddch(starsY[i], starsX[i], '*');
      refresh();
      napms(500);
    }
  }

  getch();

  // display stars
  //for (int i = 0; i < STARS; i++) {
  //}

  /*for(int i = 0; i < ROLLS; i++) {
    roll = dice(4, 6);
    if ( roll > max ) max = roll;
    if ( roll < min ) min = roll;
  }
  printf("We rolled four d6 a %d times and got the following\n", ROLLS);
  printf("Min: %d\t\tMax: %d\n", min, max);

  printf("Test text is %s \n", rand_move_text[dice(1, MOVE_TEXT) - 1]);
*/
  endwin();
  return 0;
}
