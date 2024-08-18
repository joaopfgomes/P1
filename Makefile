CC = gcc
CFLAGS = -Wall -g

all: restaurante

restaurante: interface.o pedido.o
	$(CC) $(CFLAGS) -o restaurante interface.o pedido.o

interface.o: interface.c pedido.h
	$(CC) $(CFLAGS) -c interface.c

pedido.o: pedido.c pedido.h
	$(CC) $(CFLAGS) -c pedido.c

clean:
	rm -f *.o restaurante
