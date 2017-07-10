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
    int edgeCount;             //Keeps a count of how many Edges this vertex has
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

    void remove_edge(char v)
    {
      cout << "Called remove_edge" << endl;
      int i;
      for(i = 0; i < edgeCount; i++) //Check every edge in this vertex for the one to remove
      {
        if(outgoing[i].vertex_two->data == v) //Found the edge that connects FROM ---> TO vertices
        {
          cout << "Found edge from " << data << " ---TO---> " << outgoing[i].vertex_two->data << " with weight of " << outgoing[i].weight << endl;

          Edge<Type> * outgoing_new = new Edge<Type>[10];

          cout << "Start copying" << endl;
          for(int j = 0; j < edgeCount; j++)
          {
            if(outgoing[j].vertex_two == outgoing[i].vertex_two)
            {
              //While copying found the edge to remove. Skip it.
              cout << "Found the edge to remove. Removing edge that points to " << outgoing[j].vertex_two->data << " with weight " << outgoing[j].weight << endl;
              continue;
            }

            cout << "Copying over edge that points to " << outgoing[j].vertex_two->data << " with weight " << outgoing[j].weight << endl;
            outgoing_new[j] = outgoing[j]; //Copies over each edge to new list
          }

          outgoing = outgoing_new;
          edgeCount--;
        }

        if(i >= edgeCount-1)
        {
          throw runtime_error("There is no edge to the requested Vertex");
        }
      }
      cout << "Ending remove_edge" << endl;
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

    Edge<Type> lowestWeightNotVisited()
    {
        Edge<Type> temp;
        Edge<Type> temp2;
        if (edgeCount >= 1) //atleast one edge in list
        {
            temp = outgoing[0];       //temp is first edge in list
        }
        for(int i = 1; i < edgeCount; i++)             //start our loop from second edge in list
        {
            temp2 = outgoing[i];
            if(temp.weight < temp2.weight)
            {
                if(temp.vertex_two->visisted == 1)          //already been visisted
                {
                    temp = temp2;
                }
            }
            else
            {
                if(temp.vertex_two->visisted == 1)          //already been visisted
                {
                    temp = temp2;
                }
            }
        }
        if(temp.vertex_two->visisted==1) //went through all and lowest has been visisted
        {
            //return  0;
        }
        else
        {
            return temp;     //return our lowest adjacent vertex
        }

        return temp; //Fixes warnings of reaching end of control. Should never reach this level.
    }

  friend class Graph<Type>;
  friend class DirGraph<Type>;
  friend class Edge<Type>;
};

#endif
