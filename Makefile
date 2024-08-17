CC = gcc
CFLAGS = -Wall -g

all: restaurante

restaurante: interface.o pedido.o
	$(CC) $(CFLAGS) -o restaurante interface.o pedido.o

interface.o: interface.c pedido.h
	$(CC) $(
