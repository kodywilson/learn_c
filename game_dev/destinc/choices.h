// functions for handling player selections

// globals
char *yes_no[2] = {"Yes", "No"};

// choose from num (number of) choices
// choose(select, yes_no, 2);
// Send window for menu, char** of choices, and number of choices
int choose(WINDOW *win, char **choices, int num) {
  int choice;
  int highlight = 0;

  while(1) {
    for (int i = 0; i < num; i++) {
      if (i == highlight) wattron(win, A_BOLD | COLOR_PAIR(6));
      mvwaddstr(win, i+1, 1, choices[i]);
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
