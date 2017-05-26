all: list

list: DoubleNode.o DoublyLinkedList.o menu.o
	g++ -Wall DoubleNode.o DoublyLinkedList.o menu.o -o list

menu.o: menu.cpp SingleNode.h	CyclicLinkedList.h
	g++ -Wall -c menu.cpp

#SingleNode.o: SingleNode.h
#	g++ -Wall -c SingleNode.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -Wall -c DoublyLinkedList.cpp

DoubleNode.o: DoubleNode.cpp DoubleNode.h
	g++ -Wall -c DoubleNode.cpp

#CyclicLinkedList.o: CyclicLinkedList.cpp CyclicLinkedList.h
#	g++ -Wall -c CyclicLinkedList.cpp

clean:
	rm -rf *o list
