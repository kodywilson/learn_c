// The Introduction screen for new characters

void intro_screen(WINDOW *win, char name[32]) {
  WINDOW *animation, *text;
  int max_y, max_x, timer = 0, show_text = 0;

  getmaxyx(win, max_y, max_x);
  animation  = newwin(max_y * 2 / 3, max_x, (max_y / 3) + 1, 0);
  text       = newwin(max_y / 3, max_x, 0, 0);

  // create flames and within flames loop, refresh text with intro cut scene text
  // using a timer (so every three seconds or something like that)
  int width, height, size, *b, i;
	const char characters[] = {' ', '.', ':', '^', '*', 'x', 's', 'S', '#', '$'};
	
	getmaxyx(animation,height,width);
	size=width*height;
	wclear(animation);
	
	b=calloc((size+width+1),sizeof(int));
	nodelay(animation,TRUE);
	srand(time(NULL));

	for (;;) {
		for (i =0; i < width/9; i++)
			b[(int)(((float)rand()/(float)RAND_MAX)*width+width*(height-1))]=65;
		for (i=0; i < size; i++) {
			b[i]=(b[i]+b[i+1]+b[i+width]+b[i+width+1])/4;
			if (b[i] > 15)
				wattrset(animation, COLOR_PAIR(20)|A_BOLD);
			else if (b[i] > 9)
				wattrset(animation, COLOR_PAIR(19)|A_BOLD);
			else if (b[i] > 4)
				wattrset(animation, COLOR_PAIR(18)|A_BOLD);
			else
				wattrset(animation, COLOR_PAIR(17)|A_BOLD);
			if (i < size-1) {
				wmove(animation, i/width, i%width);
				if (b[i] > 9)
					waddch(animation, characters[9]);
				else
					waddch(animation, characters[b[i]]);
			}
		}
    if ((time(NULL) % 3) == 0) timer = 1; // start timer
    if ((timer == 1) && ((time(NULL) % 5) == 0) && (show_text < INTRO_TEXT)) { // show text once timer is activated, every three seconds
      wclear(text);
      bigly(text, DOOM, intro_scene_text[show_text]);
      wrefresh(text);
      show_text++;
    }
		wrefresh(animation);
		timeout(30);
		if (getch() != ERR)
			break;
}

	free(b); // free memory for flames animation

  wclear(animation);
  wrefresh(animation);
  wclear(text);
  wrefresh(text);
}