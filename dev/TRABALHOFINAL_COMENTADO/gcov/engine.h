/*
PROJETO
Nome: MAXIMILLIAN FAN XAVIER, OTÁVIO ALVES DIAS, RAFAEL DIAS DA COSTA, TÚLIO ABNER DE LIMA
Matrícula: 12/0153271, 12/0131480, 12/0133253, 12/0137194
Curso: Engenharia de Computação
Disciplina: Métodos de Programação
Turma: A
Prof: Jan Mendonça
*/

/*	Arquivo Header	*/
#include <stdio.h>

/*	---------------DEFINIÇÃO DE FUNÇÕES---------------	*/

/*FUNÇÕES DA ENGINE*/

/***************************************************************************
* Função: Cria Estruturas
* Descrição
*
* Realiza a alocação das estruturas Castelo e CabecaPFilas e inicializa com valor NULL todas as estruturas internas de cada uma das
* estruturas alocadas anteriormente.
*
* Parâmetros
*
* Interface - ponteiro para a controladora (CabecaGeral*) do game.
* 
* Valor retornado
*
* Retorna a cabeça da estrutura com todas as estruturas Castelo e CabecaPFilas alocadas com seus ponteiros internos apontando para NULL.
* 
* Assertiva de entrada
*
* A estrutura controladora precisa ter sido alocada.
***************************************************************************/
void CriaEstruturas();

/***************************************************************************
* Função: Inicializa Estruturas
* Descrição
*
* Aloca as estruturas internas de Castelo e CabecaPFilas.
*
* Parâmetros
*
* Interface - ponteiro para a controladora do game (CabecaGeral*)
* status - valor inteiro que indica se as estruturas serão alocadas com os valores iniciais do game ou a partir de um valor específico
* cuQ - valor inteiro que representa o custo para a criação de um personagem do edifício Quartel
* nQ - valor inteiro que representa o nível do edifício quartel
* cuCDT - valor inteiro que representa o custo para a criação de um personagem do edifício Campo de Tiro
* nCDT - valor inteiro que representa o nível do edifício Campo de Tiro
* cuCDL - valor inteiro que representa o custo para a criação de um personagem do edifício Cada das Lanças
* nCDL - valor inteiro que representa o nível do edifício Casa das Lanças
* tC - valor inteiro que representa a quantidade de recursos gerados pelo edifício Comercio
* nC - valor inteiro que representa o nível do edifício Comercio
* 
* Valor retornado
*
* void - não possui retorno.
* 
* Assertiva de entrada
*
* A estrutura controladora enviada para a função precisa ter sido alocada
* A variavel status precisa obedecer os padrões, ser o valor inteiro 0 ou o valor inteiro 1
* Os valores das variáveis de inicialização precisam de acordo com o game.
***************************************************************************/
void InicializaEstruturas();

/***************************************************************************
* Função: Verifica Interface
* Descrição
*
* Verifica se a estrutura controladora está alocada ou não.
*
* Parâmetros
*
* Interface - ponteiro para a controladora (CabecaGeral*) do game.
* 
* Valor retornado
*
* Retorna o valor inteiro 1 caso a estrutura esteja alocada, caso contrário retorna 0.
* 
* Assertiva de entrada
*
* A estrutura controladora enviada para a função precisa ter sido declarada.
***************************************************************************/
int VerificaInterface();

/***************************************************************************
* Função: Start Game
* Descrição
*
* Realiza a chamada para o começo do jogo, verificando se o jogo está sendo iniciado do começo ou a partir de algum save.
*
* Parâmetros
*
* Cabeca - ponteiro para a controladora (CabecaGeral*) do game.
* horda - valor inteiro que representa a horda de inimigos da cpu, caso seja utilizada a função de Load Game.
* 
* Valor retornado
*
* void - não possui retorno.
* 
* Assertiva de entrada
*
* A estrutura controladora enviada para a função precisa ter sido declarada
* A variavel horda precisa estar de acordo com os valores do jogo, ou seja, estar entre 1 e 10.
***************************************************************************/
void StartGame();

/***************************************************************************
* Função: Save Game
* Descrição
*
* Realiza a gravação dos parâmetros do game em um arquivo  binário para posterior leitura e continuação do jogo.
*
* Parâmetros
*
* Interface - ponteiro para a controladora (CabecaGeral*) do game.
* horda - valor inteiro que representa a horda atual de inimigos do jogo.
* 
* Valor retornado
*
* void - não possui retorno.
* 
* Assertiva de entrada
*
* A estrutura controladora enviada para a função precisa ter sido declarada e alocada.
* A variavel horda precisa estar de acordo com os padrões do jogo, ou seja, estar entre 1 e 10.
***************************************************************************/
void SaveGame();

/***************************************************************************
* Função: Load Game
* Descrição
*
* Realiza a leitura do arquivo binário gerado pela função Save Game e continua com o jogo.
*
* Parâmetros
*
* Não possui parâmetros.
* 
* Valor retornado
*
* void - não possui retorno.
* 
* Assertiva de entrada
*
* O arquivo binário a ser lido precisa ser válido, ou seja, ter sido gerado pelo game.
***************************************************************************/
void LoadGame();

/***************************************************************************
* Função: Menu Evolução Edifício
* Descrição
*
* Realiza a evolução de um dos edifícios do jogo.
*
* Parâmetros
*
* Interface - ponteiro para a controladora (CabecaGeral*) do game.
* 
* Valor retornado
*
* EvoluiuEdificio - valor inteiro que indica se foi realizada a evolução de um dos edifícios.
* 
* Assertiva de entrada
*
* A estrutura controladora enviada para a função precisa ter sido declarada e alocada.
***************************************************************************/
int MenuEvolucaoEdificio();

/***************************************************************************
* Função: Menu Escolha Unidade
* Descrição
*
* Realiza a escolha do personagem a ser criado no jogo.
*
* Parâmetros
*
* Interface - ponteiro para a controladora (CabecaGeral*) do game.
* 
* Valor retornado
*
* Retorna o valor inteiro 1 caso um dos personagens tenha sido criado, ou 0 caso nenhum tenha sido criado.
* 
* Assertiva de entrada
*
* A estrutura controladora enviada para a função precisa ter sido declarada e alocada.
***************************************************************************/
int MenuEscolhaUnidade();

/***************************************************************************
* Função: Run
* Descrição
*
* Realiza a execução do loop principal do game, avançando as hordas de inimigos e executando as funções de criação e evolução de edifícios * e personagens.
*
* Parâmetros
*
* Interface - ponteiro para a controladora (CabecaGeral*) do game.
* new - valor inteiro que indica se o jogo está sendo iniciado do começo ou a partir de um save.
* wave - valor inteiro que representa a horda de inimigos caso seja executado o jogo a partir de um load.
* 
* Valor retornado
*
* void - não possui retorno.
* 
* Assertiva de entrada
*
* A estrutura controladora enviada para a função precisa ter sido declarada e alocada.
* As variáveis new e wave precisam estar de acordo com o jogo, ou seja, new precisa ser 0 ou 1 e wave precisa estar entre 1 e 10.
***************************************************************************/
void Run();

/***************************************************************************
* Função: Batalha2
* Descrição
*
* Função que executa o loop de ataque da cpu contra os personagens do player.
*
* Parâmetros
*
* Interface - ponteiro para a controladora (CabecaGeral*) do game.
* winfield - ponteiro para WINDOW (parâmetro da biblioteca ncurses) para atualizar a janela de exibição do game.
* 
* Valor retornado
*
* Retorna o valor inteiro 0 caso todos os ataques tenham sido feitos e ainda existam personagens do player, ou 2 caso todos os personagens * do player tenham sido eliminados.
* 
* Assertiva de entrada
*
* A estrutura controladora enviada para a função precisa ter sido declarada e alocada.
* A estrutura WINDOW precisa ser válida para poder exibir corretamente o game na tela.
***************************************************************************/
int Batalha2();

/***************************************************************************
* Função: Busca Alvo
* Descrição
*
* Realiza a busca pelo personagem mais fraco do player para que a cpu possa realizar o ataque.
*
* Parâmetros
*
* vitima - ponteiro para a lista de personagens do player (Unidade*).
* 
* Valor retornado
*
* Retorna o ponteiro para o personagem (Unidade*) a ser atacado.
* 
* Assertiva de entrada
*
* A lista de personagens do player enviada para a função precisa ter sido declarada e alocada.
***************************************************************************/
Unidade * buscaAlvo ();

/***************************************************************************
* Função: Ataque Inimigo
* Descrição
*
* Realiza o ataque de um personagem do cpu sobre um personagem do player.
*
* Parâmetros
*
* hit - ponteiro para um valor inteiro que vai indicar se foi realizado o ataque com eficiencia ou não
* atacante - ponteiro para o personagem da cpu (Unidade*) que vai realizar o ataque
* vitima - ponteiro para o personagem do player (Unidade*) que vai ser atacado
* 
* Valor retornado
*
* Retorna a lista de personagens do player atualizada após o ataque.
* 
* Assertiva de entrada
*
* A lista de personagens do player precisa ter sido declarada e alocada.
* O personagem da cpu que vai realizar o ataque precisa estar alocado
* O ponteiro para a variavel inteira precisa ter sido declarado.
***************************************************************************/
Unidade *AtaqueInimigo();

/***************************************************************************
* Função: Game Loop
* Descrição
*
* Realiza o loop de batalhas entre o player e o cpu no game.
*
* Parâmetros
*
* Interface - ponteiro para a controladora do game (CabecaGeral*)
* winfield - ponteiro para a estrutura WINDOW (estrutura da biblioteca ncurses) para realizar a visualização dos combates.
* 
* Valor retornado
*
* Retorna o valor inteiro 0 caso o player tenha vencido a batalha ou 1 caso o cpu tenha vencido a batalha.
* 
* Assertiva de entrada
*
* A estrutura controladora do game precisa ter sido declarada e alocada.
* A estrutura WINDOW precisa ter sido declarada e alocada para realizar a visualização.
***************************************************************************/
int GameLoop ();

/*FUNÇÕES DO MENU*/

/***************************************************************************
* Função: Inicia
* Descrição
*
* Executa a exibição do menu principal para o jogador iniciar, carregar, visualizar os créditos ou sair do jogo.
*
* Parâmetros
*
* Não possui parâmetros.
* 
* Valor retornado
*
* void - não possui retorno.
* 
* Assertiva de entrada
*
* Não possui assertivas de entrada.
***************************************************************************/
void Inicia();

/***************************************************************************
* Função: Tem Quatro
* Descrição
*
* Função para verificar se já existem 4 personagens na lista do player, para que ele possa escolher seus personagens.
*
* Parâmetros
*
* lista - ponteiro para a lista de personagens (Unidade*)
* 
* Valor retornado
*
* Retorna o valor inteiro 1 caso já existam 4 personagens, ou 0 caso caso existam menos de 4.
* 
* Assertiva de entrada
*
* A lista de personagens do player precisa ter sido declarada e alocada.
***************************************************************************/
int TemQuatro();

/***************************************************************************
* Função: Gerar Valor
* Descrição
*
* Função que gera um valor aleatório entre 1 e 3 que vai indicar o tipo de personagem a ser criado pelo cpu.
*
* Parâmetros
*
* a - valor inteiro que indica o valor máximo entre os dois.
* b - valor inteiro que indica o valor mínimo entre os dois.
* 
* Valor retornado
*
* Retorna o valor inteiro, entre gerado pelo função rand.
* 
* Assertiva de entrada
*
* Os valores de a e b precisam ser valores inteiros.
***************************************************************************/
int GerarValor();

/***************************************************************************
* Função: Gerar Nível
* Descrição
*
* Função que verifica o nível do personagem a ser criado pela cpu, de acordo com a horda de inimigos do game.
*
* Parâmetros
*
* horda - valor inteiro que representa a horda de inimigos do jogo.
* 
* Valor retornado
*
* Retorna um valor inteiro entre 1 e 3, indicando o nível do personagem a ser criado.
* 
* Assertiva de entrada
*
* A variável horda precisa estar de acordo com o jogo, ou seja, estar entre 1 e 10.
***************************************************************************/
int GerarNivel();

/***************************************************************************
* Função: Insere Unidade Inimiga
* Descrição
*
* Realiza a inserção de um personagem na lista de personagens do cpu, de acordo com os valores gerados para a classe e nível.
*
* Parâmetros
*
* Interface - ponteiro para a controladora do game (CabecaGeral*)
* horda - valor inteiro que indica a horda de inimigos no jogo.
* 
* Valor retornado
*
* Retorna o valor inteiro 0 caso o player tenha vencido a batalha ou 1 caso o cpu tenha vencido a batalha.
* 
* Assertiva de entrada
*
* A estrutura controladora do game precisa ter sido declarada e alocada.
* A variável horda precisa estar de acordo com os padroões do jogo, ou seja, ser um valor entre 1 e 10.
***************************************************************************/
void InsereUnidadeInimiga();

/***************************************************************************
* Função: Insere Unidade Boss
* Descrição
*
* Realiza a inserção do personagem Boss na lista de personagens do cpu quando o player vencer as 10 hordas de inimigos.
*
* Parâmetros
*
* Interface - ponteiro para a controladora do game (CabecaGeral*)
* 
* Valor retornado
*
* void - não possui retorno.
* 
* Assertiva de entrada
*
* A estrutura controladora do game precisa ter sido declarada e alocada.
***************************************************************************/
void InsereUnidadeBoss();

/***************************************************************************
* Função: Batalha
* Descrição
*
* Realiza a seleção do inimigo a ser atacado pelo player, um ataque para cada um de seus personagens.
*
* Parâmetros
*
* Interface - ponteiro para a controladora do game (CabecaGeral*)
* winfield - ponteiro para a estrutura WINDOW (estrutura da biblioteca ncurses) para realizar a visualização do game.
* 
* Valor retornado
*
* Retorna o valor inteiro 1 caso o player tenha vencido a batalha ou 0 caso todos os ataques tenham sido realizados e ainda existem
* inimigos na cpu.
* 
* Assertiva de entrada
*
* A estrutura controladora do game precisa ter sido declarada e alocada.
* A estrutura WINDOW precisa ter sido declarada e alocada para correta visualização do game.
***************************************************************************/
int Batalha();

/***************************************************************************
* Função: Atacar
* Descrição
*
* Realiza o ataque de um personagem do player sobre um dos personagens do cpu.
*
* Parâmetros
*
* atacante - ponteiro para o personagem do player (Unidade*) que vai realizar o ataque
* vitima - ponteiro para o personagem do cpu (Unidade*) que vai receber o ataque
* 
* Valor retornado
*
* Retorna a lista de personagen da cpu atualizada.
* 
* Assertiva de entrada
*
* As estruturas de personagens enviadas para a função precisam ter sido declaradas e alocadas.
***************************************************************************/
Unidade *Atacar();
