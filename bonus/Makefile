# Makefile for Boom
CXXFLAGS += --std=c++11

all: main

debug: CXXFLAGS += -g
debug: main

rebuild: clean main

main: main.o puzzle.o fuse.o
	$(CXX) $(CXXFLAGS) -o boom main.o puzzle.o fuse.o
main.o: main.cpp puzzle.h fuse.h
	$(CXX) $(CXXFLAGS) -c main.cpp
puzzle.o: puzzle.cpp puzzle.h
	$(CXX) $(CXXFLAGS) -c puzzle.cpp
fuse.o: fuse.cpp fuse.h
	$(CXX) $(CXXFLAGS) -c fuse.cpp
clean:
	-rm -f *.o *~ boom
