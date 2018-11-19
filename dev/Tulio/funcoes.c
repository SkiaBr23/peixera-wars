/*
PROJETO
Nome: MAXIMILLIAN FAN XAVIER, OTÁVIO ALVES DIAS, RAFAEL DIAS DA COSTA, TÚLIO ABNER DE LIMA
Matrícula: 12/0153271, 12/0131480, 12/0133253, 12/0137194
Curso: Engenharia de Computação
Disciplina: Métodos de Programação
Turma: A
Prof: Jan Mendonça
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "estruturas.h"
#include "engine.h"

/*	--------------------FUNÇÕES DE CRIAÇÃO--------------------	*/
/*
Função responsável para criação de estruturas do tipo CabecaGeral.
REQUISITO: Ter memória suficiente para alocação.
HIPOTESE: A função deve alocar e retornar um ponteiro do tipo CabecaGeral com ponteiros character=NULL e castle=NULL.
*/
CabecaGeral* CriaCabecaGeral () {
	CabecaGeral * novo = (CabecaGeral*) malloc (sizeof(CabecaGeral));
	novo->character = NULL;
	novo->castle = NULL;

	if (novo != NULL) {	/*Verificação de retorno. Analisa se o espaço se memória foi alocado*/
		return novo;
	} else {
		return NULL;
	}
}

/*
Função responsável para criação de estruturas do tipo CabecaPFilas.
REQUISITO: Ter memória suficiente para alocação.
HIPOTESE: A função deve alocar e retornar um ponteiro do tipo CabecaPFilas com ponteiros player e cpu iguais a NULL.
*/
CabecaPFilas* CriaCabecaPFilas () {
	CabecaPFilas * novo = (CabecaPFilas*) malloc (sizeof(CabecaPFilas));
	novo->player = NULL;
	novo->cpu = NULL;

	if (novo != NULL) {	/*Verificação de retorno. Analisa se o espaço se memória foi alocado*/
		return novo;
	} else {
		return NULL;
	}
}

/*
Função responsável para criação de estruturas do tipo Castelo.
REQUISITO: Ter memória suficiente para alocação.
HIPOTESE: A função deve alocar e retornar um ponteiro Castelo com ponteiros quartel,campodetiro,casadaslancas e comercio iguais a NULL. O atributo ouro deve ser incializado com 100.
*/
Castelo* CriaCastelo () {
	Castelo * novo = (Castelo*) malloc (sizeof(Castelo));
	novo->quartel = NULL;
	novo->campodetiro = NULL;
	novo->casadaslancas = NULL;
	novo->comercio = NULL;
	novo->ouro = 100;

	if (novo != NULL) {	/*Verificação de retorno. Analisa se o espaço se memória foi alocado*/
		return novo;
	} else {
		return NULL;
	}
}

/*
Função responsável para criação de estruturas do tipo Unidade.
REQUISITO: Ter memória suficiente para alocação.
HIPOTESE: A função deve retornar um ponteiro de Unidade igual a NULL.
*/
Unidade* CriaUnidade () {
	return NULL;
}

/*
Função responsável para criação de estruturas do tipo Edificio.
REQUISITO: Ter memória suficiente para alocação.
HIPOTESE: A função deve retornar um ponteiro de Edificio igual a NULL.
*/
Edificio* CriaEdificio () {
	return NULL;
}

/*
Função responsável para criação de estruturas do tipo Comercio.
REQUISITO: Ter memória suficiente para alocação.
HIPOTESE: A função deve retornar um ponteiro Comercio igual a NULL.
*/
Comercio* CriaComercio () {
	return NULL;
}

/*	--------------------FUNÇÕES QUE ANALISAM SE UMA LISTA ESTÁ VAZIA--------------------	*/
/*
Função que verifica se uma lista está vazia
REQUISITO: Ter um ponteiro de CabecaGeral alocado na memória.
HIPOTESE: A função deve retornar 1 caso o ponteiro seja igual a NULL(lista vazia) e 0 caso contrário(lista não vazia).
*/
int CabecaGeralVazia(CabecaGeral* lis){
	if(lis==NULL){	/*Se a lista for vazia, retorna 1, caso contrario, retorna 0*/
		return 1;
	}else{
		return 0;
	}
}
/*
Função que verifica se uma lista está vazia.
REQUISITO: Ter um ponteiro de CabecaPFilas alocado na memória.
HIPOTESE: A função deve retornar 1 caso o ponteiro seja igual a NULL(lista vazia) e 0 caso contrário(lista não vazia).
*/
int CabecaPFilasVazia(CabecaPFilas* lis) {
	if(lis==NULL){	/*Se a lista for vazia, retorna 1, caso contrario, retorna 0*/
		return 1;
	}else{
		return 0;
	}
}
/*
Função que verifica se uma lista está vazia.
REQUISITO: Ter um ponteiro de Castelo alocado na memória.
HIPOTESE: A função deve retornar 1 caso o ponteiro seja igual a NULL(lista vazia) e 0 caso contrário(lista não vazia).
*/
int CasteloVazia(Castelo* lis) {
	if(lis==NULL){	/*Se a lista for vazia, retorna 1, caso contrario, retorna 0*/
		return 1;
	}else{
		return 0;
	}
}
/*
Função que verifica se uma lista está vazia.
REQUISITO: Ter um ponteiro de Unidade alocado na memória.
HIPOTESE: A função deve retornar 1 caso o ponteiro seja igual a NULL(lista vazia) e 0 caso contrário(lista não vazia).
*/
int UnidadeVazia(Unidade* lis) {
	if(lis==NULL){	/*Se a lista for vazia, retorna 1, caso contrario, retorna 0*/
		return 1;
	}else{
		return 0;
	}
}
/*
Função que verifica se uma lista está vazia.
REQUISITO: Ter um ponteiro de Comercio alocado na memória.
HIPOTESE: A função deve retornar 1 caso o ponteiro seja igual a NULL(lista vazia) e 0 caso contrário(lista não vazia).
*/
int ComercioVazia(Comercio* lis) {
	if(lis==NULL){	/*Se a lista for vazia, retorna 1, caso contrario, retorna 0*/
		return 1;
	}else{
		return 0;
	}
}

/*
Função que verifica se uma lista está vazia.
REQUISITO: Ter um ponteiro de Edificio alocado na memória.
HIPOTESE: A função deve retornar 1 caso o ponteiro seja igual a NULL(lista vazia) e 0 caso contrário(lista não vazia).
*/
int EdificioVazia(Edificio* lis) {
	if(lis==NULL){	/*Se a lista for vazia, retorna 1, caso contrario, retorna 0*/
		return 1;
	}else{
		return 0;
	}
}

/*	--------------------FUNÇÕES DE INSERÇÃO--------------------	*/

/*
Função de inserção no fim da lista Unidade.
REQUISITOS: Ter um ponteiro de Unidade alocado e enviar informações positivas como argumento da função.
HIPÓTESES: A função deve inserir um novo nó no fim da lista de forma que o ponteiro de próximo seja igual a NULL e o ponteiro de anterior seja igual ao antigo nodo final.
*/
Unidade* InserirUnidadeFinal(Unidade* lis,int vida,int dano,float esquiva,int nivel,int classe){
	Unidade* novo = (Unidade*)malloc(sizeof(Unidade));
	Unidade* aux = lis;
	
	novo->vida = vida;	/*coloca as informações em uma celula auxiliar*/
	novo->dano = dano;
	novo->esquiva = esquiva;
	novo->nivel = nivel;
	novo->classe = classe;
	novo->prox = NULL;
	
	if((classe>=1 && classe<=3) && (vida>0) && (dano>0) && (esquiva>0 && esquiva<1) && ((nivel>0) && (nivel<=3))){	/*verifica a validade das informações enviadas*/
		if(!UnidadeVazia(lis)){	/*se a lista enviada não for nula, insere no fim*/
			while(aux->prox != NULL){/*enquanto o ponteiro de próximo em auxiliar não for nulo, continua com o laço. Objetivo: encontrar a última posição da lista*/
				aux = aux->prox;
			}
			aux->prox = novo;
			novo->ant = aux;

			return lis;
		} else{	/*se a lista enviada for nula, retorna a célula auxiliar*/
			novo->ant = NULL;
			return novo;
		}
	}else{	/*se alguma informação enviada for inválida, retorna a lista sem fazer alterações*/
		return lis;
	}
}

/*	--------------------FUNÇÕES DE REMOÇÃO--------------------	*/

/*
REQUISITOS: Enviar um ponteiro de Unidade alocado em memória.
HIPÓTESES: A função deve retirar o último elemento de uma lista duplamente encadeada. Se a lista for nula, não realiza operação alguma. Se a lista contiver apenas um ou mais elementos, remove o nó final.
*/
Unidade* RemoverUnidadeFinal(Unidade* lis){
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
		}else{
			aux->prox = p->prox;	/*arruma o ponteiro da penúltima posição*/
			free(p);	/*libera o último espaço de memória*/
			return lis;
		}
	}else{
		return NULL;
	}
}



/*	--------------------FUNÇÕES DE INICIALIZAÇÃO--------------------	*/

/*
Função de inicialização de Edificio.
REQUISITO: Enviar informações positivas.
HIPÓTESE: Caso o edificio não exista, a função deve alocar em memória um espaço e incializar os valores. Caso o edificio exista, os valores devem ser apenas atualizados.
*/
Edificio* InicializarEdificio(Edificio* E,int custounidade,int nivel){
	Edificio* novo;
	if(EdificioVazia(E)){	/*se edificio não existir, aloca um espaço de memória*/
		novo = (Edificio*)malloc(sizeof(Edificio));
	}else{
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

/*
Função de inicialização de Comercio.
REQUISITO: Enviar informações positivas.
HIPÓTESE: Caso o comercio não exista, a função deve alocar em memória um espaço e incializar os valores. Caso o comercio exista, os valores devem ser apenas atualizados.
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

/*
Função de verificação de Castelo.
REQUISITO: Enviar ponteiro de Castelo alocado.
HIPÓTESE: A função deve verificar os apontamentos de edificio e comercio em Castelo, certificando que sejam diferentes de nulo. Caso passe no teste, retorna 1, caso contrário, retorna 0.
*/
int VerificarCastelo(Castelo* C){
	if((!EdificioVazia(C->quartel)) && (!EdificioVazia(C->campodetiro)) && (!EdificioVazia(C->casadaslancas)) && (!ComercioVazia(C->comercio))){
		return 1;
	}else{
		return 0;
	}
}

/*
Função de verificação de CabecaGeral.
REQUISITO: Enviar ponteiro de CabecaGeral alocado.
HIPÓTESE: A função deve verificar os apontamentos de castle e character em CabecaGeral, certificando que sejam diferentes de nulo. Caso passe no teste, retorna 1, caso contrário, retorna 0.
*/
int VerificarCabecaGeral(CabecaGeral* CG){
	if((!CasteloVazia(CG->castle)) && (!CabecaPFilasVazia(CG->character))){
		return 1;
	}else{
		return 0;
	}
}

/*
Função de verificação para filas.
REQUISITO: Enviar ponteiro de Unidade alocado.
HIPÓTESE: A função deve verificar se os apontamentos de próximo e anterior das filas de Unidade estão feitos de forma correta.
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

/*
Função de atualização do ouro do Castelo.
REQUISITO: Enviar ponteiro de Castelo alocado e valor de ouro maior ou igual a zero.
HIPÓTESE: A função deve atualizar os valores de ouro do Castelo.
*/
Castelo* AtualizarCasteloOuro(Castelo* C, int ouro){
	Castelo* novo;
	novo = C;
	/*verifica a validade das informações enviadas*/
	if ((novo->ouro + (ouro)) >= 0) {
		novo->ouro = novo->ouro + (ouro);
		return novo;
	} else {
		return C;
	}
}

/*	--------------------FUNÇÕES DA ENGINE--------------------	*/

