#include <ncurses.h>

int main() {
  initscr();
  char text[] = "Greetings from nCurses! How are you today?";
  char *t;

  t = text;  // initialize pointer

  while (*t) {  // loop through the string
    addch(*t);  // add one character
    t++;        // increment pointer
    refresh();  // update the screen
    napms(100); // delay .1 sec
  }

  getch();

  endwin();

  return 0;
}
