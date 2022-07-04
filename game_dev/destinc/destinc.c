//      ---||  Destiny  ||---
// C port of original game written in Ruby
// by Kody Wilson

#define DEBUG 0 // set to 1 for additional messages during gameplay

#include "includes.h"

#define INPUT_MAX 33

int main() {
  srand(time(0)); // seed rand using time
  int choice, max_y, max_x, new_game = 9;
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

  init_pair(17,0,0);
	init_pair(18,1,0);
	init_pair(19,3,0);
	init_pair(20,4,0);

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

  // clear_box(stats_border);
  // clear_box(game_text_border);
  // clear_box(select_border);
  // clear_box(input);
  // wrefresh(game_text_border);
  // wrefresh(select_border);

  all_windows(stats_border, stats, game_text_border, game_text, select_border, select);

  keypad(select, true); // enable the keypad on the select window

  //wattron(game_text, COLOR_PAIR(4)); // not sure I like the blue text...

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
          mvwprintw(game_text, y_low - 1, x_low, "Please note: only %d saves are supported.", saves);
          mvwprintw(game_text, y_low, x_low, "You are at the limit and will need to overwrite one save to save this new game.");
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

  // New game or previous one?
  if (new_game == 0) {
    // Initial greeting
    wclear(game_text);
    mvwprintw(game_text, y_high, x_high, "Greetings brave %s! Welcome back to Destiny...", player.name);
    //mvwprintw(game_text, y_high + 1, x_high, "You are a %s with %d hit points (life).", player.role, player.cur_hp);
    wrefresh(game_text);
    pause_text(select);
  } else {
    intro_screen(player.name);
    getch();
  }
  //clear();
  //refresh();
  all_windows(stats_border, stats, game_text_border, game_text, select_border, select);

  main_loop = 1;
  // Main game loop
  while(main_loop) {
    main_loop = town(game_text, select, stats, saves, &player);
    napms(250);
  }

  // Save game on exit. Later, add more places to save before player leaves the game.
  save_game(game_text, select, player, saves);

  endwin();
  return 0;
}

