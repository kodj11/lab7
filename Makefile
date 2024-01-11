CC = gcc
CXX = g++

CFLAGS = -g -Wall
LDFLAGS = -lX11 -lm

objects = main.o geometry.o gfx.o
program = graph

default: $(program)

$(program): $(objects)
	$(CXX) $(CFLAGS) $(objects) -o $(program) $(
		LDFLAGS)

main.o: main.cpp main.h
	$(CXX) -c $(CFLAGS) main.cpp -o main.o

geometry.o: geometry.cpp geometry.h
	$(CXX) -c $(CFLAGS) geometry.cpp -o geometry.o

gfx.o: gfx.c gfx.h
	$(CC) -c $(CFLAGS) gfx.c -o gfx.o

clean:
	rm $(objects)