#include <ncurses.h>

int main() {
  int y, x;

  initscr();

  getmaxyx(stdscr, y, x);
  printw("Window is %d rows and %d columns.\n", y, x);
  refresh();
  getch();

  endwin();
  return 0;
}
