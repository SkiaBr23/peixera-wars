#include <ncurses.h>
#include <menu.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HUBH 7
#define CASTLEW 40
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

/* Funções utilizadas, futuramente .h */
void destroy_win(WINDOW *local_win);
void print_hub(WINDOW *hub,int gold,int food,int score, int wave );
void print_field(WINDOW *field);
void print_castle(WINDOW *castle);
void tela_inicial();
void tela_final();
int menu ();
void desenhaunidade (WINDOW *win, int unidade, int y, int x);
void desenhaedificio (WINDOW *win, int edificio, int y, int x);
void desenhainimigo(WINDOW *win, int inimigo, int y, int x);


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
	WINDOW *winfield;
	WINDOW *winhub;
	
	char c;


	tela_inicial();
	

	winhub = newwin(HUBH,COLS, 0, 0);
	wincastle = newwin(LINES-HUBH, CASTLEW, HUBH,0);
	winfield = newwin(LINES-HUBH, COLS-CASTLEW, HUBH, CASTLEW);
	                        /* (height,width,starty,startx) */


	while (1)
	{

		print_hub(winhub,500,500,3500,2);
		wrefresh(winhub);

		print_field(winfield);
		wrefresh(winfield);

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
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win);
	delwin(local_win);
}




/* Imprime a tela de Menu, com desenhos e opções */
void tela_inicial()
{
	WINDOW *build = newwin(35, 63, 5, 60);
	WINDOW *menuwin = newwin(5, 15, 11, 40);
	WINDOW *tela = newwin(LINES, COLS, 0, 0);
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
	mvprintw(LINES/2 - 2, COLS/2 - 10, "OBRIGADO POR JOGAR!");
	refresh();
	sleep(2);
	endwin();
	exit(1);
}



/* Imprime o HUB superior, com o título e informações sobre o jogo */
void print_hub(WINDOW *hub,int gold,int food,int score, int wave)
{

	box(hub, 0 , 0);

	mvwprintw(hub, 1, 1, " ____  ____  __  _  _  ____  ____   __     _  _   __   ____  ____");
	mvwprintw(hub, 2, 1, "(  _ \\(  __)(  )( \\/ )(  __)(  _ \\ / _\\   / )( \\ / _\\ (  _ \\/ ___)");
	mvwprintw(hub, 3, 1, " ) __/ ) _)  )(  )  (  ) _)  )   //    \\  \\ /\\ //    \\ )   /\\___ \\");
	mvwprintw(hub, 4, 1, "(__)  (____)(__)(_/\\_)(____)(__\\_)\\_/\\_/  (_/\\_)\\_/\\_/(__\\_)(____/");

	mvwprintw(hub, 2, 85, "Gold$ %d", gold);
	mvwprintw(hub, 2, 100, "Wave %d", wave);
	mvwprintw(hub, 2, 130, "M - Menu");


	/*
 ____  ____  __  _  _  ____  ____   __     _  _   __   ____  ____ 
(  _ \(  __)(  )( \/ )(  __)(  _ \ / _\   / )( \ / _\ (  _ \/ ___)
 ) __/ ) _)  )(  )  (  ) _)  )   //    \  \ /\ //    \ )   /\___ \
(__)  (____)(__)(_/\_)(____)(__\_)\_/\_/  (_/\_)\_/\_/(__\_)(____/
*/

}




/* Imprime o campo de batalha */
void print_field(WINDOW *field)
{

	box(field, 0 , 0);
	
	desenhaunidade(field, 1, 3, 10);
	desenhaunidade(field, 2, 10, 12);
	desenhaunidade(field, 3, 17, 12);
	desenhaunidade(field, 4, 24, 12);

	desenhainimigo(field, 1, 3, 40);
	desenhainimigo(field, 2, 10, 40);
	desenhainimigo(field, 3, 17, 40);
	desenhainimigo(field, 4, 24, 40);
}





/* Imprime a área dos edifícios */
void print_castle(WINDOW *castle)
{

	box(castle, 0 , 0);

		desenhaedificio(castle,0,2,4);
		desenhaedificio(castle,1, 10, 6);
		desenhaedificio(castle,2,18,4);
		desenhaedificio(castle,3,26,3);

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
void desenhaunidade (WINDOW *win, int unidade, int y, int x)
{
	switch(unidade)
	{
		case 1:
			mvwprintw(win, y, x, "    O");
            mvwprintw(win, y+1, x, "\\  /M\\");
            mvwprintw(win, y+2, x, " X/ W \\");
            mvwprintw(win, y+3, x, "    |\\");
            mvwprintw(win, y+4, x, "   /_ |_");
            break;
        case 2:
        	mvwprintw(win, y, x, "  O  \\");
            mvwprintw(win, y+1, x, " /M\\_(");
            mvwprintw(win, y+2, x, "/ W  /");
            mvwprintw(win, y+3, x, "  |\\");
            mvwprintw(win, y+4, x, " /_ |_");
            break;
        case 3:
        	  mvwprintw(win, y, x, "  O");
            mvwprintw(win, y+1, x, " /M\\");
            mvwprintw(win, y+2, x, "W===M===[>");
            mvwprintw(win, y+3, x, "  |\\");
            mvwprintw(win, y+4, x, " /_ |_");
			break;
		case 4:
			  mvwprintw(win, y, x, "  O  #");
            mvwprintw(win, y+1, x, " /M\\_|");
            mvwprintw(win, y+2, x, "/ W  |");
            mvwprintw(win, y+3, x, "  |\\ |");
            mvwprintw(win, y+4, x, " /_ |_");
			break;
	}
}

void desenhainimigo (WINDOW *win, int inimigo, int y, int x)
{
	switch(inimigo)
	{
		case 1:
			mvwprintw(win, y, x, "(___)");
            mvwprintw(win, y+1, x, "(o o)_____/");
            mvwprintw(win, y+2, x, " @@ `     \\");
            mvwprintw(win, y+3, x, "  \\ ____, /");
            mvwprintw(win, y+4, x, "  //    //");
            mvwprintw(win, y+5, x, " ^^    ^^");
            break;
        case 2:
        	mvwprintw(win, y, x, "  /|{)/");
            mvwprintw(win, y+1, x, "+---)    _");
            mvwprintw(win, y+2, x, " \\||(___( ~");
            mvwprintw(win, y+3, x, " _|)---\\\\_");
            mvwprintw(win, y+4, x, "\\        \\");
            break;
        case 3:
        	  mvwprintw(win, y, x, "     |_|   ");
            mvwprintw(win, y+1, x, "    ('.')  ///");
            mvwprintw(win, y+2, x, "     (W)   /");
            mvwprintw(win, y+3, x, "    <(M)`-/'");
            mvwprintw(win, y+4, x, "<-._/J L /  ");
			break;
		case 4:
			  mvwprintw(win, y, x, "   _//|.-~~~~-,");
            mvwprintw(win, y+1, x, " _/66  \\       \\_@");
            mvwprintw(win, y+2, x, "(\")_   /   /   |");
            mvwprintw(win, y+3, x, "  '--'|| |-\\  /");
            mvwprintw(win, y+4, x, "      //_/ /_/");
			break;
	}
}

void desenhaedificio(WINDOW *win, int edificio, int y, int x)
{
	switch(edificio)
	{
		case 0:

			  mvwprintw(win, y, x, "	        x");
            mvwprintw(win, y+1, x, ".-. ________|_     Comércio");
            mvwprintw(win, y+2, x, "|=|/     /    \\   Nível: 1");
            mvwprintw(win, y+3, x, "| |_LOJA_|_||_|");
            mvwprintw(win, y+4, x, "|_|_[ ]__|____|");
            break;

		case 1:
        	mvwprintw(win, y, x, " _   |~  _");
			mvwprintw(win, y+1, x, "[_]--'--[_]     Quartel");
			mvwprintw(win, y+2, x, "| |  S  |'|     Nível: 1");
			mvwprintw(win, y+3, x, "| | /^\\ | |");
			mvwprintw(win, y+4, x, "|_|_|I|_|_|");
			break;
        case 2:
        	  mvwprintw(win, y, x, "      +");
			mvwprintw(win, y+1, x, "   _.-A-._      Campo de Tiro");
			mvwprintw(win, y+2, x, ".='_______'=.     Nível: 1");
			mvwprintw(win, y+3, x, " ||     o ||");
			mvwprintw(win, y+4, x, "_||[X]__|_||__");
			break;
		case 3:
			mvwprintw(win, y, x, "    __-L-__");
			mvwprintw(win, y+1, x, "   /\\-'o'-/\\  Casa das Lanças");
			mvwprintw(win, y+2, x, "  _||:<_>:||_      Nível: 1");
			mvwprintw(win, y+3, x, " /\\_/=====\\_/\\");
			mvwprintw(win, y+4, x, "_|:_:_[I]_:_:|_");
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