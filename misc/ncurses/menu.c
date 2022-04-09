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

  char *choices[4] = {"Walk", "Jog", "Run", "Yoga"};
  int choice;
  int highlight = 0;

  while(1) {
    for (int i = 0; i < 4; i++) {
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
        if (highlight < 3) highlight++;
        break;
      default:
        break;
    }
    if(choice == 10)
      break;
  }

  printw("Your choice was: %s", choices[highlight]);

  getch();
  endwin();

  return 0;
}
