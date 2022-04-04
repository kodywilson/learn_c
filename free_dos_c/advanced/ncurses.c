#include <ncurses.h>

int main() {
  initscr();                  // start curses mode
  printw("Hello World!!!");   // Print Hello World
  refresh();                  // Put on screen // like fflush in conio
  getch();                    // Wait for user input
  endwin();                   // end curses mode

  return 0;
}
