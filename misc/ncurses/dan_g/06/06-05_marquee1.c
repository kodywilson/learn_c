#include <ncurses.h>
#include <string.h>

int main() {

  char text[] = "Armstrong walks on moon!";
  char *t;
  int len;

  initscr();

  len = strlen(text);
  t = text; // initialize pointer

  while(len) {
    move(5, 5);  // insert at same spot
    insch(*(t+len-1)); // work backwards
    refresh();
    napms(100);
    len--;
  }

  getch();

  endwin();
  return 0;
}
