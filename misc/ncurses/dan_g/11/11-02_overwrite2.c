#include <ncurses.h>

int main() {
  WINDOW *red, *blue;

  initscr();
  refresh();

  // colors
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_RED);
  init_pair(2, COLOR_WHITE, COLOR_BLUE);

  // create windows
  red = newwin(10, 20, 2, 22);
  blue = newwin(10, 20, 5, 32);
  if (red == NULL || blue==NULL) { // check if windows were made
    endwin();
    puts("Unable to create windows");
    return 0;
  }

  // color and fill windows
  wbkgd(red, COLOR_PAIR(1) | 'r');
  mvwaddstr(red, 1, 1, "test   text");      
  wrefresh(red);
  getch();
  wbkgd(blue, COLOR_PAIR(2) | 'b');
  wrefresh(red);
  wrefresh(blue);
  getch();

  // overwrite window
  overwrite(red, blue);
  wclear(red);
  wrefresh(red);
  getch();
  wrefresh(blue);
  getch();

  endwin();
  return 0;
}
