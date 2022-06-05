// File functions, ie. save, game directory, etc.
#include <sys/stat.h>
#include <sys/types.h>

#define GAME_DIR ".destiny"
#define SAVE_FILE "/saves.txt"
#define FILE_PATH_MAX 256

// globals for game directory and save file
char game_dir[FILE_PATH_MAX];
char save_file[FILE_PATH_MAX];

void file_init() {
  snprintf(game_dir, FILE_PATH_MAX, "%s/%s", getenv("HOME"), GAME_DIR);
  strncpy(save_file, game_dir, FILE_PATH_MAX);
  strncat(save_file, SAVE_FILE, 16);
}

// check if passed file exists and can be opened for reading
int file_there(char filepath[FILE_PATH_MAX]) {
  FILE *fp;
  if ((fp = fopen(filepath, "r")) != NULL) {
    fclose(fp);
    return 1;
  } else return 0;
}

void trunc_file(char filepath[FILE_PATH_MAX]) {
  FILE *fp;

  if ((fp = fopen(save_file, "w")) != NULL) fclose(fp);
}

// creates game directory and save file
void setup_file(WINDOW *game_text, WINDOW *select) {
  FILE *fp;
  int choice;

  // build game directory path
  if (file_there(game_dir)) { // check if directory already exists
    // mvwprintw(game_text, 3, 3, "Found game directory at %s", game_dir); DEBUG
  } else {
    mvwaddstr(game_text, 1, 1, "Hi and welcome to Destiny. To make a character and start playing");
    mvwaddstr(game_text, 2, 1, "we need to create a save file.");
    wrefresh(game_text);
    reset_choices();
    num_choices = y_n();
    choice = choose(select, num_choices, "Would you like to do that now?");
    clear_box(game_text);
    if (choice_key[choice] == 0) {
      mvwaddstr(game_text, 4, 1, "Excellent choice. Creating game directory and save file...");
      wrefresh(game_text);
      if (mkdir(game_dir, 0777) == -1) {  // if directory creation fails, bail out
        endwin();
        printf("Unable to create directory %s\n", game_dir);
        exit(1);
      }
      // now create save file if game directory was successfully created
      //mvwprintw(game_text, 6, 3, "strcat gave us %s", save_file); // DEBUG
      fp = fopen(save_file, "w");
      if (fp == NULL) {
        endwin();
        printf("Unable to create file %s", save_file);
        exit(1);
      }
      fputs("--Destiny save file--\n", fp);
      fclose(fp);
      mvwaddstr(game_text, 6, 1, "Game directory and save file created...");
      wrefresh(game_text);
    } else {
      mvwaddstr(game_text, 4, 1, "OK, maybe next time, eh?");
      mvwaddstr(game_text, 5, 1, "Press any key to exit...");
      wrefresh(game_text);
      getch();
      endwin();
      exit(0);
    }
    wrefresh(game_text);
  }
}
