/*
PROJETO
Nome: MAXIMILLIAN FAN XAVIER, OTÁVIO ALVES DIAS, RAFAEL DIAS DA COSTA, TÚLIO ABNER DE LIMA
Matrícula: 12/0153271, 12/0131480, 12/0133253, 12/0137194
Curso: Engenharia de Computação
Disciplina: Métodos de Programação
Turma: A
Prof: Jan Mendonça
*/

/*INCLUSÃO DE BIBLIOTECAS*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <unistd.h>
#include "estruturas.h"
#include "engine.h"
#include "grafico.h"

/*DEFINIÇÃO DE CONSTANTES*/
#define HUBH 7
#define CASTLEW 40
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

/*	--------------------FUNÇÕES DA ENGINE--------------------	*/

/*
Função de criação das estruturas.
REQUISITO: Ter ponteiro de interface devidamente alocado e memória livre.
HIPÓTESE: A função deve criar todas as estruturas básicas e seus apontamentos.
ASSERTIVAS DE ENTRADA: A estrutura controladora precisa ter sido alocada.
ASSERTIVAS DE SAÍDA: Não há.
INTERFACE EXPLÍCITA: O tipo de retorno void e o parâmetro de entrada CabecaGeral* Interface.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
*/
void CriaEstruturas(CabecaGeral* Interface){
	if(Interface!=NULL){
		/*CRIAÇÃO DAS CABEÇAS*/
		Interface->character = CriaCabecaPFilas();
		Interface->castle = CriaCastelo();
	
		/*CRIAÇÃO DAS LISTAS DE UNIDADES*/
		Interface->character->player = CriaUnidade();
		Interface->character->cpu = CriaUnidade();
		
		/*CRIAÇÃO DOS EDIFÍCIOS*/
		Interface->castle->quartel = CriaEdificio();
		Interface->castle->campodetiro = CriaEdificio();	
		Interface->castle->casadaslancas = CriaEdificio();
		Interface->castle->comercio = CriaComercio();	
	}
}

/*
Função de inicialização das estruturas.
REQUISITO: Ter ponteiros de interface,castelo e filas devidamente alocados.
HIPÓTESE: A função deve atribuir valores iniciais para um jogo prestes a ser inicializado caso o status seja 0, se status é 1, atribui os valores enviados como parâmetro.
ASSERTIVAS DE ENTRADA: A estrutura controladora enviada para a função precisa ter sido alocada. A variavel status precisa obedecer os padrões, ser o valor inteiro 0 ou o valor inteiro 1. Os valores das variáveis de inicialização precisam estar de acordo com o game.
ASSERTIVAS DE SAÍDA: Não há.
INTERFACE EXPLÍCITA: O tipo de retorno void e os parâmetros de entrada.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
*/
void InicializaEstruturas(CabecaGeral* Interface,int status,int cuQ,int nQ,int cuCDT,int nCDT,int cuCDL,int nCDL,int tC,int nC){
	if(Interface!=NULL){	/*verifica se a interface é nula*/
		if(status == 0){	/*se o jogo for inicializado, atribui os valores iniciais*/
			Interface->castle->quartel = InicializarEdificio(Interface->castle->quartel,25,1);
			Interface->castle->campodetiro = InicializarEdificio(Interface->castle->campodetiro,25,1);
			Interface->castle->casadaslancas = InicializarEdificio(Interface->castle->casadaslancas,25,1);
			Interface->castle->comercio = InicializarComercio(Interface->castle->comercio,100,1);
		}
		if(status == 1){/*se o jogo foi carregado, atribui os valores lidos do arquivo binário*/
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
Função verificação das estruturas.
REQUISITO: Ter ponteiro de interface devidamente alocado.
HIPÓTESE: A função deve verificar se a interface foi inicializada corretamente. Caso esteja tudo bem, retorna 1, caso contrário, retorna 0.
ASSERTIVAS DE ENTRADA: A estrutura controladora enviada para a função precisa ter sido declarada.
ASSERTIVAS DE SAÍDA: Se nenhuma das estruturas for nula, retorna 1, caso contrário, retorna 0.
INTERFACE EXPLÍCITA: O retorno int e o parâmetro de entrada CabecaGeral* Interface.
INTERFACE IMPLÍCITA: A verificação de retorno 1 ou 0.
*/
int VerificaInterface(CabecaGeral* Interface){
	if((VerificarCabecaGeral(Interface)) && (VerificarCastelo(Interface->castle))){
		return 1;
	}else{
		return 0;
	}
}

/*
Função de interface com o usuário.
REQUISITO: Não há.
HIPÓTESE: A função deve mostrar um menu de seleção inicial para o jogador.
ASSERTIVAS DE ENTRADA: Não possui.
ASSERTIVAS DE SAÍDA: Dependendo da escola do usuário, uma ação diferente é executada dentro do menu.
INTERFACE EXPLÍCITA: O tipo de retorno void.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
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
			Inicia();
			break;
			
		case 2:
			creditos(15, 1);
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
Função de inicio do jogo.
REQUISITO: Ter espaço na memória.
HIPÓTESE: A função deve chamar todas as funções de criação e inicialização, verificar suas alocações e apontamentos e certificar-se que o jogo está pronto para começar.
ASSERTIVAS DE ENTRADA: A estrutura controladora enviada para a função precisa ter sido declarada. A variavel horda precisa estar de acordo com os valores do jogo, ou seja, estar entre 1 e 10.
ASSERTIVAS DE SAÍDA: Se todas as estruturas forem corretamente verificadas, o jogo é iniciado, caso contrário, nada acontece.
INTERFACE EXPLÍCITA: O tipo de retorno void e os parâmetros de entrada CabecaGeral* Cabeca, int horda.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
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
	
	/*VERIFICAÇÃO DA INTERFACE*/
	if(VerificaInterface(Interface)){
		Run(Interface,new,horda);
	}
}

/*
Função de salvar o jogo.
REQUISITO: Ter ponteiro de interface devidamente alocado e o jogo inicializado.
HIPÓTESE: A função deve gravar as informações de atributos dos edifícios e em que horda o jogador se encontra num arquivo binário.
ASSERTIVAS DE ENTRADA: A estrutura controladora enviada para a função precisa ter sido declarada e alocada. A variavel horda precisa estar de acordo com os padrões do jogo, ou seja, estar entre 1 e 10.
ASSERTIVAS DE SAÍDA: Não há.
INTERFACE EXPLÍCITA: O tipo de retorno void, os parâmetros de entrada CabecaGeral* Cabeca, int horda e mensagem exibida ao usuário.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
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
Função de carregar um jogo salvo.
REQUISITO: Ter um arquivo binário a ser lido e memória livre para alocação.
HIPÓTESE: A função deve ler as informações de um arquivo bináro e atribuir os valores nos devidos ponteiros de edificios e informações no geral.
ASSERTIVAS DE ENTRADA: O arquivo binário a ser lido precisa ser válido, ou seja, ter sido gerado pelo game.
ASSERTIVAS DE SAÍDA: Não há.
INTERFACE EXPLÍCITA: O tipo de retorno void.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
*/
void LoadGame(){
	FILE* fp1;
	char entrada[9] = "save.bin";
	int ouro,cuQ,nQ,cuCDT,nCDT,cuCDL,nCDL,tC,nC,horda;
	CabecaGeral* Interface = CriaCabecaGeral();

	fp1 = fopen(entrada,"r+b");
	if(fp1 != NULL){
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
}

/*
Função que evolui um edifício do jogo.
REQUISITO: Ponteiro de CabecaGeral alocado e inicializado.
HIPÓTESE: A função deve evoluir um determinado edificio e enviar um inteiro, indicando que a evolução foi efetuada.
ASSERTIVAS DE ENTRADA: A estrutura controladora enviada para a função precisa ter sido declarada e alocada.
ASSERTIVAS DE SAÍDA: Dependendo do case que entre, efetua uma evolução diferente e retorna uma flag indicando que evoluiu um edificio.
INTERFACE EXPLÍCITA: O tipo de retorno int, o parâmetro de entrada CabecaGeral* Interface e as mensagens exibidas ao usuário.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
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
Função que insere unidades no jogo.
REQUISITO: Ponteiro de CabecaGeral alocado e inicializado.
HIPÓTESE: A função deve inserir até quatro unidades e enviar um inteiro, indicando que a inserção foi efetuada.
ASSERTIVAS DE ENTRADA: A estrutura controladora enviada para a função precisa ter sido declarada e alocada.
ASSERTIVAS DE SAÍDA: Dependendo do case que entre, efetua uma criação diferente e retorna uma flag indicando que comprou uma unidade.
INTERFACE EXPLÍCITA: O tipo de retorno int, o parâmetro de entrada CabecaGeral* Interface e as mensagens exibidas ao usuário.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
*/
int MenuEscolhaUnidade(CabecaGeral* Interface){			
	int OpcaoUnidade = menu_unidade(Interface->castle);
	
	switch(OpcaoUnidade){
		case 1:
			if(Interface->castle->quartel->nivel == 1){
				if(Interface->castle->ouro >= Interface->castle->quartel->custounidade){
					Interface->character->player = InserirUnidadeFinal(Interface->character->player,300,60,0.15,1,1);
					Interface->castle = AtualizarCasteloOuro(Interface->castle,(-Interface->castle->quartel->custounidade));
					mvprintw(2, 80, "Gold$ %d", Interface->castle->ouro);
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
					mvprintw(2, 80, "Gold$ %d", Interface->castle->ouro);
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
					mvprintw(2, 80, "Gold$ %d", Interface->castle->ouro);
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
					mvprintw(2, 80, "Gold$ %d", Interface->castle->ouro);
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
					mvprintw(2, 80, "Gold$ %d", Interface->castle->ouro);
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
					mvprintw(2, 80, "Gold$ %d", Interface->castle->ouro);
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
					mvprintw(2, 80, "Gold$ %d", Interface->castle->ouro);
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
					mvprintw(2, 80, "Gold$ %d", Interface->castle->ouro);
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
					mvprintw(2, 80, "Gold$ %d", Interface->castle->ouro);
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
Função que integra as demais funções do jogo.
REQUISITO: Memória livre para alocação, ponteiro de CabecaGeral alocado e inicializado.
HIPÓTESE: A função deve inicializar a interface gráfica e gerenciar os turnos de cada jogador.
ASSERTIVAS DE ENTRADA: A estrutura controladora enviada para a função precisa ter sido declarada e alocada. As variáveis new e wave precisam estar de acordo com o jogo, ou seja, new precisa ser 0 ou 1 e wave precisa estar entre 1 e 10.
ASSERTIVAS DE SAÍDA: Não há.
INTERFACE EXPLÍCITA: O tipo de retorno void e os parâmetros de entrada CabecaGeral* Interface, int new, int wave.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
*/
void Run (CabecaGeral* Interface, int new, int wave){
	int horda = 0;	/*diz em qual horda o jogador se encontra*/
	int fim = 0;	/*indica fim de jogo*/
	int newhorda = 1;	/*indica se é o início de uma nova horda*/
	int EvoluiuEdificio = 0;	/*indica se o jogador já evoluiu um de seus edifícios*/
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

			if(newhorda==1){	/*momento de pausa para o jogador fazer as evoluções e compras de unidades*/
				while((!TemQuatro(Interface->character->player)) && TemDinheiro==1){	/*limita a quantidade de unidades em jogo para até 4 e habilita a compra das mesmas*/
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
					if(horda == 10)
					{
						InsereUnidadeBoss(Interface);
						i = 4;
					}
					else
						InsereUnidadeInimiga(Interface);
						
					usleep(400000);
					print_field(winfield, Interface->character);
					wrefresh(winfield);
				}
				newhorda = 0;
			}

			fim = GameLoop (Interface, winfield);
			
			while(!UnidadeVazia(Interface->character->player)){				/*remove todas as unidades da lista de jogador */
				Interface->character->player = RemoverUnidadeFinal(Interface->character->player);
			} 
			
	
			if (fim == 0) {
				while(EvoluiuEdificio==0 && horda<9){	/*a partir da segunda horda já é possível fazer evoluções dos edifícios*/
					EvoluiuEdificio = MenuEvolucaoEdificio(Interface);
				}
				horda++;	/*avança para a próxima horda*/
				EvoluiuEdificio = 0;	/*dá um ponto de evolução para o jogador*/
				Interface->castle->ouro += Interface->castle->comercio->taxaouro;	/*credita o ouro*/
				newhorda = 1;
				TemDinheiro = 1;
				SaveGame(Interface, horda);
			} else {
				TelaGameOver();
			}
		}
		tela_final();
	}
}

/*
Função que realiza o combate por turnos entre player e cpu.
REQUISITO: Interface estar alocada com personagens de player e cpu devidamente alocados, juntamente com a estrutura WINDOW para visualização.
HIPÓTESE: Será indicado o vencedor ao final da função.
ASSERTIVAS DE ENTRADA:  A estrutura controladora do game precisa ter sido declarada e alocada. A estrutura WINDOW precisa ter sido declarada e alocada para realizar a visualização.
ASSERTIVAS DE SAÍDA: A vitória pode ser adquirida pelo player ou cpu, indicando continuação do game ou perda. 
INTERFACE EXPLÍCITA: Tipo de retorno int e os parâmetros de entrada CabecaGeral * Interface, WINDOW * winfield.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
*/
int GameLoop (CabecaGeral * Interface, WINDOW * winfield) {
	int fluxo = 0;	
	int vencedor;
	
	while (fluxo == 0) {	
		/*Indica o período em que o player realiza o seu ataque*/
		fluxo = Batalha(Interface, winfield);
		if (fluxo == 0) {
			/*Indica o período em que a cpu realiza o seu ataque*/
			fluxo = Batalha2 (Interface, winfield);
			print_field(winfield, Interface->character);
			wrefresh(winfield);
		}
	}
	if (fluxo == 1) {
		vencedor = 0;
	} else if (fluxo == 2) {
		vencedor = 1;
	}
	
	return vencedor;
}

/*
Função responsável pela batalha entre o jogador e a cpu.
REQUISITO: É necessário que a controladora do game esteja alocada juntamente com a estrutura de visualização WINDOW e existam personagens da cpu.
HIPÓTESE: Será realizado o ataque nas unidades do computador, atualizando os personagens a cada ataque e indicando ao final do turno se ainda existem personagens vivos pela parte da cpu.ASSERTIVAS DE ENTRADA: A estrutura controladora do game precisa ter sido declarada e alocada. A estrutura WINDOW precisa ter sido declarada e alocada para correta visualização do game.
ASSERTIVAS DE SAÍDA: Se o jogador ganhar, deve ser retornado 1, caso contrário, o retorno é igual a 0.
INTERFACE EXPLÍCITA: O tipo de retorno int e os parâmetros de entrada CabecaGeral *Interface, WINDOW *winfield.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
*/
int Batalha(CabecaGeral *Interface, WINDOW *winfield)
{
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
					if (UnidadeVazia(Interface->character->cpu)) {
						return 1;
					}
					break;	
			}
		}
		c = '\0';
		seta_batalha(winfield, 0, 0);
		wrefresh(winfield);
		j = 1;
	}

	return 0;
}

/*
Função responsável pela realização do ataque 
REQUISITO: Ter ponteiros de atacante e vitima alocados.
HIPÓTESE: A função deve realizar o ataque à uma unidade e caso a vitima seja igual a zero, elimina seu nó da lista.
ASSERTIVAS DE ENTRADA: As estruturas de personagens enviadas para a função precisam ter sido declaradas e alocadas.
ASSERTIVAS DE SAÍDA: Não há.
INTERFACE EXPLÍCITA: O tipo de retorno Unidade* e os parâmetros de entrada Unidade *atacante, Unidade *vitima. As mensagens para o usuário.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
*/
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
		if(dano > atacante->dano + 10)
		mensagem(20, 75, "Foi super efetivo!");
		else if(dano < atacante->dano - 5)
		mensagem(20,75,"Nao foi efetivo!");
		else
		mensagem(20,75,"Acertou o golpe!");
		sleep(1);
		if (vitima->vida<=0)
		{
			aux = RemoverUnidade(aux, vitima);
		}
	}
	else
	{
		mensagem(20, 75, "Errou o golpe!");
		sleep(1);
	}
	return aux;
}

/*
Função que realiza o combate no turno da cpu.
REQUISITO: É necessário que a controladora do game esteja alocada juntamente com a estrutura de visualização WINDOW e existam personagens da cpu.
HIPÓTESE: Será realizado o ataque nas unidades do jogador, atualizando os personagens a cada ataque e indicando ao final do turno se ainda existem personagens vivos pela parte do player.
ASSERTIVAS DE ENTRADA: A estrutura controladora enviada para a função precisa ter sido declarada e alocada. A estrutura WINDOW precisa ser válida para poder exibir corretamente o game na tela.
ASSERTIVAS DE SAÍDA: Indicação sobre eliminação de todos os personagens ou não, atualização dos atributos dos personagens existentes.
INTERFACE EXPLÍCITA: Tipo de retorno int e parâmetros de entrada CabecaGeral *Interface, WINDOW *winfield. As mensagens de erro impressas a cada situação.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
*/
int Batalha2(CabecaGeral *Interface, WINDOW *winfield)
{
	int hit;
	Unidade *cpu;
	mensagem(20, 60, "Prepare-se!");
	sleep(1);	
	print_field(winfield, Interface->character);
	wrefresh(winfield);
	for (cpu = Interface->character->cpu; cpu != NULL; cpu = cpu->prox) {
		Interface->character->player = AtaqueInimigo (&hit, cpu, Interface->character->player);
		if (UnidadeVazia(Interface->character->player)) {
			return 2;
		}
		if (hit == 1) {
			mensagem(20, 60, "O inimigo conseguiu realizar o ataque!");
			sleep(1);
			print_field(winfield, Interface->character);
			wrefresh(winfield);
			if (cpu->prox != NULL) {
				mensagem(20,60, "Preparando ataque...");
				sleep(1);
				print_field(winfield, Interface->character);
				wrefresh(winfield);
			}
		}
		if (hit == 0) {
			mensagem(20, 65, "O inimigo fracassou no ataque!");
			sleep(1);
			print_field(winfield, Interface->character);
			wrefresh(winfield);
			if (cpu->prox != NULL) {
				mensagem(20,60, "Preparando ataque...");
				sleep(1);
				print_field(winfield, Interface->character);
				wrefresh(winfield);
			}
		}
	}


	return 0;
}

/*
Função que deve realizar a busca de um alvo a ser atacado.
REQUISITO: Ter um ponteiro de Unidade alocado.
HIPÓTESE: Será selecionado o alvo(nó) mais fraco(que contiver a menor vida) e o mesmo será retornado.
ASSERTIVAS DE ENTRADA: A lista de personagens do player enviada para a função precisa ter sido declarada e alocada.
ASSSERTIVAS DE SAÍDA: Nó a ser atacado deve ser diferente de nulo.
INTERFACE EXPLÍCITA: Tipo do retorno Unidade* e parâmetro de entrada Unidade* vitima.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
*/
Unidade * buscaAlvo (Unidade * vitima) {
	Unidade * p;
	Unidade * alvo = NULL;
	int vida = vitima->vida;
	for (p = vitima; p != NULL; p = p->prox) {	/*percorre a lista em busca de um elemento com a menor vida*/
		if (p->vida <= vida) {
			alvo = p;
			vida = p->vida;
		}
	}
	return alvo;
}
			
/*
Função que realiza o ataque da cpu.
REQUISITO: É necessário que o atacante e a vítima sejam ponteiros alocados em memória.
HIPÓTESE: O alvo selecionado(nó) terá seus atributos atualizados ao final da execução da função de ataque.
ASSERTIVAS DE ENTRADA: A lista de personagens do player precisa ter sido declarada e alocada. O personagem da cpu que vai realizar o ataque precisa estar alocado. O ponteiro para a variavel inteira precisa ter sido declarado.
ASSERTIVAS DE SAÍDA: Nó selecionado com atributos atualizados e valor inteiro que indica se ocorreu ou não o ataque.
INTERFACE EXPLÍCITA: O tipo do retorno Unidade* e os parâmetros de entrada int * hit, Unidade *atacante, Unidade *vitima.
INTERFACE IMPLÍTICITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
*/
Unidade *AtaqueInimigo(int * hit, Unidade *atacante, Unidade *vitima)
{	/*declaração de variáveis*/
	float esquiva;
	int dano;
	Unidade * vit = vitima;
	Unidade * atac = atacante;
	Unidade * alvo;

	alvo = buscaAlvo (vit);	/*busca pelo alvo com menor vida*/
	esquiva = (float)GerarValor(101, 0)/100;	/*gera um valor aleatório para as chances de acerto da unidade*/
	if ((esquiva > alvo->esquiva)) {	/*se o valor estiver fora da margem de esquiva da unidade do jogador, então realiza o ataque*/
		dano = (atac->dano + GerarValor(21, -10));
		alvo->vida -= dano;
		*hit = 1;
		if (alvo->vida<=0) {
			vit = RemoverUnidade(vit, alvo);	/*se a vida da unidade do jogador for menor ou igual a zero, ela é removida da lista*/
		}
	} else {
		*hit = 0;	/*caso contrário, atribui 0 ao ataque*/
	}	
	return vit;	/*retorna a vida atualizada*/
}


/*
Função que que verifica se há quatro elementos em uma lista.
REQUISITO: Ponteiro de Unidade alocado.
HIPÓTESE: A função conta quantos elementos existem em uma lista de unidades e retorna 1 caso o somatório atinja o valor 4.
ASSERTIVAS DE ENTRADA: A lista de personagens do player precisa ter sido declarada e alocada.
ASSERTIVAS DE SAÍDA: Caso a lista não seja vazia, analise a quantidade de unidades alocadas e retorna 1 quando o valor chega a quatro, caso contrário, retorna 0.
INTERFACE EXPLÍCITA: O tipo de retorno int e os parâmetro de entrada Unidade* lista.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
*/
int TemQuatro(Unidade* lista){
	Unidade* p;	/*declaração de um ponteiro auxiliar*/
	int i = 0;

	if(!UnidadeVazia(lista)){	/*verifica se a lista é vazia*/
		for(p=lista;p!=NULL;p=p->prox){	/*percorre a lista e soma a quantidade de elementos inseridos*/
			i++;
			if(i==4){
				return 1; 	/*caso o número de unidades seja igual a 4, retorna 1*/
			}
		}
	}
	return 0;	/*caso o número de unidades não seja igual a 4, retorna 0*/
}

/*
Função que que gera valores aleatórios entre 1 e 3.
REQUISITO: Não há.
HIPÓTESE: A função deve gerar valores aleatórios para classe das unidades inimigas.
ASSERTIVAS DE ENTRADA: Os valores de a e b precisam ser valores inteiros.
ASSERTIVAS DE SAÍDA: Não há.
INTERFACE EXPLÍCITA: O tipo de retorno int e os parâmetros de entrada int a, int b.
INTERFACE IMPLÍCITA: A geração do número aleatório atribuido para a variável valor.
*/

int GerarValor(int a, int b){
	int valor = 0;	/*declaração de um valor inteiro*/

 	valor = rand() % a+b; /*geração do valor aleatório a ser retornado*/

return valor;
}

/*
Função que insere unidades inimigas no jogo.
REQUISITO: Ponteiro de CabecaGeral alocado e inicializado.
HIPÓTESE: A função deve inserir até quatro unidades inimigas com nível e classe de acordo com valores gerados aleatoriamente.
ASSERTIVAS DE ENTRADA: A estrutura controladora do game precisa ter sido declarada e alocada. A variável horda precisa estar de acordo com os padroões do jogo, ou seja, ser um valor entre 1 e 10.
ASSERTIVAS DE SAÍDA: Dependendo do case que entre, cria um tipo de unidade diferente.
INTERFACE EXPLÍCITA: O tipo de retorno void e os parâmetros de entrada CabecaGeral* Interface, int horda.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
*/

void InsereUnidadeInimiga(CabecaGeral* Interface, int horda){   
 int OpcaoUnidade = GerarValor(3, 1);	/*Gera um valor aleatório para a classe das unidades*/
 int OpcaoNivel = GerarNivel(horda);	/*Gera um valor aleatório para o nível das unidades*/


	switch(OpcaoUnidade){	/*Dependendo do case que entre, cria um tipo de unidade diferente.*/
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
  			MenuEscolhaUnidade(Interface);	/*Volta ao menu de escola*/
	}
 }
/*
REQUISITO: Ponteiro de interface CabecaGeral deve estar alocado e inicializado.
HIPÓTESE: A função deve inserir o chefão final na décima horda do jogo.
ASSERTIVAS DE ENTRADA: Ponteiro de interface CabecaGeral deve estar alocado e inicializado.
ASSERTIVAS DE SAÍDA: Não há.
INTERFACE EXPLÍCITA: O tipo de retorno void e o parâmetro de entrada CabecaGeral* Interface.
INTERFACE IMPLÍCITA: Interface->character->cpu = InserirUnidadeFinal(Interface->character->cpu, 1000,80,0.3,3,4);
*/
 void InsereUnidadeBoss(CabecaGeral* Interface)
 {
	 Interface->character->cpu = InserirUnidadeFinal(Interface->character->cpu, 1000,80,0.3,3,4);	/*Insere o chefe final*/
 }

/*
Função que que gera valores aleatórios entre 1 e 3.
REQUISITO: Receber o valor de horda entre 1 e 10.
HIPÓTESE: A função deve gerar valores aleatórios para nível das unidades inimigas.
ASSERTIVAS DE ENTRADA: A variável horda precisa estar de acordo com o jogo, ou seja, estar entre 1 e 10.
ASSERTIVAS DE SAÍDA: Dependendo do case que entre, retorna um valor diferente para o nivel.
INTERFACE EXPLÍCITA: O tipo de retorno int e o parâmetro de entrada int horda.
INTERFACE IMPLÍCITA: As estruturas e variáveis auxiliares, as assertivas de entrada e saída e as operações realizadas com os valores enviados como parâmetro.
*/

int GerarNivel(int horda)
{
	if (horda>=1 && horda<10)	/*verifica a validade da informação*/
	{
		switch(horda){	/*Dependendo do case que entre, retorna um valor diferente para o nivel.*/
			case 1:
				return 1;
			case 2:
				return 1;
			case 3:
				return rand()%2+1;	/*gera valores aleatórios entre 1 e 2*/
			case 4:
				return 2;
			case 5:
				return rand()%2+2;	/*gera valores aleatórios entre 2 e 3*/
			case 6:
				return rand()%2+2;	/*gera valores aleatórios entre 2 e 3*/
			case 7:
				return 3;
			case 8:
				return 3;
			case 9:
				return 3;
		}
	}
	return 1;	/*Caso dê algum erro, retorna sempre 1.*/
}
