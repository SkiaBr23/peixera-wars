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
			LoadGame();
			break;
			
		case 2:
			creditos(17, 40);
			Inicia();
			break;
		case 3:
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
void StartGame(CabecaGeral* Cabeca, int horda){
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
	char saida[9] = "save.bin";
	
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
	char entrada[9] = "save.bin";
	int ouro,cuQ,nQ,cuCDT,nCDT,cuCDL,nCDL,tC,nC,horda;
	CabecaGeral* Interface = CriaCabecaGeral();

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
	
	switch(OpcaoUnidade){
		case 1:
			if(Interface->castle->quartel->nivel == 1){
				if(Interface->castle->ouro >= Interface->castle->quartel->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,300,60,0.15,1,1);
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->quartel->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh(); 
				}else{
					mensagem(22, 62, "Nao ha ouro suficiente");
					return 1;
				}
			}
			if(Interface->castle->quartel->nivel == 2){
				if(Interface->castle->ouro >= Interface->castle->quartel->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,400,60,0.15,2,1);				
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->quartel->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh();
				}else{
					mensagem(22, 62, "Nao ha ouro suficiente");
					return 1;
				}
			}
			if(Interface->castle->quartel->nivel == 3){
				if(Interface->castle->ouro >= Interface->castle->quartel->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,500,60,0.15,3,1);				
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->quartel->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh();
				}else{
					mensagem(22, 62, "Nao ha ouro suficiente");
					return 1;
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
					mensagem(22, 62, "Nao ha ouro suficiente");
					return 1;
				}
			}
			if(Interface->castle->campodetiro->nivel == 2){
				if(Interface->castle->ouro >= Interface->castle->campodetiro->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,280,90,0.15,2,2);				
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->campodetiro->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh();
				}else{
					mensagem(22, 62, "Nao ha ouro suficiente");
					return 1;
				}
			}
			if(Interface->castle->campodetiro->nivel == 3){
				if(Interface->castle->ouro >= Interface->castle->campodetiro->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,280,120,0.15,3,2);				
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->campodetiro->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh();
				}else{
					mensagem(22, 62, "Nao ha ouro suficiente");
					return 1;
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
					mensagem(22, 62, "Nao ha ouro suficiente");
					return 1;
				}
			}
			if(Interface->castle->casadaslancas->nivel == 2){
				if(Interface->castle->ouro >= Interface->castle->casadaslancas->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,280,60,0.3,2,3);				
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->casadaslancas->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh();
				}else{
					mensagem(22, 62, "Nao ha ouro suficiente");
					return 1;
				}
			}
			if(Interface->castle->casadaslancas->nivel == 3){
				if(Interface->castle->ouro >= Interface->castle->casadaslancas->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,280,60,0.4,3,3);				
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->casadaslancas->custounidade));
					mvprintw(2, 91, "%d    ", Interface->castle->ouro);
					refresh();
				}else{
					mensagem(22, 62, "Nao ha ouro suficiente");
					return 1;
				}
			}
			break;

		default:
		MenuEscolhaUnidade(Interface);
	}
	return 0;
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
	int mensagem = 0;
	int i;

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
		print_hub(winhub,Interface->castle->ouro,horda);
		wrefresh(winhub);

		print_field(winfield, Interface->character);
		wrefresh(winfield);

		print_castle(wincastle, Interface->castle);
		wrefresh(wincastle);





		while(fim==0 && (horda>0 && horda<=10)){	/*contagem de hordas*/

			srand(time(NULL));

			print_hub(winhub,Interface->castle->ouro,horda);
			wrefresh(winhub);

			print_field(winfield, Interface->character);
			wrefresh(winfield);

			print_castle(wincastle, Interface->castle);
			wrefresh(wincastle);







			if(newhorda==1){	/*momento de pausa para o jogador fazer as evolu��es e compras de unidades*/
				while((!TemQuatro(Interface->character->player)) && TemDinheiro==1){	/*limita a quantidade de unidades em jogo para at� 4 e habilita a compra das mesmas*/
					mensagem = MenuEscolhaUnidade(Interface);
					if((Interface->castle->ouro < Interface->castle->quartel->custounidade) && (Interface->castle->ouro < Interface->castle->campodetiro->custounidade) && (Interface->castle->ouro < Interface->castle->casadaslancas->custounidade)) 
					{
						TemDinheiro = 0;
					}
					if (mensagem == 0)
					{
						print_field(winfield, Interface->character);
						wrefresh(winfield);
					}
				}
				for (i = 0; i < 4; i++)
				{
					InsereUnidadeInimiga(Interface);
					usleep(400000);
					print_field(winfield, Interface->character);
					wrefresh(winfield);
				}
				newhorda = 0;
			}

			/*batalha*/
			fim = Batalha(Interface, winfield);



			if (fim == 0)
			{
				Interface->character->player = LimpaLista(Interface->character->player);
				print_field(winfield, Interface->character);
				wrefresh(winfield);

				while(EvoluiuEdificio==0 && horda<9){	/*a partir da segunda horda j� � poss�vel fazer evolu��es dos edif�cios*/
						EvoluiuEdificio = MenuEvolucaoEdificio(Interface);
				}
				horda++;	/*avan�a para a pr�xima horda*/
				EvoluiuEdificio = 0;	/*d� um ponto de evolu��o para o jogador*/
				Interface->castle->ouro += Interface->castle->comercio->taxaouro;	/*credita o ouro*/
				newhorda = 1;
				TemDinheiro = 1;
			}

		}
		tela_final();
	}
}


int Batalha(CabecaGeral *Interface, WINDOW *winfield)
{
	int fim = 0;
	int i = 1;
	int j = 1;
	char c = '\0';
	Unidade *player;
	Unidade *cpu= Interface->character->cpu;

	for (player = Interface->character->player; player!=NULL; player = player->prox, cpu= Interface->character->cpu, i++)
	{
		seta_batalha(winfield, 2, i);
		seta_batalha(winfield, 1, 1);

		while(c != 10)
		{       
			c = getch();
			switch(c)
	        {	
	        	case 'm':
	        		tela_inicial();
	        	case 's':
	        		if (cpu->prox!=NULL)
	        		{
	        			cpu = cpu->prox;
	        			j++;
	        			seta_batalha(winfield, 1, j);
						wrefresh(winfield);
	        		}
					break;
				case 'w':
					if (cpu->ant!=NULL)
	        		{
	        			cpu = cpu->ant;
	        			j--;
	        			seta_batalha(winfield, 1, j);
					wrefresh(winfield);
	        		}
					break;
				case 10:	/* Enter */
					Interface->character->cpu = Atacar(player, cpu);
					print_field(winfield, Interface->character);
					wrefresh(winfield);
					break;
					
			}
		}
		c = '\0';
		seta_batalha(winfield, 0, 0);
		wrefresh(winfield);
		j = 1;
	}

	return fim;
}


Unidade *Atacar(Unidade *atacante, Unidade *vitima)
{
	float esquiva;
	Unidade *aux;
	int dano;
	for (aux=vitima; aux->ant!=NULL; aux=aux->ant);

	esquiva = (float)GerarValor(101, 0)/100;

	if ((esquiva>vitima->esquiva))
	{
		dano = (atacante->dano + GerarValor(21, -10));
		vitima->vida -= dano;
		mensagem(20, 75, "Foi super efetivo!");
		sleep(1);
		if (vitima->vida<=0)
		{
			aux = RemoverUnidade(aux, vitima);
		}
	}
	else
	{
		mensagem(20, 75, "Nao foi efetivo!");
		sleep(1);
	}
	return aux;
}



/*
Fun��o que que verifica se h� quatro elementos em uma lista.
REQUISITO: Ponteiro de Unidade alocado.
HIP�TESE: A fun��o conta quantos elementos existem em uma lista de unidades e retorna 1 caso o somat�rio atinja o valor 4.
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
Fun��o que que gera valores aleat�rios entre 1 e 3.
REQUISITO: N�o h�.
HIP�TESE: A fun��o deve gerar valores aleat�rios para classe das unidades inimigas.
*/

int GerarValor(int a, int b){
	int valor = 0;

 	valor = rand() % a+b;

return valor;
}

/*
Fun��o que insere unidades inimigas no jogo.
REQUISITO: Ponteiro de CabecaGeral alocado e inicializado.
HIP�TESE: A fun��o deve inserir at� quatro unidades inimigas com n�vel e classe de acordo com valores gerados aleatoriamente.
*/

void InsereUnidadeInimiga(CabecaGeral* Interface, int horda){   
 int OpcaoUnidade = GerarValor(3, 1);
 int OpcaoNivel = GerarNivel(horda);
 
	switch(OpcaoUnidade){
  		case 1:
   			if(OpcaoNivel==1){
     			Interface->character->cpu = InserirUnidadeFinal(Interface->character->cpu,300,60,0.15,1,1);
   			}
			if(OpcaoNivel == 2){
			    Interface->character->cpu = InserirUnidadeFinal(Interface->character->cpu,400,60,0.15,2,1);    
			}
			if(OpcaoNivel == 3){
			    Interface->character->cpu = InserirUnidadeFinal(Interface->character->cpu,500,60,0.15,3,1);    
			}
   			break;

  		case 2:
   			if(OpcaoNivel == 1){
     			Interface->character->cpu = InserirUnidadeFinal(Interface->character->cpu,280,70,0.15,1,2);    
   			}
   			if(OpcaoNivel == 2){
     			Interface->character->cpu = InserirUnidadeFinal(Interface->character->cpu,280,90,0.15,2,2);    
   			}
   			if(OpcaoNivel == 3){
     			Interface->character->cpu = InserirUnidadeFinal(Interface->character->cpu,280,120,0.15,3,2);    
    			}
   			break;

  		case 3:
   			if(OpcaoNivel == 1){
     			Interface->character->cpu = InserirUnidadeFinal(Interface->character->cpu,280,60,0.2,1,3);    
   			}
   			if(OpcaoNivel == 2){
     			Interface->character->cpu = InserirUnidadeFinal(Interface->character->cpu,280,60,0.3,2,3);    
   			}
   			if(OpcaoNivel == 3){
     			Interface->character->cpu = InserirUnidadeFinal(Interface->character->cpu,280,60,0.4,3,3);    
   			}
   			break;

  		default:
  			MenuEscolhaUnidade(Interface);
 	}
}

/*
Fun��o que que gera valores aleat�rios entre 1 e 3.
REQUISITO: Receber o valor de horda entre 1 e 10.
HIP�TESE: A fun��o deve gerar valores aleat�rios para n�vel das unidades inimigas.
*/

int GerarNivel(int horda)
{
	if (horda>=1 && horda<10)
	{
		switch(horda){
			case 1:
				return 1;
			case 2:
				return 1;
			case 3:
				return rand()%2+1;
			case 4:
				return 2;
			case 5:
				return rand()%2+2;
			case 6:
				return rand()%2+2;
			case 7:
				return 3;
			case 8:
				return 3;
			case 9:
				return 3;
		}
	}
	return 1;
}
