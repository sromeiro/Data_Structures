all: proj4

proj4: menu.o
	g++ -Wall menu.o -o proj4

menu.o: menu.cpp graph.h vertex.h edge.h dirGraph.h
	g++ -Wall -c menu.cpp

clean:
	rm -rf *o proj4
