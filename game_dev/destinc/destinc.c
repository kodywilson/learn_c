//      ---||  Destiny  ||---
// C port of original game written in Ruby
// by Kody Wilson

#include "dice.h"
#define MOVE_TEXT 6
#include "text.h"
#include <ncurses.h>
#include <string.h>
#define ROLLS 1000
#define STARS 100
#include "graphics.h"
#include "choices.h"
#include "file.h"

//#define GAME_DIR ".destiny"
//#define SAVE_FILE "saves.txt"
#define INPUT_MAX 33
#define PATH_MAX 256

// function prototypes

int main() {
  srand(time(0)); // seed rand using time
  //FILE *fp;       // file pointer for save
  //int min = 24, max = 0, roll;
  int choice, max_y, max_x, stats_y, stats_x;
  //char name[INPUT_MAX], filepath[PATH_MAX], *yes_no[2] = {"Yes", "No"};
  char *yes_no[2] = {"Yes", "No"};
  WINDOW *game_text, *select, *input, *stats;

  // setup up initial ncurses parameters
  initscr();
  noecho();
  cbreak();
  start_color(); // update this to check for success!

  // set up some colors
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);
  init_pair(6, COLOR_YELLOW, COLOR_BLACK);

  getmaxyx(stdscr, max_y, max_x);
  curs_set(0); // turn off visible cursor

  stars(stdscr, STARS);  // draw stars on the whole screen

  clear();
  refresh();

  // after intro, set up interface
  stats     = newwin(3, (max_x * 2) / 3, 0, max_x / 6);
  game_text = newwin(max_y * 2 / 3, max_x, max_y / 12, 0);
  select    = newwin(max_y / 4, max_x, (max_y * 3) / 4, 0);
  input     = newwin(2, max_x / 3, max_y / 2, max_x / 3);

  getmaxyx(stats, stats_y, stats_x);

  box(stats, 0, 0);
  box(game_text, 0, 0);
  box(select, 0, 0);
  box(input, 0, 0);

  keypad(select, true); // enable the keypad on the select window

  wattrset(game_text, COLOR_PAIR(4));

  // setup game directory and save file if needed
  setup_file(game_text, select);

  // add some placeholder text to boxes
  attrset(COLOR_PAIR(6) | A_BOLD);
  mvaddstr(0, (max_x / 2) - 5, " Stats ");
  mvwaddstr(stats, stats_y / 2, stats_x / 6, "Name: Bob  |  HP: 100  |  Mana: 50  |  XP: 10");
  wrefresh(stats);
  wrefresh(game_text);
  choice = choose(select, yes_no, 2);
  wrefresh(select);
  //wrefresh(input);

  getch();


  // display stars
  //for (int i = 0; i < STARS; i++) {
  //}

  /*for(int i = 0; i < ROLLS; i++) {
    roll = dice(4, 6);
    if ( roll > max ) max = roll;
    if ( roll < min ) min = roll;
  }
  printf("We rolled four d6 a %d times and got the following\n", ROLLS);
  printf("Min: %d\t\tMax: %d\n", min, max);

  printf("Test text is %s \n", rand_move_text[dice(1, MOVE_TEXT) - 1]);
*/
  endwin();
  return 0;
}

