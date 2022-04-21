#include <ncurses.h>

int main() {
  int x = 0, y = 0;

  initscr(); // initialize screen
  noecho(); // do not repeat key strokes
  curs_set(FALSE); // do not show cursor

  // move ball across the screen
  while(1) {
    //clear();  // clear the whole screen - seems expensive when you could hide the previous ball
    mvprintw(y, x, "o"); // print ball
    mvprintw(y, x - 1, " ");  // remove old ball
    refresh();
    napms(50);  // pause between bounces
    x++;
    if (x > 120) break;
  }

  getch();

  endwin(); // clean up
  return 0;
}
