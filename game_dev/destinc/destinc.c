//      ---||  Destiny  ||---
// C port of original game written in Ruby
// by Kody Wilson

#include "includes.h"

#define INPUT_MAX 33

// function prototypes

int main() {
  srand(time(0)); // seed rand using time
  //int min = 24, max = 0, roll;
  int choice, max_y, max_x, stats_y_border, stats_y, stats_x_border, stats_x;
  pc player; // create player struct

  //char name[INPUT_MAX], filepath[PATH_MAX], *yes_no[2] = {"Yes", "No"};
  WINDOW *game_text_border, *select_border, *stats_border;
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
  // borders are set and rarely updated. Information is displayed
  // in window nested in the border so it can be cleared easily
  stats_border     = newwin(3, (max_x * 7) / 8, 0, max_x / 16);
  stats            = newwin(1, ((max_x * 7) / 8) - 2, 1, (max_x / 16) + 1);
  game_text_border = newwin(max_y * 9 / 15, max_x, 3, 0);
  game_text        = newwin((max_y * 9 / 15) - 2, max_x - 2, 4, 1);
  select_border    = newwin(max_y * 5 / 16, max_x, (max_y * 23) / 32, 0);
  select           = newwin((max_y * 5 / 16) - 2, max_x - 2, ((max_y * 23) / 32) + 1, 1);
  input            = newwin(3, max_x / 2, max_y / 2, max_x / 4);

  getmaxyx(stats_border, stats_y_border, stats_x_border); // dimensions of stats border window
  getmaxyx(stats, stats_y, stats_x);  // dimensions of stats window

  clear_box(stats_border);
  clear_box(game_text_border);
  clear_box(select_border);
  clear_box(input);
  wrefresh(game_text_border);
  wrefresh(select_border);

  keypad(select, true); // enable the keypad on the select window

  wattron(game_text, COLOR_PAIR(4));

  // setup game directory and save file if needed
  setup_file(game_text, select);

  // check for existing save
  if (file_there(save_file)) {
    if (check_saves()) { // below, totally lame way to hide warning about unused stats_y_border
      mvwaddstr(game_text, 2, stats_y_border, "I noticed you already have a saved game going!");
      mvwaddstr(game_text, 4, 3, "Choose (Yes) to load last save, (No) to create a new game.");
      wrefresh(game_text);
      choice = choose(select, yes_no, 2) + 1;
      if (choice == 1) load_game(&player);
      else {
        mvwaddstr(game_text, 6, 3, "Ok, you chose to create a new game.");
        mvwaddstr(game_text, 7, 3, "This will remove the current save game. Are you sure?");
        wrefresh(game_text); // below, totally lame way to hide warning about unused stats_y
        choice = choose(select, yes_no, 2) + stats_y;
        if (choice == 1) {
          trunc_file(save_file);
          wclear(game_text);
          mvwaddstr(game_text, 2, 3, "Now let's create a new character.");
          wrefresh(game_text);
          create_character(game_text, select, input, &player);
          save_game(player);
        } else {
          wclear(game_text);
          mvwaddstr(game_text, 2, 3, "Ok, fair enough. Let's load the last saved game.");
          wrefresh(game_text);
          napms(2000);
          load_game(&player);
        }
      }
    } else {
      mvwaddstr(game_text, 2, 3, "No saved games found. Let's create a character!");
      wrefresh(game_text);
      napms(2000);
      create_character(game_text, select, input, &player);
      save_game(player);
    }
  } else {   // this needs to be updated to create file if missing
    mvwaddstr(game_text, 2, 3, "There is no save game file!");
    wrefresh(game_text);
    getch();
  }

  // Main game loop
  wclear(select);
  wrefresh(select);
  // set up stats window
  wattron(stats_border, COLOR_PAIR(6) | A_BOLD);
  mvwaddstr(stats_border, 0, (stats_x_border / 2) - 3, " Stats ");
  wattroff(stats_border, COLOR_PAIR(6) | A_BOLD);
  // later we will color code the mana and hp depending on status (red green)
  mvwprintw(stats, 0, stats_x / 24,
  "Name: %s | XP: %d | Lvl: %d  -|-  Coin: %d | HP: %d | Mana: %d",
  player.name, player.xp, player.lvl, player.coin, player.cur_hp, player.cur_mana);
  wrefresh(stats_border);
  wrefresh(stats);
  // Start main part of game
  wclear(game_text);
  mvwprintw(game_text, 1, 3, "Greetings brave %s! Welcome to your Destiny...", player.name);
  mvwprintw(game_text, 2, 3, "You are a %s with %d hit points (life).", player.role, player.cur_hp);
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

