#include <ncurses.h>

int main() {
  initscr();                  // start curses mode
  printw("Hello World!!!");   // Print Hello World
  refresh();                  // Put on screen
  getch();                    // Wait for user input
  endwin();                   // end curses mode

  return 0;
}
