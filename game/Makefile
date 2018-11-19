IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR = ../lib

LIBS=-lm -lcunit -lncurses -lmenu

_DEPS = estruturas.h engine.h grafico.h Tests.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
 
_OBJ = engine.o funcoes.o grafico.o peixera.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_OBJ2 = Tests.o moduloteste.o funcoes.o
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))

$(ODIR)/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

all: Game ModuloTeste

Game: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

ModuloTeste: $(OBJ2)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
