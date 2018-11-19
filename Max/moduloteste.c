/*
PROJETO
Nome: MAXIMILLIAN FAN XAVIER, OTÁVIO ALVES DIAS, RAFAEL DIAS DA COSTA, TÚLIO ABNER DE LIMA
Matrícula: 12/0153271, 12/0131480, 12/0133253, 12/0137194
Curso: Engenharia de Computação
Disciplina: Métodos de Programação
Turma: A
Prof: Jan Mendonça
*/

/*Inclusão das bibliotecas que vão ser utilizadas*/
#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "Tests.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

/*Início do programa principal de testes*/
int main () {

	system("clear");
	/*Inicialização das suites de teste*/
	CU_pSuite suite_testes_controlador = NULL;
	CU_pSuite suite_testes_cabecapfilas = NULL;
	CU_pSuite suite_testes_castelo = NULL;
	CU_pSuite suite_testes_unidade = NULL;
	CU_pSuite suite_testes_comercio = NULL;
	CU_pSuite suite_testes_edificio = NULL;
	CU_pSuite suite_testes_estruturas = NULL;
	if (CUE_SUCCESS != CU_initialize_registry()) {
		return CU_get_error();
	}
	/*Adição de uma suite de testes à suite controladora*/
	suite_testes_controlador = CU_add_suite ("Testes do controlador geral", 0, 0);
	if (NULL == suite_testes_controlador) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	/*Adição dos testes à suite de testes controladora*/
	if ((NULL == CU_add_test (suite_testes_controlador, "Teste de criação do controlador do game", teste_cria_controlador)) ||
	    (NULL == CU_add_test (suite_testes_controlador, "Teste de verificação sobre controlador vazio", teste_verifica_controlador_vazio)) ||
	    (NULL == CU_add_test (suite_testes_controlador, "Teste de verificação sobre estruturas internas do controlador", teste_verifica_cabeca_geral_interno))) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/*Adição de uma suite de testes à suite cabeça para filas*/
	suite_testes_cabecapfilas = CU_add_suite ("Testes da cabeça para as filas", 0, 0);
	if (NULL == suite_testes_cabecapfilas) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	/*Adição dos testes à suite de testes de filas para unidades*/
	if ((NULL == CU_add_test (suite_testes_cabecapfilas, "Teste de criação do controlador das filas", teste_cria_cabeca_filas)) ||
	    (NULL == CU_add_test (suite_testes_cabecapfilas, "Teste de verificação sobre cabeça para filas vazia", teste_verifica_cabeca_filas_vazia))) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/*Adição de uma suite de testes à suite castelo*/
	suite_testes_castelo = CU_add_suite ("Testes da estrutura Castelo", 0, 0);
	if (NULL == suite_testes_castelo) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	/*Adição dos testes à suite de testes castelo*/
	if ((NULL == CU_add_test (suite_testes_castelo, "Teste de criação do castelo", teste_cria_castelo)) ||
	    (NULL == CU_add_test (suite_testes_castelo, "Teste de verificação de castelo nulo", teste_castelo_vazio)) ||
	    (NULL == CU_add_test (suite_testes_castelo, "Teste das estruturas do castelo", teste_verifica_castelo_interno)) ||
	    (NULL == CU_add_test (suite_testes_castelo, "Teste para atualizar ouro do castelo", teste_atualiza_ouro_castelo))) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/*Adição de uma suite de testes à suite unidade*/
	suite_testes_unidade = CU_add_suite ("Testes da estrutura Unidade", 0, 0);
	if (NULL == suite_testes_unidade) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	/*Adição dos testes à suite de testes unidade*/
	if ((NULL == CU_add_test (suite_testes_unidade, "Teste de criação de unidade", teste_cria_unidade)) ||
	    (NULL == CU_add_test (suite_testes_unidade, "Teste de verificação de unidade vazia", teste_unidade_vazia)) ||
	    (NULL == CU_add_test (suite_testes_unidade, "Teste de inserção de unidade na lista", teste_insercao_unidade))) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/*Adição de uma suite de testes à suite comercio*/
	suite_testes_comercio = CU_add_suite ("Testes da estrutura Comercio", 0, 0);
	if (NULL == suite_testes_comercio) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	/*Adição dos testes à suite de testes açougue*/
	if ((NULL == CU_add_test (suite_testes_comercio, "Teste de criação de comercio", teste_cria_comercio)) ||
	    (NULL == CU_add_test (suite_testes_comercio, "Teste de verificação de comercio vazio", teste_comercio_vazio)) ||
	    (NULL == CU_add_test (suite_testes_comercio, "Teste de inicialização do comercio", teste_inicializar_comercio))) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/*Adição de uma suite de testes à suite edifício*/
	suite_testes_edificio = CU_add_suite ("Testes da estrutura Edificio", 0, 0);
	if (NULL == suite_testes_edificio) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	/*Adição dos testes à suite de testes edificio*/
	if ((NULL == CU_add_test (suite_testes_edificio, "Teste de criação de edifício", teste_cria_edificio)) ||
	    (NULL == CU_add_test (suite_testes_edificio, "Teste de verificação de edifício vazio", teste_edificio_vazio)) ||
	    (NULL == CU_add_test (suite_testes_edificio, "Teste de inicialização de edifício", teste_inicializar_edificio))) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/*Adição de uma suite de testes à suite estruturas*/
	suite_testes_estruturas = CU_add_suite ("Testes da consistência das estruturas", 0, 0);
	if (NULL == suite_testes_estruturas) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	/*Adição dos testes à suite de testes estruturas*/
	if ((NULL == CU_add_test (suite_testes_estruturas, "Teste de consistência da estrutura Unidade", teste_verifica_estrutura))) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/*Exibição dos resultados e encerramento do programa*/
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
