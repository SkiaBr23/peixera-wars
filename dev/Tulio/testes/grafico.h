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

void destroy_win(WINDOW *local_win);
void print_hub(WINDOW *hub,int gold,int food,int score, int wave );
void print_field(WINDOW *field);
void print_castle(WINDOW *castle);
int tela_inicial();
void tela_final();
int menu ();
void desenhaunidade (WINDOW *win, int unidade, int y, int x);
void desenhaedificio (WINDOW *win, int edificio, int y, int x);
void desenhainimigo(WINDOW *win, int inimigo, int y, int x);
void mensagem(int y, int x, char frase[]);
char* mensagem_entrada(int y, int x, char frase[]);
int menu_edificio();
void creditos(int y, int x);