#ifndef EDGE_H
#define EDGE_H
#include<stdexcept>
#include<iostream>

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

  public:


  friend class Graph<Type>;
  friend class DirGraph<Type>;
  friend class Vertex<Type>;
};

#endif
