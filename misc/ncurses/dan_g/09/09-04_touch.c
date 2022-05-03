#include <ncurses.h>

int main() {
  int ch;
  WINDOW *second;

  initscr();
  start_color();

  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_WHITE, COLOR_RED);

  // create and configure second window
  second = newwin(0, 0, 0, 0);
  if (second == NULL) {
    endwin();
    puts("Unable to create window");
    return 1;
  }

  wbkgd(second, COLOR_PAIR(2));
  waddstr(second, "This is the second window\n");

  // setup standard screen
  bkgd(COLOR_PAIR(1));
  addstr("This is the standard screen\n");
  addstr("Press ~ to exit, any other key to switch");

  // loop displaying screens until ~ is pressed
  do {
    // setup standard screen
    touchwin(stdscr);
    refresh();
    ch = getch();
    if ( ch == '~' ) break;

    // show second window
    touchwin(second);
    wrefresh(second);
    ch = getch();
  } while ( ch != '~' );

  endwin();
  return 0;
}
