#include <ncurses.h>

int main() {
  int ch, max_y, max_x;
  WINDOW *tiny;

  initscr();
  start_color();
  getmaxyx(stdscr, max_y, max_x);

  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_WHITE, COLOR_RED);

  // create and configure tiny window
  tiny = newwin(max_y / 2, max_x / 2, max_y / 4, max_x / 4);
  if (tiny == NULL) {
    endwin();
    puts("Unable to create window");
    return 1;
  }

  wbkgd(tiny, COLOR_PAIR(2));
  waddstr(tiny, "This a tiny window\n");

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
    touchwin(tiny);
    wrefresh(tiny);
    ch = getch();
  } while ( ch != '~' );

  endwin();
  return 0;
}
