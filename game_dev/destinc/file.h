// File functions, ie. save, game directory, etc.
#include <sys/stat.h>
#include <sys/types.h>

#define GAME_DIR ".destiny"
#define SAVE_FILE "/saves.txt"
#define PATH_MAX 256

int file_there(char filepath[PATH_MAX]) {
  FILE *fp;
  if ((fp = fopen(filepath, "r")) != NULL) {
    fclose(fp);
    return 1;
  } else return 0;
}

void setup_file(WINDOW *game_text, WINDOW *select) {
  FILE *fp;
  char filepath[PATH_MAX];
  char *yes_no[2] = {"Yes", "No"};
  int choice;

  // first check for existing save file and then a valid save
  // build game directory path
  snprintf(filepath, PATH_MAX, "%s/%s", getenv("HOME"), GAME_DIR);
  if (file_there(filepath)) { // check if directory already exists
    mvwprintw(game_text, 3, 3, "Found directory at %s", filepath);
  } else {
    mvwaddstr(game_text, 3, 3, "Hi and welcome to Destiny. To create a character and start playing");
    mvwaddstr(game_text, 4, 3, "we need to create a save file. Would you like to do that now?");
    wrefresh(game_text);
    choice = choose(select, yes_no, 2) + 1;
    wclear(game_text);
    if (choice == 1) {
      mvwaddstr(game_text, 3, 3, "Excellent choice. Creating game directory and save file...");
      wrefresh(game_text);
      if (mkdir(filepath, 0777) == -1) {  // if directory creation fails, bail out
        endwin();
        printf("Unable to create %s\n", filepath);
        exit(1);
      }
      // now create save file if game directory was successfully created
      strcat(filepath, SAVE_FILE);
      mvwprintw(game_text, 6, 3, "strcat gave us %s", filepath);
      //fp = fopen(filepath, "w");
      //if (fp == NULL) {
      //  endwin();
      //  printf("Unable to create file %s", filepath);
      //  exit(1);
      //}
      //snprintf(filepath, PATH_MAX, "%s/%s", filepath, SAVE_FILE);
      //mvwprintw(game_text, 7, 3, "snprintf gave us %s", filepath);
      mvwaddstr(game_text, 4, 3, "Game directory created...");
      wrefresh(game_text);
    } else {
      mvwaddstr(game_text, 3, 3, "OK, maybe next time, eh?");
      mvwaddstr(game_text, 4, 3, "Press any key to exit...");
      wrefresh(game_text);
      getch();
      endwin();
      exit(0);
    }
    wrefresh(game_text);
  }

}
