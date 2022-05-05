#include "dice.h"
#define MOVE_TEXT 6
#include "text.h"
#include <ncurses.h>
#include <string.h>
#define ROLLS 1000
#define STARS 100
#include "graphics.h"
#include <sys/stat.h>
#include <sys/types.h>

//#define MOVE_TEXT 4
//#define ROLLS 1000
//#define STARS 100
#define GAME_DIR ".destiny"
#define SAVE_FILE "saves.txt"
#define INPUT_MAX 33
#define PATH_MAX 256

// function prototypes

int main() {
  srand(time(0)); // seed rand using time
  FILE *fp;       // file pointer for save
  //int min = 24, max = 0, roll;
  int choice, highlight, max_y, max_x, stats_y, stats_x;
  char name[INPUT_MAX], filepath[PATH_MAX], *yes_no[2] = {"Yes", "No"};
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

  stars(stdscr);  // draw stars on the whole screen

  clear();
  refresh();

  // after intro, set up interface
  stats    = newwin(3, (max_x * 2) / 3, 0, max_x / 6);
  game_text = newwin(max_y * 2 / 3, max_x, max_y / 10, 0);
  select    = newwin(max_y / 4, max_x, (max_y * 3) / 4, 0);
  input     = newwin(2, max_x / 3, max_y / 2, max_x / 3);

  getmaxyx(stats, stats_y, stats_x);

  box(stats, 0, 0);
  box(game_text, 0, 0);
  box(select, 0, 0);
  box(input, 0, 0);

  keypad(select, true); // enable the keypad on the select window

  wattrset(game_text, COLOR_PAIR(4));

  // first check for existing save file and then a valid save
  snprintf(filepath, PATH_MAX, "%s/%s", getenv("HOME"), GAME_DIR);
  if ((fp = fopen(filepath, "r")) != NULL) {
    fclose(fp);
    mvwprintw(game_text, 3, 3, "Found directory at %s", filepath);
  }
  else {
    mvwaddstr(game_text, 3, 3, "Hi and welcome to Destiny. To create a character and start playing");
    mvwaddstr(game_text, 4, 3, "we need to create a save file. Would you like to do that now?");
    mvwaddstr(select, 1, 1, "[1] for yes\n[2] for no");
    wrefresh(game_text);
    wrefresh(select);
    do {
      choice = getch();
    } while (choice < 49 || choice > 50 );
    wclear(game_text);
    if (choice == 49) {
      mvwaddstr(game_text, 3, 3, "Excellent choice. Creating save file...");
      wrefresh(game_text);
      if (mkdir(filepath, 0777) == -1) {
        endwin();
        printf("Unable to create %s\n", filepath);
        return 1;
      }
      mvwaddstr(game_text, 4, 3, "Game directory created...");
      wrefresh(game_text);
      /*fp = fopen(filepath, "w");
      if (fp == NULL) {
        endwin();
        puts("Unable to create file");
        return 1;
      }*/

    } else { 
      mvwaddstr(game_text, 3, 3, "OK, maybe next time, eh?");
      mvwaddstr(game_text, 4, 3, "Press any key to exit...");
      wrefresh(game_text);
      getch();
      endwin();
      return 0;
    }
    wrefresh(game_text);
  }

  // add some placeholder text to boxes
  attrset(COLOR_PAIR(6) | A_BOLD);
  mvaddstr(0, (max_x / 2) - 5, " Stats ");
  mvwaddstr(stats, stats_y / 2, stats_x / 6, "Name: Bob  |  HP: 100  |  Mana: 50  |  XP: 10");
  wrefresh(stats);
  wrefresh(game_text);
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

