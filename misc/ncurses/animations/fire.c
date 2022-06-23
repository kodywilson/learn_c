#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

/* Credit here for C code
   http://www.melvilletheatre.com/articles/cstuff/6.html

   and he gives credit here for the original code
   http://maettig.com/code/javascript/asciifire.html
*/

void flames(void);

int main(int argc, char** argv)
	{
	initscr();
	start_color();

	flames();

	endwin();
	return 0;
	}

void flames(void)
	{
	int width, height, size, *b, i;
  int timer;
	const char characters[] = {' ', '.', ':', '^', '*', 'x', 's', 'S', '#', '$'};
	
	getmaxyx(stdscr,height,width);
	size=width*height;
	init_pair(17,0,0);
	init_pair(18,1,0);
	init_pair(19,3,0);
	init_pair(20,4,0);
	clear();
	
	b=calloc((size+width+1),sizeof(int));
	nodelay(stdscr,TRUE);
	srand(time(NULL));

  timer = time(NULL);

	for (;;)
		{
		for (i =0; i < width/9; i++)
			b[(int)(((float)rand()/(float)RAND_MAX)*width+width*(height-1))]=65;
		for (i=0; i < size; i++)
			{
			b[i]=(b[i]+b[i+1]+b[i+width]+b[i+width+1])/4;
			if (b[i] > 15)
				attrset(COLOR_PAIR(20)|A_BOLD);
			else if (b[i] > 9)
				attrset(COLOR_PAIR(19)|A_BOLD);
			else if (b[i] > 4)
				attrset(COLOR_PAIR(18)|A_BOLD);
			else
				attrset(COLOR_PAIR(17)|A_BOLD);
			if (i < size-1)
				{
				move(i/width, i%width);
				if (b[i] > 9)
					addch(characters[9]);
				else
					addch(characters[b[i]]);
				}
			}
		refresh();
		timeout(30);
    napms(10);
    if ((timer + 10) <= time(NULL)) break;
		//if (getch() != ERR)
		//	break;
		}
	
	free(b);
	return;
	}

