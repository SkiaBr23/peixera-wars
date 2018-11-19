Universidade de Brasília - 1/2014
Projeto de Métodos de Programação
Professor: Jan Mendonça Correa
Alunos: Maximillian Fan Xavier - 12/0153271
	Rafael Dias da Costa - 12/0133253
	Otávio Alves Dias - 12/0131480
	Tulio Abner de Lima - 12/0137194

- Descrição do projeto

O projeto tem como objetivo principal a construção de um Game de estratégia executado por turnos, onde o jogador tem a possibilidade de criar personagens (Soldado, Lanceiro e Arqueiro) para derrotar as 10 hordas de inimigos, sendo que a últim horda é o personagem Boss.

- Compilação

O projeto está separado em 2 pastas de execução: Game e Modulo Teste, Modulo GCov
Na pasta 'Game e Modulo Teste' o usuário precisa executar o comando 'make' para gerar o arquivo de testes com a ferramenta CUnit (ModuloTeste) e o jogo (Game)
Na pasta 'ModuloGCov' o usuário precisa executar o comando 'make' para gerar o arquivo a ser executado 'ModuloGCov'.


OBS.: Decidimos colocar o Módulo para o GCov em um diretório diferente, pois ao final da execução do game serão gerados vários arquivos para análise tornando o diretório muito confuso com muitos arquivos.

- Execução

Para executar cada um dos arquivos gerados com o comando 'make' em cada diretório basta que o usuário execute a linha de comando abaixo:
./Game
./ModuloTeste
./ModuloGCov

- Doxygen

Para visualizar a documentação através do Doxygen basta acessar a pasta 'Relatorios e Read Me' e abrir o arquivo 'DocumentacaoDoxygen.html'.

Descrição da execução
1) Game

---------- Descrição de Funcionamento do Jogo ----------
CRITÉRIO DE VITÓRIA: Sobreviver as 10 hordas e eliminar o personagem Boss.
CRITÉRIO DE DERROTA: Ter todas as suas unidades mortas.
1 - Use W(cima),S(baixo) para selecionar as opções do Menu;
2 - A organização da tela se dá pela janela superior onde são mostradas as informações como Menu(M), número da horda enfrentada e quantidade de ouro disponível, na janela lateral esquerda encontram-se seus edifícios, seus respectivos níveis e a taxa de ouro gerada por turno;
3 - Assim que um novo jogo for inicializado, o turno do usuário pede para que unidades sejam compradas, use as teclas 1,2,3 de acordo com o menu exibido;
3 - O combate será iniciado e cada unidade do jogador deve realizar um ataque, escolha qual unidade inimiga deve ser seu alvo com as teclas W(cima),S(baixo);
4 - Ao final do turno, o computador fará sua escolha e realizará os ataques ao jogador;
5 - Após ambos os turnos terem se finalizado, caso o jogador não tenha perdido todas as unidades, um menu de escolha surgirá para evoluir um dos quatro edifícios, use as teclas 1,2,3,4 de acordo com as informações em tela;
6 - Os passos 3,4,5 se repetirão até que o jogador tenha perdido ou sobrevivido todas as hordas ao eliminar todos os inimigos.

OBS.: O jogo é automaticamente salvo a cada avanço de horda, gerando o arquivo save.bin no mesmo diretório de execução.

2) Modulo Teste
---------- Descrição de Funcionamento do Módulo de teste ----------
1 - Execute o arquivo 'ModuloTeste' gerado com o comando 'make' e analise a saída gerada de acordo com os testes implementados com o módulo de teste CUnit.

3) GCov

---------- Descrição de Funcionamento do GCov ----------
O projeto já foi testado com a ferramenta GCov, os arquivos já foram criados, basta executar a linha de comando abaixo para visualizar as estatísticas de funcionamento do projeto.

gcov *.c

Caso seja de sua vontade, execute os procedimentos abaixo:

1 - Execute o arquivo 'ModuloGCov' gerado com o comando 'make' e jogue o jogo de acordo com as instruções exibidas para o arquivo 'Game' acima.
2 - Ao final da execução (executando todas as operações de evolução, criação, créditos e função de load) será necessário que o usuário rode o comando:

gcov *.c

3 - Após executar esse comando, visualizar a saída indicando a porcentagem de código coberta pelo teste do game.
