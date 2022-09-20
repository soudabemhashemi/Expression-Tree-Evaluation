all: 1.out
1.out: exception.o node.o tree.o main.o
	g++ exception.o node.o tree.o main.o -o 1.out
exception.o: exception.cpp exception.hpp 
	g++ -std=c++11 -c exception.cpp 
node.o: node.cpp node.hpp tree.hpp exception.hpp
	g++ -std=c++11 -c node.cpp
tree.o: tree.cpp tree.hpp node.hpp
	g++ -std=c++11 -c tree.cpp
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
.phony: clean
clean:
	rm*.o
	rm 1.out
