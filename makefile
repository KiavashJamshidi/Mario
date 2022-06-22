CC := g++
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: a.out

a.out: main.o rsdl.o
	$(CC) main.o rsdl.o $(CCFLAGS) -o a.out


main.o: src/rsdl.hpp Enemy.h Mario.h Defines.h Functions.h Ground.h main.cpp
	$(CC) -c main.cpp -o main.o

rsdl.o: src/rsdl.hpp src/rsdl.cpp
	$(CC) -c src/rsdl.cpp -o rsdl.o

.PHONY: clean
clean:
	rm -r *.o
