#include <ncurses.h>

int main() {
  int value = 0;

  initscr();

  addstr("Press any key to begin:\n");
  refresh();
  getch();

  // turn off getch() wait
  nodelay(stdscr, TRUE);
  addstr("Press the space bar to stop the loop!\n");
  while ( getch() != ' ' ) {
    printw("%d\r", value++);
    refresh();
    napms(100);
  }

  endwin();
  return 0;
}
