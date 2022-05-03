#include <ncurses.h>

#define NAME 33
int main() {
  char first[NAME];
  char last[NAME];

  initscr();

  addstr("Please enter your first name: ");
  getnstr(first, NAME - 1);
  addstr("Last name: ");
  getnstr(last, NAME - 1);
  printw("Pleased to meet you, %s %s\n", first, last);
  refresh();
  getch();

  endwin();
  return 0;
}
