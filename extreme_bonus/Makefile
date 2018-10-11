# Makefile for Boom
CXXFLAGS += --std=c++11

all: main

debug: CXXFLAGS += -g
debug: main

rebuild: clean main

main: main.o puzzle.o fuse.o words.o
	$(CXX) $(CXXFLAGS) -o boom main.o puzzle.o fuse.o words.o
main.o: main.cpp puzzle.h fuse.h words.h
	$(CXX) $(CXXFLAGS) -c main.cpp
puzzle.o: puzzle.cpp puzzle.h
	$(CXX) $(CXXFLAGS) -c puzzle.cpp
fuse.o: fuse.cpp fuse.h
	$(CXX) $(CXXFLAGS) -c fuse.cpp
words.o: words.cpp words.h
	$(CXX) $(CXXFLAGS) -c words.cpp
clean:
	-rm -f *.o *~ boom
