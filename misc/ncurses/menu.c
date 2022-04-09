#include <ncurses.h>
//#include <string.h>

int main() {
  // start ncurses
  initscr();
  noecho();
  cbreak();

  int yMax, xMax;

  getmaxyx(stdscr, yMax, xMax); // get terminal size

  // Create window for input
  WINDOW *menuwin = newwin(6, xMax-12, yMax-8, 5);
  box(menuwin, 0, 0);
  refresh();  // refresh screen with updates
  wrefresh(menuwin);  // refresh window with updates
  keypad(menuwin, true); // enables arrow keys

  char *choices[3] = {"Walk", "Jog", "Run"};
  int choice;
  int highlight = 0;

  while(1) {
    for (int i = 0; i < 3; i++) {
      if (i == highlight) wattron(menuwin, A_REVERSE);
      mvwprintw(menuwin, i+1, 1, choices[i]);
      wattroff(menuwin, A_REVERSE);
    }
    choice = wgetch(menuwin);

    switch(choice) {
      case KEY_UP:
        if (highlight > 0) highlight--;
        break;
      case KEY_DOWN:
        if (highlight < 2) highlight++;
        break;
      default:
        break;
    }
    if(choice == 10)
      break;
  }
  // get user input
  int c = wgetch(menuwin);
  // KEY_UP KEY_LEFT KEY_F(function key) KEY_DOWN KEY_RIGHT
  if (c == KEY_UP) {
    mvwprintw(menuwin, 1, 1, "You pressed the up key!");
    wrefresh(menuwin);
  }

  // mvprintw(yMax/2, xMax/2, "Hello");

  //mvprintw(yMax/2, xMax/2, "%d %d %d %d %d %d", y, x, yBeg, xBeg, yMax, xMax); // DEBUG

  getch();
  endwin();

  return 0;
}
