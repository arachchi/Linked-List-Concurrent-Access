#Makefile for Concurrent Access for Linked List

CCC=g++
CC=gcc

CFLAGS=-g -Wall
PTHREAD= -lpthread

all: main

serial: SerialLinkedList.o
	$(CCC) $(CFLAGS) Node.cpp LinkedList.cpp SerialLinkedList.cpp -o serial $(PTHREAD)

rwlock: ParallelLinkedListWithReadersWritersLock.o
	$(CCC) $(CFLAGS) Node.cpp LinkedList.cpp ParallelLinkedListWithReadersWritersLock.cpp -o rwlock $(PTHREAD)

mutex: ParallelLinkedListWithMutex.o
	$(CCC) $(CFLAGS) Node.cpp LinkedList.cpp ParallelLinkedListWithMutex.cpp -o mutex $(PTHREAD)

main: main.o
	$(CCC) $(CFLAGS) Node.cpp LinkedList.cpp main.cpp -o main $(PTHREAD)

clean:
	$(RM) *.o 

.PHONY: clean all