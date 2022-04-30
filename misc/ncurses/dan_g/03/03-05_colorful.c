#include <ncurses.h>

int main() {

  initscr();
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_RED); // foreground, background
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  attrset(COLOR_PAIR(1));
  addstr("I am Mr. Black!\n");
  attrset(COLOR_PAIR(2));
  addstr("I am Mr. Yellow!\n");
  attrset(COLOR_PAIR(1) | A_BOLD); // color + bold
  addstr("I'm feeling bold!\n");
  attrset(COLOR_PAIR(2) | A_BOLD);
  addstr("Me too!");
  refresh();

  getch();
  
  endwin();
  return 0;
}
