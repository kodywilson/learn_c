//      ---||  Destiny  ||---
// C port of original game written in Ruby
// by Kody Wilson

#include "dice.h"
#include "text.h"
#include <ncurses.h>
#include "graphics.h"
#include "choices.h"
#include "file.h"
#include "entities/pc.h"
#include "game_mechanics/character.h"

#define INPUT_MAX 33

// function prototypes

int main() {
  srand(time(0)); // seed rand using time
  //int min = 24, max = 0, roll;
  int choice, max_y, max_x, stats_y, stats_x;
  pc player; // create player struct

  //char name[INPUT_MAX], filepath[PATH_MAX], *yes_no[2] = {"Yes", "No"};
  WINDOW *game_text, *select, *input, *stats;

  // initialize global variables
  file_init();

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

  stars(stdscr, 100);  // draw stars on the whole screen

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

  // check for existing save
  if (file_there(save_file)) {
    if (check_saves()) {
      mvwaddstr(game_text, 5, 3, "Saved games found. Would you like to load one or start a new game?");
      wrefresh(game_text);
      //if (choose(yes_no) == 1)  
    } else {
      mvwaddstr(game_text, 5, 3, "No saved games found. Let's create a character!");
      wrefresh(game_text);
      getch();
      create_character(&player);
      mvwprintw(game_text, 6, 3, "Hi %s, you are a %s with %d hit points (life).", player.name, player.role, player.hp);
      save_game(player);
      wrefresh(game_text);
      getch();
    }
  } else {
    mvwaddstr(game_text, 5, 3, "There is no save game file!");
    wrefresh(game_text);
    getch();
  }

  // add some placeholder text to boxes
  wattron(stats, COLOR_PAIR(6) | A_BOLD);
  mvwaddstr(stats, 0, (stats_x / 2) - 3, " Stats ");
  wattroff(stats, COLOR_PAIR(6) | A_BOLD);
  mvwaddstr(stats, stats_y / 2, stats_x / 6, "Name: Bob  |  HP: 100  |  Mana: 50  |  XP: 10");
  wrefresh(stats);
  wrefresh(game_text);
  wrefresh(select);
  //wrefresh(input);

  getch();

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

