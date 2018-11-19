/*
PROJETO
Nome: MAXIMILLIAN FAN XAVIER, OT�VIO ALVES DIAS, RAFAEL DIAS DA COSTA, T�LIO ABNER DE LIMA
Matr�cula: 12/0153271, 12/0131480, 12/0133253, 12/0137194
Curso: Engenharia de Computa��o
Disciplina: M�todos de Programa��o
Turma: A
Prof: Jan Mendon�a
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "estruturas.h"
#include "engine.h"

/*	--------------------FUN��ES DA ENGINE--------------------	*/

/*
Fun��o de cria��o das estruturas.
REQUISITO: Ter ponteiro de interface devidamente alocado e mem�ria livre.
HIP�TESE: A fun��o deve 
*/
void CriaEstruturas(CabecaGeral* Interface){
	if(Interface!=NULL){
		/*CRIA��O DAS CABE�AS*/
		Interface->character = CriaCabecaPFilas();
		Interface->castle = CriaCastelo();

		/*CRIA��O DAS LISTAS DE UNIDADES*/
		Interface->character->player = CriaUnidade();
		Interface->character->cpu = CriaUnidade();
		
		/*CRIA��O DOS EDIF�CIOS*/
		Interface->castle->quartel = CriaEdificio();
		Interface->castle->campodetiro = CriaEdificio();	
		Interface->castle->casadaslancas = CriaEdificio();
		Interface->castle->comercio = CriaComercio();	
	}
}


/*
Fun��o de inicializa��o das estruturas.
REQUISITO: Ter ponteiros de interface,castelo e filas devidamente alocados.
HIP�TESE: A fun��o deve atribuir valores iniciais para um jogo prestes a ser inicializado caso o status seja 0, se status � 1, atribui os valores enviados como par�metro.
*/
void InicializaEstruturas(CabecaGeral* Interface,int status,int cuQ,int nQ,int cuCDT,int nCDT,int cuCDL,int nCDL,int tC,int nC){
	if(Interface!=NULL){
		if(status == 0){
			Interface->castle->quartel = InicializarEdificio(Interface->castle->quartel,25,1);
			Interface->castle->campodetiro = InicializarEdificio(Interface->castle->campodetiro,25,1);
			Interface->castle->casadaslancas = InicializarEdificio(Interface->castle->casadaslancas,25,1);
			Interface->castle->comercio = InicializarComercio(Interface->castle->comercio,100,1);
		}
		if(status == 1){
			if((nQ>0 && nQ<=3) && (nCDT>0 && nCDT<=3) && (nCDL>0 && nCDL<=3) && (nC>0 && nC<=3)){
				Interface->castle->quartel = InicializarEdificio(Interface->castle->quartel,cuQ,nQ);
				Interface->castle->campodetiro = InicializarEdificio(Interface->castle->campodetiro,cuCDT,nCDT);
				Interface->castle->casadaslancas = InicializarEdificio(Interface->castle->casadaslancas,cuCDL,nCDL);
				Interface->castle->comercio = InicializarComercio(Interface->castle->comercio,tC,nC);
			}
		}
	}
}

/*
Fun��o verifica��o das estruturas.
REQUISITO: Ter ponteiro de interface devidamente alocado.
HIP�TESE: A fun��o deve verificar se a interface foi inicializada corretamente. Caso esteja tudo bem, retorna 1, caso contr�rio, retorna 0.
*/
int VerificaInterface(CabecaGeral* Interface){
	if((VerificarCabecaGeral(Interface)) && (VerificarCastelo(Interface->castle))){
		return 1;
	}else{
		return 0;
	}
}

/*
Fun��o de inicio do jogo.
REQUISITO: Ter espa�o na mem�ria.
HIP�TESE: A fun��o deve chamar todas as fun��es de cria��o e inicializa��o, verificar suas aloca��es e apontamentos e certificar-se que o jogo est� pronto para come�ar.
*/
CabecaGeral* StartGame(CabecaGeral* Cabeca, int horda){
	CabecaGeral* Interface = CriaCabecaGeral();

	if(Cabeca == NULL){
		CriaEstruturas(Interface);
		InicializaEstruturas(Interface,0,25,1,25,1,25,1,100,1);
		
	}else{
		Interface = Cabeca;
	}
	
	/*VERIFICA��O DA INTERFACE*/
	if(VerificaInterface(Interface)){
		printf("\nJOGO INICIALIZADO COM SUCESSO\n");
		printf("%d,%d\n",Interface->castle->comercio->taxaouro,Interface->castle->comercio->nivel);
		printf("%d,%d,%d,%d,%d,%d\n",Interface->castle->quartel->custounidade,Interface->castle->quartel->nivel,Interface->castle->campodetiro->custounidade,Interface->castle->campodetiro->nivel,Interface->castle->casadaslancas->custounidade,Interface->castle->casadaslancas->nivel);
	}else{
		printf("\nNAO FOI POSSIVEL INICIALIZAR O JOGO\n");
	}
	
	return Interface;
}

/*
Fun��o de salvar o jogo.
REQUISITO: Ter ponteiro de interface devidamente alocado e o jogo inicializado.
HIP�TESE: A fun��o deve gravar as informa��es de atributos dos edif�cios e em que horda o jogador se encontra num arquivo bin�rio.
*/
void SaveGame(CabecaGeral* Interface, int horda){
	FILE* fp1;
	char saida[100];
	
	printf("\nDigite o nome do arquivo: \n");
	scanf(" %[^\n]s",saida);
	strcat(saida,".bin");
	
	fp1 = fopen(saida,"w+b");
	
	if((horda>0 && horda<=10) && (!CabecaGeralVazia(Interface))){
		fwrite(&Interface->castle->ouro,sizeof(int),1,fp1);
		fwrite(&Interface->castle->quartel->custounidade,sizeof(int),1,fp1);
		fwrite(&Interface->castle->quartel->nivel,sizeof(int),1,fp1);
		fwrite(&Interface->castle->campodetiro->custounidade,sizeof(int),1,fp1);
		fwrite(&Interface->castle->campodetiro->nivel,sizeof(int),1,fp1);
		fwrite(&Interface->castle->casadaslancas->custounidade,sizeof(int),1,fp1);
		fwrite(&Interface->castle->casadaslancas->nivel,sizeof(int),1,fp1);
		fwrite(&Interface->castle->comercio->taxaouro,sizeof(int),1,fp1);
		fwrite(&Interface->castle->comercio->nivel,sizeof(int),1,fp1);
		fwrite(&horda,sizeof(int),1,fp1);
		printf("\nJogo salvo com sucesso\n");
	}
	fclose(fp1);
}


/*
Fun��o de carregar um jogo salvo.
REQUISITO: Ter um arquivo bin�rio a ser lido e mem�ria livre para aloca��o.
HIP�TESE: A fun��o deve ler as informa��es de um arquivo bin�ro e atribuir os valores nos devidos ponteiros de edificios e informa��es no geral.
*/
void LoadGame(){
	FILE* fp1;
	char entrada[100];
	int ouro,cuQ,nQ,cuCDT,nCDT,cuCDL,nCDL,tC,nC,horda;
	CabecaGeral* Interface = CriaCabecaGeral();

	printf("\nDigite o nome do arquivo: \n");
	scanf(" %[^\n]s",entrada);
	strcat(entrada,".bin");
	fp1 = fopen(entrada,"r+b");
	fread(&ouro,sizeof(int),1,fp1);
	fread(&cuQ,sizeof(int),1,fp1);
	fread(&nQ,sizeof(int),1,fp1);
	fread(&cuCDT,sizeof(int),1,fp1);
	fread(&nCDT,sizeof(int),1,fp1);
	fread(&cuCDL,sizeof(int),1,fp1);
	fread(&nCDL,sizeof(int),1,fp1);
	fread(&tC,sizeof(int),1,fp1);
	fread(&nC,sizeof(int),1,fp1);
	fread(&horda,sizeof(int),1,fp1);
	fclose(fp1);
	
	CriaEstruturas(Interface);
	InicializaEstruturas(Interface,1,cuQ,nQ,cuCDT,nCDT,cuCDL,nCDL,tC,nC);

}

