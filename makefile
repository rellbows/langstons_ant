CXX = g++
CXXFLAGS = -std=c++0x

main: Ant.cpp Ant.hpp Board.cpp Board.hpp menu.cpp menu.hpp main.cpp
	g++ Ant.cpp Board.cpp menu.cpp main.cpp -o main 

clean:
	rm -f *.o
