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

void destroy_win(WINDOW *local_win);
void print_hub(WINDOW *hub,int gold, int wave );
void print_field();
void print_castle();
void tela_inicial();
void tela_final();
int menu ();
void desenhaunidade (WINDOW *win, int unidade, int y, int x);
void desenhaedificio (WINDOW *win, int nivel, int edificio, int y, int x);
void desenhainimigo(WINDOW *win, int inimigo, int y, int x);
void mensagem(int y, int x, char frase[]);
char* mensagem_entrada(int y, int x, char frase[]);
int menu_edificio();
int menu_unidade();
void creditos(int y, int x);
void seta(WINDOW *win, int tipo, int y, int x);
void seta_batalha(WINDOW *winfield, int j, int i);
void TelaGameOver();
