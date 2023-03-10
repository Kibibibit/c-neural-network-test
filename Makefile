# Autogenerated Makefile from mmake!
CC=gcc
CFLAGS=-Werror -Wall -g -O
LIBS=-lm

.default: all

all: main

clean:
	rm -rf main *.o

main: graphs.o helpers.o linked_list.o main.o matrix.o neural_network.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ $(LIBS)
