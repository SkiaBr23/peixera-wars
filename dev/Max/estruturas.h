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
/*	Estrutura genérica do tipo unidade. Responsável por representar todas as unidades do jogo.	*/
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

/*	Estrutura genérica do tipo edificio. Responsável por representar a maioria das construções do jogo.	*/
struct edificio  {
	int custounidade;
	int nivel;
};
typedef struct edificio Edificio;

/*	Estrutura do tipo açougue a qual faz parte do castelo. Responsável por controlar a produção de ouro.	*/
struct comercio {
	int taxaouro;
	int nivel;
};
typedef struct comercio Comercio;

/*	Estrutura de cabeça que organiza as três filas de ação do jogo	*/
struct cabecapfilas {
	Unidade *player;
	Unidade *cpu;
};
typedef struct cabecapfilas CabecaPFilas;

/*	Estrutura de cabeça que organiza e dá acesso aos quatro edifícios do jogo, possui informações de vida e quantidade de ouro disponível	*/
struct castelo {
	Edificio *quartel;
	Edificio *campodetiro;
	Edificio *casadaslancas;
	Comercio *comercio;
	int ouro;
};
typedef struct castelo Castelo;

/*	Estrutura de cabeça geral responsável pela união dos edifícios e das unidades	*/
struct cabecageral {
	CabecaPFilas *character;
	Castelo *castle;
};
typedef struct cabecageral CabecaGeral;


/*	---------------DEFINIÇÃO DE FUNÇÕES---------------	*/
/*FUNÇÕES DE CABECA GERAL*/
CabecaGeral* CriaCabecaGeral();
int CabecaGeralVazia();
int VerificarCabecaGeral();

/*FUNÇÕES DE CABECAPFILAS*/
CabecaPFilas* CriaCabecaPFilas();
int CabecaPFilasVazia();

/*FUNÇÕES DE CASTELO*/
Castelo* CriaCastelo ();
int CasteloVazia();
int VerificarCastelo();
Castelo* AtualizarCasteloOuro();

/*FUNÇÕES DE UNIDADE*/
Unidade* CriaUnidade ();
int UnidadeVazia();
Unidade* InserirUnidadeFinal(Unidade*,int,int,float,int,int);
Unidade* RemoverUnidadeFinal();
int VerificaEstrutura ();

/*FUNÇÕES DE COMERCIO*/
Comercio* CriaComercio ();
int ComercioVazia();
Comercio* InicializarComercio();

/*FUNÇÕES DE EDIFICIO*/
Edificio* CriaEdificio ();
int EdificioVazia();
Edificio* InicializarEdificio();
