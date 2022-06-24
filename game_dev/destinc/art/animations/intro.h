// The Introduction screen for new characters

void intro_screen(WINDOW *game_text, WINDOW *select, char name[32]) {
  //WINDOW *text;
  pthread_t  thread_id;
  //int max_y, max_x, show_text = 0;

  //getmaxyx(win, max_y, max_x);
  //text       = newwin(max_y / 3, max_x, 0, 0);

  clear();
  refresh();

  // create flames and within flames loop, refresh text with intro cut scene text
  // using a timer (so every three seconds or something like that)
  // open flames in a separate thread
  pthread_create(&thread_id, NULL, flames, stdscr);
  //void* ret_from_thread;

	//for (;;) {
  for (int i = 0; i < 4; i++) {
    waddstr(stdscr, intro_scene_text[i]);
    //wclear(select);
    //bigly(text, DOOM, intro_scene_text[show_text]);
    //bigly(text, DOOM, intro_scene_text[i]);
    //wrefresh(select);
    //show_text++;
    napms(2000);
    //if (show_text == (INTRO_TEXT - 1)) break;
  }

   //pthread_exit(NULL);
  pthread_join(thread_id, NULL);	 // join threads

  //wclear(text);
  //wrefresh(text);
}