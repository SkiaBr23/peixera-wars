/*! \file lista.c
	\brief Módulo de implementação do módulo lista.h */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/* Iteradores para as funções de manipulação de listas. */

/********************************************************//**
* \fn Lista* CriarNovo(void)
* \brief Criar um novo ponteiro de lista e
* retorná-lo.
*
* \return O iterador retorna um ponteiro de lista,
* correspondendo ao novo elemento alocado. Caso não haja
* espaço disponível na memória para alocação, o programa é
* encerrado com o código de execução 1.
*
* O iterador funciona corretamente se houver espaço na memória
* para ser alocado.
************************************************************/
Lista* CriarNovo(void){
	Lista *novo = malloc(sizeof(Lista));
	/* Assertiva para verificar se há espaço disponível na memória para alocação. */
	if(novo == NULO){
		exit(1);
	}
	return(novo);
}

/********************************************************//**
* \fn Lista* VerificarIgual(Lista *lis, char *string)
* \brief Verificar se um elemento é igual a outro já existen
* te na lista.
*
* @param lis Ponteiro para lista duplamente encadeada
* @param string Ponteiro de char
*
* \return O iterador retorna um ponteiro NULL caso o
* elemento exista na lista e retorna um ponteiro para o
* início da lista caso o elemento não exista na lista.
*
* O iterador funciona corretamente se o ponteiro retornado
* é coerente com a situação da lista. Caso a palavra exista
* na lista, o ponteiro retornado deve ser NULL. Caso a
* palavra não exista na lista, um ponteiro para o início da
* lista é retornado.
************************************************************/
Lista* VerificarIgual(Lista *lis, char *string){
	Lista *p;

	/* Assertiva para verificar se o elemento que se deseja inserir em uma lista já existe na lista. */
	for(p=lis;p!=NULO;p=p->prox){
		if(strcmp(string,p->string)==0){
			return(NULO);
		}
	}

	p=lis;

	return(p);
}

/********************************************************//**
* \fn Lista* PassarProximoOrd(Lista *lis,char *string)
* \brief Percorrer a lista de forma ordenada,
* para que o ponteiro seja movido para a posição correta.
*
* @param lis Dois ponteiros de lista
* @param string Ponteiro de char
*
* O iterador recebe como parâmetros dois
* ponteiros de lista e um ponteiro de char. O primeiro
* ponteiro recebido serve para percorrer a lista e o
* segundo ponteiro serve para apontar para a posição atual
* na lista.
*
* \return O iterador retorna o ponteiro que marca a
* posição atual na lista.
*
* O iterador funciona corretamente se a posição na lista
* está correta depois que o ponteiro percorre a lista.
************************************************************/
Lista* PassarProximoOrd(Lista *lis,char *string){
	
	Lista *ant = malloc(sizeof(Lista));
	ant = NULO;
	Lista *p = lis;

	while ((p!=NULO) && (strcmp(p->string,string)<0)){
		ant = p;
		p=p->prox;
	}

	return(ant);
}

/********************************************************//**
* \fn Lista* PassarProximo(Lista *p)
* Objetivo do iterador: Percorrer a lista até a última
* posição.
*
* @param p Dois ponteiros de lista
*
* O iterador recebe como parâmetros dois
* ponteiros de lista. O primeiro ponteiro de lista irá 
* percorrer a lista, indicando seu final e o segundo 
* ponteiro de lista apontará para a posição atual na lista.
*
* \return O iterador retorna o ponteiro que marca a
* posição atual na lista.
*
* O iterador funciona corretamente se após a chamada dele
* o ponteiro p apontar para o fim da lista.
************************************************************/
Lista* PassarProximo(Lista *p){
	
	Lista *ant = malloc(sizeof(Lista));
	ant = NULO;

	while((p!=NULO)){
		ant = p;
		p=p->prox;
	}

	return(ant);
}

/********************************************************//**
* \fn char* VerificarString(char* string)
* Objetivo do iterador: Verificar se uma string aponta para
* NULL.
*
* @param string Ponteiro de char (string que será verificada)
*
* \return O iterador retorna NULL caso a string aponte para
* NULL e retorna a string inalterada caso a string não
* aponte para NULL.
*
* O iterador funciona corretamente se seu retorno for
* verificado após sua chamada.
************************************************************/
char* VerificarString(char* string){

	char *verificador = malloc(strlen(string)*sizeof(char));

	if(verificador==NULL){
		return(NULL);
	}

	return(verificador);
}

/* A partir daqui estão as funções para manipulação de listas. */

/********************************************************//**
* \fn Lista* CriarLista(void)
* \brief Criar um ponteiro de lista apontando
* para NULL.
*
* \return Retorna um ponteiro do tipo Lista, ou seja, um
* ponteiro para uma lista duplamente encadeada.
*
* A função funciona com sucesso se o retorno da função for
* um ponteiro apontando para NULL.
************************************************************/
Lista* CriarLista(void){
	return NULO;
}

/********************************************************//**
* \fn Lista* InserirInicio(Lista *lis, char *string)
* \brief Inserir uma palavra no início de uma
* lista duplamente encadeada.
*
* @param lis Ponteiro de Lista (pode ou não apontar para NULL)
* @param string Ponteiro de char (corresponde ao elemento que
* se deseja inserir; não pode estar vazio)
*
* \return Retorna um ponteiro do tipo Lista,
* correspondendo à lista atualizada. Caso o elemento a ser
* inserido já exista na lista, a lista é retornada sem
* alterações. Se a string que deve ser inserida na lista
* não existir, a lista é retornada sem alterações.
*
* A função funciona com sucesso se o primeiro elemento da
* lista é o elemento inserido e se o apontamento foi feito
* de forma correta, ou seja, se o ponteiro anterior do
* primeiro elemento aponta para NULL e se o ponteiro
* próximo do primeiro elemento aponta para a lista existente
* anteriormente.
*************************************************************/
Lista* InserirInicio(Lista *lis, char *string){

	char *verificador = malloc(strlen(string)*sizeof(char));

	/* Chamada do iterador para verificar se a string que se deseja inserir na lista aponta para NULL. */
	verificador = VerificarString(string);
	/* Assertiva para verificar se a string que se deseja inserir na lista aponta para NULL. */
	if(verificador==NULL){
		return(lis);
	}

	Lista *p;
	
	p = VerificarIgual(lis,string);
	/* Assertiva para verificar o retorno do iterador VerificarIgual */
	if(p==NULO && lis!=NULO){
		return(lis);
	}

	Lista *novo = CriarNovo();

	novo->string = malloc(100*sizeof(char));
	strcpy(novo->string,string);
	novo->prox = lis;
	novo->ant = NULO;
	
	if (lis!=NULO){
		lis->ant = novo;
	}
	
	return (novo);
}

/********************************************************//**
* \fn Lista* InserirFim(Lista *lis, char *string)
* \brief Inserir uma palavra no fim de uma
* lista duplamente encadeada.
*
* @param lis Ponteiro de Lista (lista na qual se deve inse
* rir uma palavra; não pode apontar para NULL)
* @param string Ponteiro de char (corresponde à palavra que
* deve ser inserida no fim da lista; não pode apontar para
* NULL ao chamar a função)
*
* \return A função retorna um ponteiro do tipo Lista,
* correspondendo à lista atualizada. Caso o elemento a ser
* inserido já exista na lista, ela é retornada sem
* alterações. Se a string que deve ser inserida na lista
* não existir, a lista é retornada sem alterações. Se a
* lista estiver vazia ao chamar a função, ela é retornada
* sem alterações.
*
* A função funciona corretamente se o ponteiro próximo
* do último elemento da lista aponta para NULL e se o
* ponteiro anterior do último elemento da lista aponta
* para a lista como ela estava antes da inserção desse
* último elemento.
************************************************************/
Lista* InserirFim(Lista *lis, char *string){

	if(lis==NULO){
		return(lis);
	}

	char *verificador = malloc(strlen(string)*sizeof(char));

	/* Chamada do iterador para verificar se a string que se deseja inserir na lista aponta para NULL. */
	verificador = VerificarString(string);
	/* Assertiva para verificar se a string que se deseja inserir na lista aponta para NULL. */
	if(verificador==NULL){
		return(lis);
	}

	Lista *novo; Lista *ant = NULO; Lista *p = lis;

	p = VerificarIgual(lis,string);
	/* Assertiva para verificar o retorno do iterador VerificarIgual */
	if(p==NULO){
		return(lis);
	}
	
	ant = PassarProximo(p);

	novo = CriarNovo();

	novo->string = malloc(100*sizeof(char));
	strcpy(novo->string,string);
	novo->prox = NULO;
	novo->ant = ant;
	ant->prox = novo;
	
	return (lis);
}

/************************************************************
* Objetivo da função: Remover uma palavra do fim de uma
* lista encadeada.
*
* Parâmetros: A função recebe como parâmetros um ponteiro do
* tipo Lista, que corresponde à lista que deve ter seu último
* elemento removido. Esse ponteiro não pode apontar para
* NULL.
*
* Retorno: A função retorna um ponteiro do tipo Lista, que
* corresponde à lista atualizada, sem o seu último elemento.
* Se a lista enviada como parâmetro estiver vazia, ela é
* retornada sem alterações.
*
* A função funciona corretamente se o último elemento da
* lista é o elemento anterior antes da chamada da função.
* Além disso, o ponteiro próximo do último elemento deve
* apontar para NULL e o ponteiro anterior do último
* elemento deve continuar apontando para a lista.
************************************************************/
Lista* RemoverFim(Lista* lis){
	Lista *p=lis, *ant=NULL;
	
	while (p!=NULL){
		ant = p;
		p=p->prox;
	}

	ant->ant->prox = NULL;
	
	free(ant);

	return lis;
}

/********************************************************//**
* \fn Lista* RemoverElemento(Lista *lis, char *string)
* \brief Remover uma palavra de uma lista
* duplamente encadeada.
*
* @param lis Ponteiro de lista duplamente encadeada
* @param string Ponteiro de char (elemento que deve ser remo
* vido)
*
* \return A função retorna um ponteiro para uma lista
* duplamente encadeada, correspondendo à lista atualizada,
* com o elemento removido. Se o elemento a ser removido
* não existe na lista, ela é retornada sem alterações.
* Se a string que deve ser inserida na lista não existir, 
* a lista é retornada sem alterações.
*
* A função funciona corretamente se o elemento passado como
* parâmetro não existe mais na lista após o retorno da
* função.
************************************************************/
Lista* RemoverElemento(Lista *lis, char *string){

	Lista *p = BuscarElemento(lis, string);
	
	/* Assertiva para verificar o retorno da função BuscarElemento. */
	if(p==NULO){
	    
		return NULL;
	}

	if (lis == p){
		lis=p->prox;
	}else{
		p->ant->prox = p->prox;
    }
    
    if(p->prox!=NULL){
        p->prox->ant = p->ant;
    }
    
    free(p);
	
	return lis;
}

/********************************************************//**
* \fn Lista* BuscarElemento(Lista *lis, char *string)
* \brief Buscar uma palavra em uma lista
* duplamente encadeada.
*
* @param lis Ponteiro para lista duplamente encadeada (lista
* em que se deve buscar uma palavra)
* @param string Ponteiro para char (palavra que deve ser bus-
* cada na lista)
*
* \return A função retorna um ponteiro de lista, que
* corresponde ao ponteiro do elemento existente na lista.
* Caso o elemento não exista na lista, a função retorna
* um ponteiro apontando para NULL.
*
* A função funciona corretamente se o retorno for coerente.
* Caso o elemento exista na lista, o ponteiro deve apontar
* para esse elemento. Caso o elemento não exista na lista,
* o ponteiro deve apontar para NULL.
************************************************************/
Lista* BuscarElemento(Lista *lis, char *string){
	Lista *p;
	for(p=lis;p!=NULO;p=p->prox){
		if(strcmp(p->string,string)==0){
			return p;
		}
	}

	return(NULO);
}

/********************************************************//**
* \fn char* BuscarProximo(Lista *lis, char *string)
* \brief Retornar a próxima posição de um
* determinado elemento na lista.
*
* @param lis Ponteiro de lista que precisa ser previamente
* alocado
* @param string Ponteiro de char que precisa ser previamente
* alocado
*
* \return A função retorna um ponteiro de char,
* correspondendo à string da próxima célula da string que
* foi enviada como parâmetro. Caso a string não exista
* na lista, a função retorna um ponteiro NULL.
*
* A função funciona corretamente se os parâmetros
* obedecem às condições de alocação e se o retorno da
* função é a string presente na próxima posição da
* posição da string que foi enviada como parâmetro.
************************************************************/
char* BuscarProximo(Lista *lis, char *string){
    Lista *p;
    for(p=lis;p!=NULO;p=p->prox){
        if(strcmp(p->string,string)==0){
            return (p->prox->string);
        }
    }
    
    return(NULO);
}

/********************************************************//**
* \fn Lista* LerArquivo(FILE *fp)
* \brief Ler um arquivo e armazenar as palavras
* desse arquivo em uma lista duplamente encadeada.
*
* @param fp Ponteiro de arquivo que deve ser previamente aber
* to antes da chamada da função
*
* \return A função retorna um ponteiro de lista, que
* corresponde às palavras do arquivo armazenadas em uma
* lista duplamente encadeada.
*
* A função funciona corretamente se o arquivo estiver no
* formato de uma palavra seguida de um caractere indicando
* uma nova linha. Além disso, o ponteiro do arquivo deve
* estar previamente aberto. O arquivo é então lido, as
* palavras são armazenadas em uma lista e essa lista é
* retornada pela função.
************************************************************/
Lista* LerArquivo(FILE *fp){
	Lista *L;
	char *palavra=NULL;
	int i=1;

	L = CriarLista();
	
	if(fp!=NULL){

	    while(!feof(fp)){
            
            palavra = malloc(100*sizeof(char));
		    fgets(palavra,100,fp);
		    if(i==1){
		        L = InserirInicio(L,palavra);
		    }else{
		        L = InserirFim(L,palavra);
		    }
		
		    i++;
	    }
	}

	return(L);
}

/********************************************************//**
* \fn void EscreverArquivo(Lista *lis, FILE *fp, int choice)
* \brief Escrever uma lista em um arquivo
* texto.
*
* @param lis Ponteiro de lista
* @param fp Ponteiro de arquivo (precisa ser previamente aber
* to)
* @param choice Número inteiro
*
* \return A função não retorna, já que manipula ponteiros
* e escreve diretamente no arquivo. Se o ponteiro do arquivo 
* não estiver previamente aberto, o programa é encerrado com 
* código de execução 1.
*
* A função funciona corretamente se o ponteiro do arquivo
* foi previamente aberto antes de chamar a função.
* Além disso, o arquivo escrito deve conter uma palavra
* por linha, contendo todas as palavras da lista que
* deve ser escrita nele.
************************************************************/
void EscreverArquivo(Lista *lis, FILE *fp, int choice){
	Lista *p=lis;
	
	if(choice==2){
	    for(p=lis;p!=NULO;p=p->prox){
	        fprintf(fp,"%s",p->string);
	    }
    }else{
	   
	    for (p=lis->prox->prox;p!=NULO;p=p->prox){
	    	fprintf(fp,"%s",p->string);
	    }
	}
}
/********************************************************//**
* \fn void LiberarLista(Lista *lis)
* \brief Liberar a memória alocada por uma
* lista duplamente encadeada.
*
* @param lis Ponteiro para lista duplamente encadeada
*
* \return A função retorna void, ou seja, não retorna.
*
* A função funciona corretamente se após a chamada dela,
* o ponteiro de lista fica com sua memória desalocada.
* Além disso, os parâmetros precisam obedecer às condições
* de alocação.
************************************************************/
void LiberarLista(Lista *lis){
   
    Lista *p = lis;

    while(p!=NULL){
        Lista *t = p->prox;
        free(p);
        p=t;

    }
}
