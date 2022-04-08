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

  getyx(stdscr, y, x); // start position 0, 0
  getbegyx(stdscr, yBeg, xBeg); 
  getmaxyx(stdscr, yMax, xMax); // get terminal size

  // Create window for input
  WINDOW *inputwin = newwin(3, xMax-12, yMax-5, 5);
  box(inputwin, 0, 0);
  refresh();
  wrefresh(inputwin);

  // get user input
  int c = wgetch(inputwin);
  if (c == 'j') {
    mvwprintw(inputwin, 1, 1, "You pressed j!");
    wrefresh(inputwin);
  }

  // mvprintw(yMax/2, xMax/2, "Hello");

  //mvprintw(yMax/2, xMax/2, "%d %d %d %d %d %d", y, x, yBeg, xBeg, yMax, xMax); // DEBUG

  getch();
  endwin();

  return 0;
}
