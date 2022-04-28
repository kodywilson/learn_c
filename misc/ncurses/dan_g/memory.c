#include <ncurses.h>

int main() {
  initscr();
  start_color();
 
  init_pair(1, COLOR_BLACK, COLOR_RED);
  attrset(COLOR_PAIR(1));
  addstr("This is a test!\n");

  getch();

  endwin();
  return 0;

}
