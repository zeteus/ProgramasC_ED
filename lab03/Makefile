CC=gcc
CFLAGS=-I. -Wall  -lm
DEPS = listaproduto.h
OBJ = prog_listaproduto.o listaproduto.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

progListaProd: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
