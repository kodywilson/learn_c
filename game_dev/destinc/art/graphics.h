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
  int destiny_y, destiny_x, letter_width, win_y, win_x;
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

  // Iterate over struct and print the letters
  destiny_y = (win_y / 2 - 5) / 2;
  destiny_x = (win_x - (LETTERS * fonts[DOOM].width[0][0])) / 2;
  letter_width = 0; // initialize letter width
  for (int let = 0; let < LETTERS; let++) {
    for (int i = 0; i < fonts[DOOM].width[0][0]; i++) {
      destiny_y = (win_y / 2 - 5) / 2;
      for (int j = 0; j < fonts[DOOM].height[0]; j++) { // have to pass the height of the character j < height
        //mvaddstr(destiny_y, destiny_x, letters[i].doom_up[j]);
        mvaddch(destiny_y, destiny_x, fonts[DOOM].up[j][i + letter_width]);
        destiny_y++;
      }
      destiny_x++;
    }
    destiny_x++; // accounts for space between each character
    letter_width+=8; // letter width plus the space
    //bigly(intro[i]);
    refresh();
    napms(100);
  }

  attrset(A_UNDERLINE | COLOR_PAIR(1));
  center(stdscr, "Press any key to begin...");
  getch();

  clear();
}

