/*
PROJETO
Nome: MAXIMILLIAN FAN XAVIER, OTÁVIO ALVES DIAS, RAFAEL DIAS DA COSTA, TÚLIO ABNER DE LIMA
Matrícula: 12/0153271, 12/0131480, 12/0133253, 12/0137194
Curso: Engenharia de Computação
Disciplina: Métodos de Programação
Turma: A
Prof: Jan Mendonça
*/

/*	Arquivo Header	*/
#include <stdio.h>

/*	---------------DEFINIÇÃO DE FUNÇÕES---------------	*/

/*FUNÇÕES DA ENGINE*/
void CriaEstruturas();
void InicializaEstruturas();
int VerificaInterface();
void StartGame();
void SaveGame();
void LoadGame();
int MenuEvolucaoEdificio();
int MenuEscolhaUnidade();
void Run();
int Batalha2();
Unidade * buscaAlvo ();
Unidade *AtaqueInimigo();
int GameLoop ();

/*FUNÇÕES DO MENU*/
void Inicia();

int TemQuatro();
int GerarValor();
int GerarNivel();
void InsereUnidadeInimiga();
void InsereUnidadeBoss();
int Batalha();
Unidade *Atacar();
