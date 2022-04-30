#include <ncurses.h>
#include <string.h>

int main() {

  char text[] = "Armstrong walks on moon!";
  char *t;
  char a;
  int len;

  initscr();

  len = strlen(text);
  t = text; // initialize pointer
  mvprintw(4, 5, "The length of string is %d", len);

  move(5, 0); // show line of text
  for(a = 'A'; a < 'Z' + 1; a++) {
    addch(a);
    addstr("  "); // two spaces
  }

  while(len) {
    move(5, 5);  // insert at same spot
    insch(*(t+len-1)); // work backwards
    move(6, 5);  // insert at same spot
    insch(text[len-1]); // work backwards
    refresh();
    napms(100);
    len--;
  }

  getch();

  endwin();
  return 0;
}
