%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Trabalho II                          %
% Ot�vio Alves Dias - 12/0131480       %
% Rafael Dias da Costa - 12/0133253    %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear all %remove as vari�veis do espa�o de trabalho, desalocando mem�ria
close all %fecha as figuras abertas
clc %limpa as entradas e sa�das da janela de comando

% Varia��o das vari�veis de tempo para cada convolu��o
t = [-10:0.01:10];
 
% PARTE 1
x1 = 2*exp(-t);
h1 = t.*exp(-t).*heaviside(t);
 
% Computa as transformadas de x1 e h1
X1 = fft(x1);
H1 = fft(h1);

% Utiliza da propriedade da multiplica��o de transformadas
Y1 = H1.*X1;

% Retorna ao dom�nio do tempo
y1 = ifft(Y1);
 
% Faz a convolu��o de x1 e h1 pela fun��o do matlab
y1conv = conv(x1,h1);

%%%%%%%%%%% PRIMEIRA JANELA %%%%%%%%%%%%%%%%%%%%%%%%%
fig1 = figure; %guarda uma figura na vari�vel "fig"
set(fig1, 'Name', 'Convolu��es(MatLab)',...
    'unit','pixel','Position',[50, 50, 800, 600]);
%seta as propriedades da janela
set(subplot(2,1,1), 'XColor', [0,0,0], 'YColor', [0,0,0], 'Color', 'w',...
    'Fontsize', 12);
%seta as propriedades do primeiro gr�fico
hold on;
grid on;%ativa o grid
axis([0 length(y1) 0 (max(y1))]);

plot(y1);%plota o gr�fico da convolucao da letra A
title('Letra A - Por Transformada');

set(subplot(2,1,2), 'XColor', [0,0,0], 'YColor', [0,0,0], 'Color', 'w',...
    'Fontsize', 12);
%seta as propriedades do segundo gr�fico
hold on;
grid on;%ativa o grid
axis([0 length(y1) 0 (max(y1))]);
plot(y1conv);%plota o gr�fico da convolucao da letra B
title('Letra A - Fun��o conv()');

% PARTE 2
x0 = heaviside(t);
h0 = exp(-t).*heaviside(t);
 
% Formata��o do vetor para o uso da fft
x2 = [x0,zeros(1,2000)];
h2 = [h0,zeros(1,2000)];
 
% Computa as transformadas de x2 e h2
X2 = fft(x2);
H2 = fft(h2);

% Utiliza da propriedade da multiplica��o de transformadas
Y2 = H2.*X2;

% Retorna ao dom�nio do tempo
y2 = ifft(Y2);

% Faz a convolu��o de x0 e h0 pela fun��o do matlab
y2conv = conv(x0,h0);
 
%%%%%%%%%%% SEGUNDA JANELA %%%%%%%%%%%%%%%%%%%%%%%%%
fig2 = figure; %guarda uma figura na vari�vel "fig"
set(fig2, 'Name', 'Convolu��es(MatLab)',...
    'unit','pixel','Position',[50, 50, 800, 600]);
%seta as propriedades da janela
set(subplot(2,1,1), 'XColor', [0,0,0], 'YColor', [0,0,0], 'Color', 'w',...
    'Fontsize', 12);
%seta as propriedades do primeiro gr�fico
hold on;
grid on;%ativa o grid
axis([0 length(y2) 0 (max(y2))]);

plot(y2);%plota o gr�fico da convolucao da letra A
title('Letra B - Por Transformada');
set(subplot(2,1,2), 'XColor', [0,0,0], 'YColor', [0,0,0], 'Color', 'w',...
    'Fontsize', 12);
%seta as propriedades do segundo gr�fico
hold on;
grid on;%ativa o grid
axis([0 length(y2) 0 (max(y2))]);
plot(y2conv);%plota o gr�fico da convolucao da letra B
title('Letra B - Fun��o conv()');
