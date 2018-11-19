IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR = ../lib

LIBS=-lm

_DEPS = estruturas.h Tests.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
 
_OBJ = funcoes.o moduloteste.o Tests.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

ModuloTeste: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS) -lcunit

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
