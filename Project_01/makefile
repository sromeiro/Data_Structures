all: list

list: menu.o
	g++ -Wall menu.o -o list

menu.o: menu.cpp SingleNode.h	CyclicLinkedList.h DoubleNode.h DoublyLinkedList.h
	g++ -Wall -c menu.cpp

clean:
	rm -rf *o list
