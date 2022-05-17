// functions for handling player selections

#define MAX_CHOICES 10
#define MAX_CHOICE_LEN 32
#define Y_N 2

// globals
char *yes_no[Y_N] = {"Yes", "No"};
char choices[MAX_CHOICES][MAX_CHOICE_LEN];
int  choice_key[MAX_CHOICES];

void reset_choices(char choices[MAX_CHOICES][MAX_CHOICE_LEN], int choice_key[MAX_CHOICES]) {
  for (int i = 0; i < MAX_CHOICES; i++) {
    memset(choices[i], 0, MAX_CHOICE_LEN);     // "null" char[][] array
    choice_key[i] = 99;                        // "null" int array
  }
}

// choose from num (number of) choices
// choose(select, yes_no, 2);
// Send window for menu, char** of choices, and number of choices
int choose(WINDOW *win, char **choices, int num, char *text) {
  int choice, x, y;
  int highlight = 0;

  wclear(win);
  mvwaddstr(win, 0, 0, text);

  while(1) {
    for (int i = 0; i < num; i++) {
      if (i < 6) {
        y = i + 1;
        x = 1;
      }
      if (i > 5) { // wrap choices over to new column if there are more than 5 (should be 4?)
        y = i - 3;
        x = 16;
      }
      if (i == highlight) wattron(win, A_BOLD | COLOR_PAIR(6));
      mvwaddstr(win, y, x, choices[i]);
      wattroff(win, A_BOLD | COLOR_PAIR(6));
    }
    choice = wgetch(win);

    switch(choice) {
      case KEY_UP:
        if (highlight > 0) highlight--;
        break;
      case KEY_DOWN:
        if (highlight < num - 1) highlight++;
        break;
      default:
        break;
    }
    if(choice == 10) // might need to change this in the future to handle more than line feed
      break;
  }

  return highlight;

}

int choose_test(WINDOW *win, char selections[MAX_CHOICES][MAX_CHOICE_LEN], int num, char *text) {
  int choice, x, y;
  int highlight = 0;

  wclear(win);
  mvwaddstr(win, 0, 0, text);

  while(1) {
    for (int i = 0; i < num; i++) {
      if (i < 6) {
        y = i + 1;
        x = 1;
      }
      if (i > 5) { // wrap selections over to new column if there are more than 5 (should be 4?)
        y = i - 3;
        x = 16;
      }
      if (i == highlight) wattron(win, A_BOLD | COLOR_PAIR(6));
      mvwaddstr(win, y, x, selections[i]);
      wattroff(win, A_BOLD | COLOR_PAIR(6));
    }
    choice = wgetch(win);

    switch(choice) {
      case KEY_UP:
        if (highlight > 0) highlight--;
        break;
      case KEY_DOWN:
        if (highlight < num - 1) highlight++;
        break;
      default:
        break;
    }
    if(choice == 10) // might need to change this in the future to handle more than line feed
      break;
  }

  return highlight;

}
