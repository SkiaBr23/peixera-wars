/*! \file engine.h
	\brief Módulo para gerenciar a engine*/

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
#include <ncurses.h>

/*	---------------DEFINIÇÃO DE FUNÇÕES---------------	*/

/*FUNÇÕES DA ENGINE*/

void CriaEstruturas(CabecaGeral* Interface,int novawave,int valor);
void InicializaEstruturas(CabecaGeral* Interface,int status,int cuQ,int nQ,int cuCDT,int nCDT,int cuCDL,int nCDL,int tC,int nC);
int VerificaInterface(CabecaGeral* Interface);
void StartGame(CabecaGeral* Cabeca, int horda);
void SaveGame(CabecaGeral* Interface, int horda);
void LoadGame();
int TemQuatro(Unidade* lista);
int GerarValor(int a, int b);
int GerarNivel(int horda);
void InsereUnidadeInimiga(CabecaGeral* Interface, int horda);
void InsereUnidadeBoss(CabecaGeral* Interface);
int Batalha(CabecaGeral *Interface, WINDOW *winfield);
void Run(CabecaGeral* Interface, int new, int wave);
int Batalha2(CabecaGeral *Interface, WINDOW *winfield);
Unidade * Atacar(Unidade *atacante, Unidade *vitima);
Unidade * buscaAlvo (Unidade * vitima);
Unidade *AtaqueInimigo(int * hit, Unidade *atacante, Unidade *vitima);
int GameLoop (CabecaGeral * Interface, WINDOW * winfield);

/*FUNÇÕES DO MENU*/

void Inicia();
int MenuEvolucaoEdificio(CabecaGeral* Interface);
int MenuEscolhaUnidade(CabecaGeral* Interface);
