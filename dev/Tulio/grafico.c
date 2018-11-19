/*
PROJETO
Nome: MAXIMILLIAN FAN XAVIER, OTÁVIO ALVES DIAS, RAFAEL DIAS DA COSTA, TÚLIO ABNER DE LIMA
Matrícula: 12/0153271, 12/0131480, 12/0133253, 12/0137194
Curso: Engenharia de Computação
Disciplina: Métodos de Programação
Turma: A
Prof: Jan Mendonça
*/

#include <ncurses.h>
#include <menu.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "grafico.h"
#include "estruturas.h"
#include "engine.h"

#define HUBH 7
#define CASTLEW 40
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

/* Apaga as informações de uma janela e deleta a estrutura */
void destroy_win(WINDOW *local_win)
{	
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win);
	delwin(local_win);
}

int menu_edificio()
{
	WINDOW *menu = newwin(10, 45, 10, 60);
	box(menu, 0, 0);

	int c;

	mvwprintw(menu, 2, 3, "Escolha um edificio para evoluir:");
	mvwprintw(menu, 4, 4, "1 - Comercio");
	mvwprintw(menu, 5, 4, "2 - Quartel");
	mvwprintw(menu, 6, 4, "3 - Campo de tiro");
	mvwprintw(menu, 7, 4, "4 - Casa das lanças");

	wrefresh(menu);

	do
	{
		c = getchar();
	} while ((c != '1') && (c != '2') && (c != '3') && (c != '4'));

	switch(c)
	{
		case '1':
			return 4;
			break;
		case '2':
			return 1;
			break;
		case '3':
			return 2;
			break;
		case '4':
			return 3;
			break;
	}
	return 1;
}

int menu_unidade(Castelo *castelo)
{
	WINDOW *menu = newwin(11, 53, 10, 60);
	box(menu, 0, 0);

	int c;

	mvwprintw(menu, 2, 3, "Escolha uma unidade para treinar:");

	switch(castelo->quartel->nivel)
	{
		case 1:
			mvwprintw(menu, 4, 3, "Guerreiro Nv 1");
			mvwprintw(menu, 5, 3, "Vida: 300");
			mvwprintw(menu, 6, 3, "Ataque: 60");
			mvwprintw(menu, 7, 3, "Esquiva: 15%%");
			mvwprintw(menu, 8, 3, "Preco: $25");
			break;
		case 2:
			mvwprintw(menu, 4, 3, "Guerreiro Nv 2");
			mvwprintw(menu, 5, 3, "Vida: 400");
			mvwprintw(menu, 6, 3, "Ataque: 60");
			mvwprintw(menu, 7, 3, "Esquiva: 15%%");
			mvwprintw(menu, 8, 3, "Preco: $60");
			break;
		case 3:
			mvwprintw(menu, 4, 3, "Guerreiro Nv 3");
			mvwprintw(menu, 5, 3, "Vida: 500");
			mvwprintw(menu, 6, 3, "Ataque: 60");
			mvwprintw(menu, 7, 3, "Esquiva: 15%%");
			mvwprintw(menu, 8, 3, "Preco: $95");
			break;		
	}

	switch(castelo->campodetiro->nivel)
	{
		case 1:
			mvwprintw(menu, 4, 20, "Arqueiro Nv 1");
			mvwprintw(menu, 5, 20, "Vida: 280");
			mvwprintw(menu, 6, 20, "Ataque: 60");
			mvwprintw(menu, 7, 20, "Esquiva: 20%%");
			mvwprintw(menu, 8, 20, "Preco: $25");
			break;
		case 2:
			mvwprintw(menu, 4, 20, "Arqueiro Nv 2");
			mvwprintw(menu, 5, 20, "Vida: 280");
			mvwprintw(menu, 6, 20, "Ataque: 60");
			mvwprintw(menu, 7, 20, "Esquiva: 30%%");
			mvwprintw(menu, 8, 20, "Preco: $60");
			break;
		case 3:
			mvwprintw(menu, 4, 20, "Arqueiro Nv 3");
			mvwprintw(menu, 5, 20, "Vida: 280");
			mvwprintw(menu, 6, 20, "Ataque: 60");
			mvwprintw(menu, 7, 20, "Esquiva: 40%%");
			mvwprintw(menu, 8, 20, "Preco: $95");
			break;		
	}

	switch(castelo->casadaslancas->nivel)
	{
		case 1:
			mvwprintw(menu, 4, 36, "Lanceiro Nv 1");
			mvwprintw(menu, 5, 36, "Vida: 280");
			mvwprintw(menu, 6, 36, "Ataque: 70");
			mvwprintw(menu, 7, 36, "Esquiva: 15%%");
			mvwprintw(menu, 8, 36, "Preco: $25");
			break;
		case 2:
			mvwprintw(menu, 4, 36, "Lanceiro Nv 2");
			mvwprintw(menu, 5, 36, "Vida: 280");
			mvwprintw(menu, 6, 36, "Ataque: 90");
			mvwprintw(menu, 7, 36, "Esquiva: 15%%");
			mvwprintw(menu, 8, 36, "Preco: $60");
			break;
		case 3:
			mvwprintw(menu, 4, 36, "Lanceiro Nv 3");
			mvwprintw(menu, 5, 36, "Vida: 280");
			mvwprintw(menu, 6, 36, "Ataque: 120");
			mvwprintw(menu, 7, 36, "Esquiva: 15%%");
			mvwprintw(menu, 8, 36, "Preco: $95");
			break;		
	}

	wrefresh(menu);

	do
	{
		c = getchar();
	} while ((c != '1') && (c != '2') && (c != '3'));

	mvwprintw(menu, 2, 3, "                                                  ");
	mvwprintw(menu, 4, 3, "                                                  ");
	mvwprintw(menu, 5, 3, "                                                  ");
	mvwprintw(menu, 6, 3, "                                                  ");
	mvwprintw(menu, 7, 3, "                                                  ");
	mvwprintw(menu, 8, 3, "                                                  ");

	destroy_win(menu);

	switch(c)
	{
		case '1':
			return 1;
			break;
		case '2':
			return 2;
			break;
		case '3':
			return 3;
			break;
	}
	return 1;
}


void mensagem(int y, int x, char frase[])
{
	int tam;
	tam = strlen(frase);
	WINDOW *mensagem = newwin(5, tam+4, y, x);
	box(mensagem, 0, 0);

	mvwprintw(mensagem, 2, 2, frase);

	wrefresh(mensagem);
}

char* mensagem_entrada(int y, int x, char frase[])
{
	char *string = (char *) malloc(31 * sizeof(char));
	int tam;
	int i;
	tam = strlen(frase);
	WINDOW *mensagem = newwin(7, tam+4, y, x);
	box(mensagem, 0, 0);

	mvwprintw(mensagem, 2, 2, frase);
	wrefresh(mensagem);
	move(y+4, x+2);
	echo();
	getstr(string);
	noecho();
	string[30] = '\0';

	for (i = 0; i < tam; ++i)
	{
		mvwprintw(mensagem, 2, i+2, " ");
	}

	destroy_win(mensagem);

	return string;
}



/* Imprime a tela de Menu, com desenhos e opções */
void tela_inicial()
{
	WINDOW *build = newwin(35, 63, 5, 60);
	WINDOW *menuwin = newwin(5, 15, 11, 40);
	WINDOW *tela = newwin(LINES, COLS, 0, 0);
	
	keypad(menuwin, TRUE);

	refresh();

	mvwprintw(tela, 1, 30, " ____  ____  __  _  _  ____  ____   __     _  _   __   ____  ____");
	mvwprintw(tela, 2, 30, "(  _ \\(  __)(  )( \\/ )(  __)(  _ \\ / _\\   / )( \\ / _\\ (  _ \\/ ___)");
	mvwprintw(tela, 3, 30, " ) __/ ) _)  )(  )  (  ) _)  )   //    \\  \\ /\\ //    \\ )   /\\___ \\");
	mvwprintw(tela, 4, 30, "(__)  (____)(__)(_/\\_)(____)(__\\_)\\_/\\_/  (_/\\_)\\_/\\_/(__\\_)(____/");
	wrefresh(tela);

	mvwprintw(build, 0, 0, "                                                    !_\n                                                    |*~=-.,\n                                                    |_,-'`\n                                                    |\n                                                    |\n                                                   /^\\\n                     !_                           /   \\\n                     |*`~-.,                     /,    \\\n                     |.-~^`                     /#\"     \\\n                     |                        _/##_   _  \\_\n                _   _|  _   _   _            [ ]_[ ]_[ ]_[ ]\n               [ ]_[ ]_[ ]_[ ]_[ ]            |_=_-=_ - =_|\n             !_ |_=_ =-_-_  = =_|           !_ |=_= -    |\n             |*`--,_- _        |            |*`~-.,= []  |\n             |.-'|=     []     |   !_       |_.-\"`_-     |\n             |   |_=- -        |   |*`~-.,  |  |=_-      |\n            /^\\  |=_= -        |   |_,-~`  /^\\ |_ - =[]  |\n        _  /   \\_|_=- _   _   _|  _|  _   /   \\|=_-      |\n       [ ]/,    \\[ ]_[ ]_[ ]_[ ]_[ ]_[ ]_/,    \\[ ]=-    |\n        |/#\"     \\_=-___=__=__- =-_ -=_ /#\"     \\| _ []  |\n       _/##_   _  \\_-_ =  _____       _/##_   _  \\_ -    |\\\n      [ ]_[ ]_[ ]_[ ]=_0~{_ _ _}~0   [ ]_[ ]_[ ]_[ ]=-   | \\\n      |_=__-_=-_  =_|-=_ |~~~~~|     |_=-___-_ =-__|_    |  \\\n       | _- =-     |-_   | E C |      |= _=       | -    |___\\\n       |= -_=      |=  _ |~~~~~|      |_-=_       |=_    |/+\\|\n       | =_  -     |_ = _ `-.-`       | =_ = =    |=_-   ||+||\n       |-_=- _     |=_   =            |=_= -_     |  =   ||+||\n       |=_- /+\\    | -=               |_=- /+\\    |=_    |^^^|\n       |=_ |+|+|   |= -  -_,--,_      |_= |+|+|   |  -_  |=  |\n       |  -|+|+|   |-_=  / |  | \\     |=_ |+|+|   |-=_   |_-/\n       |=_=|+|+|   | =_= | |  | |     |_- |+|+|   |_ =   |=/\n       | _ ^^^^^   |= -  | |  <&>     |=_=^^^^^   |_=-   |/\n       |=_ =       | =_-_| |  | |     |   =_      | -_   |\n       |_=-_       |=_=  | |  | |     |=_=        |=-    |\n `^^^^^^^^^^`^`^^`^`^`^^^\"\"\"\"\"\"\"\"^`^^``^^`^^`^^`^`^``^`^``^``^^");
	
	wrefresh(build);

	Inicia();
	
}


/* Imprime a mensagem de despedida e encerra o programa */
void tela_final()
{
	WINDOW *tela = newwin(LINES, COLS, 0, 0);
	mvprintw(LINES/2 - 2, COLS/2 - 10, "OBRIGADO POR JOGAR!");
	refresh();
	sleep(2);
	endwin();
	exit(1);
}






void creditos(int y, int x)
{
	WINDOW *creditos = newwin(8, 26, y, x);
	box(creditos, 0, 0);
	int i, j;

	mvwprintw(creditos, 2, 2, "Maximillian Fan Xavier");
	mvwprintw(creditos, 3, 2, "Otavio Alves Dias");
	mvwprintw(creditos, 4, 2, "Rafael Dias da Costa");
	mvwprintw(creditos, 5, 2, "Tulio Abner de Lima");

	wrefresh(creditos);

	getch();

	for (j = 2; j < 6; j++)
	{
		for (i = 0; i < 22; i++)
		{
			mvwprintw(creditos, j, i+2, " ");
		}
	}

	destroy_win(creditos);
}






/* Imprime o HUB superior, com o título e informações sobre o jogo */
void print_hub(WINDOW *hub,int gold, int wave)
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

	desenhainimigo(field, 1, 3, 80);
	desenhainimigo(field, 2, 10, 80);
	desenhainimigo(field, 3, 17, 80);
	desenhainimigo(field, 4, 24, 80);
}





/* Imprime a área dos edifícios */
void print_castle(WINDOW *castle, Castelo *castelo)
{

	box(castle, 0 , 0);

		desenhaedificio(castle, castelo->comercio->nivel, 0, 2, 4);
		desenhaedificio(castle, castelo->quartel->nivel,1, 10, 6);
		desenhaedificio(castle, castelo->campodetiro->nivel,2,18,4);
		desenhaedificio(castle, castelo->casadaslancas->nivel,3,26,3);

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
        	mvwprintw(win, y, x, " /|{)/");
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

void desenhaedificio(WINDOW *win, int nivel, int edificio, int y, int x)
{
	switch(edificio)
	{
		case 0:

			mvwprintw(win, y, x, "	        x");
            mvwprintw(win, y+1, x, ".-. ________|_    Comercio");
            mvwprintw(win, y+2, x, "|=|/     /    \\   Nivel: %d", nivel);
            mvwprintw(win, y+3, x, "| |_LOJA_|_||_|");
            mvwprintw(win, y+4, x, "|_|_[ ]__|____|");
            break;

		case 1:
        	mvwprintw(win, y, x, " _   |~  _");
			mvwprintw(win, y+1, x, "[_]--'--[_]     Quartel");
			mvwprintw(win, y+2, x, "| |  S  |'|     Nivel: %d", nivel);
			mvwprintw(win, y+3, x, "| | /^\\ | |");
			mvwprintw(win, y+4, x, "|_|_|I|_|_|");
			break;
        case 2:
        	  mvwprintw(win, y, x, "      +");
			mvwprintw(win, y+1, x, "   _.-A-._      Campo de Tiro");
			mvwprintw(win, y+2, x, ".='_______'=.     Nivel: %d", nivel);
			mvwprintw(win, y+3, x, " ||     o ||");
			mvwprintw(win, y+4, x, "_||[X]__|_||__");
			break;
		case 3:
			mvwprintw(win, y, x, "    __-L-__");
			mvwprintw(win, y+1, x, "   /\\-'o'-/\\    Casa das Lancas");
			mvwprintw(win, y+2, x, "  _||:<_>:||_      Nivel: %d", nivel);
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