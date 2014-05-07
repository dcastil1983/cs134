## CS134 Winter 2013: Video Game Design
## Lab 2 akefile
##
## This file does not need to be modified
#########################################

LIBS = -lglut -lGLU -lGL -lXmu -lXext -lXi -lX11 -lm
CC = g++

## Global header files
INCLUDE = const.h

## Object files and executables
MAIN_OUT = assn1
BSPTREE_OUT = bsptree.o
OBJECT_OUT = object.o

## Requirements for each command
MAIN_REQS = main.cpp $(OBJECT_OUT) $(BSPTREE_OUT)
BSPTREE_REQS = bsptree.h bsptree.cpp $(OBJECT_OUT)
OBJECT_REQS = object.h object.cpp

## Targets to compile for each command
MAIN_TARGETS = main.cpp $(OBJECT_OUT) $(BSPTREE_OUT)
QUADTREE_TARGETS = bsptree.cpp
OBJECT_TARGETS = object.cpp

all: main

## Main 
main: $(MAIN_REQS) $(INCLUDE)
	$(CC) $(MAIN_TARGETS) $(LIBS) -o $(MAIN_OUT)

## QuadTree class
$(QUADTREE_OUT): $(INCLUDE)
	$(CC) -c $(BSPTREE_TARGETS)

## Object class
$(OBJECT_OUT): $(OBJECT_REQS) $(INCLUDE)
	$(CC) -c $(OBJECT_TARGETS)

clean:
	rm -f *~ *.o *.out assn1
