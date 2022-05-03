#include <ncurses.h>

int main() {
  WINDOW *sub;

  initscr();

  sub = subwin(stdscr, LINES / 2, COLS / 2, LINES / 4, COLS / 4);
  if (sub == NULL) {
    endwin();
    puts("Unable to create subwindow");
    return 1;
  }

  // draw a box around stdscr
  box(stdscr, 0, 0);
  // put text to the subwindow
  box(sub, 0, 0);
  mvwaddstr(sub, 1, 1, "I'm in the subwindow.");
  refresh();
  getch();

  endwin();
  return 0;
}
