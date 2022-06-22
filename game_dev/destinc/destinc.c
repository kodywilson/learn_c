//      ---||  Destiny  ||---
// C port of original game written in Ruby
// by Kody Wilson

#define DEBUG 0 // set to 1 for additional messages during gameplay

#include "includes.h"

#define INPUT_MAX 33

int main() {
  srand(time(0)); // seed rand using time
  int choice, max_y, max_x, new_game;
  // last four of next line are oft used offsets
  int game_text_y, game_text_x, main_loop, saves, y_high, x_high, y_low, x_low;
  pc player; // create player struct

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
  init_pair(7, COLOR_GREEN, COLOR_BLACK);

  getmaxyx(stdscr, max_y, max_x);
  curs_set(0); // turn off visible cursor

  intro(stdscr, 100);  // draw stars and intro text on the whole screen

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

  // calculate window sizes
  getmaxyx(game_text, game_text_y, game_text_x);

  // build offsets for text padding
  y_high = 1;
  x_high = 1;
  y_low = game_text_y - 1;
  x_low = game_text_x - game_text_x + 1; // LOL

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
    saves = check_saves();
    if (saves > 0) {
      mvwaddstr(game_text, y_high, x_high, "I noticed you already have a saved game going. Welcome back to Destiny!");
      wrefresh(game_text);
      reset_choices();
      num_choices = y_n();
      choice = choose(select, num_choices, "Load a save? Choose (Yes) to load a save, (No) to create a new game.");
      if (choice_key[choice] == 0) {
        choice = choose_save(game_text, select, saves);
        player = saved_games[choice];
        new_game = 0;
      } else {
        wclear(game_text);
        mvwaddstr(game_text, y_high, x_high, "Ok, you chose to create a new game.");
        if (saves >= SAVE_SLOTS) {
          wattron(game_text, COLOR_PAIR(1) | A_BOLD);
          mvwprintw(game_text, y_low, x_low, "Please note: only %d saves are supported. You are at the limit and will need to overwrite one save to create a new game.", saves);
          wattroff(game_text, COLOR_PAIR(1) | A_BOLD);
          wattron(game_text, COLOR_PAIR(4));
          wrefresh(game_text);
          reset_choices();
          num_choices = y_n();
          choice = choose(select, num_choices, "Do you want to continue?");
          if (choice_key[choice] == 0) {
            wclear(game_text);
            mvwaddstr(game_text, y_high, x_high, "Right on, let's create a new character.");
            wrefresh(game_text);
            player = player_classes[choose_class(game_text, select)];
            update_name(select, input, &player);
            new_game = 1;
          } else {
            wclear(game_text);
            mvwaddstr(game_text, y_high, x_high, "Ok, fair enough. Let's load a saved game.");
            wrefresh(game_text);
            napms(1000);
            choice = choose_save(game_text, select, saves);
            player = saved_games[choice];
            new_game = 0;
          }
        } else {
          wclear(game_text);
          mvwaddstr(game_text, y_high, x_high, "Right on, let's create a new character.");
          wrefresh(game_text);
          player = player_classes[choose_class(game_text, select)];
          update_name(select, input, &player);
          new_game = 1;
        }
        wrefresh(game_text);
      }
    } else {
      mvwaddstr(game_text, y_high, x_high, "No saved games found. Let's create a character!");
      wrefresh(game_text);
      napms(1000);
      player = player_classes[choose_class(game_text, select)];
      update_name(select, input, &player);
      new_game = 1;
    }
  } else {   // this needs to be updated to create file if missing
    mvwaddstr(game_text, y_high, x_high, "There is no save game file!");
    wrefresh(game_text);
    getch();
  }

  // Intro
  wclear(select);
  wrefresh(select);
  // set up stats window border
  wattron(stats_border, COLOR_PAIR(6) | A_BOLD);
  mvwaddstr(stats_border, 0, (((max_x * 7) / 8) / 2) - 2, " Stats ");
  wattroff(stats_border, COLOR_PAIR(6) | A_BOLD);
  wrefresh(stats_border);
  refresh_stats(stats, &player); // print stats window
  // set up game text window border
  wattron(game_text_border, COLOR_PAIR(6) | A_BOLD);
  mvwaddstr(game_text_border, 0, (max_x / 2) - 5, " Game Text ");
  wattroff(game_text_border, COLOR_PAIR(6) | A_BOLD);
  wrefresh(game_text_border);
  // set up actions window border
  wattron(select_border, COLOR_PAIR(6) | A_BOLD);
  mvwaddstr(select_border, 0, (max_x / 2) - 4, " Actions ");
  wattroff(select_border, COLOR_PAIR(6) | A_BOLD);
  wrefresh(select_border);
  // New game or previous one?
  if (new_game == 0) {
    // Initial greeting
    wclear(game_text);
    mvwprintw(game_text, y_high, x_high, "Greetings brave %s! Welcome back to Destiny...", player.name);
    //mvwprintw(game_text, y_high + 1, x_high, "You are a %s with %d hit points (life).", player.role, player.cur_hp);
    mvwaddstr(game_text, y_low, x_low, "Press any key to begin...");
    wrefresh(game_text);
    getch();
  } else {
    // new game stuff here
  }
  

  main_loop = 1;
  // Main game loop
  while(main_loop) {
    main_loop = town(game_text, select, stats, &player);
    napms(250);
  }

  // Save game on exit. Later, add more places to save before player leaves the game.
  save_game(game_text, select, player, saves);

  endwin();
  return 0;
}

