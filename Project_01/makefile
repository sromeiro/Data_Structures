all: menu

menu: CyclicLinkedList.o DoubleNode.o DoublyLinkedList.o SingleNode.o menu.o
	g++ -Wall CyclicLinkedList.o DoubleNode.o DoublyLinkedList.o SingleNode.o menu.o -o menu

menu.o: menu.cpp
	g++ -Wall -c menu.cpp

SingleNode.o: SingleNode.cpp SingleNode.h
	g++ -Wall -c SingleNode.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -Wall -c DoublyLinkedList.cpp

DoubleNode.o: DoubleNode.cpp DoubleNode.h
	g++ -Wall -c DoubleNode.cpp

CyclicLinkedList.o: CyclicLinkedList.cpp CyclicLinkedList.h
	g++ -Wall -c CyclicLinkedList.cpp

clean:
	rm -rf *o menu
