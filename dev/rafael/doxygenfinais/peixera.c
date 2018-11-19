/*! \file peixera.c
	\brief Módulo da main do jogo */


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
#include <unistd.h>
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

int main()
{

	keypad(stdscr, TRUE);		/* Capturar teclas como F1, F2, etc */
	inicia_ncurses();			/* Começa o modo ncurses */
	noecho();					/* Caracteres digitados não aparecem na tela */
	cbreak();					/* Caracteres são capturados sem pressionar Enter */
	curs_set(FALSE);			/* Não mostra o cursor na tela */
	srand(time(NULL));			/* Função para gerar números aleatórios */

	tela_inicial();

	finaliza_ncurses();			/* Finaliza o modo ncurses */
	return 0;
}
