/*! \file funcoes.c
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

/*INCLUSÃO DAS BIBLIOTECAS*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "estruturas.h"
#include "engine.h"

/*	--------------------FUNÇÕES DE CRIAÇÃO--------------------	*/

/***************************************************************************/
/**
* \fn CabecaGeral* CriaCabecaGeral ()
*
* \brief Aloca a estrutura controladora do game e faz com que seus ponteiros internos para as estruturas do game apontem para NULL.
*
* void - Nenhum parâmetro enviada para a função.
*
* \return Retorna a estrutura alocada com os ponteiros internos apontando para NULL.
* 
* Assertiva de entrada
*
* Não possui assertivas de entrada.
***************************************************************************/

/*
Função responsável para criação de estruturas do tipo CabecaGeral.
REQUISITO: Ter memória suficiente para alocação.
HIPOTESE: A função deve alocar e retornar um ponteiro do tipo CabecaGeral com ponteiros character=NULL e castle=NULL.
ASSERTIVAS DE ENTRADA: Não há.
ASSERTIVAS DE SAÍDA: O ponteiro novo deve ser diferente de nulo para ser retornado, caso contrário, retorna-se NULL.
INTERFACE EXPLÍCITA: O tipo de retorno CabecaGeral*.
INTERFACE IMPLÍCITA: CabecaGeral* novo, novo->character, novo->castle.
*/
CabecaGeral* CriaCabecaGeral () {
	CabecaGeral * novo = (CabecaGeral*) malloc (sizeof(CabecaGeral));	/*Aloca um espaço de memória do tipo CabecaGeral*/
	novo->character = NULL;	/*Associa valores de NULL aos ponteiros e character e castle*/
	novo->castle = NULL;

	if (novo != NULL) {	/*Verificação de retorno. Analisa se o espaço se memória foi alocado*/
		return novo;	/*Caso tenha sido, retorna a cabeça criada*/
	} else {
		return NULL;	/*Caso contrário, retorna NULL*/
	}
}

/***************************************************************************/
/**
* \fn CabecaPFilas* CriaCabecaPFilas ()
*
* \brief Aloca a estrutura que contém as duas listas de personagens do game (player e cpu), fazendo com que seus ponteiros internos apontem para * NULL.
*
* void - Nenhum parâmetro enviada para a função.
*
* \return Retorna a estrutura alocada com os ponteiros internos apontando para NULL.
* 
* Assertiva de entrada
*
* Não possui assertivas de entrada.
***************************************************************************/

/*
Função responsável para criação de estruturas do tipo CabecaPFilas.
REQUISITO: Ter memória suficiente para alocação.
HIPOTESE: A função deve alocar e retornar um ponteiro do tipo CabecaPFilas com ponteiros player e cpu iguais a NULL.
ASSERTIVAS DE ENTRADA: Não há.
ASSERTIVAS DE SAÍDA: O ponteiro novo deve ser diferente de nulo para ser retornado, caso contrário, retorna-se NULL.
INTERFACE EXPLÍCITA: O tipo de retorno CabecaGeral*.
INTERFACE IMPLÍCITA: CabecaPFilas* novo, novo->player, novo->cpu.
*/
CabecaPFilas* CriaCabecaPFilas () {
	CabecaPFilas * novo = (CabecaPFilas*) malloc (sizeof(CabecaPFilas));	/*Aloca um espaço de memoria do tipo CabecaPFilas*/
	novo->player = NULL;	/*Associa valores de NULL aos ponteiros de player e cpu*/
	novo->cpu = NULL;

	if (novo != NULL) {	/*Verificação de retorno. Analisa se o espaço se memória foi alocado*/
		return novo;	/*Caso tenha sido, retorna a cabeça criada*/
	} else {
		return NULL;	/*Caso contrário, retorna NULL*/
	}
}

/***************************************************************************/
/**
* \fn Castelo* CriaCastelo (int novawave,int valor)
*
* \brief Aloca a estrutura que contém os ponteiros para cada edifício do game e faz com que esses ponteiros apontem para NULL.
*
* @param novawave - determina o valor inicial
* @param valor - informa a quantidade de ouro
*
* \return Retorna o a estrutura alocada com os ponteiros internos apontando para NULL.
* 
* Assertiva de entrada
*
* Não possui assertivas de entrada.
***************************************************************************/

/*
Função responsável para criação de estruturas do tipo Castelo.
REQUISITO: Ter memória suficiente para alocação.
HIPOTESE: A função deve alocar e retornar um ponteiro Castelo com ponteiros quartel,campodetiro,casadaslancas e comercio iguais a NULL. O atributo ouro deve ser incializado com 100.
ASSERTIVAS DE ENTRADA: Não há.
ASSERTIVAS DE SAÍDA: O ponteiro novo deve ser diferente de nulo para ser retornado, caso contrário, retorna-se NULL.
INTERFACE EXPLÍCITA: O tipo de retorno Castelo*.
INTERFACE IMPLÍCITA: Castelo * novo, novo->quartel, novo->campodetiro, novo->casadaslancas, novo->comercio, novo->ouro
*/
Castelo* CriaCastelo (int novawave,int valor) {
	Castelo * novo = (Castelo*) malloc (sizeof(Castelo));	/*Aloca um espaço de memoria do tipo Castelo*/
	novo->quartel = NULL;	/*Associa valores de NULL aos ponteiros de quartel,campodetiro,casadaslancas e comercio*/
	novo->campodetiro = NULL;
	novo->casadaslancas = NULL;
	novo->comercio = NULL;
	if(novawave==1){	/*Se o jogo começar da primeira horda, seta o valor inicial de ouro para 100*/
		novo->ouro = 100;	/*Seta o valor inicial de ouro*/
	}else{
		novo->ouro = valor;	/*Se o jogo começar de uma horda carregada, atualiza o valor*/
	}
	if (novo != NULL) {	/*Verificação de retorno. Analisa se o espaço se memória foi alocado*/
		return novo;	/*Caso tenha sido, retorna a cabeça criada*/
	} else {
		return NULL;	/*Caso contrário, retorna NULL*/
	}
}

/***************************************************************************/
/**
* \fn Unidade* CriaUnidade ()
*
* \brief Inicializa uma estrutura de Unidade com o valor NULL.
*
* void - Nenhum parâmetro enviada para a função.
*
* \return Retorna o valor NULL para o ponteiro do tipo Unidade.
* 
* Assertiva de entrada
*
* Não possui assertivas de entrada.
***************************************************************************/

/*
Função responsável para criação de estruturas do tipo Unidade.
REQUISITO: Ter memória suficiente para alocação.
HIPOTESE: A função deve retornar um ponteiro de Unidade igual a NULL.
ASSERTIVAS DE ENTRADA: Não há.
ASSERTIVAS DE SAÍDA: Não há.
INTERFACE EXPLÍCITA: O tipo de retorno Unidade*.
INTERFACE IMPLÍCITA: O retorno ser igual a NULL.
*/
Unidade* CriaUnidade () {
	return NULL;	/*A função deve apenas retornar NULL*/
}

/***************************************************************************/
/**
* \fn Edificio* CriaEdificio ()
*
* \brief Inicializa a estrutura Edificio com o valor NULL.
*
* void - Nenhum parâmetro enviada para a função.
*
* \return Retorna o valor NULL para o ponteiro do tipo Edificio.
* 
* Assertiva de entrada
*
* Não possui assertivas de entrada.
***************************************************************************/

/*
Função responsável para criação de estruturas do tipo Edificio.
REQUISITO: Ter memória suficiente para alocação.
HIPOTESE: A função deve retornar um ponteiro de Edificio igual a NULL.
ASSERTIVAS DE ENTRADA: Não há.
ASSERTIVAS DE SAÍDA: Não há.
INTERFACE EXPLÍCITA: O tipo de retorno Edificio*.
INTERFACE IMPLÍCITA: O retorno ser igual a NULL.
*/
Edificio* CriaEdificio () {
	return NULL;	/*A função deve apenas retornar NULL*/
}

/***************************************************************************/
/**
* \fn Comercio* CriaComercio ()
*
* \brief Inicializa a estrutura Comércio com o valor NULL.
*
* void - Nenhum parâmetro enviada para a função.
*
* \return Retorna o valor NULL para o ponteiro do tipo Comercio.
* 
* Assertiva de entrada
*
* Não possui assertivas de entrada.
***************************************************************************/

/*
Função responsável para criação de estruturas do tipo Comercio.
REQUISITO: Ter memória suficiente para alocação.
HIPOTESE: A função deve retornar um ponteiro Comercio igual a NULL.
ASSERTIVAS DE ENTRADA: Não há.
ASSERTIVAS DE SAÍDA: Não há.
INTERFACE EXPLÍCITA: O tipo de retorno Comercio*.
INTERFACE IMPLÍCITA: O retorno ser igual a NULL.
*/
Comercio* CriaComercio () {
	return NULL;	/*A função deve apenas retornar NULL*/
}

/*	--------------------FUNÇÕES QUE ANALISAM SE UMA LISTA ESTÁ VAZIA--------------------	*/

/***************************************************************************/
/**
* \fn int CabecaGeralVazia(CabecaGeral* lis)
*
* \brief Verifica se a estrutura controladora do game é nula ou não.
*
* @param lis - ponteiro para a estrutura controladora
*
* \return Retorna o valor inteiro 1 caso a estrutura seja nula, ou 0 caso não seja.
* 
* Assertiva de entrada
*
* A estrutura enviada precisa ter sido declarada.
***************************************************************************/

/*
Função que verifica se uma lista está vazia
REQUISITO: Ter um ponteiro de CabecaGeral alocado na memória.
HIPOTESE: A função deve retornar 1 caso o ponteiro seja igual a NULL(lista vazia) e 0 caso contrário(lista não vazia).
ASSERTIVAS DE ENTRADA: Estrutura enviada ter sido declarada e há a necessidade de um ponteiro de CabecaGeral alocado.
ASSERTIVAS DE SAÍDA: Verficia se é vazia, se for, retorna 1 e, caso contrario, retorna 0.
INTERFACE EXPLÍCITA: O tipo de retorno "int" e o parâmetro de entrada do tipo CabecaGeral*.
INTERFACE IMPLÍCITA: A verificação de retorno 1 ou 0.
*/
int CabecaGeralVazia(CabecaGeral* lis){
	if(lis==NULL){	/*Se a lista for vazia, retorna 1, caso contrario, retorna 0*/
		return 1;
	}else{
		return 0;
	}
}

/***************************************************************************/
/**
* \fn int CabecaPFilasVazia(CabecaPFilas* lis)
*
* \brief Verifica se a estrutura que contém as listas de personagens é nula ou não.
*
* @param lis - ponteiro para a estrutura dos personagens
*
* \return Retorna o valor inteiro 1 caso a estrutura seja nula, ou 0 caso não seja.
* 
* Assertiva de entrada
*
* A estrutura enviada para a função precisa ter sido declarada.
***************************************************************************/

/*
Função que verifica se uma lista está vazia.
REQUISITO: Ter um ponteiro de CabecaPFilas alocado na memória.
HIPOTESE: A função deve retornar 1 caso o ponteiro seja igual a NULL(lista vazia) e 0 caso contrário(lista não vazia).
ASSERTIVAS DE ENTRADA: Estrutura enviada para a função necessita ter sido declarada e alocada.
ASSERTIVAS DE SAÍDA: Verficia se é vazia, se for, retorna 1 e, caso contrario, retorna 0.
INTERFACE EXPLÍCITA: O tipo de retorno "int" e o parâmetro de entrada do tipo CabecaPFilas*.
INTERFACE IMPLÍCITA: A verificação de retorno 1 ou 0.
*/
int CabecaPFilasVazia(CabecaPFilas* lis) {
	if(lis==NULL){	/*Se a lista for vazia, retorna 1, caso contrario, retorna 0*/
		return 1;
	}else{
		return 0;
	}
}

/***************************************************************************/
/**
* \fn int CasteloVazia(Castelo* lis)
*
* \brief Verifica se a estrutura que contém os edifícios é nula ou não.
*
* @param lis - ponteiro para a estrutura que contém os edifícios
*
* \return Retorna o valor inteiro 1 caso a estrutura seja nula, ou 0 caso não seja.
* 
* Assertiva de entrada
*
* A estrutura enviada para a função precisa ter sido declarada.
***************************************************************************/

/*
Função que verifica se uma lista está vazia.
REQUISITO: Ter um ponteiro de Castelo alocado na memória.
HIPOTESE: A função deve retornar 1 caso o ponteiro seja igual a NULL(lista vazia) e 0 caso contrário(lista não vazia).
ASSERTIVAS DE ENTRADA: Estrutura enviada para a função necessita ter sido declarada e alocada.
ASSERTIVAS DE SAÍDA: Verficia se é vazia, se for, retorna 1 e, caso contrario, retorna 0.
INTERFACE EXPLÍCITA: O tipo de retorno "int" e o parâmetro de entrada do tipo Cstelo*.
INTERFACE IMPLÍCITA: A verificação de retorno 1 ou 0.
*/
int CasteloVazia(Castelo* lis) {
	if(lis==NULL){	/*Se a lista for vazia, retorna 1, caso contrario, retorna 0*/
		return 1;
	}else{
		return 0;
	}
}

/***************************************************************************/
/**
* \fn int UnidadeVazia(Unidade* lis)
*
* \brief Verifica se a estrutura de Unidade é nula ou não.
*
* @param lis - ponteiro para a estrutura Unidade.
*
* \return Retorna o valor inteiro 1 caso a estrutura seja nula, ou 0 caso contrário.
* 
* Assertiva de entrada
*
* A estrutura de Unidade enviada para a função precisa ter sido declarada corretamente.
***************************************************************************/

/*
Função que verifica se uma lista está vazia.
REQUISITO: Ter um ponteiro de Unidade alocado na memória.
HIPOTESE: A função deve retornar 1 caso o ponteiro seja igual a NULL(lista vazia) e 0 caso contrário(lista não vazia).
ASSERTIVAS DE ENTRADA: Estrutura enviada para a função necessita ter sido declarada e alocada.
ASSERTIVAS DE SAÍDA: Verficia se é vazia, se for, retorna 1 e, caso contrario, retorna 0.
INTERFACE EXPLÍCITA: O tipo de retorno "int" e o parâmetro de entrada do tipo Unidade*.
INTERFACE IMPLÍCITA: A verificação de retorno 1 ou 0.
*/
int UnidadeVazia(Unidade* lis) {
	if(lis==NULL){	/*Se a lista for vazia, retorna 1, caso contrario, retorna 0*/
		return 1;
	}else{
		return 0;
	}
}

/***************************************************************************/
/**
* \fn int ComercioVazia(Comercio* lis)
*
* \brief Verifica se a estrutura Comercio está alocada ou não.
*
* @param lis - ponteiro para a estrutura Comercio (geradora de recursos).
*
* \return Retorna o valor inteiro 1 caso a estrutura seja nula, ou 0 caso contrário.
* 
* Assertiva de entrada
*
* A estrutura de Comercio precisa ter sido declarada.
***************************************************************************/

/*
Função que verifica se uma lista está vazia.
REQUISITO: Ter um ponteiro de Comercio alocado na memória.
HIPOTESE: A função deve retornar 1 caso o ponteiro seja igual a NULL(lista vazia) e 0 caso contrário(lista não vazia).
ASSERTIVAS DE ENTRADA: Estrutura enviada para a função necessita ter sido declarada e alocada.
ASSERTIVAS DE SAÍDA: Verficia se é vazia, se for, retorna 1 e, caso contrario, retorna 0.
INTERFACE EXPLÍCITA: O tipo de retorno "int" e o parâmetro de entrada do tipo Comercio*.
INTERFACE IMPLÍCITA: A verificação de retorno 1 ou 0.
*/
int ComercioVazia(Comercio* lis) {
	if(lis==NULL){	/*Se a lista for vazia, retorna 1, caso contrario, retorna 0*/
		return 1;
	}else{
		return 0;
	}
}

/***************************************************************************/
/**
* \fn int EdificioVazia(Edificio* lis)
*
* \brief Verifica se a estrutura Edificio é nula ou não.
*
* @param lis - ponteiro para a estrutura Edificio.
*
* \return Retorna o valor inteiro 1 caso a estrutura seja nula, ou 0 caso contrário.
* 
* Assertiva de entrada
*
* A estrutura de Edificio enviada para a função precisa ter sido declarada.
***************************************************************************/

/*
Função que verifica se uma lista está vazia.
REQUISITO: Ter um ponteiro de Edificio alocado na memória.
HIPOTESE: A função deve retornar 1 caso o ponteiro seja igual a NULL(lista vazia) e 0 caso contrário(lista não vazia).
ASSERTIVAS DE SAÍDA: Verficia se é vazia, se for, retorna 1 e, caso contrario, retorna 0.
INTERFACE EXPLÍCITA: O tipo de retorno "int" e o parâmetro de entrada do tipo Edificio*.
INTERFACE IMPLÍCITA: A verificação de retorno 1 ou 0.
*/
int EdificioVazia(Edificio* lis) {
	if(lis==NULL){	/*Se a lista for vazia, retorna 1, caso contrario, retorna 0*/
		return 1;
	}else{
		return 0;
	}
}

/*	--------------------FUNÇÕES DE INSERÇÃO--------------------	*/

/***************************************************************************/
/**
* \fn Unidade* InserirUnidadeFinal(Unidade* lis,int vida,int dano,float esquiva,int nivel,int classe)
*
* \brief Realiza a inserção de um personagem na lista de personagens do game sempre a última posição da lista.
*
* @param lis - ponteiro para a estrutura Unidade (lista de personagens)
* @param vida - valor inteiro que representa a vida do personagem.
* @param dano - valor inteiro que representa o dano causado por esse personagem.
* @param esquiva - valor decimal que representa a capacidade de esquiva do personagem.
* @param nivel - valor inteiro que representa o nível do personagem.
* @param classe - valor inteiro que representa qual o tipo do personagem.
*
* \return Retorna a lista de personagens atualizada.
* 
* Assertiva de entrada
*
* A estrutura Unidade enviada para a função precisa ter sido declarada.
* Os tipos de cada parâmetros precisam estar de acordo.
***************************************************************************/

/*
Função de inserção no fim da lista Unidade.
REQUISITOS: Ter um ponteiro de Unidade alocado e enviar informações positivas como argumento da função.
HIPÓTESES: A função deve inserir um novo nó no fim da lista de forma que o ponteiro de próximo seja igual a NULL e o ponteiro de anterior seja igual ao antigo nodo final.
ASSERTIVAS DE ENTRADA: Estrutura enviada para a função necessita ter sido declarada e alocada e os atributos devem estar de acordo com seus tipos.
ASSERTIVAS DE SAÍDA: Se os valores enviados estiverem dentro da faixa aceita, realizam-se as operações de inserção e a lista atulizada é retornada, caso contrário, retorna-se a lista sem efetuar operações.
INTERFACE EXPLÍCITA: O tipo de retorno Unidade* e os parâmetros de entrada Unidade* lis,int vida,int dano,float esquiva,int nivel,int classe.
INTERFACE IMPLÍCITA: Alocação e atribuição de valores para a célula "novo", a inserção do elemento na lista e as verificações de entrada e saída.
*/
Unidade* InserirUnidadeFinal(Unidade* lis,int vida,int dano,float esquiva,int nivel,int classe){
	Unidade* novo = (Unidade*)malloc(sizeof(Unidade));	/*aloca uma celula nova do tipo Unidade*/
	Unidade* aux = lis;	/*ponteiro auxiliar do tipo Unidade recebe a lista do parâmetro de entrada*/
	
	novo->vida = vida;	/*coloca as informações em uma celula auxiliar*/
	novo->dano = dano;
	novo->esquiva = esquiva;
	novo->nivel = nivel;
	novo->classe = classe;
	novo->prox = NULL;	/*nula-se o ponteiro de próximo já que a célula será sempre inserida no fim da lista*/
	
	if((classe>=1 && classe<=4) && (vida>0) && (dano>0) && (esquiva>0 && esquiva<1) && ((nivel>0) && (nivel<=3))){	/*ASSERTIVA EXECUTÁVEL DE ENTRADA: verifica a validade das informações enviadas(se estão dentro do intervalo aceito pelo jogo)*/
		if(!UnidadeVazia(lis)){	/*se a lista enviada não for nula, insere no fim*/
			while(aux->prox != NULL){/*enquanto o ponteiro de próximo em auxiliar não for nulo, continua com o laço. Objetivo: encontrar a última posição da lista*/
				aux = aux->prox;
			}
			aux->prox = novo;	/*ponteiro de próximo da última célula recebe o novo elemento*/
			novo->ant = aux;	/*ponteiro de anterior da célula inserida recebe o último elemento da lista exsitente*/

			return lis;	/*retorna a lista atualizada*/
		} else{	/*se a lista enviada for nula, retorna a célula auxiliar*/
			novo->ant = NULL;	/*ponteiro de anterior da célula inserida recebe nulo já que é o único elemento da lista*/
			return novo;
		}
	}else{	/*se alguma informação enviada for inválida, retorna a lista sem fazer alterações*/
		return lis;
	}
}

/*	--------------------FUNÇÕES DE REMOÇÃO--------------------	*/

/***************************************************************************/
/**
* \fn Unidade* RemoverUnidade(Unidade* lis, Unidade *retira)
*
* \brief Realiza a remoção do nó (personagem) específico que foi enviado para a função.
*
* @param lis - ponteiro para estrutura Unidade (lista de personagens).
* @param retira - ponteiro para o nó (personagem) específico a ser removido.
*
* \return Retorna a lista atualizada.
* 
* Assertiva de entrada
*
* A estrutura de Unidade que contém os personagens precisa ter sido declarada.
* A estrutura de Unidade que será removida precisa estar contida na lista enviada.
***************************************************************************/

/*
Função responsável pela remoção de elementos em qualquer posição de uma lista.
REQUISITOS: Enviar um ponteiro de Unidade alocado em memória.
HIPÓTESES: A função deve retirar um elemento de uma lista duplamente encadeada. Se a lista for nula, não realiza operação alguma. Se a lista contiver apenas um ou mais elementos, remove o nó final.
ASSERTIVAS DE ENTRADA: A estrutura de unidade que contém a lista deve ter sido declarada e alocada, enquanto a estrutura a ser removida deve pertencer à lista.
ASSERTIVAS DE SAÍDA: Se a lista for vazia, retorna nulo, caso contrário, remove o elemento procurado e retorna a lista atualizada.
INTERFACE EXPLÍCITA: O tipo de saída Unidade* e os parâmetros de entrada Unidade* lis, Unidade *retira.
INTERFACE IMPLÍCITA: As variáveis auxiliares, a remoção do elemento na lista e as verificações de entrada e saída.
*/

Unidade* RemoverUnidade(Unidade* lis, Unidade *retira){
	Unidade* aux = NULL;	/*ponteiro auxiliar do tipo Unidade recebe NULL*/
	Unidade* p = lis;	/*ponteiro auxiliar do tipo Unidade recebe a lista do parâmetro de entrada*/
 
	while(p!=retira && p != NULL)	/*o laço deve procurar pelo elemento a ser removido*/
	{
		aux = p;
	  	p = p->prox;
	}
	if(p==NULL)     /*se p é nulo, então a lista é vazia*/
	{ 
		return lis;	/*retorna-se a lista vazia*/
	}
	  
	if(aux==NULL){ /*se aux for nulo, significa que o elemento a ser removido é o primeiro*/
		lis = p->prox; /*pega a segunda posição da lista*/
		if (p->prox!=NULL)
		   	{
		   		lis->ant = NULL;	/*seta o poneiro de anterior da segunda posição para nulo*/
		   	}
	   	free(p); /*libera a posição atual*/
	   	return lis;	/*retorna a lista atualizada*/
	}
	else	/*se aux é diferente de nulo, significa que o elemento está no meio ou fim da lista*/
	{
	   	aux->prox = p->prox; /*arruma o ponteiro da penúltima posição*/
	   	if (p->prox!=NULL)
	   	{
	   		p->prox->ant = aux;	/*rearranja o ponteiro de anterior da unidade à frentre*/
	   	}
	   	free(p); /*libera o último espaço de memória*/
	   	return lis;	/*retorna a lista atualizada*/
	}
}

/***************************************************************************/
/**
* \fn Unidade* LimpaLista(Unidade* lis)
*
* \brief Realiza a limpeza de uma lista de personagens, removendo todos os seus nós.
*
* @param lis - ponteiro para a estrutura Unidade (lista de personagens).
*
* \return Retorna a lista sem nenhum nó com o valor NULL.
* 
* Assertiva de entrada
*
* A estrutura de Unidade enviada para a função precisa ser válida.
***************************************************************************/

/*
Função que remove todos os elementos de uma lista.
REQUISITO: Enviar um ponteiro de Unidade devidamente alocado.
HIPÓTESE: A função deve receber um ponteiro de lista do tipo Unidade e remover todos os seus elementos.
ASSERTIVAS DE ENTRADA: Estrutura enviada para a função necessita ter sido declarada e alocada.
ASSERTIVAS DE SAÍDA: Não há.
INTERFACE EXPLÍCITA: O tipo de retorno Unidade* e a lista de entrada Unidade* lis.
INTERFACE IMPLÍCITA: As variáveis auxiliares e a remoção de todos os  elementos da lista.
*/
Unidade* LimpaLista(Unidade* lis){
	Unidade* aux;	/*ponteiros auxiliares para percorrimento da lista*/
	Unidade* p = lis;
	while(p!=NULL)	/*enquanto o ponteiro nao for nulo, passa para a p´roximo posição da lista e libera a memória da anterior*/
	{
		aux = p->prox;
		free(p);
		p=aux;
	}
	return NULL;	/*retorna nulo*/
}

/***************************************************************************/
/**
* \fn Unidade * RemoverUnidadeFinal (Unidade * lis)
*
* \brief Realiza a remoção do último nó (personagem) da lista de personagens.
*
* @param lis - ponteiro para a estrutura Unidade (lista de personagens).
*
* \return Retorna a lista atualizada.
* 
* Assertiva de entrada
*
* A estrutura de Unidade enviada para a função precisa ter sido declarada.
***************************************************************************/

/*
Função de remoção no fim de uma lista.
REQUISITO: Ponteiro de Unidade declarado e devidamento alocado.
HIPÓTESE: A função deve remover a última célula de uma lista duplamente encadeada.
ASSERTIVAS DE ENTRADA: Estrutura enviada para a função necessita ter sido declarada e alocada.
ASSERTIVAS DE SAÍDA: Se a lista for vazia, retorna nulo, caso contrário, remove o elemento procurado e retorna a lista atualizada.
INTERFACE EXPLÍCITA: o tipo de retorno Unidade* e o parâmetros de entrada Unidade * lis.
INTERFACE IMPLÍCITA: Os ponteiros auxiliares e a operação de remoção.
*/
Unidade * RemoverUnidadeFinal (Unidade * lis){
	Unidade* aux = NULL;
	Unidade* p = lis;
	
	if(!UnidadeVazia(lis)){	/*verifica se a lista tem elementos*/
		if(p==NULL){	/*se p é nulo, então a lista é vazia(apenas para certificar)*/
			return lis;
		}

		while(p->prox!=NULL){	/*vai até o final da lista*/
			aux = p;
			p = p->prox;
		}
		
		if(aux==NULL){	/*se aux for nulo, significa que o elemento a ser removido é unico*/
			lis = p->prox;	/*pega a segunda posição da lista(nula)*/
			free(p);	/*libera a posição atual*/
			return lis;
		} else {
			aux->prox = p->prox;	/*arruma o ponteiro da penúltima posição*/
			free(p);	/*libera o último espaço de memória*/
			return lis;
		}
	} else {
		return NULL;
	}
}

/*	--------------------FUNÇÕES DE INICIALIZAÇÃO--------------------	*/

/***************************************************************************/
/**
* \fn Edificio* InicializarEdificio(Edificio* E,int custounidade,int nivel)
*
* \brief Aloca a estrutura Edifício que pode representar no game um Quartel, Casa da Lanças ou Campo de Tiro.
*
* @param E - ponteiro para a estrutura Edificio.
* @param custounidade - valor inteiro que representa a taxa para a criação de uma unidade para aquele tipo de edifício.
* @param nivel - valor inteiro que representa o nível do edifício.
*
* \return Retorna a estrutura alocada.
* 
* Assertiva de entrada
*
* A estrutura de Edificio enviada para a função precisa ter sido declarada.
* Os tipos de cada parâmetros precisam estar de acordo com a função.
***************************************************************************/

/*
Função de inicialização de Edificio.
REQUISITO: Enviar informações positivas.
HIPÓTESE: Caso o edificio não exista, a função deve alocar em memória um espaço e incializar os valores. Caso o edificio exista, os valores devem ser apenas atualizados.
ASSERTIVAS DE ENTRADA: Estrutura enviada para a função necessita ter sido declarada e alocada. Os valores numéricos devem respeitar seus tipos.
ASSERTIVAS DE SAÍDA: Caso os valores enviados nos parâmetros estejam dentro do intervalo imposto pela verificação, retorna-se a estrutura "novo" com valores inicializados, caso contrário, retorna a estrutura original(enviada no parâmetro) sem realizar alterações.
INTERFACE EXPLÍCITA: O tipo de retorno Edificio* e os parâmetros de entrada Edificio* E,int custounidade,int nivel.
INTERFACE IMPLÍCITA: As assertivas, o ponteiro auxiliar de "novo" e as operações com ponteiro.
*/
Edificio* InicializarEdificio(Edificio* E,int custounidade,int nivel){
	Edificio* novo;	/*declaração de uma estrutura auxiliar chamada "novo"*/
	if(EdificioVazia(E)){	/*se edificio não existir, aloca um espaço de memória*/
		novo = (Edificio*)malloc(sizeof(Edificio));
	}else{	/*caso exista, passa o ponteiro para a estrutura auxiliar*/
		novo = E;
	}
	
	if((custounidade>0) && ((nivel>0) && (nivel<=3))){	/*verifica a validade das informações enviadas*/
		novo->custounidade = custounidade;
		novo->nivel = nivel;
		
		return novo;
	}else{
		return novo;/*se alguma informação enviada for inválida, retorna o ponteiro sem fazer alterações*/
	}
}

/***************************************************************************/
/**
* \fn Comercio* InicializarComercio(Comercio* C,int taxaouro,int nivel)
*
* \brief Aloca a estrutura Comercio com os devidos atributos.
*
* @param C - ponteiro para a estrutura Comercio.
* @param taxaouro - valor inteiro que representa a quantidade de ouro gerada por wave no game.
* @param nivel - valor inteiro que representa o nível do edifício Comércio.
*
* \return Retorna a estrutura alocada.
* 
* Assertiva de entrada
*
* A estrutura de Comercio enviada para a função precisa ser válida.
* Os tipos dos parâmetros precisam ser obedecidos.
***************************************************************************/

/*
Função de inicialização de Comercio.
REQUISITO: Comercio ter sido alocado e enviar informações positivas.
HIPÓTESE: Caso o comercio não exista, a função deve alocar em memória um espaço e incializar os valores. Caso o comercio exista, os valores devem ser apenas atualizados.
ASSERTIVA DE ENTRADA: Estrutura enviada para a função necessita ter sido declarada e alocada. Os valores numéricos devem estar de acordo com seus tipos.
ASSERTIVAS DE SAÍDA: Caso as informações estejam dentro do intervalo especificado pelo jogo, retorna-se o ponteiro de "novo" com os valores atualizados ,caso contrário, retorna-se o ponteiro enviado como parâmetro sem alterações.
INTERFACE EXPLÍCITA: O tipo de retorno Comercio* e os parâmetros de entrada Comercio* C,int taxaouro,int nivel.
INTERFACE IMPLÍCITA: As assertivas, o ponteiro auxiliar de "novo" e as operações.
*/
Comercio* InicializarComercio(Comercio* C,int taxaouro,int nivel){
	Comercio* novo;
	if(ComercioVazia(C)){	/*se comercio não existir, aloca um espaço de memória e atribui o tempo de geração de recursos*/
		novo = (Comercio*)malloc(sizeof(Comercio));
	}else{
		novo = C;
	}
	
	if((taxaouro>0) && ((nivel>0) && (nivel<=3))){	/*verifica a validade das informações enviadas*/
		novo->taxaouro = taxaouro;
		novo->nivel = nivel;
		
		return novo;
	}else{
		return novo;/*se alguma informação enviada for inválida, retorna o ponteiro sem fazer alterações*/
	}
}

/*	--------------------FUNÇÕES DE VERIFICAÇÃO--------------------	*/

/***************************************************************************/
/**
* \fn int VerificarCastelo(Castelo* C)
*
* \brief Verifica se cada edifício da estrutura Castelo é nulo ou não.
*
* @param C - ponteiro para a estrutura que contém os edifícios
*
* \return Retorna o valor inteiro 1 caso todos os edifícios não sejam nulos, ou 0 caso algum deles seja.
* 
* Assertiva de entrada
*
* A estrutura enviada para a função precisa ter sido declarada para que a análise funcione corretamente.
***************************************************************************/

/*
Função de verificação de Castelo.
REQUISITO: Enviar ponteiro de Castelo alocado.
HIPÓTESE: A função deve verificar os apontamentos de edificio e comercio em Castelo, certificando que sejam diferentes de nulo. Caso passe no teste, retorna 1, caso contrário, retorna 0.
ASSERTIVAS DE ENTRADA: Estrutura enviada para a função necessita ter sido declarada e alocada.
ASSERTIVAS DE SAÍDA: Caso todas as estruturas sejam diferentes de nulo, retorna-se 1, caso contrário, retorna-se 0.
INTERFACE EXPLÍCITA: O tipo de retorno int e o parâmetro de entrada Castelo* C.
INTERFACE IMPLÍCITA: A verificação de retorno 0 ou 1.
*/
int VerificarCastelo(Castelo* C){
	if((!EdificioVazia(C->quartel)) && (!EdificioVazia(C->campodetiro)) && (!EdificioVazia(C->casadaslancas)) && (!ComercioVazia(C->comercio))){
		return 1;
	}else{
		return 0;
	}
}

/***************************************************************************/
/**
* \fn int VerificarCabecaGeral(CabecaGeral* CG)
*
* \brief Verifica se as estruturas internas do controlador são nulas ou não.
*
* @param CG - ponteiro para a estrutura controladora
*
* \return Retorna o valor inteiro 1 caso as suas estruturas não sejam nulas, ou 0 caso as estruturas sejam nulas.
* 
* Assertiva de entrada
*
* A estrutura controladora precisa ter sido declarada.
***************************************************************************/

/*
Função de verificação de CabecaGeral.
REQUISITO: Enviar ponteiro de CabecaGeral alocado.
HIPÓTESE: A função deve verificar os apontamentos de castle e character em CabecaGeral, certificando que sejam diferentes de nulo. Caso passe no teste, retorna 1, caso contrário, retorna 0.
ASSERTIVAS DE ENTRADA: A estrutura controladora necessita ter sido declarada e alocada.
ASSERTIVAS DE SAÍDA:  Caso todas as estruturas sejam diferentes de nulo, retorna-se 1, caso contrário, retorna-se 0.
INTERFACE EXPLÍCITA: O tipo de retorno int e o parâmetro de entrada CabecaGeral* CG.
INTERFACE IMPLÍCITA: A verificação de retorno 0 ou 1.
*/
int VerificarCabecaGeral(CabecaGeral* CG){
	if((!CasteloVazia(CG->castle)) && (!CabecaPFilasVazia(CG->character))){
		return 1;
	}else{
		return 0;
	}
}

/***************************************************************************/
/**
* \fn int VerificaEstrutura (Unidade * lista)
*
* \brief Assertiva estrutural para garantir que a estrutura de lista duplamente encadeada foi implementada corretamente.
*
* @param lista - ponteiro para a estrutura Unidade (lista de personagens).
*
* \return Retorna o valor inteiro 1 caso a estrutura esteja correta, ou 0 caso contrário.
* 
* Assertiva de entrada
*
* A estrutura de Unidade enviada para a função precisa ter sido declarada.
***************************************************************************/

/*
Função de verificação para filas.
REQUISITO: Enviar ponteiro de Unidade alocado.
HIPÓTESE: A função deve verificar se os apontamentos de próximo e anterior das filas de Unidade estão feitos de forma correta.
ASSERTIVAS DE ENTRADA: Estrutura enviada para a função necessita ter sido declarada e alocada.
ASSERTIVAS DE SAÍDA:  Caso todas a estruturas seja diferentes de nulo e o apontamento da lista esteja correto, retorna-se 1, caso contrário, retorna-se 0.
INTERFACE EXPLÍCITA: O tipo de retorno int e o parâmetro de entrada Unidade* lista.
INTERFACE IMPLÍCITA: As assertivas, os ponteiros auxiliares e as operações.
*/
int VerificaEstrutura (Unidade * lista) {
	Unidade* t = NULL;
	Unidade* q = NULL;
	int v = 0;

	if(!UnidadeVazia(lista)){	/*Verifica se a lista está vazia*/
		for (t = lista; t != NULL; t = t->prox) {	/*Estrutura de repetição contada para varrer o polinômio do começo até o fim*/
			if (t->prox != NULL) {
				if (t->prox->ant == t) {	/*Verifica se o prox->ant é igual a ele mesmo*/
					v = 1;	/*Se for, a variável de retorno recebe 1*/
				}else{
					v = 0;	/*Caso contrário, recebe 0*/
				}
			}
		}

		t = lista;
		while(t->prox != NULL){/*Vai até o fim da fila*/
			t = t->prox;
		}

		for(q = t; q != NULL; q = q->ant){	/*Estrutura de repetição contada para varrer o polinômio do final até o início*/
			if(q->ant != NULL){
				if(q->ant->prox == q){	/*Verifica se o ant->prox é igual a ele mesmo*/
					v = 1;	/*Se for, a variável de retorno recebe 1*/
				}else{
					v = 0;	/*Caso contrário, recebe 0*/
				}
			}
		}
	}else{
		v = 0;
	}
	
	return v;
}

/*	--------------------FUNÇÕES DE ATUALIZAÇÃO--------------------	*/

/***************************************************************************/
/**
* \fn Castelo* AtualizarCasteloOuro(Castelo* C, int ouro)
*
* \brief Atualiza a quantidade de ouro (recurso) do castelo do game.
*
* @param C - ponteiro para a estrutura de Castelo do game.
* @param ouro - valor inteiro que representa a quantidade de ouro a ser adicionada ou removida do Castelo.
*
* \return Retorna a estrutura de Castelo com a quantidade de ouro atualizada.
* 
* Assertiva de entrada
*
* A estrutura de Castelo enviada precisa ter sido declarada.
* A quantidade de ouro precisa ser um valor inteiro.
***************************************************************************/

/*
Função de atualização do ouro do Castelo.
REQUISITO: Enviar ponteiro de Castelo alocado e valor de ouro maior ou igual a zero.
HIPÓTESE: A função deve atualizar os valores de ouro do Castelo.
ASSERTIVAS DE ENTRADA: Estrutura enviada para a função necessita ter sido declarada e alocada. O valor de ouro deve ser inteiro.
ASSERTIVAS DE SAÍDA: Se a soma/subtração for positiva, retorna o ponteiro de castelo com o valor do ouro atualizado, caso contrário, retorna o castelo sem efetuar operações.
INTERFACE EXPLÍCITA: O tipo de retorno Castelo* e os parâmetros de entrada Castelo* C, int ouro.
INTERFACE IMPLÍCITA: Os ponteiros auxiliares, a verificação das informações e a soma/subtração.
*/
Castelo* AtualizarCasteloOuro(Castelo* C, int ouro){
	Castelo* novo;	/*ponteiro auxiliar do tipo castelo*/
	novo = C;	/*novo recebe o ponteiro de castelo*/
	
	if ((novo->ouro + (ouro)) >= 0) {	/*ASSERTIVA EXECUTÁVEL DE ENTRADA: verifica a validade das informações enviadas(se o valor permanece positivo)*/
		novo->ouro = novo->ouro + (ouro);	/*soma/subtrai o valor original do valor enviado*/
		return novo;
	} else {	/*caso o valor se torne negativo, não realiza operação alguma e retorna o ponteiro do castelo*/
		return C;
	}
}
