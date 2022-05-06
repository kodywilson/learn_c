#include <ncurses.h>

int main() {
  WINDOW *one, *two;

  initscr();
  refresh();

  one = newwin(LINES, COLS / 2, 0, 0);
  two = newwin(LINES, COLS / 2, 0, COLS / 2);

  if ( one == NULL || two == NULL ) {
    endwin();
    puts("Unable to create windows");
    return 1;
  }

  wbkgd(one, '|');
  waddstr(one, "Window One\n");
  wbkgd(two, '-');
  waddstr(two, "Window Two\n");

  // update screen
  wrefresh(one);
  getch();
  wrefresh(two);
  getch();

  // remove window 1
  wclear(one);
  wrefresh(one);
  delwin(one);
  waddstr(two, "Window one deleted\n");
  wrefresh(two);
  getch();

  endwin();
  return 0;
}
