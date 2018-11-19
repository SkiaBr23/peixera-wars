#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

int main(){

	CabecaGeral* cabeca = CriaCabecaGeral();
	cabeca->character = CriaCabecaPFilas();
	cabeca->castle = CriaCastelo();
	cabeca->character->fila1 = CriaUnidade();
	
	printf("\nINSERINDO UNIDADE\n");
		cabeca->character->fila1 = InserirUnidadeFinal(cabeca->character->fila1,10,20,40,2);
	cabeca->character->fila1 = InserirUnidadeFinal(cabeca->character->fila1,1,2,4,3);

	printf("\nINSERIU\n");
	if(VerificaEstrutura(cabeca->character->fila1)){
		printf("\nESTRUTURA VERIFICADA\n");
	}else{
		printf("\nESTRUTURA NAO VERIFICADA\n");
	}

	printf("\nREMOVENDO\n");
	cabeca->character->fila1 = RemoverUnidadeFinal(cabeca->character->fila1);
	
	if(cabeca->character->fila1!=NULL){
		printf("\nVALORES:%d\n",cabeca->character->fila1->nivel);
	}else{
		printf("\nVAZIA\n");
	}
	

return 0;
}