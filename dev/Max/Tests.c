/*
PROJETO
Nome: MAXIMILLIAN FAN XAVIER, OTÁVIO ALVES DIAS, RAFAEL DIAS DA COSTA, TÚLIO ABNER DE LIMA
Matrícula: 12/0153271, 12/0131480, 12/0133253, 12/0137194
Curso: Engenharia de Computação
Disciplina: Métodos de Programação
Turma: A
Prof: Jan Mendonça
*/

/*Declaração das bibliotecas que vão ser utilizadas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

/*----------------------------------------------------------------------------------------------------------------------------------------*/
/*Teste das funções utilizadas na estrutura de polinômio*/

/*Função de teste de criação do polinômio*/
void teste_cria_controlador(void){
	CabecaGeral * p;
	p = CriaCabecaGeral();
	/*Verifica se o ponteiro aponta pra NULL*/
	CU_ASSERT_PTR_NOT_NULL(p);
}

void teste_verifica_controlador_vazio (void) {
	CabecaGeral * p;
	p = NULL;
	int i;
	i = CabecaGeralVazia (p);

	CU_ASSERT_EQUAL (i, 1);

	p = CriaCabecaGeral ();
	i = CabecaGeralVazia (p);

	CU_ASSERT_EQUAL (i, 0);
}

void teste_verifica_cabeca_geral_interno (void) {
	CabecaGeral * p;
	p = CriaCabecaGeral ();
	
	int i;
	i = VerificarCabecaGeral (p);

	CU_ASSERT_EQUAL (i,0);

	p->castle = CriaCastelo ();
	p->character = CriaCabecaPFilas ();

	i = VerificarCabecaGeral (p);
	
	CU_ASSERT_EQUAL (i, 1);
}

/*--------------------------------------------------------------------------------------------------------------------------------*/
/*Funcões da cabeça para filas*/
void teste_cria_cabeca_filas (void) {
	CabecaPFilas * p;
	p = CriaCabecaPFilas ();

	CU_ASSERT_PTR_NOT_NULL (p);
}

void teste_verifica_cabeca_filas_vazia (void) {
	CabecaPFilas * p;
	p = NULL;
	
	int i;

	i = CabecaPFilasVazia (p);

	CU_ASSERT_EQUAL (i, 1);

	p = CriaCabecaPFilas ();

	i = CabecaPFilasVazia (p);

	CU_ASSERT_EQUAL (i, 0);
}

/*--------------------------------------------------------------------------------------------------------------------------------*/
/*Funcões do Castelo*/

void teste_cria_castelo (void) {
	Castelo * p;
	p = CriaCastelo ();
	
	CU_ASSERT_PTR_NOT_NULL (p);
}

void teste_castelo_vazio (void) {
	Castelo * p;
	p = NULL;

	int i;
	i = CasteloVazia (p);
	CU_ASSERT_EQUAL (i, 1);

	p = CriaCastelo ();
	
	i = CasteloVazia(p);
	CU_ASSERT_EQUAL (i, 0);
}

void teste_verifica_castelo_interno (void) {
	Castelo * p;
	int i;
	p = CriaCastelo ();
	i = VerificarCastelo (p);

	CU_ASSERT_EQUAL (i, 0);

	p->quartel = InicializarEdificio (p->quartel, 1, 1, 1);
	p->casadaslancas = InicializarEdificio (p->casadaslancas, 1, 1, 1);
	p->campodetiro = InicializarEdificio (p->campodetiro, 1, 1, 1);
	p->comercio = InicializarComercio (p->comercio, 1, 1);
	
	i = VerificarCastelo (p);

	CU_ASSERT_EQUAL (i, 1);
}

void teste_atualiza_ouro_castelo (void) {
	Castelo * p;
	p = CriaCastelo ();

	p = AtualizarCasteloOuro (p, 200);
	
	CU_ASSERT_EQUAL (p->ouro, 300);

	p = AtualizarCasteloOuro (p, -301);

	CU_ASSERT_EQUAL (p->ouro, 300);
}

/*--------------------------------------------------------------------------------------------------------------------------------*/
/*Funcões da Unidade*/

void teste_cria_unidade (void) {
	Unidade * p;
	p = CriaUnidade ();
	
	CU_ASSERT_PTR_NULL (p);
}

void teste_unidade_vazia (void) {
	Unidade * p;
	p = CriaUnidade ();

	int i;

	i = UnidadeVazia (p);

	CU_ASSERT_EQUAL (i, 1);

	p = InserirUnidadeFinal (p, 1, 1, 0.5, 1,1);

	i = UnidadeVazia (p);

	CU_ASSERT_EQUAL (i, 0);
}

void teste_insercao_unidade (void) {
	Unidade * p;
	Unidade * t;
	p = CriaUnidade ();


	p = InserirUnidadeFinal (p, 1, 2, 0.3, 3,1);
	p = InserirUnidadeFinal (p, 2, 2, 0.4, 3,1);
	p = InserirUnidadeFinal (p, 3, 2, 0.5, 3,1);
	p = InserirUnidadeFinal (p, 4, 2, 0.6, 3,1);


	int i = 0;

	for (t = p; t != NULL; t = t->prox) {
		if (i == 0) {
			CU_ASSERT_EQUAL (t->vida, 1);
		}
		if (i == 1) {
			CU_ASSERT_EQUAL (t->vida, 2);
		}
		if (i == 2) {
			CU_ASSERT_EQUAL (t->vida, 3);
		}
		if (i == 3) {
			CU_ASSERT_EQUAL (t->vida, 4);
		}
		i++;
	}
}

/*--------------------------------------------------------------------------------------------------------------------------------*/
/*Funcões da Comercio*/

void teste_cria_comercio (void) {
	Comercio* p;
	p = CriaComercio ();

	CU_ASSERT_PTR_NULL (p);
}

void teste_comercio_vazio (void) {
	Comercio* p;
	p = NULL;

	int i;
	i = ComercioVazia (p);

	CU_ASSERT_EQUAL (i, 1);

	p = InicializarComercio (p, 1, 1);

	i = ComercioVazia (p);

	CU_ASSERT_EQUAL (i, 0);
}

void teste_inicializar_comercio (void) {
	Comercio* p;
	p = CriaComercio ();
	
	p = InicializarComercio (p, 1, 2);

	CU_ASSERT_EQUAL (p->taxaouro, 1);
	CU_ASSERT_EQUAL (p->nivel, 2);

}

/*--------------------------------------------------------------------------------------------------------------------------------*/
/*Funcões de Edifício*/

void teste_cria_edificio (void) {
	Edificio * p;
	p = CriaEdificio ();

	CU_ASSERT_PTR_NULL (p);
}

void teste_edificio_vazio (void) {
	Edificio * p;
	p = CriaEdificio ();

	int i;
	i = EdificioVazia (p);
	
	CU_ASSERT_EQUAL (i, 1);

	p = InicializarEdificio (p, 1, 1);

	i = EdificioVazia (p);

	CU_ASSERT_EQUAL (i, 0);
}

void teste_inicializar_edificio (void) {
	Edificio * p;
	p = CriaEdificio ();

	p = InicializarEdificio (p, 10, 1);

	CU_ASSERT_EQUAL (p->custounidade, 10);
	CU_ASSERT_EQUAL (p->nivel, 1);
}

void teste_verifica_estrutura (void) {
	int i;
	Unidade * p;
	p = CriaUnidade ();

	p = InserirUnidadeFinal (p, 100, 50, 0.2, 2,1);
	p = InserirUnidadeFinal (p, 50, 78, 0.2, 3,1);
	p = InserirUnidadeFinal (p, 10, 54, 0.1, 3,1);
	p = InserirUnidadeFinal (p, 11, 34, 0.2, 1,1);
	p = InserirUnidadeFinal (p, 60, 44, 0.1, 1,1);
	p = InserirUnidadeFinal (p, 33, 67, 0.2, 1,1);
	p = InserirUnidadeFinal (p, 12, 90, 0.1, 3,1);

	i = VerificaEstrutura (p);

	CU_ASSERT_EQUAL (i, 1);	
}
