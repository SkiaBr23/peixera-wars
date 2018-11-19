/*! \file estruturas.h
	\brief Módulo para gerenciar as estruturas */

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

/*	---------------Estruturas---------------	*/
/*!
	\struct unidade estruturas.h Unidade
	\brief Estrutura genérica do tipo unidade. Responsável por representar todas as unidades do jogo.	*/
struct unidade {
	int vida;
	int dano;
	float esquiva;
	int nivel;
	int classe;
	struct unidade *prox;
	struct unidade *ant;
};
typedef struct unidade Unidade;

/*!	
    \struct edificio estruturas.h Edificio
	\brief Estrutura genérica do tipo edificio. Responsável por representar a maioria das construções do jogo.	*/
struct edificio  {
	int custounidade;
	int nivel;
};
typedef struct edificio Edificio;

/*!
	\struct comercio estruturas.h Comercio
	\brief 	Estrutura do tipo comércio a qual faz parte do castelo. Responsável por controlar a produção de ouro.	*/
struct comercio {
	int taxaouro;
	int nivel;
};
typedef struct comercio Comercio;

/*!
	\struct cabecapfilas estruturas.h CabecaPFilas
	\brief Estrutura de cabeça que organiza as duas filas de ação do jogo	*/
struct cabecapfilas {
	Unidade *player;
	Unidade *cpu;
};
typedef struct cabecapfilas CabecaPFilas;

/*!
	\struct castelo estruturas.h Castelo
	\brief 	Estrutura de cabeça que organiza e dá acesso aos quatro edifícios do jogo, possui informações de vida e quantidade de ouro disponível	*/
struct castelo {
	Edificio *quartel;
	Edificio *campodetiro;
	Edificio *casadaslancas;
	Comercio *comercio;
	int ouro;
};
typedef struct castelo Castelo;

/*!
	\struct cabecageral estruturas.h CabecaGeral
	\brief 	Estrutura de cabeça geral responsável pela união dos edifícios e das unidades	*/
struct cabecageral {
	CabecaPFilas *character;
	Castelo *castle;
};
typedef struct cabecageral CabecaGeral;



/*	---------------DEFINIÇÃO DE FUNÇÕES---------------	*/
/*FUNÇÕES DE CABECA GERAL*/

CabecaGeral* CriaCabecaGeral();
int CabecaGeralVazia(CabecaGeral* lis);
int VerificarCabecaGeral(CabecaGeral* CG);

/*FUNÇÕES DE CABECAPFILAS*/

CabecaPFilas* CriaCabecaPFilas();
int CabecaPFilasVazia(CabecaPFilas* lis);

/*FUNÇÕES DE CASTELO*/

Castelo* CriaCastelo (int novawave,int valor);
int CasteloVazia(Castelo* lis);
int VerificarCastelo(Castelo* C);
Castelo* AtualizarCasteloOuro(Castelo* C, int ouro);

/*FUNÇÕES DE UNIDADE*/

Unidade * CriaUnidade ();
int UnidadeVazia(Unidade* lis);
Unidade * InserirUnidadeFinal(Unidade*,int,int,float,int,int);
int VerificaEstrutura(Unidade * lista);
Unidade * RemoverUnidadeFinal(Unidade * lis);
Unidade * RemoverUnidade(Unidade* lis, Unidade *retira);
Unidade * LimpaLista(Unidade* lis);

/*FUNÇÕES DE COMERCIO*/

Comercio* CriaComercio ();
int ComercioVazia(Comercio* lis);
Comercio* InicializarComercio(Comercio* C,int taxaouro,int nivel);

/*FUNÇÕES DE EDIFICIO*/

Edificio* CriaEdificio();
int EdificioVazia(Edificio* lis);
Edificio* InicializarEdificio(Edificio* E,int custounidade,int nivel);
