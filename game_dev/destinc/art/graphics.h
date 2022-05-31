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

void refresh_stats(WINDOW *win, mob *player) {
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
  int ch, frame_y, frame_x, start_y, start_x, frame_width, win_y, win_x;

  getmaxyx(win, win_y, win_x);  // grab window size

  // where to start printing the frames - later, make these arguments
  frame_y = win_y - 3;//(win_y / 2) + 3;
  frame_x = 1; // start at left, later send starting coordinates (upper left corner of frame)

  // loop a few times so player cartwheels across the screen
  for (int sequence = 0; sequence < 3; sequence++) {
    // Iterate over frames and print the frame
    for (int frame = 0; frame < CART_WHEEL_FRAMES; frame++) {
      for (int i = 0; i < 3; i++) {
        start_y         = frame_y + i;
        for (int j = 0; j < 6; j++) {
          start_x = frame_x + j;
          mvwaddch(win, start_y, start_x, cartwheel[frame][i][j]);
        }
      }
      wrefresh(win);
      napms(250);
      wclear(win); // change this to only clear the bottom part of the window
      frame_x+=2;
    }
  }
  // for (int let = 0; text[let] != '\0'; let++) {
  //   ch            = text[let];
  //   letter_width  = fonts[font].width[!is_capital(ch)][letter_position(ch)];
  //   start         = letter_start(ch, fonts[font]);
  //   for (int i = start; i < start + letter_width; i++) {
  //     text_y = (win_y / 2 - 5) / 2;
  //     for (int j = 0; j < fonts[font].height[!is_capital(ch)]; j++) { // j < height
  //       if (is_capital(ch)) mvaddch(text_y, text_x, fonts[font].up[j][i]);
  //       //else mvaddch(text_y, text_x, fonts[font].low[j][i + letter_width]); // need to add lowercase to font first
  //       text_y++;
  //     }
  //     text_x++;
  //   }
  //   text_x++; // accounts for space between each character
}

void celebrate(WINDOW *win) {
  //stars(win, 50);
  bigly(win, DOOM, "YAY");
  draw_cartwheel(win);
}
