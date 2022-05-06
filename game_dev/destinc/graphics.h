// Functions for displaying graphics and text

// center text to the window
void center(WINDOW *win, char *text) {
  int len, indent, y, width;
  getmaxyx(win, y, width);
  len = strlen(text);
  indent = (width - len) / 2;
  mvaddstr(y / 2, indent, text);
  wrefresh(win);
}

// print stars in the window
void stars(WINDOW *win, int num_stars) {
  int win_y, win_x;
  int starsY[num_stars], starsX[num_stars], starsColor[num_stars];

  getmaxyx(win, win_y, win_x);
  //curs_set(0); // turn off visible cursor

  // generate randomly located stars
  for (int i = 0; i < num_stars; i++) {
    starsY[i] = dice(1, win_y);
    starsX[i] = dice(1, win_x);
    starsColor[i] = dice(1, 6);
    attrset(COLOR_PAIR(starsColor[i]));
    mvaddch(starsY[i], starsX[i], '*');
    refresh();
    napms(dice(1, 80));
  }

  napms(1500);

  // I really like the idea of making the various star actions, ie.
  // falling away, shaking, into selectable options...
  // stars go up
  for (int a = 1; a < 4; a++) {
    for (int i = 0; i < num_stars; i++) {
      mvaddch(starsY[i], starsX[i], ' ');
      starsY[i] = starsY[i] - a;
      attrset(COLOR_PAIR(starsColor[i]));
      mvaddch(starsY[i], starsX[i], '*');
    }
    refresh();
    napms(120);
  }

  napms(500);

  // stars fall away
  int drop_speed = 100;
  for (int a = 1; a < win_y + 1; a++) {
    for (int i = 0; i < num_stars; i++) {
      mvaddch(starsY[i], starsX[i], ' ');
      starsY[i] = starsY[i] + a;
      attrset(COLOR_PAIR(starsColor[i]));
      mvaddch(starsY[i], starsX[i], '*');
    }
    refresh();
    napms(drop_speed-=5);
  }

  attrset(A_UNDERLINE | COLOR_PAIR(1));
  center(stdscr, "Press any key to begin...");
  getch();

  clear();
}

