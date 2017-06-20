all: project2

project2: menu.o
	g++ -Wall menu.o -o project2

menu.o: menu.cpp queue.h	stack.h
	g++ -Wall -c menu.cpp

clean:
	rm -rf *o project2
