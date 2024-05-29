CC = g++

EXE1 = DS071

EXE2 = DS072

EXE3 = DS073

EXEALL = $(EXE1) $(EXE2) $(EXE3)

all: $(EXEALL)


$(EXE1): $(EXE1).cpp
	$(CC) -o $@ $^
	$(CC) -o DS071_debug $^ -D_DEBUG

$(EXE2): $(EXE2).cpp
	$(CC) -o $@ $^
	$(CC) -o DS072_debug $^ -D_DEBUG

$(EXE3): $(EXE3).cpp
	$(CC) -o $@ $^
	$(CC) -o DS073_debug $^ -D_DEBUG

clean:
	del $(EXE1).exe
	del DS071_debug.exe
	del $(EXE2).exe
	del DS072_debug.exe
	del $(EXE3).exe
	del DS073_debug.exe