CXXFLAGS=-std=c++11

main: maze.cpp
	g++ $(CXXFLAGS) -o maze maze.cpp

List.o: List.cpp List.h
Node.o: Node.cpp Node.h

clean:
	rm -rf *~ *.o maze main