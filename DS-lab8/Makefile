CC = g++

EXE1 = DS071

EXEALL = $(EXE1)

all: $(EXEALL)


$(EXE1): $(EXE1).cpp
	$(CC) -o $@ $^
	$(CC) -o DS071_debug $^ -D_DEBUG

clean:
	del $(EXE1).exe
	del DS071_debug.exe