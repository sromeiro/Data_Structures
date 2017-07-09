#ifndef VERTEX_H
#define VERTEX_H
#include<stdexcept>
#include<iostream>
#include<list>
#include "edge.h"

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
    char data;     //Holds data information for one vertex

    /*
    * A list where each node holds an integer value that points to the next vertex.
    * This integer value represents an edge from the current vertex to the next vertex.
    * Vertices are held in an array/vector. These integers represent the index numbers.
    * The list contains only outgoing edges. See lecture slides 33 & 92.
    */
    //list <int> adjacencyList;
    Edge<Type> * outgoing;     //store the list of edges
    int edgeCount;
    int visisted;              //keep track of vertex being visited
  public:
    Vertex() : data(0) {};     //empty contructor to create list in classes
    Vertex(char the_data)
    {
        data = the_data;       //since our data is the vertex itself ( A , B , C , D etc...)
        edgeCount = 0;         //when created has zero adjacent edges (must be added)
        outgoing = new Edge<Type>[10];  //create a list of 10 edges
        visisted = 0;
    }
    char getData()
    {
        return data;
    }
    void add_edge(Edge<Type> the_edge)
    {
        if(edgeCount != 10)    //10 can later be changed since i just made this a base case of # of edges
        {
            outgoing[edgeCount] = the_edge;
            edgeCount++;
        }
    }
    int getNumEdges()
    {
        return edgeCount;
    }
    Vertex<Type> * lowestEdgeVertexNotVisited() {
        Vertex<Type> * temp;
        Vertex<Type> * temp2;
        if (edgeCount >= 1) //atleast one edge in list
        {
            temp = outgoing[0].vertex_two;       //temp is first edge in list
        }
        for(int i = 1; i < edgeCount; i++)             //start our loop from second edge in list
        {
            temp2 = outgoing[i].vertex_two;
            if(temp->data < temp2->data)
            {
                if(temp->visisted == 1)          //already been visisted
                {
                    temp = temp2;
                }
            }
            else
            {
                temp = temp2;
            }
        }
        if(temp->visisted==1) //went through all and lowest has been visisted
        {
            return  NULL;
        }
        else
        {
            return temp;     //return our lowest adjacent vertex
        }
    }
    bool BoolVisted() {
        Vertex<Type> * temp;
        Vertex<Type> * temp2;
        if (edgeCount >= 1) //atleast one edge in list
        {
            temp = outgoing[0].vertex_two;       //temp is first edge in list
        }
        else{ return 0; }//VERY IMPORTANT TO RETURN 0 HERE
        for(int i = 1; i < edgeCount; i++)             //start our loop from second edge in list
        {
            temp2 = outgoing[i].vertex_two;
            if(temp->data < temp2->data)
            {
                if(temp->visisted == 1)          //already been visisted
                {
                    temp = temp2;
                }
            }
            else
            {
                temp = temp2;
            }
        }
        if(temp->visisted==1) //went through all and lowest has been visisted
        {
            return  0;
        }
        else
        {
            return 1;     //return our lowest adjacent vertex
        }
    }
  friend class Graph<Type>;
  friend class DirGraph<Type>;
  friend class Edge<Type>;
};

#endif
