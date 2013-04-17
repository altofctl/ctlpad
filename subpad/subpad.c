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
	curs_set(0);

	keypad(stdscr, TRUE);

	mvprintw(1, 5, "sub_pad test");
	refresh();
	sub_pad = newwin(3, 56, 4, 10);
	box(sub_pad, 0, 0);
	print_pad(sub_pad, v);

	while((c = getch()) != 'q')
	{
		switch(c)
		{
			case KEY_LEFT:
				if(v > 0) --v;
				break;
			case KEY_RIGHT:
				if(v < 100) ++v;
				break;
			case '0':
				v = 0;
				break;
			case '1':
				v = 10;
				break;
			case '2':
				v = 20;
				break;
			case '3':
				v = 30;
				break;
			case '4':
				v = 40;
				break;
			case '5':
				v = 50;
				break;
			case '6':
				v = 60;
				break;
			case '7':
				v = 70;
				break;
			case '8':
				v = 80;
				break;
			case '9':
				v = 90;
				break;
			default:
				mvprintw(2, 5, "Key pressed '%c'", c);
				refresh();
				break;
		}
		print_pad(sub_pad, v);
	}

	getch();
	endwin();
	return 0;
}

void print_pad(WINDOW *pad, int v)
{
	mvwprintw(pad, 1, 1, "%3d", v);
	v/=2;
	wattron(pad, A_REVERSE);
	mvwhline(pad, 1, 5, ' ', v);
	wattroff(pad, A_REVERSE);
	mvwhline(pad, 1, v+5, ' ', 50-v);
	wrefresh(pad);
}
