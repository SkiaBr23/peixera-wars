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
#include <time.h>
#include "estruturas.h"
#include "engine.h"
#include "grafico.h"

#define HUBH 7
#define CASTLEW 40
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

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
Fun��o de interface com o usu�rio.
REQUISITO: N�o h�.
HIP�TESE: A fun��o deve mostrar um menu de sele��o inicial para o jogador.
*/
void Inicia(){
	WINDOW *menuwin = newwin(5, 15, 11, 40);
	int opcao = menu(menuwin);
	

	switch(opcao){
		case 0:
			StartGame(NULL, 1);
			break;
		
		case 1:
			SaveGame();
			Inicia();
			break;
			
		case 2:
			LoadGame();
			break;
			
		case 3:
			creditos(17, 40);
			Inicia();
			break;
		case 4:
			tela_final();
			break;
		
		default:
			Inicia();
	}
}

/*
Fun��o de inicio do jogo.
REQUISITO: Ter espa�o na mem�ria.
HIP�TESE: A fun��o deve chamar todas as fun��es de cria��o e inicializa��o, verificar suas aloca��es e apontamentos e certificar-se que o jogo est� pronto para come�ar.
*/
void StartGame(CabecaGeral* Cabeca, int horda){	/*horda tem que manipular, ver isso depois*/
	int new = 1;
	CabecaGeral* Interface = CriaCabecaGeral();

	if(Cabeca == NULL){
		CriaEstruturas(Interface);
		InicializaEstruturas(Interface,0,25,1,25,1,25,1,100,1);
		new = 1;
	}else{
		Interface = Cabeca;
		new = 0;
	}
	
	/*VERIFICA��O DA INTERFACE*/
	if(VerificaInterface(Interface)){
		Run(Interface,new,horda);
	}
}

/*
Fun��o de salvar o jogo.
REQUISITO: Ter ponteiro de interface devidamente alocado e o jogo inicializado.
HIP�TESE: A fun��o deve gravar as informa��es de atributos dos edif�cios e em que horda o jogador se encontra num arquivo bin�rio.
*/
void SaveGame(CabecaGeral* Interface, int horda){
	FILE* fp1;
	char *saida = (char *) malloc(36*sizeof(char));

	saida = mensagem_entrada(17, 30, "Digite com qual nome voce quer salvar o jogo:");	
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
		mensagem(17, 40, "Jogo salvo com sucesso");
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
	char *entrada = (char *) malloc(36*sizeof(char));
	int ouro,cuQ,nQ,cuCDT,nCDT,cuCDL,nCDL,tC,nC,horda;
	CabecaGeral* Interface = CriaCabecaGeral();

	entrada = mensagem_entrada(17, 30, "Digite seu savegame:");	
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
	StartGame(Interface,horda);
}

/*
Fun��o que evolui um edif�cio do jogo.
REQUISITO: Ponteiro de CabecaGeral alocado e inicializado.
HIP�TESE: A fun��o deve evoluir um determinado edificio e enviar um inteiro, indicando que a evolu��o foi efetuada.
*/
int MenuEvolucaoEdificio(CabecaGeral* Interface){
	int OpcaoEdificio = menu_edificio();
	int EvoluiuEdificio = 0;
	switch(OpcaoEdificio){
		case 1:
			if(Interface->castle->quartel->nivel < 3){
				Interface->castle->quartel->nivel++;
				Interface->castle->quartel->custounidade +=35;
				EvoluiuEdificio=1;
			}
			else
			{
				mensagem(21, 62, "Edificio no nivel maximo.");
			}
			break;
				
		case 2:
			if(Interface->castle->campodetiro->nivel < 3){
				Interface->castle->campodetiro->nivel++;
				Interface->castle->campodetiro->custounidade +=35;
				EvoluiuEdificio=1;
			}
			else
			{
				mensagem(21, 62, "Edificio no nivel maximo.");
			}
			break;

			case 3:
			if(Interface->castle->casadaslancas->nivel < 3){
				Interface->castle->casadaslancas->nivel++;
				Interface->castle->casadaslancas->custounidade +=35;
				EvoluiuEdificio=1;
			}
			else
			{
				mensagem(21, 62, "Edificio no nivel maximo.");
			}
			break;
						
		case 4:
			if(Interface->castle->comercio->nivel < 3){
				Interface->castle->comercio->nivel++;
				Interface->castle->comercio->taxaouro +=100;
				EvoluiuEdificio=1;
			}
			else
			{
				mensagem(21, 62, "Edificio no nivel maximo.");
			}
			break;
						
		default:
			MenuEvolucaoEdificio(Interface);
	}
	
	return EvoluiuEdificio;
}

/*
Fun��o que insere unidades no jogo.
REQUISITO: Ponteiro de CabecaGeral alocado e inicializado.
HIP�TESE: A fun��o deve inserir at� quatro unidades e enviar um inteiro, indicando que a inser��o foi efetuada.
*/
int MenuEscolhaUnidade(CabecaGeral* Interface){			
	int OpcaoUnidade = menu_unidade(Interface->castle);
	int TemDinheiro = 1;
	
	switch(OpcaoUnidade){
		case 1:
			if(Interface->castle->quartel->nivel == 1){
				if(Interface->castle->ouro >= Interface->castle->quartel->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,300,60,0.15,1,1);
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->quartel->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh(); 
				}else{
					mensagem(21, 62, "Nao ha ouro suficiente");
				}
			}
			if(Interface->castle->quartel->nivel == 2){
				if(Interface->castle->ouro >= Interface->castle->quartel->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,400,60,0.15,2,1);				
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->quartel->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh();
				}else{
					mensagem(21, 62, "Nao ha ouro suficiente");
				}
			}
			if(Interface->castle->quartel->nivel == 3){
				if(Interface->castle->ouro >= Interface->castle->quartel->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,500,60,0.15,3,1);				
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->quartel->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh();
				}else{
					mensagem(21, 62, "Nao ha ouro suficiente");
				}
			}

			break;

		case 2:
			if(Interface->castle->campodetiro->nivel == 1){
				if(Interface->castle->ouro >= Interface->castle->campodetiro->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,280,70,0.15,1,2);				
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->campodetiro->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh();
				}else{
					mensagem(21, 62, "Nao ha ouro suficiente");
				}
			}
			if(Interface->castle->campodetiro->nivel == 2){
				if(Interface->castle->ouro >= Interface->castle->campodetiro->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,280,90,0.15,2,2);				
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->campodetiro->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh();
				}else{
					mensagem(21, 62, "Nao ha ouro suficiente");
				}
			}
			if(Interface->castle->campodetiro->nivel == 3){
				if(Interface->castle->ouro >= Interface->castle->campodetiro->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,280,120,0.15,3,2);				
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->campodetiro->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh();
				}else{
					mensagem(21, 62, "Nao ha ouro suficiente");
				}
			}
			break;

		case 3:
			if(Interface->castle->casadaslancas->nivel == 1){
				if(Interface->castle->ouro >= Interface->castle->casadaslancas->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,280,60,0.2,1,3);				
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->casadaslancas->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh();
				}else{
					mensagem(21, 62, "Nao ha ouro suficiente");
				}
			}
			if(Interface->castle->casadaslancas->nivel == 2){
				if(Interface->castle->ouro >= Interface->castle->casadaslancas->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,280,60,0.3,2,3);				
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->casadaslancas->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh();
				}else{
					mensagem(21, 62, "Nao ha ouro suficiente");
				}
			}
			if(Interface->castle->casadaslancas->nivel == 3){
				if(Interface->castle->ouro >= Interface->castle->casadaslancas->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,280,60,0.4,3,3);				
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->casadaslancas->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh();
				}else{
					mensagem(21, 62, "Nao ha ouro suficiente");
				}
			}
			break;

		default:
		MenuEscolhaUnidade(Interface);
	}
	
	return TemDinheiro;
}

/*
Fun��o que integra as demais fun��es do jogo.
REQUISITO: Mem�ria livre para aloca��o, ponteiro de CabecaGeral alocado e inicializado.
HIP�TESE: .
*/
void Run (CabecaGeral* Interface, int new, int wave){
	int horda = 0;	/*diz em qual horda o jogador se encontra*/
	int fim = 0;	/*indica fim de jogo*/
	int newhorda = 1;	/*indica se � o in�cio de uma nova horda*/
	int EvoluiuEdificio = 0;	/*indica se o jogador j� evoluiu um de seus edif�cios*/
	int TemDinheiro = 1;	/*indica se o jogador possui dinheiro suficiente para comprar unidades*/
	int OpcaoEdficio = 0;	/*indica qual edificio o jogador deicidiu evoluir*/
	int GanhouBatalha = 1;	/*indica se o jogador ganhou ou n�o a batalha*/

	WINDOW *winhub = newwin(HUBH,COLS, 0, 0);
	WINDOW *wincastle = newwin(LINES-HUBH, CASTLEW, HUBH,0);
	WINDOW *winfield = newwin(LINES-HUBH, COLS-CASTLEW, HUBH, CASTLEW);
	                        /* (height,width,starty,startx) */
	
	if(!CabecaGeralVazia(Interface)){
		if(new==1){	/*atribui o valor da horda. Caso seja um novo jogo, horda =1, caso seja um Load, horda = wave.*/
			horda = 1;
		}else{
			horda = wave;
		}

		while(fim==0 && (horda>0 && horda<=10)){	/*contagem de hordas*/

			print_hub(winhub,Interface->castle->ouro,horda);
			wrefresh(winhub);

			print_field(winfield);
			wrefresh(winfield);

			print_castle(wincastle, Interface->castle);
			wrefresh(wincastle);

			if(newhorda==1){	/*momento de pausa para o jogador fazer as evolu��es e compras de unidades*/
				while((!TemQuatro(Interface->character->player)) && TemDinheiro==1){	/*limita a quantidade de unidades em jogo para at� 4 e habilita a compra das mesmas*/
					TemDinheiro = MenuEscolhaUnidade(Interface);
					if((Interface->castle->ouro < Interface->castle->quartel->custounidade) && (Interface->castle->ouro < Interface->castle->campodetiro->custounidade) && (Interface->castle->ouro < Interface->castle->casadaslancas->custounidade)) 
					{
						TemDinheiro = 0;
					}
				}
				
				/*RAND PARA INIMIGO(Cria��o das unidades inimigas, s�o 2 rands, 1 para a classe e 1 para o nivel)*/
				newhorda = 0;
			}

			/*batalha*/

			while(EvoluiuEdificio==0 && horda<9){	/*a partir da segunda horda j� � poss�vel fazer evolu��es dos edif�cios*/
					EvoluiuEdificio = MenuEvolucaoEdificio(Interface);
					GanhouBatalha = 0;
			}
			horda++;	/*avan�a para a pr�xima horda*/
			EvoluiuEdificio = 0;	/*d� um ponto de evolu��o para o jogador*/
			Interface->castle->ouro += Interface->castle->comercio->taxaouro;	/*credita o ouro*/
			newhorda = 1;
			TemDinheiro = 1;
			while(!UnidadeVazia(Interface->character->player)){	/*remove todas as unidades da lista de jogador*/
				Interface->character->player = RemoverUnidadeFinal(Interface->character->player);
			}
		tela_final();
		}
	}
}

/*
Fun��o que que verifica se h� quatro elementos em uma lista.
REQUISITO: Ponteiro de Unidade alocado.
HIP�TESE: A fun��o conta quantos elementos existem em uma lista e unidades e retorna 1 caso o somat�rio atinja o valor 4.
*/
int TemQuatro(Unidade* lista){
 Unidade* p;
 int i = 0;

 if(!UnidadeVazia(lista)){
  for(p=lista;p!=NULL;p=p->prox){
   i++;
   if(i==4){
    return 1;
   }
  }
 }
 return 0;
}

/*
Fun��o que que verifica se h� quatro elementos em uma lista.
REQUISITO: Mem�ria livre.
HIP�TESE: A fun��o deve gerar valores aleat�rios para n�vel e classe das unidades inimigas.
*/

int GerarValor(){
 int valor = 0;

 srand(time(NULL));
 valor = rand() % 3+1;

return valor;
}