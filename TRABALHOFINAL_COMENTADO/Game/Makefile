IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR = ../lib

LIBS=-lm

_DEPS = estruturas.h engine.h grafico.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
 
_OBJ = engine.o funcoes.o grafico.o peixera.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

Projeto: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS) -lncurses -lmenu

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
