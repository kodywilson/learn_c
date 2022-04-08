#include <ncurses.h>
//#include <string.h>

int main() {
  // start ncurses
  initscr();
  noecho();
  cbreak();

  int yMax, xMax;

  getmaxyx(stdscr, yMax, xMax); // get terminal size

  // Create window for input
  WINDOW *menuwin = newwin(6, xMax-12, yMax-8, 5);
  box(menuwin, 0, 0);
  refresh();
  wrefresh(menuwin);
  keypad(menuwin, true); // enables arrow keys

  // get user input
  int c = wgetch(menuwin);
  // KEY_UP KEY_LEFT KEY_F(function key) KEY_DOWN KEY_RIGHT
  if (c == KEY_UP) {
    mvwprintw(menuwin, 1, 1, "You pressed the up key!");
    wrefresh(menuwin);
  }

  // mvprintw(yMax/2, xMax/2, "Hello");

  //mvprintw(yMax/2, xMax/2, "%d %d %d %d %d %d", y, x, yBeg, xBeg, yMax, xMax); // DEBUG

  getch();
  endwin();

  return 0;
}
