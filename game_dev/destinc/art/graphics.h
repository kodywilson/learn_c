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

void clear_box(WINDOW *win) {
  wclear(win);
  box(win, 0, 0);
}

// print stars in the window
void stars(WINDOW *win, int num_stars) {
  int win_y, win_x;
  int starsY[num_stars], starsX[num_stars], starsColor[num_stars];
  //char intro[8] = "Destiny";

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
    napms(dice(1, 50));
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
    napms(100);
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

  clear();
}

void intro(WINDOW *win, int num_stars) {

  stars(win, num_stars);
  bigly(win, DOOM, "DESTINY");

  attrset(A_UNDERLINE | COLOR_PAIR(1));
  center(stdscr, "Press any key to begin...");
  getch();
}

void refresh_stats(WINDOW *win, pc *player) {
  int stats_y, stats_x;
  getmaxyx(win, stats_y, stats_x);

  wclear(win);
  // later we will color code the mana and hp depending on status (red green)
  mvwprintw(win, stats_y * 0, stats_x / 20,
  "Name: %s | XP: %d | Lvl: %d  -|-  Coin: %d | HP: %d | Mana: %d",
  player->name, player->xp, player->lvl, player->coin, player->cur_hp, player->cur_mana);
  wrefresh(win);
}
