#include <ncurses.h>

int main() {
  initscr();  // initialize the screen, set up memory, clear screen

  refresh(); // refreshes screen with any updates

  getch(); // waits for input from user

  endwin(); // deallocates memory and ends ncurses

  return 0;
}
