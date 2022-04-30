#include <ncurses.h>

int main() {
  initscr();

  addstr("Where did that silly cat go?");
  refresh();
  getch();

  move(0, 15);
  for (int i = 0; i < 5; i++) {
    delch();
    napms(250);
    refresh();
  }
  getch();

  move(0, 15);
  insch('t');
  napms(250);
  refresh();
  insch('a');
  napms(250);
  refresh();
  insch('f');
  napms(250);
  refresh();

  getch();

  endwin();
  return 0;

}
  
