#include <ncurses.h>

int main() {
  WINDOW *sub;

  initscr();

  sub = derwin(stdscr, LINES / 2, COLS / 2, LINES / 4, COLS / 4);
  if (sub == NULL) {
    endwin();
    puts("Unable to create subwindow");
    return 1;
  }

  // draw a box around stdscr
  box(stdscr, 0, 0);
  addstr("I'm writing text\n");
  addstr("to the standard screen.");
  refresh();
  getch();
  // put text to the subwindow
  box(sub, 0, 0);
  mvwaddstr(sub, 1, 1, "I'm in the subwindow.");
  wrefresh(sub);
  getch();

  // clear subwindow
  wclear(sub);
  wrefresh(sub);
  getch();

  endwin();
  return 0;
}
