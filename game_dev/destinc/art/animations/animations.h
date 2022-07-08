// Various animations used in the game

/* Credit here for C code
   http://www.melvilletheatre.com/articles/cstuff/6.html

   and he gives credit here for the original code
   http://maettig.com/code/javascript/asciifire.html
*/

//void *flames(void *window) { // was using this when I was playing around with threads
void flames(WINDOW *animation, int duration) {
	int width, height, size, *b, i;
  int timer;
  //int max_y, max_x;
  //WINDOW *animation = window;

  //getmaxyx(animation, max_y, max_x);
  //animation  = newwin(max_y * 2 / 3, max_x, (max_y / 3) + 1, 0);

	const char characters[] = {' ', '.', ':', '^', '*', 'x', 's', 'S', '#', '$'};
	
	getmaxyx(animation,height,width);
	size=width*height;
	wclear(animation);
	
	b=calloc((size+width+1),sizeof(int));
	//nodelay(animation,TRUE);
	srand(time(NULL));

  timer = time(NULL);

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
		wrefresh(animation);
		//timeout(30);
    napms(15);
    if ((timer + duration) <= time(NULL)) break;
  }
	free(b);
  //nodelay(animation,FALSE);
  //return (void*) 1; // for pthreads
}

#include "intro.h"
#include "game_over.h"