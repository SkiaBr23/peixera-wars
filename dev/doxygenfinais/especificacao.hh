/*! \mainpage ESPECIFICAÇÃO
*1 Informações Gerais\n
*2 Grupo\n
*3 Descrição Geral\n
*3.1 Unidades\n
*3.2 Edifícios\n
*3.3 Recursos\n
*3.4 Mecânica\n\n\n
*\section geral 1. INFORMAÇÕES GERAIS
*Nome do projeto: Peixera Wars\n
*Projeto de Disciplina: Jogo de Estratégia\n
*Semestre Cursado: 1/2014\n
*Curso: Engenharia de Computação\n
*Disciplina: Métodos de Programação\n
*Professor: Jan Mendonça\n
*Turma: A\n\n\n
*\section grupo 2. GRUPO
*No de Integrantes: 4\n
*Nome: Maximillian Fan Xavier\n
*Matrícula: 12/0153271\n
*Função: Estrutura de Dados\n
*Nome: Otávio Alves Dias\n
*Matrícula: 12/0131480\n
*Função: Estrutura de Dados\n
*Nome: Rafael Dias da Costa\n
*Matrícula: 12/0133253\n
*Função: Interface Gráfica\n
*Nome: Túlio Abner de Lima\n
*Matrícula: 12/0137194\n
*Função: Interface Gráfica\n\n\n
*\section descricao 3. DESCRIÇÃO GERAL
*\subsection unidades 3.1. Unidades
*Existirão ao todo três(3) unidades de combate, onde cada qual pode ser
*evoluída em até dois níveis, ou seja, as unidades mais básicas iniciam no nível
*um(1) e podem chegar até o nível mais alto, sendo este três(3).\n
*As unidades dependem da evolução dos edifícios para assim poderem passar
*para o próximo nível, ou seja, ao evoluir uma construção, a unidade específica
*relacionada àquele edifício também evoluirá. Dependem de ouro para serem
*criadas. Possuem os atributos Vida, Esquiva, Dano, e Nível.\n\n
*Soldado: Tem vantagem contra lanceiro e desvantagem contra arqueiro. É a
*unidade com maior vida do jogo;\n
*Arqueiro: Tem vantagem contra soldado e desvantagem contra lanceiro. É a
*unidade de maior esquiva do jogo;\n
*Lanceiro: Tem vantagem contra arqueiro e desvantagem contra soldado. É a
*unidade com maior ataque do jogo.\n
*\subsection edificios 3.2. Edifícios
*Existirão ao todo quatro(4) edifícios, onde cada qual pode ser evoluído em até
*dois níveis, ou seja, as construções mais básicas iniciam no nível um(1) e podem
*chegar até o nível mais alto, sendo este três(3).\n
*As construções dependem de pontos de evolução para serem evoluídas.\n\n
*Possuem os atributos:\n
*Quartel: Responsável pela criação de soldados;\n
*Campo de Tiro: Responsável pela criação de arqueiros;\n
*Casa das Lanças: Responsável pela criação de lanceiros;\n
*Comércio: Responsável por gerar o recurso "Ouro".\n
*Todos os edifícios juntos representam seu castelo.\n
*\subsection recursos 3.3. Recursos
*Ponto de Evolução: Recurso utilizado na evolução de edifícios. É adquirido ao
*fim de cada horda como recompensa por ter sobrevivido.\n
*Ouro: Recurso utilizado na evolução de soldados. É gerado pelo edifício
*comércio.\n
*\subsection mecanica 3.4. Mecânica
*O jogo é de tema medieval baseado em hordas, totalizando oito(10) ataques
*que o jogador deverá sobreviver, mantendo suas unidades vivas até o fim da
*rodada.\n
*O mapa será composto por um menu superior que mostra as informações
*gerais, um menu esquerdo que mostra os edifícios e a janela central onde as
*unidades realizam o combate. O objetivo do jogador é criar batalhões de defesa que
*irão resistir aos ataques da CPU.\n
*\image html image1.png
*Imagem ilustrativa do jogo Final Fantasy para Super Nintendo.\n\n
*O jogador já inicia a partida com todas as construções disponíveis, apenas
*necessitando evoluí-las conforme sua necessidade. Ao fim de cada horda, todas as
*unidades em campo são removidas e um ponto de evolução é gerado, possibilitando
*a evolução dos edifícios. O ouro gerado pelo comércio também é creditado neste
*instante.\n
*Os edifícios só podem ser evoluídos na transição entre uma horda e outra,
*sendo representada por um tempo de pausa entre os ataques da CPU.\n
*As unidades são criadas da seguinte forma: o jogador deverá selecionar, no
*inicio de cada horda, quais unidades deseja comprar. Em seguida, o combate se
*inicia e o usuário deve escolher que unidades inimigas atacar.\n\n
*No turno do jogador, todas as unidades atacam, cabendo a ele escolher qual
*dos inimigos receberá o dano. No fim da rodada, a CPU faz sua investida. O dano é
*gerado aleatoriamente dentro de uma margem de diferença de até 10 pontos, ou
*seja, se um guerreiro ataca com 60 pontos, o valor absoluto de seu ataque pode
*flutuar dentre um intervalo de 50 e 70 pontos. No caso da esquiva, um valor aleatório
*é gerado entre 0 e 1 e caso este número caia fora do intervalo do inimigo, o ataque é
*realizado com sucesso, caso contrário, resulta em uma falha e não causa dano.\n
*\image html image2.png
*Imagem ilustrativa do menu de castelo do jogo CastleStorm.\n\n
*Os comandos evolutivos do jogo serão feitos através de um menu; as
*informações úteis aparecerão na parte superior da tela, farão parte da HUD(heads-
*up display); as interações serão efetuadas através das teclas do teclado.\n
*Critério de vitória: Sobreviver as dez(10) hordas inimigas, eliminando todas as
*unidades da CPU.\n
*Critério de derrota: Ter todas as suas unidades mortas.\n\n\n
*/