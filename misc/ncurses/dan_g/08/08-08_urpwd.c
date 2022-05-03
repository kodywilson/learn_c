#include <ncurses.h>

int main() {
  char name[32];
  char pass[32];

  initscr();

  addstr("Name: ");
  getnstr(name, 31);
  noecho(); // disable text output for taking password
  addstr("Password: ");
  getnstr(pass, 31);
  echo();
  printw("%s's password is '%s'\n", name, pass);
  refresh();
  getch();

  endwin();
  return 0;
}
