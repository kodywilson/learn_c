#include <ncurses.h>

int main() {
  int y = 0, x = 0, max_y, max_x;
  int next_x = 0;
  int direction = 1;

  initscr(); // initialize screen
  noecho(); // do not repeat key strokes
  curs_set(FALSE); // do not show cursor

  // move ball across the screen
  while(1) {
    getmaxyx(stdscr, max_y, max_x);
    //clear();  // clear the whole screen - seems expensive when you could hide the previous ball
    mvprintw(y, x, "o"); // print ball
    if ( direction == 1 ) mvprintw(y, x - 1, " ");  // remove old ball
    if ( direction == -1 ) mvprintw(y, x + 1, " ");  // remove old ball
    refresh();
    napms(50);  // pause between bounces
    next_x = x + direction;
    if (next_x >= max_x || next_x < 0) direction*=-1;
    else x+= direction;
  }

  getch();

  endwin(); // clean up
  return 0;
}
