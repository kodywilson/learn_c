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
  int maxY, maxX, starsY[STARS], starsX[STARS], starsColor[STARS];

  initscr();
  start_color();
  // set up some colors
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);
  init_pair(6, COLOR_YELLOW, COLOR_BLACK);

  getmaxyx(stdscr, maxY, maxX);
  curs_set(0);

  // generate randomly located stars
  for (int i = 0; i < STARS; i++) {
    starsY[i] = dice(1, maxY);
    starsX[i] = dice(1, maxX);
    starsColor[i] = dice(1, 6);
    attrset(COLOR_PAIR(starsColor[i]));
    mvaddch(starsY[i], starsX[i], '*');
    refresh();
    napms(dice(1, 100));
  }

  napms(2000);

  // stars go up
  for (int a = 1; a < 4; a++) {
    for (int i = 0; i < STARS; i++) {
      mvaddch(starsY[i], starsX[i], ' ');
      starsY[i] = starsY[i] - a;
      attrset(COLOR_PAIR(starsColor[i]));
      mvaddch(starsY[i], starsX[i], '*');
    }
    refresh();
    napms(150);
  }

  // stars fall away
  int drop_speed = 100;
  for (int a = 1; a < maxY + 1; a++) {
    for (int i = 0; i < STARS; i++) {
      mvaddch(starsY[i], starsX[i], ' ');
      starsY[i] = starsY[i] + a;
      attrset(COLOR_PAIR(starsColor[i]));
      mvaddch(starsY[i], starsX[i], '*');
    }
    refresh();
    napms(drop_speed-=5);
  }

  attrset(A_UNDERLINE | COLOR_PAIR(1));
  mvaddstr(maxY/2, (maxX * 2)/5, "Press any key to begin...");
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
