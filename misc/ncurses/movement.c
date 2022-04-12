// move character around the terminal

#include <ncurses.h>

struct Player {
  char rep;
  int y, x, old_y, old_x;
};

int main() {

  struct Player bob;

  initscr();
  noecho();
  cbreak();
  curs_set(0); // set cursor to invisible

  // get terminal stats
  int choice, yMax, xMax, yMax_term, xMax_term;
  getmaxyx(stdscr, yMax_term, xMax_term);
  keypad(stdscr, true);

  // create room for player to start in
  WINDOW *playwin = newwin(20, 50, (yMax_term/2)-10, xMax_term/10); // will change on terminal resize
  box(playwin, 0, 0);
  refresh();
  wrefresh(playwin);

  // draw player on the screen
  getmaxyx(playwin, yMax, xMax);
  bob.y = 1;
  bob.x = 1;
  bob.rep = '@';

  // start game - handle movement and wall detection
  do {
    mvwaddch(playwin, bob.y, bob.x, bob.rep);
    wrefresh(playwin);
    bob.old_y = bob.y; // track previous position so we can clear it
    bob.old_x = bob.x;
    choice = getch();
    switch (choice) {
      case KEY_UP: if (bob.y > 1) bob.y--; break;
      case KEY_DOWN: if (bob.y < yMax - 2) bob.y++; break;
      case KEY_RIGHT: if (bob.x < xMax - 2) bob.x++; break;
      case KEY_LEFT: if (bob.x > 1) bob.x--; break;
      default: break;
    }
    if (choice == 113) break;
    mvwaddch(playwin, bob.old_y, bob.old_x, ' ');
    wrefresh(playwin);
  }
  while (1); 
  
  //getch(); // maybe add game over screen?

  endwin();

  return 0;
}
