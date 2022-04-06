#include <ncurses.h>

int main() {
  initscr();  // initialize the screen, set up memory, clear screen

  printw("This is a test\n"); // print to window
  addstr("Hello World!\n"); // add string
  addstr("Yo!\n");

  refresh(); // refreshes screen with any updates

  int ch = getch(); // waits for input from user

  printw("\nYou pressed %c\n", (char) ch);

  getch();

  endwin(); // deallocates memory and ends ncurses

  return 0;
}
