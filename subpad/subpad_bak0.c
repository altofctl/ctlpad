#include <ncurses.h>
#include <stdlib.h>

void print_pad(WINDOW *pad, int v);
int main()
{
	int v = 50;
	int c;
	WINDOW *sub_pad;

	initscr();
	cbreak();
	noecho();

	keypad(stdscr, TRUE);

	mvprintw(1, 5, "sub_pad test");
	refresh();
	sub_pad = newwin(3, 102, 4, 10);
	box(sub_pad, 0, 0);
	print_pad(sub_pad, v);

	/*while((c = getch()) != 'q')
	{
		switch(c)
		{
			case KEY_LEFT:
				if(v > 0) --v;
				print_pad(sub_pad, v);
				break;
			case KEY_RIGHT:
				if(v < 100) ++v;
				print_pad(sub_pad, v);
				break;
			default:
				mvprintw(2, 5, "Key pressed '%c'", c);
				refresh();
				break;
		}
	}*/

	getch();
	endwin();
	return 0;
}

void print_pad(WINDOW *pad, int v)
{
	int y, x;
	getbegyx(pad, y, x);

	mvhline(y+1, x+v+1, '=', 100-v);
	attron(A_REVERSE);
	mvhline(y+1, x+1, '*', v);
	attroff(A_REVERSE);
	wrefresh(pad);
}
