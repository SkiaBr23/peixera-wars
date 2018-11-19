#include <ncurses.h>
#include <menu.h>
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>

#define HUBH 7
#define CASTLEW 30
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4
#define COL 1024
#define LINE 768

/* Funções utilizadas, futuramente .h */
void destroy_win(WINDOW *local_win);
void print_hub(WINDOW *hub, int castlehp,int gold,int food,int score, int wave );
void print_field(WINDOW *field, int lane, int unit, int enemyunit);

void print_castle(WINDOW *castle);
void tela_inicial();
void tela_final();
int menu ();
void desenha (WINDOW *win, int i, int y, int x);


int main()
{	

	keypad(stdscr, TRUE);		/* Capturar teclas como F1, F2, etc */
	initscr();			        /* Começa o modo curses */
	noecho();
	cbreak();			
	curs_set(FALSE);			/* Não mostra o cursor na tela */
	srand(time(NULL));
	halfdelay(5);				/* Todos os leitores de entrada do usuário possuem um tempo máximo de espera */

	WINDOW *wincastle;
	WINDOW *winfield1;
	WINDOW *winfield2;
	WINDOW *winfield3;
	WINDOW *winfield4;
	WINDOW *winhub;
	
	char c;


	tela_inicial();
	

	winhub = newwin(HUBH,COL, 0, 0);
	wincastle = newwin(LINE-HUBH, CASTLEW, HUBH,0);
	winfield1 = newwin((LINE-HUBH)/4, COL-CASTLEW, HUBH, CASTLEW);
	winfield2 = newwin((LINE-HUBH)/4, COL-CASTLEW, HUBH - (LINE-HUBH)/4, CASTLEW);
	winfield3 = newwin((LINE-HUBH)/4, COL-CASTLEW, HUBH - (LINE-HUBH)/2, CASTLEW);
	winfield4 = newwin((LINE-HUBH)/4, COL-CASTLEW, HUBH - (LINE-HUBH), CASTLEW);

	                        /* (height,width,starty,startx) */


	while (1)
	{

		print_hub(winhub,100,500,500,3500,2);
		wrefresh(winhub);

		print_field(winfield1,1,0,0);
		print_field(winfield2,1,0,0);
		print_field(winfield3,1,0,0);
		print_field(winfield4,1,0,0);
		wrefresh(winfield1);
		wrefresh(winfield2);
		wrefresh(winfield3);
		wrefresh(winfield4);

		print_castle(wincastle);
		wrefresh(wincastle);

		c = getch();

		switch(c)
		{
			case 'm':
				tela_inicial();
				break;
		}

	}

	endwin();
	return 0;
}

/* Apaga as informações de uma janela e deleta a estrutura */
void destroy_win(WINDOW *local_win)
{	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win);
	delwin(local_win);
}




/* Imprime a tela de Menu, com desenhos e opções */
void tela_inicial()
{
	WINDOW *build = newwin(35, 63, 5, 60);
	WINDOW *menuwin = newwin(5, 15, 11, 40);
	WINDOW *tela = newwin(1024, 768, 0, 0);
	WINDOW *mensagem = newwin(35, 63, 5, 60);
	keypad(menuwin, TRUE);

	int escolha;
	char c;
	refresh();

	mvwprintw(tela, 1, 30, " ____  ____  __  _  _  ____  ____   __     _  _   __   ____  ____");
	mvwprintw(tela, 2, 30, "(  _ \\(  __)(  )( \\/ )(  __)(  _ \\ / _\\   / )( \\ / _\\ (  _ \\/ ___)");
	mvwprintw(tela, 3, 30, " ) __/ ) _)  )(  )  (  ) _)  )   //    \\  \\ /\\ //    \\ )   /\\___ \\");
	mvwprintw(tela, 4, 30, "(__)  (____)(__)(_/\\_)(____)(__\\_)\\_/\\_/  (_/\\_)\\_/\\_/(__\\_)(____/");
	wrefresh(tela);

	mvwprintw(build, 0, 0, "                                                    !_\n                                                    |*~=-.,\n                                                    |_,-'`\n                                                    |\n                                                    |\n                                                   /^\\\n                     !_                           /   \\\n                     |*`~-.,                     /,    \\\n                     |.-~^`                     /#\"     \\\n                     |                        _/##_   _  \\_\n                _   _|  _   _   _            [ ]_[ ]_[ ]_[ ]\n               [ ]_[ ]_[ ]_[ ]_[ ]            |_=_-=_ - =_|\n             !_ |_=_ =-_-_  = =_|           !_ |=_= -    |\n             |*`--,_- _        |            |*`~-.,= []  |\n             |.-'|=     []     |   !_       |_.-\"`_-     |\n             |   |_=- -        |   |*`~-.,  |  |=_-      |\n            /^\\  |=_= -        |   |_,-~`  /^\\ |_ - =[]  |\n        _  /   \\_|_=- _   _   _|  _|  _   /   \\|=_-      |\n       [ ]/,    \\[ ]_[ ]_[ ]_[ ]_[ ]_[ ]_/,    \\[ ]=-    |\n        |/#\"     \\_=-___=__=__- =-_ -=_ /#\"     \\| _ []  |\n       _/##_   _  \\_-_ =  _____       _/##_   _  \\_ -    |\\\n      [ ]_[ ]_[ ]_[ ]=_0~{_ _ _}~0   [ ]_[ ]_[ ]_[ ]=-   | \\\n      |_=__-_=-_  =_|-=_ |~~~~~|     |_=-___-_ =-__|_    |  \\\n       | _- =-     |-_   | E C |      |= _=       | -    |___\\\n       |= -_=      |=  _ |~~~~~|      |_-=_       |=_    |/+\\|\n       | =_  -     |_ = _ `-.-`       | =_ = =    |=_-   ||+||\n       |-_=- _     |=_   =            |=_= -_     |  =   ||+||\n       |=_- /+\\    | -=               |_=- /+\\    |=_    |^^^|\n       |=_ |+|+|   |= -  -_,--,_      |_= |+|+|   |  -_  |=  |\n       |  -|+|+|   |-_=  / |  | \\     |=_ |+|+|   |-=_   |_-/\n       |=_=|+|+|   | =_= | |  | |     |_- |+|+|   |_ =   |=/\n       | _ ^^^^^   |= -  | |  <&>     |=_=^^^^^   |_=-   |/\n       |=_ =       | =_-_| |  | |     |   =_      | -_   |\n       |_=-_       |=_=  | |  | |     |=_=        |=-    |\n `^^^^^^^^^^`^`^^`^`^`^^^\"\"\"\"\"\"\"\"^`^^``^^`^^`^^`^`^``^`^``^``^^");
	
	wrefresh(build);
	escolha = menu(menuwin);
	destroy_win(tela);
	switch(escolha)
	{
		case 0:		/* Novo Jogo */
			break;
		case 1:		/* Salvar Jogo */
			break;
		case 2:		/* Carregar Jogo */
			break;
		case 3:		/* Créditos */
			break;
		case 4:		/* Sair */
			tela_final();
			break;
	}


}


/* Imprime a mensagem de despedida e encerra o programa */
void tela_final()
{
	clear();
	mvprintw(LINE/2 - 2, COL/2 - 10, "OBRIGADO POR JOGAR!");
	refresh();
	sleep(2);
	endwin();
	exit(1);
}



/* Imprime o HUB superior, com o título e informações sobre o jogo */
void print_hub(WINDOW *hub, int castlehp,int gold,int food,int score, int wave)
{

	box(hub, 0 , 0);

	mvwprintw(hub, 1, 1, " ____  ____  __  _  _  ____  ____   __     _  _   __   ____  ____");
	mvwprintw(hub, 2, 1, "(  _ \\(  __)(  )( \\/ )(  __)(  _ \\ / _\\   / )( \\ / _\\ (  _ \\/ ___)");
	mvwprintw(hub, 3, 1, " ) __/ ) _)  )(  )  (  ) _)  )   //    \\  \\ /\\ //    \\ )   /\\___ \\");
	mvwprintw(hub, 4, 1, "(__)  (____)(__)(_/\\_)(____)(__\\_)\\_/\\_/  (_/\\_)\\_/\\_/(__\\_)(____/");

	mvwprintw(hub, 2, 85, "G$ %d", gold);
	mvwprintw(hub, 2, 95, "Fd %d", food);
	mvwprintw(hub, 2, 105, "Pt %d", score);
	mvwprintw(hub, 2, 115, "Wv %d", wave);
	mvwprintw(hub, 2, 130, "M - Menu");


	/*
 ____  ____  __  _  _  ____  ____   __     _  _   __   ____  ____ 
(  _ \(  __)(  )( \/ )(  __)(  _ \ / _\   / )( \ / _\ (  _ \/ ___)
 ) __/ ) _)  )(  )  (  ) _)  )   //    \  \ /\ //    \ )   /\___ \
(__)  (____)(__)(_/\_)(____)(__\_)\_/\_/  (_/\_)\_/\_/(__\_)(____/
*/

}




/* Imprime o campo de batalha */
void print_field(WINDOW *field, int lane, int unit, int enemyunit)
{

	box(field, 0 , 0);

	mvwprintw(field, 2, 5, "---------------------");
	desenha(field, 1, 3, 10);
	mvwprintw(field, 9, 5, "---------------------");
	desenha(field, 2, 10, 12);
	mvwprintw(field, 16, 5, "---------------------");
	desenha(field, 2, 17, 12);
	mvwprintw(field, 23, 5, "---------------------");
	desenha(field, 1, 24, 10);
	mvwprintw(field, 30, 5, "---------------------");
}





/* Imprime a área dos edifícios */
void print_castle(WINDOW *castle)
{

	box(castle, 0 , 0);

	if ((rand()%100) > 50)
	{
		desenha(castle, 3, 2, 2);
	} else {
		desenha(castle, 4, 2, 2);
	}
}




/* Estrutura de opções disponíveis para o usuário na tela inicial */
int menu (WINDOW *menuwin)
{

	char *choices[] = {
                        "Novo Jogo",
                        "Salvar Jogo",
                        "Carregar Jogo",
                        "Creditos",
                        "Sair",
                  };

	ITEM **my_items;		
	ITEM *cur_item;
	MENU *my_menu;
    int n_choices, i, c;
	
    n_choices = ARRAY_SIZE(choices);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

    for(i = 0; i < n_choices; ++i) my_items[i] = new_item(choices[i], choices[i]);

	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu((ITEM **)my_items);
	set_menu_win(my_menu, menuwin);
	post_menu(my_menu);
	wrefresh(menuwin);
	
	while(1)
	{       
		c = getch();
		switch(c)
        {	
        	case 's':
				menu_driver(my_menu, REQ_DOWN_ITEM);
				wrefresh(menuwin);
				break;
			case 'w':
				menu_driver(my_menu, REQ_UP_ITEM);
				wrefresh(menuwin);
				break;
			case 10:	/* Enter */
				cur_item = current_item(my_menu);
				return (item_index(cur_item));
		}
	}
	return -1;
}



/* Imprime nas coordenadas indicadas o desenho escolhido */
void desenha (WINDOW *win, int i, int y, int x)
{
	switch(i)
	{
		case 1:
			mvwprintw(win, y, x, "    O");
            mvwprintw(win, y+1, x, "\\  /M\\");
            mvwprintw(win, y+2, x, " X/ W \\");
            mvwprintw(win, y+3, x, "    |\\");
            mvwprintw(win, y+4, x, "   /  |,");
            break;
        case 2:
        	mvwprintw(win, y, x, "  O  \\");
            mvwprintw(win, y+1, x, " /M\\_(");
            mvwprintw(win, y+2, x, "/ W  /");
            mvwprintw(win, y+3, x, "  |\\");
            mvwprintw(win, y+4, x, " /  |");
            break;
        case 3:
        	mvwprintw(win, y, x, "   +");
			mvwprintw(win, y+1, x, "   A____");
			mvwprintw(win, y+2, x, "  /\\____\\");
			mvwprintw(win, y+3, x, " _||\"\"\"\"|_");
			mvwprintw(win, y+4, x, "-^-^-^-^-^-^-");
			break;
		case 4:
			mvwprintw(win, y, x, "   +");
			mvwprintw(win, y+1, x, "   A____");
			mvwprintw(win, y+2, x, "  /\\____\\");
			mvwprintw(win, y+3, x, " _||\"\"\"\"|_");
			mvwprintw(win, y+4, x, "~^~^~^~^~^~^~");
			break;
	}
}