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

/* Funções utilizadas, futuramente .h */



int main()
{

	keypad(stdscr, TRUE);		/* Capturar teclas como F1, F2, etc */
	initscr();			        /* Começa o modo curses */
	noecho();
	cbreak();			
	curs_set(FALSE);			/* Não mostra o cursor na tela */
	srand(time(NULL));


	
	
	char c;
	int i;

	tela_inicial();
	

	


	while (i<9)
	{

		

		c = getch();

		switch(c)
		{
			case 'm':
				tela_inicial();
				break;
			case 'f':
				mensagem(LINES/2, COLS/2, "Nao ha ouro suficiente!");
				sleep(5);
				break;
			case 'e':
				menu_edificio();
				break;
		}

		i++;
	}

	endwin();
	return 0;
}