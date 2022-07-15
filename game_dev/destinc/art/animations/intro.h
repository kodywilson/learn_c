// The Introduction screen for new characters

void intro_screen(char name[32]) {
  WINDOW *animation, *text;
  
  int max_y, max_x;

  getmaxyx(stdscr, max_y, max_x);
  animation  = newwin(max_y * 2 / 3, max_x, (max_y / 3) + 1, 0);
  text       = newwin(max_y / 3, max_x, 0, 0);

  clear();
  refresh();

  //pthread_create(&thread_id, NULL, flames, game_text); // was playing around with pthreads
  // pthreads don't play nicely with ncurses unless you compile it to support them
  //void* ret_from_thread;

  for (int i = 0; i < INTRO_TEXT; i++) {
    wclear(text);
    bigly(text, DOOM, 1, 1, 10, intro_scene_text[i]);
    napms(1000);
  }
  napms(1000);

  wclear(text);
  mvwaddstr(text, 2, 0, "You awaken with a start! You're alive, somehow you survived the flames, but ... how?");
  mvwaddstr(text, 3, 0, "They dance in your vision even now, forever seared into your mind. The heat ... unbearable ...");
  mvwprintw(text, 4, 0, "%s...yes, you are %s or were...You are not sure who you are now or ... where?", name, name);
  mvwaddstr(text, 5, 0, "You remember your village was attacked at night, the flames, the screams... chaos and terror ...");
  mvwaddstr(text, 7, 0, "As your full consciousness returns, you take stock of your surroundings.");
  mvwaddstr(text, 8, 0, "You seem to be in a small town. You have no weapon, only a few coins in one pocket...");
  wrefresh(text);
  flames(animation, 20);
  wclear(animation);
  mvwaddstr(animation, 4, 0, "Press any key to continue...");
  wrefresh(animation);
  wgetch(animation);
  //pthread_exit(NULL);
  //pthread_join(thread_id, NULL);	 // join threads

}