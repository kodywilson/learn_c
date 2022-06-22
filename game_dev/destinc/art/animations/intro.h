// The Introduction screen for new characters

void intro_screen(WINDOW *win, char name[32]) {
  WINDOW *animation;//, *text;
  int max_y, max_x;

  getmaxyx(win, max_y, max_x);
  animation  = newwin(max_y * 2 / 3, max_x, (max_y / 3) + 1, 0);
  //text       = newwin(max_y / 3, max_x, 0, 0);

  flames(animation);
}