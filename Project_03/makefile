all: proj3

proj3: menu.o
	g++ -Wall menu.o -o proj3

menu.o: menu.cpp avlTree.h	linkedTree.h maxHeapTree.h treeNode.h
	g++ -Wall -c menu.cpp

clean:
	rm -rf *o proj3
