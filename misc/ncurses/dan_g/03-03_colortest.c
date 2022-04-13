#include <ncurses.h>

int main() {
  initscr();

  // test for color capability
  if (!has_colors()) {
    endwin();
    puts("Terminal cannot do colors");
    return 1;
  }

  // see if start_colors works
  if (start_color() != OK) {
    endwin();
    puts("Unable to start colors");
    return 1;
  }

  // colors are ok, continue
  printw("Colors initialized\n");
  printw("%d colors available\n", COLORS);
  printw("%d color pairs\n", COLOR_PAIRS);
  refresh();
  getch();

  endwin();
  return 0;
}
