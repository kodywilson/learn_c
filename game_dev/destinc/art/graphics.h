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
  //int stats_y, stats_x;
  //getmaxyx(win, stats_y, stats_x);

  wclear(win);
  // later we will color code the mana and hp depending on status (red green)
  mvwprintw(win, 0, 0,
  "Name: %s | XP: %d | Lvl: %d  -|-  Coin: %d | HP: %d | Mana: %d",
  player->name, player->xp, player->lvl, player->coin, player->cur_hp, player->cur_mana);
  wrefresh(win);
}

void draw_cartwheel(WINDOW *win) {
  int frame_y, frame_x, start_y, start_x, win_y, win_x;

  getmaxyx(win, win_y, win_x);  // grab window size

  // where to start printing the frames - later, make these arguments
  // it might look cool to have the animation start off screen and then go all the way across...
  frame_y = win_y - 3;//(win_y / 2) + 3;
  frame_x = win_x - win_x + 1; // start at left, later send starting coordinates (upper left corner of frame)

  // loop a few times so player cartwheels across the screen
  // add way for player to hit spacebar or something to get out of animation more quickly
  for (int sequence = 0; sequence < 6; sequence++) {
    // Iterate over frames and print the frame
    for (int frame = 1; frame < CART_WHEEL_FRAMES - 2; frame++) {
      for (int i = 0; i < 3; i++) {
        start_y         = frame_y + i;
        for (int j = 0; j < 6; j++) {
          start_x = frame_x + j;
          mvwaddch(win, start_y, start_x, cartwheel[frame][i][j]);
        }
      }
      wrefresh(win);
      if ((frame <= 1) && (sequence == 0)) napms(500);  // slight pause before we start cartwheeling
      else napms(100);
      mvwaddch(win, frame_y, 0, ' '); // move cursor to left position so we can clear to bottom
      wclrtobot(win);
      frame_x+=2;
    }
  }
  // napms(1000); // only pause if we display final frames. Maybe play frames one and two then pause on frame with arms up?
}

void celebrate(WINDOW *win) {
  //stars(win, 50);
  //bigly(win, DOOM, "YAY");
  //napms(500);
  draw_cartwheel(win);
}
