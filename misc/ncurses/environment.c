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

  getyx(stdscr, y, x);
  getbegyx(stdscr, yBeg, xBeg);
  getmaxyx(stdscr, yMax, xMax);

  printw("%d %d %d %d %d %d", y, x, yBeg, xBeg, yMax, xMax);

  getch();
  endwin();

  return 0;
}
