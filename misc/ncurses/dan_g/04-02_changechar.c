#include <ncurses.h>

int main() {
  initscr();

  addch('c');
  addch(A_BOLD | 'a');
  addch(A_REVERSE | 't');
  refresh();
  getch();

  // replace the t with r
  move(0,2);
  addch('r');
  refresh();
  getch();

  //replace the r with a b
  move(0,2);
  addch(A_REVERSE | 'b');
  refresh();
  getch();

  endwin();
  return 0;
}
