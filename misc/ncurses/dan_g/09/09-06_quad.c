#include <ncurses.h>

int main() {
  int max_y, max_x;
  WINDOW *upper_left, *upper_right, *lower_left, *lower_right;

  initscr();
  getmaxyx(stdscr, max_y, max_x);

  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLUE);
  init_pair(3, COLOR_RED, COLOR_GREEN);
  init_pair(4, COLOR_RED, COLOR_WHITE);

  upper_left  = newwin(max_y / 2, max_x / 2, 0, 0);
  upper_right = newwin(max_y / 2, max_x / 2, 0, max_x / 2);
  lower_left  = newwin(max_y / 2, max_x / 2, max_y / 2, 0);
  lower_right = newwin(max_y / 2, max_x / 2, max_y / 2, max_x / 2);

  box(upper_left, 0, 0);
  wbkgd(upper_left, COLOR_PAIR(1));
  mvwaddstr(upper_left, 1, 1, "This is a quarter window");
  box(upper_right, 0, 0);
  wbkgd(upper_right, COLOR_PAIR(2));
  mvwaddstr(upper_right, 1, 1, "This is a quarter window");
  box(lower_left, 0, 0);
  wbkgd(lower_left, COLOR_PAIR(3));
  mvwaddstr(lower_left, 1, 1, "This is a quarter window");
  box(lower_right, 0, 0);
  wbkgd(lower_right, COLOR_PAIR(4));
  mvwaddstr(lower_right, 1, 1, "This is a quarter window");

  refresh();
  getch();
  wrefresh(upper_left);
  wrefresh(upper_right);
  wrefresh(lower_left);
  wrefresh(lower_right);
  //refresh();

  getch();

  endwin();
  return 0;

}
