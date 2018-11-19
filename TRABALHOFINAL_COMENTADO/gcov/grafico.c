/*
PROJETO
Nome: MAXIMILLIAN FAN XAVIER, OTÁVIO ALVES DIAS, RAFAEL DIAS DA COSTA, TÚLIO ABNER DE LIMA
Matrícula: 12/0153271, 12/0131480, 12/0133253, 12/0137194
Curso: Engenharia de Computação
Disciplina: Métodos de Programação
Turma: A
Prof: Jan Mendonça
*/

/*INCLUSÃO DAS BIBLIOTECAS*/
#include <ncurses.h>
#include <menu.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "grafico.h"
#include "estruturas.h"
#include "engine.h"

/*DEFINIÇÃO DE CONSTANTES*/
#define HUBH 7
#define CASTLEW 40
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

/*
Função responsável por apagar as informações de uma janela e deletar sua estrutura.
REQUISITO: Uma estrutura do tipo WINDOW previamente inicializada.
HIPÓTESE: A janela deixará de existir.
ASSERTIVAS DE ENTRADA: A estrutura não pode apontar para NULL.
ASSERTIVAS DE SAÍDA: A função não possui saída. 
INTERFACE EXPLÍCITA: Tipo de retorno void e o parâmetro de entrada WINDOW *local_win.
INTERFACE IMPLÍCITA: funções auxiliares pala gerenciar a janela.
*/
void destroy_win(WINDOW *local_win)
{	
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win);
	delwin(local_win);
}

/*
Função responsável pela criação do menu de evolução dos edifícios.
REQUISITO: A função deve ser chamada no final de uma rodada.
HIPÓTESE: A função irá retornar um valor correspondente à uma das opções do menu.
ASSERTIVAS DE ENTRADA: A função não possui parâmetros.
ASSERTIVAS DE SAÍDA: O retorno deve ser um número entre 1 e 4. 
INTERFACE EXPLÍCITA: Tipo de retorno int.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
*/
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

/*
Função responsável pela criação do menu de compra de unidades.
REQUISITO: A função deve ser chamada no início de uma rodada.
HIPÓTESE: A função irá retornar um valor correspondente à uma das opções do menu.
ASSERTIVAS DE ENTRADA: A função não possui parâmetros.
ASSERTIVAS DE SAÍDA: O retorno deve ser um número entre 1 e 3. 
INTERFACE EXPLÍCITA: Tipo de retorno int.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
*/
int menu_unidade(Castelo *castelo)
{
	WINDOW *menu = newwin(12, 53, 10, 60);
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
			mvwprintw(menu, 10, 3, "Pressione 1");
			break;
		case 2:
			mvwprintw(menu, 4, 3, "Guerreiro Nv 2");
			mvwprintw(menu, 5, 3, "Vida: 400");
			mvwprintw(menu, 6, 3, "Ataque: 60");
			mvwprintw(menu, 7, 3, "Esquiva: 15%%");
			mvwprintw(menu, 8, 3, "Preco: $60");
			mvwprintw(menu, 10, 3, "Pressione 1");
			break;
		case 3:
			mvwprintw(menu, 4, 3, "Guerreiro Nv 3");
			mvwprintw(menu, 5, 3, "Vida: 500");
			mvwprintw(menu, 6, 3, "Ataque: 60");
			mvwprintw(menu, 7, 3, "Esquiva: 15%%");
			mvwprintw(menu, 8, 3, "Preco: $95");
			mvwprintw(menu, 10, 3, "Pressione 1");
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
			mvwprintw(menu, 10, 20, "Pressione 2");
			break;
		case 2:
			mvwprintw(menu, 4, 20, "Arqueiro Nv 2");
			mvwprintw(menu, 5, 20, "Vida: 280");
			mvwprintw(menu, 6, 20, "Ataque: 60");
			mvwprintw(menu, 7, 20, "Esquiva: 30%%");
			mvwprintw(menu, 8, 20, "Preco: $60");
			mvwprintw(menu, 10, 20, "Pressione 2");
			break;
		case 3:
			mvwprintw(menu, 4, 20, "Arqueiro Nv 3");
			mvwprintw(menu, 5, 20, "Vida: 280");
			mvwprintw(menu, 6, 20, "Ataque: 60");
			mvwprintw(menu, 7, 20, "Esquiva: 40%%");
			mvwprintw(menu, 8, 20, "Preco: $95");
			mvwprintw(menu, 10, 20, "Pressione 2");
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
			mvwprintw(menu, 10, 36, "Pressione 3");
			break;
		case 2:
			mvwprintw(menu, 4, 36, "Lanceiro Nv 2");
			mvwprintw(menu, 5, 36, "Vida: 280");
			mvwprintw(menu, 6, 36, "Ataque: 90");
			mvwprintw(menu, 7, 36, "Esquiva: 15%%");
			mvwprintw(menu, 8, 36, "Preco: $60");
			mvwprintw(menu, 10, 36, "Pressione 3");
			break;
		case 3:
			mvwprintw(menu, 4, 36, "Lanceiro Nv 3");
			mvwprintw(menu, 5, 36, "Vida: 280");
			mvwprintw(menu, 6, 36, "Ataque: 120");
			mvwprintw(menu, 7, 36, "Esquiva: 15%%");
			mvwprintw(menu, 8, 36, "Preco: $95");
			mvwprintw(menu, 10, 36, "Pressione 3");
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

/*
Função responsável pela impressão de uma mensagem na tela
REQUISITO: O usuário deve passar as coordenadas da impressão.
HIPÓTESE: A função irá imprimir na tela a mensagem passada como parâmetro.
ASSERTIVAS DE ENTRADA: os inteiros devem estar entre 0 e LINES e COLS respectivamente.
ASSERTIVAS DE SAÍDA: A função não possui saída. 
INTERFACE EXPLÍCITA: Tipo de retorno void, com parâmetros int y, int x, char frase[].
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
*/
void mensagem(int y, int x, char frase[])
{
	int tam;
	tam = strlen(frase);
	WINDOW *mensagem = newwin(5, tam+4, y, x);
	box(mensagem, 0, 0);

	mvwprintw(mensagem, 2, 2, frase);

	wrefresh(mensagem);
}

/*Função responsável pela impressão de uma mensagem na tela e guardar a informação digitada pelo usuário*/
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

/* Função responsável pela  impressão da tela de Menu, com desenhos e opções*/
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


/* Função responsável por imprimir a mensagem de despedida e encerrar o programa */
void tela_final()
{
	clear();
	mvprintw(LINES/2 - 2, COLS/2 - 10, "OBRIGADO POR JOGAR!");
	refresh();
	sleep(2);
	endwin();
	exit(1);
}

/*Função responsável por imprimir a mensagem de fim de jogo e encerrar o programa*/
void TelaGameOver()
{
	int x = COLS/4,y=15;
	clear();

	mvprintw(y,x,"      _____          __  __ ______    ______      ________ _____  _       ");
	mvprintw(y+1,x,"     / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\| |      ");
	mvprintw(y+2,x,"    | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) | |      ");
	mvprintw(y+3,x,"    | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /| |      ");
	mvprintw(y+4,x,"    | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\|_|      ");
	mvprintw(y+5,x,"     \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_(_)      ");
	mvprintw(y+6,x," ________________________________________________________________________ ");
	mvprintw(y+7,x,"|________________________________________________________________________|");
	refresh();
	sleep(3);
	endwin();
	exit(1);
}

/*Função responsável pela impressão dos créditos*/
void creditos(int y, int x)
{
	WINDOW *creditos = newwin(16, 64, y, x);
	int i, j;

	
	mvwprintw(creditos, 2, 2, "			    								   ,  ,");
	mvwprintw(creditos, 3, 2, "                                               / \\/ \\");
	mvwprintw(creditos, 4, 2, "                                              (/ //_ \\_");
	mvwprintw(creditos, 5, 2, "     .-._                                      \\||  .  \\");
	mvwprintw(creditos, 6, 2, "      \\  '-._                            _,:__.-'/---\\_ \\");
	mvwprintw(creditos, 7, 2, " ______/___  '.    .--------------------'~-'--.)__( , )\\ \\");
	mvwprintw(creditos, 8, 2, "`'--.___  _\\  /    |   Maximillian Fan Xavier ,'    \\)|\\ `\\|");
	mvwprintw(creditos, 9, 2, "     /_.-' _\\ \\ _:,_    Otavio Alves Dias           ' |   (");
	mvwprintw(creditos, 10, 2, "   .'__ _.' \\'-/,`-~`    Rafael Dias da Costa        |/");
	mvwprintw(creditos, 11, 2, "       '. ___.> /=,|       Tulio Abner de Lima       |");
	mvwprintw(creditos, 12, 2, "        / .-'/_ )  '---------------------------------'");
	mvwprintw(creditos, 13, 2, "        )'  ( /(/");
	mvwprintw(creditos, 14, 2, "             \\\\ '");
	mvwprintw(creditos, 15, 2, "              '==''");

	wrefresh(creditos);

	getch();

	for (j = 2; j < 16; j++)
	{
		for (i = 0; i < 64; i++)
		{
			mvwprintw(creditos, j, i+2, " ");
		}
	}

	destroy_win(creditos);
}

/* Função responsável pela impressão do HUB superior, contendo título e informações sobre o jogo(ouro disponível e numero da horda) */
void print_hub(WINDOW *hub,int gold, int wave)
{

	box(hub, 0 , 0);

	mvwprintw(hub, 1, 1, " ____  ____  __  _  _  ____  ____   __     _  _   __   ____  ____");
	mvwprintw(hub, 2, 1, "(  _ \\(  __)(  )( \\/ )(  __)(  _ \\ / _\\   / )( \\ / _\\ (  _ \\/ ___)");
	mvwprintw(hub, 3, 1, " ) __/ ) _)  )(  )  (  ) _)  )   //    \\  \\ /\\ //    \\ )   /\\___ \\");
	mvwprintw(hub, 4, 1, "(__)  (____)(__)(_/\\_)(____)(__\\_)\\_/\\_/  (_/\\_)\\_/\\_/(__\\_)(____/");

	mvwprintw(hub, 2, 80, "Gold$ %d", gold);
	mvwprintw(hub, 4, 80, "Wave %d", wave);
	mvwprintw(hub, 2, 100, "M - Menu");

}




/* Função responsável pela impressão do campo de batalha */
void print_field(WINDOW *field, CabecaPFilas *filas)
{

	box(field, 0 , 0);
	Unidade *lis;
	int i, j;

	for (i = 1; i < LINES-HUBH-2; ++i)
	{
		for (j = 1; j < COLS-CASTLEW; ++j)
		{
			mvwprintw(field, i, j, " ");
		}
	}

	for (lis = filas->player, i = 3; lis!=NULL; lis = lis->prox, i+=7)
	{
		desenhaunidade(field, lis->classe, i, 10);
		mvwprintw(field, i, 5, "HP %d", lis->vida);
	}

	for (lis = filas->cpu, i = 3; lis!=NULL; lis = lis->prox, i+=7)
	{
		desenhainimigo(field, lis->classe, i, 80);
		mvwprintw(field, i, 90, "HP %d", lis->vida);
	}
}

/* Função responsável pela impressão da área de edifícios*/
void print_castle(WINDOW *castle, Castelo *castelo)
{

	box(castle, 0 , 0);

		desenhaedificio(castle, castelo->comercio->nivel, 0, 2, 4);
		desenhaedificio(castle, castelo->quartel->nivel,1, 10, 6);
		desenhaedificio(castle, castelo->campodetiro->nivel,2,18,4);
		desenhaedificio(castle, castelo->casadaslancas->nivel,3,26,3);

}

/* Função que cria a estrutura de opções disponíveis para o usuário na tela inicial */
int menu (WINDOW *menuwin)
{

	char *choices[] = {
                        "Novo Jogo",
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

/* Função responsável pela impressão do desenho escolhido nas coordenadas indicadas */
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
        	mvwprintw(win, y, x, "    O  \\");
            mvwprintw(win, y+1, x, "   /M\\_(");
            mvwprintw(win, y+2, x, "  / W  /");
            mvwprintw(win, y+3, x, "    |\\");
            mvwprintw(win, y+4, x, "   /_ |_");
            break;
        case 3:
        	  mvwprintw(win, y, x, "    O");
            mvwprintw(win, y+1, x, "   /M\\");
            mvwprintw(win, y+2, x, "  W===M===[>");
            mvwprintw(win, y+3, x, "    |\\");
            mvwprintw(win, y+4, x, "   /_ |_");
			break;
		case 4:
			  mvwprintw(win, y, x, "    O  #");
            mvwprintw(win, y+1, x, "   /M\\_|");
            mvwprintw(win, y+2, x, "  / W  |");
            mvwprintw(win, y+3, x, "    |\\ |");
            mvwprintw(win, y+4, x, "   /_ |_");
			break;
	}
}

/*Função responsável pela impressão de unidades inimigas nas coordenadas escolhidas*/
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
        	mvwprintw(win, y, x, "   _//|.-~~~~-,");
            mvwprintw(win, y+1, x, " _/66  \\       \\_@");
            mvwprintw(win, y+2, x, "(\")_   /   /   |");
            mvwprintw(win, y+3, x, "  '--'|| |-\\  /");
            mvwprintw(win, y+4, x, "      //_/ /_/");
        	
            break;
        case 3:
        	  mvwprintw(win, y, x, "     |_|   ");
            mvwprintw(win, y+1, x, "    ('.')  ///");
            mvwprintw(win, y+2, x, "     (W)   /");
            mvwprintw(win, y+3, x, "    <(M)`-/'");
            mvwprintw(win, y+4, x, "<-._/J L /  ");
			break;
		case 5:
			mvwprintw(win, y, x, " /|{)/");
            mvwprintw(win, y+1, x, "+---)    _");
            mvwprintw(win, y+2, x, " \\||(___( ~");
            mvwprintw(win, y+3, x, " _|)---\\\\_");
            mvwprintw(win, y+4, x, "\\        \\");
			break;
			
		case 4:
			x = x-18;
			y = y + 5;
			
			mvwprintw(win, y, x, " <>=======() ");
            mvwprintw(win, y+1, x, "   (/\\___   /|\\\\          ()==========<>_");
            mvwprintw(win, y+2, x, "        \\_/ | \\\\        //|\\   ______/ \\)");
            mvwprintw(win, y+3, x, "          \\_|  \\\\      // | \\_/");
            mvwprintw(win, y+4, x, "            \\|\\/|\\_   //  /\\/");
			mvwprintw(win, y+5, x, "            (oo)\\ \\_//  /");
			mvwprintw(win, y+6, x, "            //_/\\_\\/ /  |");
			mvwprintw(win, y+7, x, "           @@/  |=\\  \\  |");
			mvwprintw(win, y+8, x, "                \\_=\\_ \\ |");
			mvwprintw(win, y+9, x, "               __(\\===\\(  )\\");
			mvwprintw(win, y+10, x, "              (((~) __(_/   |");
			mvwprintw(win, y+11, x, "                   (((~) \\  /");
			mvwprintw(win, y+12, x, "                   ______/ /");
			mvwprintw(win, y+13, x, "                   '------'");
				   
			break;		
			
	}
}

/*Função responsável pela impressão do desenho de edifícios*/
void desenhaedificio(WINDOW *win, int nivel, int edificio, int y, int x)
{
	switch(edificio)
	{
		case 0:

			mvwprintw(win, y, x, "	        x");
            mvwprintw(win, y+1, x, ".-. ________|_    Comercio");
            mvwprintw(win, y+2, x, "|=|/     /    \\   Nivel: %d", nivel);
            mvwprintw(win, y+3, x, "| |_LOJA_|_||_|   %d gold/wave",100*nivel);
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

/*Função responsável pela impressão das setas de escolha de unidade*/
void seta(WINDOW *win, int tipo, int y, int x)
{
	if (tipo == 1)
	{
		mvwprintw(win, y, x, "  \\");
		mvwprintw(win, y+1, x, "===\\");
		mvwprintw(win, y+2, x, "===/");
		mvwprintw(win, y+3, x, "  /");
	}
	else
	{
		if (tipo == 2)
		{
			mvwprintw(win, y, x, " /");
			mvwprintw(win, y+1, x, "/===");
			mvwprintw(win, y+2, x, "\\===");
			mvwprintw(win, y+3, x, " \\");
		}
		else
		{
			mvwprintw(win, y, x, "      ");
			mvwprintw(win, y+1, x, "      ");
			mvwprintw(win, y+2, x, "      ");
			mvwprintw(win, y+3, x, "      ");
		}
	}
}

/*Função responsável pela atualização do desenho de seta durante uma batalha*/
void seta_batalha(WINDOW *winfield, int j, int i)
{
	if (j == 2)
	{
		switch(i)
		{
			case 1:
				seta(winfield, 2, 3, 23);
				wrefresh(winfield);
				break;
			case 2:
				seta(winfield, 0, 3, 23);
				seta(winfield, 2, 10, 23);
				wrefresh(winfield);
				break;
			case 3:
				seta(winfield, 0, 10, 23);
				seta(winfield, 2, 17, 23);
				wrefresh(winfield);
				break;
			case 4:
				seta(winfield, 0, 17, 23);
				seta(winfield, 2, 24, 23);
				wrefresh(winfield);
				break;
		}
	}
	else
	{
		if (j == 1)
		{
			switch(i)
			{
				case 1:
					seta(winfield, 1, 3, 70);
					seta(winfield, 0, 10, 70);
					wrefresh(winfield);
					break;
				case 2:
					seta(winfield, 0, 3, 70);
					seta(winfield, 0, 17, 70);
					seta(winfield, 1, 10, 70);
					wrefresh(winfield);
					break;
				case 3:
					seta(winfield, 0, 10, 70);
					seta(winfield, 0, 24, 70);
					seta(winfield, 1, 17, 70);
					wrefresh(winfield);
					break;
				case 4:
					seta(winfield, 0, 17, 70);
					seta(winfield, 1, 24, 70);
					wrefresh(winfield);
					break;
			}
		}
		else
		{
			seta(winfield, 0, 3, 23);
			seta(winfield, 0, 10, 23);
			seta(winfield, 0, 17, 23);
			seta(winfield, 0, 24, 23);
			seta(winfield, 0, 3, 70);
			seta(winfield, 0, 10, 70);
			seta(winfield, 0, 17, 70);
			seta(winfield, 0, 24, 70);
		}
	}
}
