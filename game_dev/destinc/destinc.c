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
  stats     = newwin(3, (max_x * 7) / 8, 0, max_x / 16);
  //game_text = newwin(max_y * 2 / 3, max_x, max_y / 12, 0);
  game_text = newwin(max_y * 2 / 3, max_x, 3, 0);
  select    = newwin(max_y / 4, max_x, (max_y * 3) / 4, 0);
  input     = newwin(2, max_x / 3, max_y / 2, max_x / 3);

  getmaxyx(stats, stats_y, stats_x); // dimensions of stats window

  clear_box(stats);
  clear_box(game_text);
  clear_box(select);
  clear_box(input);

  keypad(select, true); // enable the keypad on the select window

  wattron(game_text, COLOR_PAIR(4));

  // setup game directory and save file if needed
  setup_file(game_text, select);

  // check for existing save
  if (file_there(save_file)) {
    if (check_saves()) {
      mvwaddstr(game_text, 5, 3, "Saved games found. (Yes) to load last save. (No) to create new game.");
      wrefresh(game_text);
      choice = choose(select, yes_no, 2) + 1;
      if (choice == 1) load_game(&player);
      else {
        mvwaddstr(game_text, 7, 3, "Ok, you chose to create a new game.");
        mvwaddstr(game_text, 8, 3, "This will remove the current save game. Are you sure?");
        wrefresh(game_text);
        choice = choose(select, yes_no, 2) + 1;
        if (choice == 1) {
          trunc_file(save_file);
          clear_box(game_text);
          mvwaddstr(game_text, 3, 3, "Now let's create a new character.");
          wrefresh(game_text);
          create_character(game_text, select, &player);
          save_game(player);
        } else {
          mvwaddstr(game_text, 3, 3, "Ok, fair enough. Let's load the last saved game.");
          wrefresh(game_text);
          napms(2000);
          load_game(&player);
        }
      }
    } else {
      mvwaddstr(game_text, 5, 3, "No saved games found. Let's create a character!");
      wrefresh(game_text);
      napms(2000);
      create_character(game_text, select, &player);
      save_game(player);
    }
  } else {   // this needs to be updated to create file if missing
    mvwaddstr(game_text, 5, 3, "There is no save game file!");
    wrefresh(game_text);
    getch();
  }

  // Main game loop
  clear_box(select);
  wrefresh(select);
  wattron(stats, COLOR_PAIR(6) | A_BOLD);
  mvwaddstr(stats, 0, (stats_x / 2) - 3, " Stats ");
  wattroff(stats, COLOR_PAIR(6) | A_BOLD);
  mvwprintw(stats, stats_y / 2, stats_x / 6, "Name: %s  |  HP: %d  |  Mana: 50  |  XP: 10", player.name, player.hp);
  wrefresh(stats);
  clear_box(game_text);
  mvwprintw(game_text, 3, 3, "Greetings brave %s! Welcome to your Destiny...", player.name);
  mvwprintw(game_text, 4, 3, "You are a %s with %d hit points (life).", player.role, player.hp);
  wrefresh(game_text);
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

