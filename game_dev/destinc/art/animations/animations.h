// Various animations used in the game

/* Credit here for C code
   http://www.melvilletheatre.com/articles/cstuff/6.html

   and he gives credit here for the original code
   http://maettig.com/code/javascript/asciifire.html
*/

void *flames(void *win_in) {
	int width, height, size, *b, i;
  int timer;
  //WINDOW *win = (WINDOW) win_in;
  WINDOW *win = malloc(sizeof(win_in));
  //dungeon *d1 = malloc(sizeof(dungeon));
	const char characters[] = {' ', '.', ':', '^', '*', 'x', 's', 'S', '#', '$'};
	
	getmaxyx(win,height,width);
	size=width*height;
	wclear(win);
	
	b=calloc((size+width+1),sizeof(int));
	nodelay(win,TRUE);
	srand(time(NULL));

  timer = time(NULL);

  pthread_detach(pthread_self()); // detach thread from main()
	for (;;) {
		for (i =0; i < width/9; i++)
			b[(int)(((float)rand()/(float)RAND_MAX)*width+width*(height-1))]=65;
		for (i=0; i < size; i++) {
			b[i]=(b[i]+b[i+1]+b[i+width]+b[i+width+1])/4;
			if (b[i] > 15)
				wattrset(win, COLOR_PAIR(20)|A_BOLD);
			else if (b[i] > 9)
				wattrset(win, COLOR_PAIR(19)|A_BOLD);
			else if (b[i] > 4)
				wattrset(win, COLOR_PAIR(18)|A_BOLD);
			else
				wattrset(win, COLOR_PAIR(17)|A_BOLD);
			if (i < size-1) {
				wmove(win, i/width, i%width);
				if (b[i] > 9)
					waddch(win, characters[9]);
				else
					waddch(win, characters[b[i]]);
			}
		}
		wrefresh(win);
		timeout(30);
    napms(15);
    if ((timer + 30) <= time(NULL)) break;
		//if (getch() != ERR)
		//	break;
}
	free(b);
  free(win);
  pthread_exit(NULL);	 // terminate thread
}

#include "intro.h"