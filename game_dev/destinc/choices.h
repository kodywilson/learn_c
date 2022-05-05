// functions for handling player selections

// choose from num (number of) choices
// choose(select, yes_no, 2);
// Send window for menu, char** of choices, and number of choices
int choose(WINDOW *win, char **choices, int num) {
  int choice;
  int highlight = 0;

  while(1) {
    for (int i = 0; i < num; i++) {
      if (i == highlight) wattron(win, A_REVERSE);
      mvwaddstr(win, i+1, 1, choices[i]);
      wattroff(win, A_REVERSE);
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
    if(choice == 10)
      break;
  }

  wclear(win);
  mvwprintw(win, 4, 4, "Your choice was: %s", choices[highlight]);
  wrefresh(win);

  getch(); // DEBUG

  return highlight;

}
