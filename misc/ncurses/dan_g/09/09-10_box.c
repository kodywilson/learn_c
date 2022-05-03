#include <ncurses.h>

int main() {
  initscr();

  box(stdscr, 0, 0);
  mvaddstr(1, 1, "This is a box");
  refresh();
  getch();

  endwin();
  return 0;
}
