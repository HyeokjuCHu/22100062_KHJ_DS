CC = g++

EXE1 = DS071
EXE2 = DS072
EXE3 = DS073
EXE4 = DS074
EXE5 = DS075
EXE6 = DS076

EXEALL = $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5) $(EXE6)

all: $(EXEALL)

$(EXE1): $(EXE1).cpp
	$(CC) -o $@ $^
	$(CC) -o $(EXE1)_debug $^ -D_DEBUG

$(EXE2): $(EXE2).cpp
	$(CC) -o $@ $^
	$(CC) -o $(EXE2)_debug $^ -D_DEBUG

$(EXE3): $(EXE3).cpp
	$(CC) -o $@ $^
	$(CC) -o $(EXE3)_debug $^ -D_DEBUG

$(EXE4): $(EXE4).cpp
	$(CC) -o $@ $^
	$(CC) -o $(EXE4)_debug $^ -D_DEBUG

$(EXE5): $(EXE5).cpp
	$(CC) -o $@ $^
	$(CC) -o $(EXE5)_debug $^ -D_DEBUG

$(EXE6): lib/sort.o $(EXE6).o
	$(CC) -o $@ $(EXE6).o lib/sort.o -I./lib
	$(CC) -o $(EXE6)_debug $(EXE6).o lib/sort.o -I./lib -D_DEBUG

$(EXE6).o: $(EXE6).cpp
	$(CC) -c $(EXE6).cpp -I./lib
	$(CC) -c $(EXE6).cpp -I./lib -D_DEBUG -o $(EXE6)_debug.o

lib/sort.o: lib/sort.cpp lib/sort.h
	$(CC) -c lib/sort.cpp -I./lib -o lib/sort.o
	$(CC) -c lib/sort.cpp -I./lib -D_DEBUG -o lib/sort_debug.o

clean:
	del $(EXE1).exe
	del $(EXE1)_debug.exe
	del $(EXE2).exe
	del $(EXE2)_debug.exe
	del $(EXE3).exe
	del $(EXE3)_debug.exe
	del $(EXE4).exe
	del $(EXE4)_debug.exe
	del $(EXE5).exe
	del $(EXE5)_debug.exe
	del $(EXE6).exe
	del $(EXE6)_debug.exe
	del $(EXE6).o
	del $(EXE6)_debug.o
	del lib/sort.o
	del lib/sort_debug.o
