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
    Edge<Type> * outgoing;     //store the list of edges
    int edgeCount;             //Keeps a count of how many Edges this vertex has
    int visited;              //keep track of vertex being visited
    int incoming;

  public:
    Vertex() : data(0),edgeCount(0) {};     //empty contructor to create list in classes

    Vertex(char the_data)
    {
        data = the_data;       //since our data is the vertex itself ( A , B , C , D etc...)
        edgeCount = 0;         //when created has zero adjacent edges (must be added)
        outgoing = new Edge<Type>[10];  //create a list of 10 edges
        visited = 0;
        incoming = 0;
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

    void remove_edge(char v)
    {
      int i, found = 0;
      for(i = 0; i < edgeCount; i++) //Check every edge in this vertex for the one to remove
      {
        if(outgoing[i].vertex_two->data == v) //Found the edge that connects FROM ---> TO vertices
        {

          Edge<Type> * outgoing_new = new Edge<Type>[10];
          for(int j = 0; j < edgeCount; j++)
          {
            if(outgoing[j].vertex_two == outgoing[i].vertex_two)
            {
              //While copying found the edge to remove. Skip it.
              continue;
            }
            outgoing_new[j-1] = outgoing[j]; //Copies over each edge to new list
          }

          outgoing = outgoing_new;
          edgeCount--;
          found++;

        }
      }

      if(found == 0)
      {
        throw runtime_error("There is no edge to the requested Vertex");
      }
    }

    bool findEdge(char v)
    {
      for(int i = 0; i < edgeCount; i++)
      {
        if(outgoing[i].vertex_two->data == v) //Found the edge that connects FROM ---> TO vertices
        {
          //Found an edge that connect these vertices.
          return true;
        }
      }
      //Edge was not found
      return false;
    }

    Edge<Type> * returnEdge(char v)
    {
      int i;
      for(i = 0; i < edgeCount; i++)
      {
        if(outgoing[i].vertex_two->data == v) //Found the edge that connects FROM ---> TO vertices
        {
          //Found an edge that connect these vertices. Update that weight
          return &outgoing[i];
        }
      }
      //Edge was not found
      throw runtime_error("There is no edge to the requested Vertex");
    }

    int getNumEdges()
    {
        return edgeCount;
    }

    Vertex<Type> * lowestEdgeVertexNotVisited()
    {
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
                if(temp->visited == 1)          //already been visited
                {
                    temp = temp2;
                }
            }else if(temp2->visited == 1)
            {
            }
            else
            {
                temp = temp2;
            }
        }
        if(temp->visited==1) //went through all and lowest has been visited
        {
            return  NULL;
        }
        else
        {
            return temp;     //return our lowest adjacent vertex
        }
    }

    bool BoolVisted()
    {
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
                if(temp->visited == 1)          //already been visited
                {
                    temp = temp2;
                }
            }
            else if(temp2->visited == 1)
            {
            }
            else
            {
                temp = temp2;
            }
        }
        if(temp->visited==1) //went through all and lowest has been visited
        {
            return  0;
        }
        else
        {
            return 1;     //return our lowest adjacent vertex
        }
    }

    Edge<Type> lowestWeightNotVisited()
    {
        Edge<Type> temp;
        Edge<Type> temp2;
        Edge<Type> temp3;
        if (edgeCount >= 1) //atleast one edge in list
        {
            temp = outgoing[0];       //temp is first edge in list
            temp3 = outgoing[0];
        }
        for(int i = 1; i < edgeCount; i++)             //start our loop from second edge in list
        {
            temp2 = outgoing[i];
            if(temp.weight < temp2.weight)
            {
                if(temp.vertex_two->visited == 1)          //already been visited
                {
                    temp = temp2;
                }
            }
            else
            {
                temp3= temp;
                temp = temp2;
            }
                if(temp.vertex_two->visited == 1)          //already been visited
                {
                    temp = temp3;
                }

//            }
        }
        if(temp.vertex_two->visited==1) //went through all and lowest has been visited
        {
        }
        else
        {
            return temp;     //return our lowest adjacent vertex
        }

        return temp; //Fixes warnings of reaching end of control. Should never reach this level.
    }
    void incomingInc()
    {
        incoming++;
    }
    ~Vertex()
    {
      if(edgeCount >= 1)
      {
          delete[] outgoing;
      }
    }

  friend class Graph<Type>;
  friend class DirGraph<Type>;
  friend class Edge<Type>;
};

#endif
