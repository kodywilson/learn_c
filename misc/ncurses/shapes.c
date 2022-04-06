// take number and create shapes with that length sides
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int any_key(void) {
  printw("Press any key...\n");
  int ch = getch();
  return ch;
}

void boxy(int length) {
  clear();
  int x, y;
  x = y = 10;
  move(y, x); // with ncurses, and and y are inversed, y is lines and x is columns
  // print top
  for(int i = 0; i < length; i++) {
    printw("*");
    refresh();
    napms(100);
    x++;
    move(y, x);
  }
  // print right side
  for(int i = 0; i < length; i++) {
    printw("*");
    refresh();
    napms(100);
    y++;
    move(y, x);
  }
  //print lower side
  for(int i = 0; i < length; i++) {
    printw("*");
    refresh();
    napms(100);
    x--;
    move(y, x);
  }
  // print left side
  for(int i = 0; i < length; i++) {
    printw("*");
    refresh();
    napms(100);
    y--;
    move(y, x);
  }
}

int main(int argc, char **argv) {
  initscr();

  if (argc < 2) {
    printw("Pass a single integer greater than one and less than 20\n");
    any_key();
    endwin();
    return 1;
  }

  int length = atoi(argv[1]);
  printw("You entered %d\n", length);

  boxy(length);

  getch();

  endwin();

  return 0;
}
