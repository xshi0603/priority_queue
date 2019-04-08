CXXFLAGS=-std=c++11

main: main.o List.o Node.o
	g++ $(CXXFLAGS) -o main main.o List.o Node.o

ListTest.o: main.cpp List.h Node.h
List.o: List.cpp List.h Node.h
Node.o: Node.cpp Node.h

test: test.cpp main.o List.o Node.o
	g++ $(CXXFLAGS) -o test test.cpp List.o Node.o
clean:
	rm -rf *~ main *.o test