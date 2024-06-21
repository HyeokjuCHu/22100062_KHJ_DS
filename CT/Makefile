CC = g++

EXE1 = DS101
EXE2 = DS102
EXE3 = DS103
EXE4 = DS104
EXE5 = DS105
EXE7 = DS107
EXE8 = DS108
EXE9 = DS109
EXE10 = DS110


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

$(EXE2): $(EXE2).cpp
	$(CC) -o $@ $^

$(EXE3): $(EXE3).cpp
	$(CC) -o $@ $^

$(EXE4): $(EXE4).cpp
	$(CC) -o $@ $^

$(EXE5): $(EXE5).cpp
	$(CC) -o $@ $^

$(EXE7): $(EXE7).cpp
	$(CC) -o $@ $^

$(EXE8): $(EXE8).cpp
	$(CC) -o $@ $^

$(EXE9): $(EXE9).cpp
	$(CC) -o $@ $^

$(EXE10): $(EXE10).cpp
	$(CC) -o $@ $^

clean:
	del $(EXE1).exe
	del $(EXE1)_debug.exe
	del $(EXE1).o
	del $(EXE1)_debug.o
	del lib/sort.o
	del lib/sort_debug.o
	del $(EXE2).exe
	del $(EXE3).exe
	del $(EXE4).exe
	del $(EXE5).exe
	del $(EXE7).exe
	del $(EXE8).exe
	del $(EXE9).exe
	del $(EXE10).exe
