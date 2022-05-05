// File functions, ie. save, game directory, etc.
#include <sys/stat.h>
#include <sys/types.h>

#define GAME_DIR ".destiny"
#define SAVE_FILE "saves.txt"
#define PATH_MAX 256

void setup_file(WINDOW *game_text, WINDOW *select) {
  FILE *fp;
  char filepath[PATH_MAX];
  int choice;

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
        exit(1);
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
      exit(0);
    }
    wrefresh(game_text);
  }

}
