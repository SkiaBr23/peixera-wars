IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR = ../lib

LIBS=-lm

_DEPS = estruturas.h Tests.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
 
_OBJ = moduloteste.o Tests.o funcoes.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS) -lcunit

ModuloTeste: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS) -lcunit

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
