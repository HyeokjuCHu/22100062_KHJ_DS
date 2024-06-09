CC = g++

EXE1 = DS101

EXEALL = $(EXE1)

all: $(EXEALL)

$(EXE1): lib/sort.o $(EXE1).o
	$(CC) -o $@ $(EXE1).o lib/sort.o -I./lib
	$(CC) -o $(EXE1)_debug $(EXE1).o lib/sort.o -I./lib -D_DEBUG

$(EXE1).o: $(EXE1).cpp
	$(CC) -c $(EXE1).cpp -I./lib
	$(CC) -c $(EXE1).cpp -I./lib -D_DEBUG -o $(EXE1)_debug.o

lib/sort.o: lib/sort.cpp lib/sort.h
	$(CC) -c lib/sort.cpp -I./lib -o lib/sort.o
	$(CC) -c lib/sort.cpp -I./lib -D_DEBUG -o lib/sort_debug.o

clean:
	del $(EXE1).exe
	del $(EXE1)_debug.exe
	del $(EXE1).o
	del $(EXE1)_debug.o
	del lib/sort.o
	del lib/sort_debug.o
