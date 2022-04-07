#include <ncurses.h>

int main() {

  //start_ncurses(true, true);
  initscr();

  // A_STANDOUT and A_REVERSE are same on my terminal
  // A_BLINK works on my terminal
  attron(A_BLINK);
  printw("This is some sample text");
  attroff(A_BLINK);

  getch();

  endwin();

  return 0;
}
