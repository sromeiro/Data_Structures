#ifndef VERTEX_H
#define VERTEX_H
#include<stdexcept>
#include<iostream>
#include<list>

using namespace std;

//==========================Friend Class Definitions==========================//
template <class Type>
class Graph;
template <class Type>
class DirGraph;
template <class Type>
class Edge;
//============================================================================//

template <class Type>
class Vertex
{
  private:
    Type data; //Holds data information for one vertex

    /*
    * A list where each node holds an integer value that points to the next vertex.
    * This integer value represents an edge from the current vertex to the next vertex.
    * Vertices are held in an array/vector. These integers represent the index numbers.
    * The list contains only outgoing edges. See lecture slides 33 & 92.
    */
    list <int> adjacencyList;
  public:


  friend class Graph<Type>;
  friend class DirGraph<Type>;
  friend class Edge<Type>;
};

#endif
