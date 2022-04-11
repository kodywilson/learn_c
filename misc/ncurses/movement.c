// move character around the terminal

#include <ncurses.h>

struct Player {
  char rep[2];
  int y;
  int x;
};

int main() {

  struct Player bob;
  

  initscr();
  noecho();
  // get terminal stats
  int choice;//, yMax, xMax;
  //getmaxyx(stdscr, yMax, xMax);
  keypad(stdscr, true);

  // draw player on the screen
  bob.y = bob.x = 0;
  bob.rep[0] = '@';
  bob.rep[1] = '\0';

  while (1) {
    mvprintw(bob.y, bob.x, bob.rep);
    choice = getch();
    switch (choice) {
      case KEY_UP: bob.y--; break;
      case KEY_DOWN: bob.y++; break;
      case KEY_RIGHT: bob.x++; break;
      case KEY_LEFT: bob.x--; break;
      default: break;
    }
    if (choice == 113) break;
  }
  
  getch();

  endwin();

  return 0;
}
