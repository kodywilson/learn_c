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

  colouring();

  addstr("\nPress any key to exit...");
  refresh();

  getch(); // get keypress
 
  endwin(); // close ncurses

  return EXIT_SUCCESS;
}

void printing() {
  // addstr: prints the specified string. You can use control characters.
  addstr("This was printed using addstr\n\n");
  refresh();

  addstr("The following letter was printed using addch: - ");
  addch('a'); // prints the character specified
  refresh();

  printw("\n\nThese numbers were printed using printw\n%d\n%f\n", 123, 456.789);
  refresh();
}

void moving_and_sleeping() {
  int row = 5; // set cursor row
  int col = 0; // set cursor column

  curs_set(0); // hide or show the cursor (0) for hide (1) for show

  for(char c = 65; c <= 90; c++) {
    move(row++, col++); // increment row and column
    addch(c); // print each character
    refresh();
    napms(100); // pause (nap for milliseconds)
  }

  row = 5;
  col = 3;

  for(char c = 97; c <= 122; c++) {
    mvaddch(row++, col++, c);
    refresh();
    napms(100);
  }

  curs_set(1);

  addch('\n');
}

void colouring() {
  if(has_colors()) {  // check that terminal has color capability
    if(start_color() == OK) { // start color if possible
      init_pair(1, COLOR_YELLOW, COLOR_RED); // create foreground, background color pairs
      init_pair(2, COLOR_GREEN, COLOR_GREEN);
      init_pair(3, COLOR_MAGENTA, COLOR_CYAN);

      attrset(COLOR_PAIR(1)); // set color
      addstr("Yellow and red\n\n");
      refresh();
      attroff(COLOR_PAIR(1)); // remove color

      attrset(COLOR_PAIR(2));
      attrset(A_BOLD); // set bold
      addstr("Green and green A_BOLD\n\n");
      refresh();
      attroff(COLOR_PAIR(2));
      attroff(A_BOLD); // remove bold

      attrset(COLOR_PAIR(3));
      addstr("Magenta and cyan\n");
      refresh();
      attroff(COLOR_PAIR(3));
    } else {
      addstr("Cannot start colors\n");
      refresh();
    }
  } else {
    addstr("Not color capable\n");
    refresh();
  }
}
