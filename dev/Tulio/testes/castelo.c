#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

int main () {

	initscr();
  	noecho();
  	curs_set(FALSE);
  	halfdelay(1);

  	char str4[] = " __ ";
  	char str[] = "/oo\\";
  	char str1[] = "|ww|";
  	char str2[] = "/  \\";
  	char str3[] = " \\/";
  	char c;
  	int x = 10;
  	int y = 9;


  	while (x<100) {
	  	mvprintw(y, x, str4);
	  	mvprintw(y+1, x, str);
	  	mvprintw(y+2, x, str1);
	  	if (x%2 == 0) {
	  		mvprintw(y+3, x, str2);
	  	} else {
	  		mvprintw(y+3, x, str3);
	  	}

	  	c = getch();
  		if (c == 'w') {
  			y--;
  		} else {
  			if (c == 's') {
  				y++;
  			}
  		}
  		refresh();

  		x++;
  		clear();
  	}



 	sleep(1);
	endwin();

	return 0;
}