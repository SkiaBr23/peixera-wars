/*! \file grafico.c
	\brief Módulo de implementação do módulo grafico.h **/

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
#define HUDH 7
#define CASTLEW 40
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

/****************************************************************************/
/**
* \fn void inicia_ncurses()
*
* \brief Função responsável por iniciar o modo ncurses.
*
* \return void
***************************************************************************/
/*
REQUISITO: Não possui requisitos.
HIPÓTESE: Será possível utilizar as funções da ncurses.
ASSERTIVAS DE ENTRADA: A função não possui entrada.
ASSERTIVAS DE SAÍDA: A função não possui saída. 
INTERFACE EXPLÍCITA: Tipo de retorno void.
INTERFACE IMPLÍCITA: função auxiliar.
*/
void inicia_ncurses()
{
	initscr();
}

/****************************************************************************/
/**
* \fn void finaliza_ncurses()
*
* \brief Função responsável por finalizar o modo ncurses.
*
* \return void
***************************************************************************/
/*
REQUISITO: Não possui requisitos.
HIPÓTESE: Não será mais possível utilizar as funções da ncurses.
ASSERTIVAS DE ENTRADA: A função não possui entrada.
ASSERTIVAS DE SAÍDA: A função não possui saída. 
INTERFACE EXPLÍCITA: Tipo de retorno void.
INTERFACE IMPLÍCITA: função auxiliar.
*/
void finaliza_ncurses()
{
	endwin();
}

/****************************************************************************/
/**
* \fn void destroy_win(WINDOW *local_win)
*
* \brief Função responsável por apagar as informações de uma janela e deletar sua estrutura.
*
* @param local_win Uma estrutura do tipo WINDOW previamente inicializada.
*
* \return void
***************************************************************************/
/*
REQUISITO: A janela passada por parâmetro deve estar inicializada.
HIPÓTESE: A janela deixará de existir.
ASSERTIVAS DE ENTRADA: A estrutura não pode apontar para NULL.
ASSERTIVAS DE SAÍDA: A função não possui saída. 
INTERFACE EXPLÍCITA: Tipo de retorno void e o parâmetro de entrada WINDOW *local_win.
INTERFACE IMPLÍCITA: funções auxiliares pala gerenciar a janela.
*/
void destroy_win(WINDOW *local_win)
{
	
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');/*Apaga a borda da janela*/
	wrefresh(local_win);
	delwin(local_win);/*deleta a estrutura*/
}

/****************************************************************************/
/**
* \fn int menu_edificio(void)
*
* \brief Função responsável pela criação do menu de evolução dos edifícios.
*
* \return Opção selecionada do menu
***************************************************************************/

/**

REQUISITO: A função deve ser chamada no final de uma rodada.
HIPÓTESE: A função irá retornar um valor correspondente à uma das opções do menu.
ASSERTIVAS DE ENTRADA: A função não possui parâmetros.
ASSERTIVAS DE SAÍDA: O retorno deve ser um número entre 1 e 4. 
INTERFACE EXPLÍCITA: Tipo de retorno int.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
int menu_edificio()
{
	WINDOW *menu = newwin(10, 45, 10, 60);/*Cria uma nova janela*/
	box(menu, 0, 0);/*Coloca a borda*/

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


/****************************************************************************/
/**
* \fn int menu_unidade(Castelo *castelo)
*
* \brief Função responsável pela criação do menu de evolução dos edifícios.
*
* @param castelo Estrutura de Castelo previamente inicializada.
* 
* \return Opção selecionada do menu
***************************************************************************/

/**
REQUISITO: A função deve ser chamada no início de uma rodada.
HIPÓTESE: A função irá retornar um valor correspondente à uma das opções do menu.
ASSERTIVAS DE ENTRADA: castelo != NULL.
ASSERTIVAS DE SAÍDA: O retorno deve ser um número entre 1 e 3. 
INTERFACE EXPLÍCITA: Tipo de retorno int.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
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

	mvwprintw(menu, 2, 3, "                                                  ");/*Apaga o conteúdo da janela*/
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

/****************************************************************************/
/**
* \fn void mensagem(int y, int x, char frase[])
*
* \brief Função responsável pela impressão de uma mensagem na tela.
*
* @param y Coordenada y desejada
* @param x Coordenada x desejada
* @param frase[] String a ser mostrada ao jogador
* 
* \return void
***************************************************************************/

/**
REQUISITO: O usuário deve passar as coordenadas da impressão e a mensagem.
HIPÓTESE: A função irá imprimir na tela a mensagem passada como parâmetro.
ASSERTIVAS DE ENTRADA: os inteiros devem estar entre 0 e LINES e COLS respectivamente, e a frase seve ser uma string não nula.
ASSERTIVAS DE SAÍDA: A função não possui saída. 
INTERFACE EXPLÍCITA: Tipo de retorno void, com parâmetros int y, int x, char frase[].
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
void mensagem(int y, int x, char frase[])
{
	int tam;
	tam = strlen(frase);/*Verifica o tamanho da mensagem para construir a janela*/
	WINDOW *mensagem = newwin(5, tam+4, y, x);
	box(mensagem, 0, 0);

	mvwprintw(mensagem, 2, 2, frase);

	wrefresh(mensagem);
}

/****************************************************************************/
/**
* \fn char* mensagem_entrada(int y, int x, char frase[])
*
* \brief Função responsável por imprimir uma mensagem na tela e guardar a informação digitada pelo usuário.
*
* @param y Coordenada y desejada
* @param x Coordenada x desejada
* @param frase[] String a ser mostrada ao jogador
*
* \return string Texto inserido pelo usuario
***************************************************************************/

/**
REQUISITO: O usuário deve passar as coordenadas da impressão e a mensagem.
HIPÓTESE: A função irá imprimir na tela a mensagem passada como parâmetro e irá retornar a string digitada.
ASSERTIVAS DE ENTRADA: os inteiros devem estar entre 0 e LINES e COLS respectivamente, e a frase seve ser uma string não nula.
ASSERTIVAS DE SAÍDA: A saída deve ser um ponteiro para char. 
INTERFACE EXPLÍCITA: Tipo de retorno char*, com parâmetros int y, int x, char frase[].
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
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
	move(y+4, x+2);/*Move o cursor para receber a String*/
	echo();/*Permite que os caracteres digitados apareçam na tela*/
	getstr(string);/*Pega a String*/
	noecho();/*Cancela a função echo()*/
	string[30] = '\0';

	for (i = 0; i < tam; ++i)/*Apaga o conteúdo da janela*/
	{
		mvwprintw(mensagem, 2, i+2, " ");
	}

	destroy_win(mensagem);/*apaga a estrutura*/

	return string;
}

/****************************************************************************/
/**
* \fn void tela_inicial()
*
* \brief Função responsável pela  impressão da tela inicial, com desenhos e opções do menu.
*
* \return void
***************************************************************************/
/**
REQUISITO: Não há requisitos.
HIPÓTESE: A função irá imprimir na tela o design da tela inicial.
ASSERTIVAS DE ENTRADA: A função não possui entrada.
ASSERTIVAS DE SAÍDA: A função não possui saída. 
INTERFACE EXPLÍCITA: Tipo de retorno void.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
void tela_inicial()
{
	WINDOW *build = newwin(35, 63, 5, 60);
	WINDOW *menuwin = newwin(5, 15, 11, 40);
	WINDOW *tela = newwin(LINES, COLS, 0, 0);
	
	keypad(menuwin, TRUE);/*Permite o uso de todos as teclas do teclado na janela menuwin*/

	refresh();
/*Imprime o título*/
	mvwprintw(tela, 1, 30, " ____  ____  __  _  _  ____  ____   __     _  _   __   ____  ____");
	mvwprintw(tela, 2, 30, "(  _ \\(  __)(  )( \\/ )(  __)(  _ \\ / _\\   / )( \\ / _\\ (  _ \\/ ___)");
	mvwprintw(tela, 3, 30, " ) __/ ) _)  )(  )  (  ) _)  )   //    \\  \\ /\\ //    \\ )   /\\___ \\");
	mvwprintw(tela, 4, 30, "(__)  (____)(__)(_/\\_)(____)(__\\_)\\_/\\_/  (_/\\_)\\_/\\_/(__\\_)(____/");
	wrefresh(tela);
/*Imprime o castelo*/
	mvwprintw(build, 0, 0, "                                                    !_\n                                                    |*~=-.,\n                                                    |_,-'`\n                                                    |\n                                                    |\n                                                   /^\\\n                     !_                           /   \\\n                     |*`~-.,                     /,    \\\n                     |.-~^`                     /#\"     \\\n                     |                        _/##_   _  \\_\n                _   _|  _   _   _            [ ]_[ ]_[ ]_[ ]\n               [ ]_[ ]_[ ]_[ ]_[ ]            |_=_-=_ - =_|\n             !_ |_=_ =-_-_  = =_|           !_ |=_= -    |\n             |*`--,_- _        |            |*`~-.,= []  |\n             |.-'|=     []     |   !_       |_.-\"`_-     |\n             |   |_=- -        |   |*`~-.,  |  |=_-      |\n            /^\\  |=_= -        |   |_,-~`  /^\\ |_ - =[]  |\n        _  /   \\_|_=- _   _   _|  _|  _   /   \\|=_-      |\n       [ ]/,    \\[ ]_[ ]_[ ]_[ ]_[ ]_[ ]_/,    \\[ ]=-    |\n        |/#\"     \\_=-___=__=__- =-_ -=_ /#\"     \\| _ []  |\n       _/##_   _  \\_-_ =  _____       _/##_   _  \\_ -    |\\\n      [ ]_[ ]_[ ]_[ ]=_0~{_ _ _}~0   [ ]_[ ]_[ ]_[ ]=-   | \\\n      |_=__-_=-_  =_|-=_ |~~~~~|     |_=-___-_ =-__|_    |  \\\n       | _- =-     |-_   | E C |      |= _=       | -    |___\\\n       |= -_=      |=  _ |~~~~~|      |_-=_       |=_    |/+\\|\n       | =_  -     |_ = _ `-.-`       | =_ = =    |=_-   ||+||\n       |-_=- _     |=_   =            |=_= -_     |  =   ||+||\n       |=_- /+\\    | -=               |_=- /+\\    |=_    |^^^|\n       |=_ |+|+|   |= -  -_,--,_      |_= |+|+|   |  -_  |=  |\n       |  -|+|+|   |-_=  / |  | \\     |=_ |+|+|   |-=_   |_-/\n       |=_=|+|+|   | =_= | |  | |     |_- |+|+|   |_ =   |=/\n       | _ ^^^^^   |= -  | |  <&>     |=_=^^^^^   |_=-   |/\n       |=_ =       | =_-_| |  | |     |   =_      | -_   |\n       |_=-_       |=_=  | |  | |     |=_=        |=-    |\n `^^^^^^^^^^`^`^^`^`^`^^^\"\"\"\"\"\"\"\"^`^^``^^`^^`^^`^`^``^`^``^``^^");
	
	wrefresh(build);

	Inicia();
	
}

/****************************************************************************/
/**
* \fn void tela_final()
*
* \brief Função responsável por imprimir a mensagem de despedida e encerrar o programa.
*
* \return void
***************************************************************************/

/**
REQUISITO: Não há requisitos.
HIPÓTESE: A função irá imprimir na tela o design da tela final e irá encerrar o programa.
ASSERTIVAS DE ENTRADA: A função não possui entrada.
ASSERTIVAS DE SAÍDA: A função não possui saída. 
INTERFACE EXPLÍCITA: Tipo de retorno void.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
void tela_final()
{
	clear();
	mvprintw(LINES/2 - 2, COLS/2 - 10, "OBRIGADO POR JOGAR!");
	refresh();
	sleep(2);/*Aguarda dois segundos*/
	finaliza_ncurses();/*Encerra a Ncurses*/
	exit(1);/*Encerra o programa*/
}

/****************************************************************************/
/**
* \fn TelaGameOver()
*
* \brief Função responsável por imprimir a mensagem de fim de jogo e encerrar o programa.
*
* \return void
***************************************************************************/
/*
REQUISITO: Não há requisitos.
HIPÓTESE: A função irá imprimir na tela o design da tela de fim de jogo e irá encerrar o programa.
ASSERTIVAS DE ENTRADA: A função não possui entrada.
ASSERTIVAS DE SAÍDA: A função não possui saída. 
INTERFACE EXPLÍCITA: Tipo de retorno void.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
void TelaGameOver()
{
	int x = COLS/4,y=15;
	clear();

	mvprintw(y  ,x,"      _____          __  __ ______    ______      ________ _____  _");
	mvprintw(y+1,x,"     / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\| |");
	mvprintw(y+2,x,"    | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) | |");
	mvprintw(y+3,x,"    | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /| |");
	mvprintw(y+4,x,"    | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\|_|");
	mvprintw(y+5,x,"     \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_(_)");
	mvprintw(y+6,x," ________________________________________________________________________ ");
	mvprintw(y+7,x,"|________________________________________________________________________|");
	refresh();
	sleep(3);/*Aguarda 3 segundos*/
	finaliza_ncurses();/*Encerra a Ncurses*/
	exit(1);/*Encerra o programa*/
}

/****************************************************************************/
/**
* \fn void creditos(int y, int x)
*
* \brief Função responsável pela impressão dos créditos.
*
* @param y Coordenada x desejada
* @param x Coordenada y desejada
*
* \return void
***************************************************************************/

/**

REQUISITO: O usuário deve passar as coordenadas da impressão.
HIPÓTESE: A função irá imprimir na tela os créditos dos criadores do jogo.
ASSERTIVAS DE ENTRADA: os inteiros devem estar entre 0 e LINES e COLS respectivamente.
ASSERTIVAS DE SAÍDA: A função não possui saída. 
INTERFACE EXPLÍCITA: Tipo de retorno void, com parâmetros int y, int x.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
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

	for (j = 2; j < 16; j++)/*Apaga o conteúdo da janela*/
	{
		for (i = 0; i < 64; i++)
		{
			mvwprintw(creditos, j, i+2, " ");
		}
	}

	destroy_win(creditos);
}

/****************************************************************************/
/**
* \fn void print_hud(WINDOW *hud,int gold, int wave)
*
* \brief Função responsável pela impressão do HUD superior, contendo título e informações sobre o jogo(ouro disponível e numero da horda).
*
* @param hud Ponteiro para a janela do HUD do jogo (Head's Up Display)
* @param wave Inteiro que determina em qual wave o jogador se encontra
* @param gold Inteiro que determina o gold atual do usuário
*
* \return void
***************************************************************************/

/**
REQUISITO: O usuário deve passar o ponteiro para a janela, a quantidade de ouro e o número da horda.
HIPÓTESE: A função irá imprimir na tela o HUD.
ASSERTIVAS DE ENTRADA: hud não pode ser nulo, gold não pode ser negativo e wave deve estar entre 1 e 10.
ASSERTIVAS DE SAÍDA: A função não possui saída. 
INTERFACE EXPLÍCITA: Tipo de retorno void, com parâmetros WINDOW *hud,int gold, int wave.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
void print_hud(WINDOW *hud,int gold, int wave)
{

	box(hud, 0 , 0);/*Cria a margem da janela*/

	mvwprintw(hud, 1, 1, " ____  ____  __  _  _  ____  ____   __     _  _   __   ____  ____");
	mvwprintw(hud, 2, 1, "(  _ \\(  __)(  )( \\/ )(  __)(  _ \\ / _\\   / )( \\ / _\\ (  _ \\/ ___)");
	mvwprintw(hud, 3, 1, " ) __/ ) _)  )(  )  (  ) _)  )   //    \\  \\ /\\ //    \\ )   /\\___ \\");
	mvwprintw(hud, 4, 1, "(__)  (____)(__)(_/\\_)(____)(__\\_)\\_/\\_/  (_/\\_)\\_/\\_/(__\\_)(____/");

	mvwprintw(hud, 2, 80, "Gold$ %d", gold);
	mvwprintw(hud, 4, 80, "Wave %d", wave);
	mvwprintw(hud, 2, 100, "M - Menu");

}

/****************************************************************************/
/**
* \fn void print_field(WINDOW *field, CabecaPFilas *filas)
*
* \brief Função responsável pela impressão do campo de batalha.
*
* @param field Ponteiro para a janela do campo de batalha do jogo
* @param filas Ponteiro para a estrutura de filas de unidades e inimigos.
*
* \return void
***************************************************************************/

/** 
REQUISITO: O usuário deve passar o ponteiro para a janela e o ponteiro para as filas de personagens.
HIPÓTESE: A função irá imprimir na tela o campo de batalha.
ASSERTIVAS DE ENTRADA: field e filas não podem ser nulos.
ASSERTIVAS DE SAÍDA: A função não possui saída. 
INTERFACE EXPLÍCITA: Tipo de retorno void, com parâmetros WINDOW *field, CabecaPFilas *filas.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
void print_field(WINDOW *field, CabecaPFilas *filas)
{

	box(field, 0 , 0);
	Unidade *lis;
	int i, j;

	for (i = 1; i < LINES-HUDH-2; ++i)/*Apaga o conteúdo da Janela*/
	{
		for (j = 1; j < COLS-CASTLEW; ++j)
		{
			mvwprintw(field, i, j, " ");
		}
	}

	for (lis = filas->player, i = 3; lis!=NULL; lis = lis->prox, i+=7)/*Imprime as unidade do jogador*/
	{
		desenhaunidade(field, lis->classe, i, 10);
		mvwprintw(field, i, 5, "HP %d", lis->vida);
	}

	for (lis = filas->cpu, i = 3; lis!=NULL; lis = lis->prox, i+=7)/*Imprime as unidades do inimigo*/
	{
		desenhainimigo(field, lis->classe, i, 80);
		mvwprintw(field, i, 90, "HP %d", lis->vida);
	}
}

/****************************************************************************/
/**
* \fn void print_castle(WINDOW *castle, Castelo *castelo)
*
* \brief Função responsável pela impressão da área de edifícios.
*
* @param castle Ponteiro para a janela do castelo, onde ficam os edifícios.
* @param castelo Ponteiro para a estrutura Castelo
*
* \return void
***************************************************************************/

/**
REQUISITO: O usuário deve passar o ponteiro para a janela e o ponteiro para os edifícios.
HIPÓTESE: A função irá imprimir na tela a área de edifícios.
ASSERTIVAS DE ENTRADA: castle e castelo não podem ser nulos.
ASSERTIVAS DE SAÍDA: A função não possui saída. 
INTERFACE EXPLÍCITA: Tipo de retorno void, com parâmetros WINDOW *castle, Castelo *castelo.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
void print_castle(WINDOW *castle, Castelo *castelo)
{

	box(castle, 0 , 0);

		desenhaedificio(castle, castelo->comercio->nivel, 0, 2, 4);
		desenhaedificio(castle, castelo->quartel->nivel,1, 10, 6);
		desenhaedificio(castle, castelo->campodetiro->nivel,2,18,4);
		desenhaedificio(castle, castelo->casadaslancas->nivel,3,26,3);

}

/****************************************************************************/
/**
* \fn menu (WINDOW *menuwin)
*
* \brief Função que cria o menu de opções disponíveis para o usuário na tela inicial.
*
* @param menuwin Ponteiro da janela de menu
*
* \return Opção selecionada pelo jogador
***************************************************************************/

/**
REQUISITO: O usuário deve passar o ponteiro para a janela.
HIPÓTESE: A função irá imprimir na tela o menu.
ASSERTIVAS DE ENTRADA: menuwin não pode ser nulo.
ASSERTIVAS DE SAÍDA: A saída deve estar entre -1 e 3.
INTERFACE EXPLÍCITA: Tipo de retorno int, com parâmetro WINDOW *menuwin.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
int menu (WINDOW *menuwin)
{

	char *choices[] = {/*Cria os itens do menu*/
                        "Novo Jogo",
                        "Carregar Jogo",
                        "Creditos",
                        "Sair",
                  	};

	ITEM **my_items;		
	ITEM *cur_item;
	MENU *my_menu;
    int n_choices, i, c;
	
    n_choices = ARRAY_SIZE(choices);/*Estabelece o número de itens*/
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));/*Aloca os itens na memória*/

    for(i = 0; i < n_choices; ++i) my_items[i] = new_item(choices[i], choices[i]);/*Grava os itens*/

	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu((ITEM **)my_items);/*Coloca os itens no menu*/
	set_menu_win(my_menu, menuwin);/*Coloca o menu na janela*/
	post_menu(my_menu);/*Imprime o menu na tela*/
	wrefresh(menuwin);
	
	while(1)
	{       
		c = getch();
		switch(c)
        {	
        	case 's':
				menu_driver(my_menu, REQ_DOWN_ITEM);/*Caso o jogador aperte s passa a seleção do menu para baixo*/
				wrefresh(menuwin);
				break;
			case 'w':
				menu_driver(my_menu, REQ_UP_ITEM);/*Caso o jogador aperte w passa a seleção do menu para cima*/
				wrefresh(menuwin);
				break;
			case 10:	/* Enter */
				cur_item = current_item(my_menu);
				return (item_index(cur_item));/*Retorna a opção do menu selecionada*/
		}
	}
	return -1;
}

/****************************************************************************/
/**
* \fn void desenhaunidade (WINDOW *win, int unidade, int y, int x)
*
* \brief Função responsável pela impressão do desenho da unidade escolhida nas coordenadas indicadas.
*
* @param win Ponteiro para a janela em que será desenhada a unidade
* @param unidade Indentificador de unidade. Dependendo do número, desenha uma unidade diferente
* @param y Coordenada y desejada
* @param x Coordenada x desejada
*
* \return void
***************************************************************************/

/**
REQUISITO: O usuário deve passar o ponteiro para a janela, o tipo de unidade e as coordenadas.
HIPÓTESE: A função irá imprimir no campo de batalha as unidades adiquiridas pelo jogador.
ASSERTIVAS DE ENTRADA: win não pode ser nulo, unidade deve estar entre 1 e 4, y e x devem estar entre 0 e LINES e COLS respectivamente.
ASSERTIVAS DE SAÍDA: A função não possui saída.
INTERFACE EXPLÍCITA: Tipo de retorno void, com parâmetros WINDOW *win, int unidade, int y, int x.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
void desenhaunidade (WINDOW *win, int unidade, int y, int x)
{
	switch(unidade)
	{
		case 1:
			mvwprintw(win, y  , x, "    O");
            mvwprintw(win, y+1, x, "\\  /M\\");
            mvwprintw(win, y+2, x, " X/ W \\");
            mvwprintw(win, y+3, x, "    |\\");
            mvwprintw(win, y+4, x, "   /_ |_");
            break;
        case 2:
        	mvwprintw(win, y  , x, "    O  \\");
            mvwprintw(win, y+1, x, "   /M\\_(");
            mvwprintw(win, y+2, x, "  / W  /");
            mvwprintw(win, y+3, x, "    |\\");
            mvwprintw(win, y+4, x, "   /_ |_");
            break;
        case 3:
        	mvwprintw(win, y  , x, "    O");
            mvwprintw(win, y+1, x, "   /M\\");
            mvwprintw(win, y+2, x, "  W===M===[>");
            mvwprintw(win, y+3, x, "    |\\");
            mvwprintw(win, y+4, x, "   /_ |_");
			break;
	}
}

/****************************************************************************/
/**
* \fn void desenhainimigo (WINDOW *win, int inimigo, int y, int x)
*
* \brief Função responsável pela impressão de unidades inimigas nas coordenadas escolhidas.
*
* @param win Ponteiro para a janela em que será desenhada a unidade
* @param inimigo Indentificador de unidade. Dependendo do número, desenha uma unidade diferente
* @param y Coordenada y desejada
* @param x Coordenada x desejada
*
* \return void
***************************************************************************/

/**
REQUISITO: O usuário deve passar o ponteiro para a janela, o tipo de unidade e as coordenadas.
HIPÓTESE: A função irá imprimir no campo de batalha as unidades geradas pelo inimigo.
ASSERTIVAS DE ENTRADA: win não pode ser nulo, inimigo deve estar entre 1 e 4, y e x devem estar entre 0 e LINES e COLS respectivamente.
ASSERTIVAS DE SAÍDA: A função não possui saída.
INTERFACE EXPLÍCITA: Tipo de retorno void, com parâmetros WINDOW *win, int inimigo, int y, int x.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
void desenhainimigo (WINDOW *win, int inimigo, int y, int x)
{
	switch(inimigo)
	{
		case 1:
			mvwprintw(win, y  , x, "(___)");
            mvwprintw(win, y+1, x, "(o o)_____/");
            mvwprintw(win, y+2, x, " @@ `     \\");
            mvwprintw(win, y+3, x, "  \\ ____, /");
            mvwprintw(win, y+4, x, "  //    //");
            mvwprintw(win, y+5, x, " ^^    ^^");
            break;
        case 2:
        	mvwprintw(win, y  , x, "   _//|.-~~~~-,");
            mvwprintw(win, y+1, x, " _/66  \\       \\_@");
            mvwprintw(win, y+2, x, "(\")_   /   /   |");
            mvwprintw(win, y+3, x, "  '--'|| |-\\  /");
            mvwprintw(win, y+4, x, "      //_/ /_/");
            break;
        case 3:
        	mvwprintw(win, y  , x, "     |_|   ");
            mvwprintw(win, y+1, x, "    ('.')  ///");
            mvwprintw(win, y+2, x, "     (W)   /");
            mvwprintw(win, y+3, x, "    <(M)`-/'");
            mvwprintw(win, y+4, x, "<-._/J L /  ");
			break;			
		case 4:
			x = x-18;
			y = y + 5;
			mvwprintw(win, y  , x, " <>=======()");
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

/****************************************************************************/
/**
* \fn desenhaedificio(WINDOW *win, int nivel, int edificio, int y, int x)
*
* \brief Função responsável pela impressão do desenho dos edifícios.
*
* @param win Ponteiro para a janela em que será desenhada o edificio.
* @param nivel Nível atual do edifício que será desenhado.
* @param edificio Indentificador de edificio. Dependendo do número, desenha um edificio diferente.
* @param y Coordenada y desejada.
* @param x Coordenada x desejada.
*
* \return void
***************************************************************************/

/**
REQUISITO: O usuário deve passar o ponteiro para a janela, o nível do edifício, o tipo do edifício e as coordenadas.
HIPÓTESE: A função irá imprimir os desenhos na área de edifícios.
ASSERTIVAS DE ENTRADA: win não pode ser nulo, nivel deve estar entre 1 e 3, edificio deve estar entre 0 e 3, y e x devem estar entre 0 e LINES e COLS respectivamente.
ASSERTIVAS DE SAÍDA: A função não possui saída.
INTERFACE EXPLÍCITA: Tipo de retorno void, com parâmetros WINDOW *win, int nivel, int edificio, int y, int x.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
void desenhaedificio(WINDOW *win, int nivel, int edificio, int y, int x)
{
	switch(edificio)
	{
		case 0:
			mvwprintw(win, y  , x, "	        x");
            mvwprintw(win, y+1, x, ".-. ________|_    Comercio");
            mvwprintw(win, y+2, x, "|=|/     /    \\   Nivel: %d", nivel);
            mvwprintw(win, y+3, x, "| |_LOJA_|_||_|   %d gold/wave",100*nivel);
            mvwprintw(win, y+4, x, "|_|_[ ]__|____|");
            break;
		case 1:
        	mvwprintw(win, y  , x, " _   |~  _");
			mvwprintw(win, y+1, x, "[_]--'--[_]     Quartel");
			mvwprintw(win, y+2, x, "| |  S  |'|     Nivel: %d", nivel);
			mvwprintw(win, y+3, x, "| | /^\\ | |");
			mvwprintw(win, y+4, x, "|_|_|I|_|_|");
			break;
        case 2:
        	mvwprintw(win, y  , x, "      +");
			mvwprintw(win, y+1, x, "   _.-A-._      Campo de Tiro");
			mvwprintw(win, y+2, x, ".='_______'=.     Nivel: %d", nivel);
			mvwprintw(win, y+3, x, " ||     o ||");
			mvwprintw(win, y+4, x, "_||[X]__|_||__");
			break;
		case 3:
			mvwprintw(win, y  , x, "    __-L-__");
			mvwprintw(win, y+1, x, "   /\\-'o'-/\\    Casa das Lancas");
			mvwprintw(win, y+2, x, "  _||:<_>:||_      Nivel: %d", nivel);
			mvwprintw(win, y+3, x, " /\\_/=====\\_/\\");
			mvwprintw(win, y+4, x, "_|:_:_[I]_:_:|_");
			break;
	}
}

/****************************************************************************/
/**
* \fn void seta(WINDOW *win, int tipo, int y, int x)
*
* \brief  Função responsável pela impressão das setas.
*
* @param win Ponteiro para a janela.
* @param tipo Direção da seta.
* @param y Coordenada y da impressão.
* @param x Coordenada x da impressão.
*
* \return void
***************************************************************************/

/**
REQUISITO: O usuário deve passar o ponteiro para a janela, o tipo da seta e as coordenadas.
HIPÓTESE: A função irá imprimir a seta escolhida nas coordenadas.
ASSERTIVAS DE ENTRADA: win não pode ser nulo, y e x devem estar entre 0 e LINES e COLS respectivamente.
ASSERTIVAS DE SAÍDA: A função não possui saída.
INTERFACE EXPLÍCITA: Tipo de retorno void, com parâmetros WINDOW *win, int tipo, int y, int x.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
void seta(WINDOW *win, int tipo, int y, int x)
{
	if (tipo == 1)
	{
		mvwprintw(win, y  , x, "  \\");
		mvwprintw(win, y+1, x, "===\\");
		mvwprintw(win, y+2, x, "===/");
		mvwprintw(win, y+3, x, "  /");
	}
	else
	{
		if (tipo == 2)
		{
			mvwprintw(win, y  , x, " /");
			mvwprintw(win, y+1, x, "/===");
			mvwprintw(win, y+2, x, "\\===");
			mvwprintw(win, y+3, x, " \\");
		}
		else/*Apaga a seta*/
		{
			mvwprintw(win, y  , x, "      ");
			mvwprintw(win, y+1, x, "      ");
			mvwprintw(win, y+2, x, "      ");
			mvwprintw(win, y+3, x, "      ");
		}
	}
}

/****************************************************************************/
/**
* \fn void seta_batalha(WINDOW *winfield, int j, int i)
*
* \brief Função responsável pela atualização do desenho de seta durante uma batalha.
*
* @param winfield Ponteiro para a janela.
* @param j Direção da seta.
* @param i Posição da seta.
*
* \return void
***************************************************************************/

/**
REQUISITO: O usuário deve passar o ponteiro para a janela, a direção e o tipo da seta.
HIPÓTESE: A função irá imprimir a seta escolhida.
ASSERTIVAS DE ENTRADA: winfield não pode ser nulo, i deve estar entre 1 e 4.
ASSERTIVAS DE SAÍDA: A função não possui saída.
INTERFACE EXPLÍCITA: Tipo de retorno void, com parâmetros WINDOW *winfield, int j, int i.
INTERFACE IMPLÍCITA: variáveis e funções auxiliares.
**/
void seta_batalha(WINDOW *winfield, int j, int i)
{
	if (j == 2)
	{
		switch(i)/*Imprime a seta correspondente e apaga as outras*/
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
			switch(i)/*Imprime a seta correspondente e apaga as outras*/
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
		else/*Apaga todas as setas*/
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
