#include <ncurses.h>

int main() {
  initscr();  // initialize the screen, set up memory, clear screen

  int x, y;
  x = y = 10;

  move(y, x); // y is lines and x is columns (characters)

  printw("Hello World!\n"); // print to window

  //refresh(); // refreshes screen with any updates

  int ch = getch(); // waits for input from user
  clear(); // clear the screen

  //move(0, 0);
  //printw("\nYou pressed %c\n", (char) ch);

  // move and print at the same time
  mvprintw(0 ,0, "You pressed %c\n", (char) ch);
  getch();

  endwin(); // deallocates memory and ends ncurses

  return 0;
}
