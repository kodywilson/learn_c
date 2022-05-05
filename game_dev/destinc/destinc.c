#include "dice.h"
#define MOVE_TEXT 6
#include "text.h"
#include <ncurses.h>
#include <string.h>

//#define MOVE_TEXT 4
#define ROLLS 1000
#define STARS 100
#define GAME_DIR ".destiny"
#define SAVE_FILE "saves.txt"
#define INPUT_MAX 33
#define PATH_MAX 256

// function prototypes
void center(char *title);

int main() {
  srand(time(0)); // seed rand using time
  FILE *fp;       // file pointer for save
  //int min = 24, max = 0, roll;
  int choice, max_y, max_x, stats_y, stats_x;
  int starsY[STARS], starsX[STARS], starsColor[STARS];
  char name[INPUT_MAX], filepath[PATH_MAX];
  WINDOW *game_text, *select, *input, *stats;

  initscr();
  start_color();
  // set up some colors
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);
  init_pair(6, COLOR_YELLOW, COLOR_BLACK);

  getmaxyx(stdscr, max_y, max_x);
  curs_set(0);

  // generate randomly located stars
  for (int i = 0; i < STARS; i++) {
    starsY[i] = dice(1, max_y);
    starsX[i] = dice(1, max_x);
    starsColor[i] = dice(1, 6);
    attrset(COLOR_PAIR(starsColor[i]));
    mvaddch(starsY[i], starsX[i], '*');
    refresh();
    napms(dice(1, 80));
  }

  napms(1500);

  // stars go up
  for (int a = 1; a < 4; a++) {
    for (int i = 0; i < STARS; i++) {
      mvaddch(starsY[i], starsX[i], ' ');
      starsY[i] = starsY[i] - a;
      attrset(COLOR_PAIR(starsColor[i]));
      mvaddch(starsY[i], starsX[i], '*');
    }
    refresh();
    napms(120);
  }

  // stars fall away
  int drop_speed = 100;
  for (int a = 1; a < max_y + 1; a++) {
    for (int i = 0; i < STARS; i++) {
      mvaddch(starsY[i], starsX[i], ' ');
      starsY[i] = starsY[i] + a;
      attrset(COLOR_PAIR(starsColor[i]));
      mvaddch(starsY[i], starsX[i], '*');
    }
    refresh();
    napms(drop_speed-=5);
  }

  attrset(A_UNDERLINE | COLOR_PAIR(1));
  center("Press any key to begin...");
  getch();

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

  // first check for existing save file and then a valid save
  snprintf(filepath, PATH_MAX, "%s/%s", getenv("HOME"), GAME_DIR);
  if ((fp = fopen(filepath, "r")) != NULL) fclose(fp);
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
  attrset(COLOR_PAIR(1));
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

void center(char *title) {
  int len, indent, y, width;
  getmaxyx(stdscr, y, width);
  len = strlen(title);
  indent = (width - len) / 2;
  mvaddstr(y / 2, indent, title);
  refresh();
}
