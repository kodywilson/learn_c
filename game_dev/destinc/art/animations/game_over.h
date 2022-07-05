// Sadly, it's game over

void game_over(WINDOW *win, char name[32]) {
  WINDOW *animation, *text;
  
  int max_y, max_x;

  getmaxyx(stdscr, max_y, max_x);
  animation  = newwin(max_y * 2 / 3, max_x, (max_y / 3) + 1, 0);
  text       = newwin(max_y / 3, max_x, 0, 0);

  clear();
  refresh();

  bigly(win, DOOM, 1, 1, 100, "GAME OVER");
  napms(2000);

  flames(animation, 8);
  wclear(animation);
  wrefresh(animation);

  wclear(win);
  wrefresh(win);
  wclear(text);
  mvwaddstr(text, 2, 0, "Swirling sensations of light surround you. Is this what it feels like to lose your grip on life?");
  wrefresh(text);
  napms(2000);
  mvwaddstr(text, 3, 0, "You hear a musical voice calling your name, a sound sweeter than any heard before.");
  wrefresh(text);
  napms(2000);
  mvwprintw(text, 4, 0, "%s....... %s........ Awaken, you must fulfill your destiny. The world needs you %s.", name, name, name);
  // mvwaddstr(text, 5, 0, "You remember your village was attacked at night, the flames, the screams... chaos and terror ...");
  wrefresh(text);
  napms(2000);
  mvwaddstr(text, 7, 0, "As your full consciousness returns, you take stock of your surroundings.");
  wrefresh(text);
  napms(2000);
  mvwaddstr(text, 8, 0, "You seem to be back in town, right where your journey first began...");
  wrefresh(text);
  wclear(animation);
  wattron(animation, COLOR_PAIR(5));
  mvwaddstr(animation, 4, 0, "Press any key to continue...");
  wrefresh(animation);
  wgetch(animation);
  wclear(animation);
  wclear(text);
  wrefresh(animation);
  wrefresh(text);
   //pthread_exit(NULL);
  //pthread_join(thread_id, NULL);	 // join threads

  //wclear(text);
  //wrefresh(text);
}