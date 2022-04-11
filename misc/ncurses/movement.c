// move character around the terminal

#include <ncurses.h>

struct Player {
  char rep[2];
  int y, x, old_y, old_x;
};

int main() {

  struct Player bob;

  initscr();
  noecho();
  curs_set(0); // set cursor to invisible

  // get terminal stats
  int choice, yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);
  keypad(stdscr, true);

  // draw player on the screen
  bob.y = bob.x = 0;
  bob.rep[0] = '@';
  bob.rep[1] = '\0';

  while (1) {
    mvprintw(bob.y, bob.x, bob.rep);
    bob.old_y = bob.y; // track previous position so we can clear it
    bob.old_x = bob.x;
    choice = getch();
    switch (choice) {
      case KEY_UP: if (bob.y > 0) bob.y--; break;
      case KEY_DOWN: if (bob.y < yMax) bob.y++; break;
      case KEY_RIGHT: if (bob.x < xMax) bob.x++; break;
      case KEY_LEFT: if (bob.x > 0) bob.x--; break;
      default: break;
    }
    if (choice == 113) break;
    mvaddch(bob.old_y, bob.old_x, ' ');
  }
  
  // getch(); // maybe add game over screen?

  endwin();

  return 0;
}
