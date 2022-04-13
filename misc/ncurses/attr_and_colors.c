#include <ncurses.h>

int main() {

  initscr();
  // check if terminal supports color
  if (!has_colors()) {
    printw("Terminal does not support color");
    getch();
    return -1;
  }

  start_color(); // setup color

  init_pair(1, COLOR_RED, COLOR_BLACK);

  // A_STANDOUT and A_REVERSE are same on my terminal
  // A_BLINK works on my terminal
  attron(COLOR_PAIR(1));
  printw("This is some sample text");
  attroff(COLOR_PAIR(1));

  if (can_change_color()) {
    printw("Can change color - turning red to cyan");
    init_color(COLOR_RED, 9, 999, 999); // changes red to cyan
  }

  attron(COLOR_PAIR(1));
  printw("This is more sample text");
  attroff(COLOR_PAIR(1));

  getch();

  endwin();

  return 0;
}
