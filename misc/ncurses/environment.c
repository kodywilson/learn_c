#include <ncurses.h>
//#include <string.h>

void start_ncurses(bool useRaw, bool useNoecho);
//void printMenu(WINDOW *menu, string choices[], int size, int highlight);

int main() {
  // start ncurses
  initscr();
  noecho();
  cbreak();

  int y, x, yBeg, xBeg, yMax, xMax;

  WINDOW *win = newwin(10, 20, 10, 10);

  getyx(stdscr, y, x);
  getbegyx(win, yBeg, xBeg);
  getmaxyx(stdscr, yMax, xMax);

  // mvprintw(yMax/2, xMax/2, "Hello");

  mvprintw(yMax/2, xMax/2, "%d %d %d %d %d %d", y, x, yBeg, xBeg, yMax, xMax); // DEBUG

  getch();
  endwin();

  return 0;
}
