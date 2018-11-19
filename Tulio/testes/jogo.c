#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

int main () {

    initscr();
  	noecho();
  	curs_set(FALSE);
  	halfdelay(1);

    char str0[] = "     _";
  	char str1[] = " |> / \\  |>";
  	char str2[] = " | / O \\ |";
  	char str3[] = "/VV| O |VV\\";
  	char str4[] = "|  | _ |  |";
  	char str5[] = "|  |[_]|  |";

    char str0a[] = "     _";
    char str1a[] = "<|  / \\ <|";
    char str2a[] = " | / O \\ |";
    char str3a[] = "/VV| O |VV\\";
    char str4a[] = "|  | _ |  |";
    char str5a[] = "|  |[_]|  |";

    char arv0[] = " __";
    char arv1[] = "(%%%%)";
    char arv2[] = " )(";

    char man0[] = " __";
    char man1[] = "(%%%%)";
    char man2[] = " )(";

  	int i = 0;

  	while (i<100) {

  		if (i%19 == 0 || i%13 == 0) {
            mvprintw(10, 0, str0);
            mvprintw(11, 0, str1);
            mvprintw(12, 0, str2);
            mvprintw(13, 0, str3);
            mvprintw(14, 0, str4);
            mvprintw(15, 0, str5);

            mvprintw(13, 15, arv0a);
            mvprintw(14, 15, arv1a);
            mvprintw(15, 15, arv2a);
        } else {
            mvprintw(10, 0, str0a);
            mvprintw(11, 0, str1a);
            mvprintw(12, 0, str2a);
            mvprintw(13, 0, str3a);
            mvprintw(14, 0, str4a);
            mvprintw(15, 0, str5a);

            mvprintw(13, 15, arv0);
            mvprintw(14, 15, arv1);
            mvprintw(15, 15, arv2);
        }
      
        /*c = getch();*/

        refresh();
        usleep(100000);
        i++;
        clear();
  	}



 	sleep(1);
	endwin();

	return 0;
}