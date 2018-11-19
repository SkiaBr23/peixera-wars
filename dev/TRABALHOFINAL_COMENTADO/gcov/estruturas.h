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

/*	Estrutura do tipo comércio a qual faz parte do castelo. Responsável por controlar a produção de ouro.	*/
struct comercio {
	int taxaouro;
	int nivel;
};
typedef struct comercio Comercio;

/*	Estrutura de cabeça que organiza as duas filas de ação do jogo	*/
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

/***************************************************************************
* Função: Cria Cabeça Geral
* Descrição
*
* Aloca a estrutura controladora do game e faz com que seus ponteiros internos para as estruturas do game apontem para NULL.
*
* Parâmetros
*
* void - Nenhum parâmetro enviada para a função.
* 
* Valor retornado
*
* Retorna a estrutura alocada com os ponteiros internos apontando para NULL.
* 
* Assertiva de entrada
*
* Não possui assertivas de entrada.
***************************************************************************/
CabecaGeral* CriaCabecaGeral();

/***************************************************************************
* Função: Cabeça Geral Vazia
* Descrição
*
* Verifica se a estrutura controladora do game é nula ou não.
*
* Parâmetros
*
* CabecaGeral* - ponteiro para a estrutura controladora
* 
* Valor retornado
*
* Retorna o valor inteiro 1 caso a estrutura seja nula, ou 0 caso não seja.
* 
* Assertiva de entrada
*
* A estrutura enviada precisa ter sido declarada.
***************************************************************************/
int CabecaGeralVazia();

/***************************************************************************
* Função: Verificar Cabeça Geral
* Descrição
*
* Verifica se as estruturas internas do controlador são nulas ou não.
*
* Parâmetros
*
* CabecaGeral* - ponteiro para a estrutura controladora
* 
* Valor retornado
*
* Retorna o valor inteiro 1 caso as suas estruturas não sejam nulas, ou 0 caso as estruturas sejam nulas.
* 
* Assertiva de entrada
*
* A estrutura controladora precisa ter sido declarada.
***************************************************************************/
int VerificarCabecaGeral();

/*FUNÇÕES DE CABECAPFILAS*/

/***************************************************************************
* Função: Cria Cabeça Para Filas
* Descrição
*
* Aloca a estrutura que contém as duas listas de personagens do game (player e cpu), fazendo com que seus ponteiros internos apontem para * NULL.
*
* Parâmetros
*
* void - Nenhum parâmetro enviada para a função.
* 
* Valor retornado
*
* Retorna a estrutura alocada com os ponteiros internos apontando para NULL.
* 
* Assertiva de entrada
*
* Não possui assertivas de entrada.
***************************************************************************/
CabecaPFilas* CriaCabecaPFilas();

/***************************************************************************
* Função: Cabeça Para Filas Vazia
* Descrição
*
* Verifica se a estrutura que contém as listas de personagens é nula ou não.
*
* Parâmetros
*
* CabecaPFilas* - ponteiro para a estrutura dos personagens
* 
* Valor retornado
*
* Retorna o valor inteiro 1 caso a estrutura seja nula, ou 0 caso não seja.
* 
* Assertiva de entrada
*
* A estrutura enviada para a função precisa ter sido declarada.
***************************************************************************/
int CabecaPFilasVazia();

/*FUNÇÕES DE CASTELO*/

/***************************************************************************
* Função: Cria Castelo
* Descrição
*
* Aloca a estrutura que contém os ponteiros para cada edifício do game e faz com que esses ponteiros apontem para NULL.
*
* Parâmetros
*
* void - Nenhum parâmetro enviada para a função.
* 
* Valor retornado
*
* Retorna o a estrutura alocada com os ponteiros internos apontando para NULL.
* 
* Assertiva de entrada
*
* Não possui assertivas de entrada.
***************************************************************************/
Castelo* CriaCastelo ();

/***************************************************************************
* Função: Castelo Vazia
* Descrição
*
* Verifica se a estrutura que contém os edifícios é nula ou não.
*
* Parâmetros
*
* Castelo* - ponteiro para a estrutura que contém os edifícios
* 
* Valor retornado
*
* Retorna o valor inteiro 1 caso a estrutura seja nula, ou 0 caso não seja.
* 
* Assertiva de entrada
*
* A estrutura enviada para a função precisa ter sido declarada.
***************************************************************************/
int CasteloVazia();

/***************************************************************************
* Função: Verificar Castelo
* Descrição
*
* Verifica se cada edifício da estrutura Castelo é nulo ou não.
*
* Parâmetros
*
* Castelo* - ponteiro para a estrutura que contém os edifícios
* 
* Valor retornado
*
* Retorna o valor inteiro 1 caso todos os edifícios não sejam nulos, ou 0 caso algum deles seja.
* 
* Assertiva de entrada
*
* A estrutura enviada para a função precisa ter sido declarada para que a análise funcione corretamente.
***************************************************************************/
int VerificarCastelo();

/***************************************************************************
* Função: Atualizar Castelo Ouro
* Descrição
*
* Atualiza a quantidade de ouro (recurso) do castelo do game.
*
* Parâmetros
*
* Castelo* - ponteiro para a estrutura de Castelo do game.
* ouro - valor inteiro que representa a quantidade de ouro a ser adicionada ou removida do Castelo.
* 
* Valor retornado
*
* Retorna a estrutura de Castelo com a quantidade de ouro atualizada.
* 
* Assertiva de entrada
*
* A estrutura de Castelo enviada precisa ter sido declarada.
* A quantidade de ouro precisa ser um valor inteiro.
***************************************************************************/
Castelo* AtualizarCasteloOuro();

/*FUNÇÕES DE UNIDADE*/

/***************************************************************************
* Função: Cria Unidade
* Descrição
*
* Inicializa uma estrutura de Unidade com o valor NULL.
*
* Parâmetros
*
* void - Nenhum parâmetro enviada para a função.
* 
* Valor retornado
*
* Retorna o valor NULL para o ponteiro do tipo Unidade.
* 
* Assertiva de entrada
*
* Não possui assertivas de entrada.
***************************************************************************/
Unidade * CriaUnidade ();

/***************************************************************************
* Função: Unidade Vazia
* Descrição
*
* Verifica se a estrutura de Unidade é nula ou não.
*
* Parâmetros
*
* Unidade* - ponteiro para a estrutura Unidade.
* 
* Valor retornado
*
* Retorna o valor inteiro 1 caso a estrutura seja nula, ou 0 caso contrário.
* 
* Assertiva de entrada
*
* A estrutura de Unidade enviada para a função precisa ter sido declarada corretamente.
***************************************************************************/
int UnidadeVazia();

/***************************************************************************
* Função: Inserir Unidade Final
* Descrição
*
* Realiza a inserção de um personagem na lista de personagens do game sempre a última posição da lista.
*
* Parâmetros
*
* Unidade* - ponteiro para a estrutura Unidade (lista de personagens)
* vida - valor inteiro que representa a vida do personagem.
* dano - valor inteiro que representa o dano causado por esse personagem.
* esquiva - valor decimal que representa a capacidade de esquiva do personagem.
* nivel - valor inteiro que representa o nível do personagem.
* classe - valor inteiro que representa qual o tipo do personagem.
* 
* Valor retornado
*
* Retorna a lista de personagens atualizada.
* 
* Assertiva de entrada
*
* A estrutura Unidade enviada para a função precisa ter sido declarada.
* Os tipos de cada parâmetros precisam estar de acordo.
***************************************************************************/
Unidade * InserirUnidadeFinal(Unidade*,int,int,float,int,int);

/***************************************************************************
* Função: Verifica Estrutura
* Descrição
*
* Assertiva estrutural para garantir que a estrutura de lista duplamente encadeada foi implementada corretamente.
*
* Parâmetros
*
* Unidade* - ponteiro para a estrutura Unidade (lista de personagens).
* 
* Valor retornado
*
* Retorna o valor inteiro 1 caso a estrutura esteja correta, ou 0 caso contrário.
* 
* Assertiva de entrada
*
* A estrutura de Unidade enviada para a função precisa ter sido declarada.
***************************************************************************/
int VerificaEstrutura();

/***************************************************************************
* Função: Remover Unidade Final
* Descrição
*
* Realiza a remoção do último nó (personagem) da lista de personagens.
*
* Parâmetros
*
* Unidade* - ponteiro para a estrutura Unidade (lista de personagens).
* 
* Valor retornado
*
* Retorna a lista atualizada.
* 
* Assertiva de entrada
*
* A estrutura de Unidade enviada para a função precisa ter sido declarada.
***************************************************************************/
Unidade * RemoverUnidadeFinal();

/***************************************************************************
* Função: Remover Unidade
* Descrição
*
* Realiza a remoção do nó (personagem) específico que foi enviado para a função.
*
* Parâmetros
*
* Unidade* - ponteiro para estrutura Unidade (lista de personagens).
* Unidade* - ponteiro para o nó (personagem) específico a ser removido.
* 
* Valor retornado
*
* Retorna a lista atualizada.
* 
* Assertiva de entrada
*
* A estrutura de Unidade que contém os personagens precisa ter sido declarada.
* A estrutura de Unidade que será removida precisa estar contida na lista enviada.
***************************************************************************/
Unidade * RemoverUnidade();

/***************************************************************************
* Função: Limpa Lista
* Descrição
*
* Realiza a limpeza de uma lista de personagens, removendo todos os seus nós.
*
* Parâmetros
*
* Unidade* - ponteiro para a estrutura Unidade (lista de personagens).
* 
* Valor retornado
*
* Retorna a lista sem nenhum nó com o valor NULL.
* 
* Assertiva de entrada
*
* A estrutura de Unidade enviada para a função precisa ser válida.
***************************************************************************/
Unidade * LimpaLista();

/*FUNÇÕES DE COMERCIO*/

/***************************************************************************
* Função: Cria Comércio
* Descrição
*
* Inicializa a estrutura Comércio com o valor NULL.
*
* Parâmetros
*
* void - Nenhum parâmetro enviada para a função.
* 
* Valor retornado
*
* Retorna o valor NULL para o ponteiro do tipo Comercio.
* 
* Assertiva de entrada
*
* Não possui assertivas de entrada.
***************************************************************************/
Comercio* CriaComercio ();

/***************************************************************************
* Função: Comércio Vazia
* Descrição
*
* Verifica se a estrutura Comercio está alocada ou não.
*
* Parâmetros
*
* Comercio* - ponteiro para a estrutura Comercio (geradora de recursos).
* 
* Valor retornado
*
* Retorna o valor inteiro 1 caso a estrutura seja nula, ou 0 caso contrário.
* 
* Assertiva de entrada
*
* A estrutura de Comercio precisa ter sido declarada.
***************************************************************************/
int ComercioVazia();

/***************************************************************************
* Função: Inicializar Comércio
* Descrição
*
* Aloca a estrutura Comercio com os devidos atributos.
*
* Parâmetros
*
* Comercio* - ponteiro para a estrutura Comercio.
* taxaouro - valor inteiro que representa a quantidade de ouro gerada por wave no game.
* nivel - valor inteiro que representa o nível do edifício Comércio.
* 
* Valor retornado
*
* Retorna a estrutura alocada.
* 
* Assertiva de entrada
*
* A estrutura de Comercio enviada para a função precisa ser válida.
* Os tipos dos parâmetros precisam ser obedecidos.
***************************************************************************/
Comercio* InicializarComercio();

/*FUNÇÕES DE EDIFICIO*/

/***************************************************************************
* Função: Cria Edifício
* Descrição
*
* Inicializa a estrutura Edificio com o valor NULL.
*
* Parâmetros
*
* void - Nenhum parâmetro enviada para a função.
* 
* Valor retornado
*
* Retorna o valor NULL para o ponteiro do tipo Edificio.
* 
* Assertiva de entrada
*
* Não possui assertivas de entrada.
***************************************************************************/
Edificio* CriaEdificio();

/***************************************************************************
* Função: Edifício Vazia
* Descrição
*
* Verifica se a estrutura Edificio é nula ou não.
*
* Parâmetros
*
* Edificio* - ponteiro para a estrutura Edificio.
* 
* Valor retornado
*
* Retorna o valor inteiro 1 caso a estrutura seja nula, ou 0 caso contrário.
* 
* Assertiva de entrada
*
* A estrutura de Edificio enviada para a função precisa ter sido declarada.
***************************************************************************/
int EdificioVazia();

/***************************************************************************
* Função: Inicializar Edifício
* Descrição
*
* Aloca a estrutura Edifício que pode representar no game um Quartel, Casa da Lanças ou Campo de Tiro.
*
* Parâmetros
*
* Edificio* - ponteiro para a estrutura Edificio.
* custounidade - valor inteiro que representa a taxa para a criação de uma unidade para aquele tipo de edifício.
* nivel - valor inteiro que representa o nível do edifício.
* 
* Valor retornado
*
* Retorna a estrutura alocada.
* 
* Assertiva de entrada
*
* A estrutura de Edificio enviada para a função precisa ter sido declarada.
* Os tipos de cada parâmetros precisam estar de acordo com a função.
***************************************************************************/
Edificio* InicializarEdificio();
