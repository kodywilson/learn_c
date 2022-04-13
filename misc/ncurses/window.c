#include <ncurses.h>

int main() {
  initscr();

  int height, width, start_y, start_x;
  height = 10; // height in lines
  width = 20;  // width in characters
  start_y = start_x = 10;
  WINDOW *win = newwin(height, width, start_y, start_x);
  refresh();

  // box prints a box, takes window, border_type (left and right), border_type (top and bottom)
  box(win, 0, 0);
  //wborder(win, left, right, top, bottom, tlc, trc, blc, brc);
  // wborder gives much more control over the border of the box shape
  // after passing the window (win) you can specify border character for all sides and corners
  mvwprintw(win, 1, 1, "A cool box");
  wrefresh(win);

  getch();

  endwin();

  return 0;
}
