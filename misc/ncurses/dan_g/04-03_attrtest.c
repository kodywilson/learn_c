#include <ncurses.h>

int main() {
  initscr();

  attrset(A_STANDOUT);
  addstr("This is A_STANDOUT\n");

  getch();

  endwin();
  return 0;
}
