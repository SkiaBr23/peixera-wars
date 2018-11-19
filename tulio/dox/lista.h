/*! \file lista.h
	\brief Módulo para gerenciar as listas */

#include <stdio.h>

/*!	\struct lista lista.h Lista
	\brief Definição da estrutura da lista duplamente encadeada.
	\details Contém um campo para armazenar um ponteiro de char e dois ponteiros do mesmo tipo da estrutura para apontar para o elemento anterior e para o próximo elemento. */
struct lista{
	char *string;
	struct lista *prox,*ant;
};
typedef struct lista Lista;

/*! \def NULO
	\brief Definição dos iteradores */
#define NULO NULL

/* Protótipos das funções para manipulação de uma lista duplamente encadeada. */
Lista* CriarLista(void);
Lista* InserirInicio(Lista *lis, char *string);
Lista* InserirFim(Lista *lis, char *string);
Lista* RemoverInicio(Lista *lis);
Lista* RemoverFim(Lista *lis);
Lista* InserirOrdenado(Lista *lis, char *string);
Lista* RemoverElemento(Lista *lis, char *string);
Lista* BuscarElemento(Lista *lis, char *string);
char* BuscarProximo(Lista *lis, char *string);
Lista* BuscarPosicao(Lista *lis, int posicao);
Lista* InserirPosicao(Lista *lis, char *string, int posicao);
Lista* RemoverPosicao(Lista *lis, int posicao);
Lista* LerArquivo(FILE *fp);
int ContarLista(Lista *lis);
void EscreverArquivo(Lista *lis,FILE *fp,int choice);
void LiberarLista(Lista *lis);

/* Protótipos dos iteradores utilizados nas funções */
Lista* CriarNovo(void);
Lista* VerificarIgual(Lista *lis, char *string);
Lista* PassarProximoOrd(Lista *lis, char *string);
Lista* PassarProximo(Lista *p);
char* VerificarString(char* string);
