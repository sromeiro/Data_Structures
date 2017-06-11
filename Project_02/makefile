all: menu

menu: menu.o
	g++ -Wall menu.o -o menu

menu.o: menu.cpp queue.h	stack.h
	g++ -Wall -c menu.cpp

clean:
	rm -rf *o menu
