#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

int main () {

	initscr();
  noecho();
  curs_set(FALSE);

  attron(COLOR_PAIR(20));
  mvprintw(10, 10, "ABCDEFGabcdefg");
  refresh();

 	sleep(2);
	endwin();

	return 0;
}