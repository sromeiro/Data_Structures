#ifndef EDGE_H
#define EDGE_H
#include<stdexcept>
#include<iostream>
#include "vertex.h"

using namespace std;

//==========================Friend Class Definitions==========================//
template <class Type>
class Graph;
template <class Type>
class DirGraph;
template <class Type>
class Vertex;
//============================================================================//

template <class Type>
class Edge
{
  private:
    Vertex<Type> * vertex_one; //Suggestion: Rename to fromVertex
    Vertex<Type> * vertex_two; //Suggestion: Rename to toVertex
    double weight;
  public:
    Edge() {}                        //needto create list of edges in the vertex class
    Edge(Vertex<Type> * the_vertex_one,Vertex<Type> * the_vertex_two, double the_weight)
    {
        vertex_one = the_vertex_one;
        vertex_two = the_vertex_two;
        weight = the_weight;
    }
    Vertex<Type> * getOne() //Suggestion: Rename to getFrom
    {
        return vertex_one;
    }
    Vertex<Type> * getTwo() //Suggestion: Rename to getTo
    {
        return vertex_two;
    }
    double getWeight()
    {
        return weight;
    }
  friend class Graph<Type>;
  friend class DirGraph<Type>;
  friend class Vertex<Type>;
};

#endif
