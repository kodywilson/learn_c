#include <ncurses.h>

int main() {
  initscr();
  start_color();
  
  addstr("This is a test!\n");

  getch();

  endwin();
  return 0;

}
