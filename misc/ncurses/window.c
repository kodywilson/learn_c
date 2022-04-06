#include <ncurses.h>

int main() {
  initscr();

  int height, width, start_y, start_x;
  height = 10; // height in lines
  width = 20;  // width in characters
  start_y = start_x = 10;
  WINDOW *win = newwin(height, width, start_y, start_x);
  refresh();

  // box prints a box, takes window, y, x
  box(win, 0, 0);
  mvwprintw(win, 1, 1, "A cool box");
  wrefresh(win);

  getch();

  endwin();

  return 0;
}
