#Makefile for Concurrent Access for Linked List

CCC=g++
CC=gcc

CFLAGS=-g -Wall
PTHREAD= -Ipthread

all: main

main: main.o
	$(CCC) $(CFLAGS) Node.cpp LinkedList.cpp main.cpp -o hello

clean:
	$(RM) *.o 

.PHONY: clean all