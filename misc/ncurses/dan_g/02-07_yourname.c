#include <ncurses.h>

int main() {
  char first[24];
  char last[32];

  initscr(); // initialize ncurses

  addstr("What is your first name? ");
  refresh();
  getnstr(first, 23);

  addstr("What is your last name? ");
  refresh();
  getnstr(last, 31);

  printw("Pleased to meet you, %s %s!", first, last);
  refresh();
  getch();

  endwin(); // clean up and exit
  return 0;
}
