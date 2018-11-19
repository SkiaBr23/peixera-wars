/*! \file grafico.h
	\brief Módulo para gerenciar a interface gráfica */

/*
PROJETO
Nome: MAXIMILLIAN FAN XAVIER, OTÁVIO ALVES DIAS, RAFAEL DIAS DA COSTA, TÚLIO ABNER DE LIMA
Matrícula: 12/0153271, 12/0131480, 12/0133253, 12/0137194
Curso: Engenharia de Computação
Disciplina: Métodos de Programação
Turma: A
Prof: Jan Mendonça
*/

/* Arquivo Header */
#include <stdio.h>
#include <ncurses.h>

/*FUNÇÕES DE GERENCIAMENTO DA NCURSES*/
void inicia_ncurses();
void finaliza_ncurses();
/*FUNÇÕES DE ATUALIZAÇÃO DA TELA*/
void destroy_win(WINDOW *local_win);
void print_hud(WINDOW *hub,int gold, int wave );
void print_field();
void print_castle();
/*FUNÇÕES DE TELAS PRONTAS*/
void tela_inicial();
void tela_final();
void TelaGameOver();
void creditos(int y, int x);
/*MENUS INTERATIVOS*/
int menu ();
int menu_edificio();
int menu_unidade();
/*FUNÇÕES DE DESENHO DE UNIDADE*/
void desenhaunidade (WINDOW *win, int unidade, int y, int x);
void desenhaedificio (WINDOW *win, int nivel, int edificio, int y, int x);
void desenhainimigo(WINDOW *win, int inimigo, int y, int x);
/*FUNÇÕES DE MENSAGEM AO JOGADOR*/
void mensagem(int y, int x, char frase[]);
char* mensagem_entrada(int y, int x, char frase[]);
/*FUNÇÕES DA SETA AUXILIAR*/
void seta(WINDOW *win, int tipo, int y, int x);
void seta_batalha(WINDOW *winfield, int j, int i);
