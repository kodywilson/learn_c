// The Introduction screen for new characters

void intro_screen(WINDOW *win, char name[32]) {
  WINDOW *animation, *text;
  pthread_t  thread_id;
  int max_y, max_x, show_text = 0;

  getmaxyx(win, max_y, max_x);
  animation  = newwin(max_y * 2 / 3, max_x, (max_y / 3) + 1, 0);
  text       = newwin(max_y / 3, max_x, 0, 0);

  // create flames and within flames loop, refresh text with intro cut scene text
  // using a timer (so every three seconds or something like that)
  // open flames in a separate thread
  pthread_create(&thread_id, NULL, flames, (void*) animation);

	for (;;) {
    wclear(text);
    bigly(text, DOOM, intro_scene_text[show_text]);
    wrefresh(text);
    show_text++;
    napms(5000);
  }

  pthread_exit(NULL);	 // terminate thread

  wclear(animation);
  wrefresh(animation);
  wclear(text);
  wrefresh(text);
}