#include <ncurses.h>
#include <stdlib.h>

// prototypes
void printing();
void moving_and_sleeping();
void colouring();

int main(void) {
  initscr(); // initialize the screen

  addstr("-----------------\n| Hello world! |\n| ncurses Demo  |\n-----------------\n\n");
  refresh(); // refresh the screen with any updates like the addstr above

  //printing();

  //moving_and_sleeping();

  //colouring();

  addstr("\nPress any key to exit...");
  refresh();

  getch();

  endwin();

  return EXIT_SUCCESS;
}
