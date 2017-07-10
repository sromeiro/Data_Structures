#ifndef GRAPH_H
#define GRAPH_H
#include<stdexcept>
#include<iostream>
#include<stack>
#include<queue>
#include<fstream>
#include"vertex.h"

#define PRIMENUMBER 31

using namespace std;

template <class Type>
class Graph
{
  private:
    int orig_size;
    int updated_size;
    int total_edge_count;
    int total_vertex_count;
    Vertex<Type> * hash_list;             //used to store our vertex
    char vertices[100];                   //used to store vertices characters for reset visited

  public:
    //Default Constructor
    Graph()
    {
      hash_list = new Vertex<Type>[PRIMENUMBER]; //size of 31 (prime number better for hash table)
      orig_size = PRIMENUMBER;                   //set our original size
      updated_size = PRIMENUMBER;
      total_edge_count = 0;
      total_vertex_count = 0;
    }

/******************************************************************************/
    //Returns true if there are no vertices in the hash table
    bool empty()
    {
      return total_vertex_count == 0;
    }

/******************************************************************************/
    //Returns the number of edges a particular Vertex has if Vertex is found
    int degree(char v)
    {
      int run = 1, j = 0; //Initializes

      while (run)
      {
          if (hash_list[(v + j * j) % updated_size].getData() == v) //make sure we found our correct vertex
          {
              return hash_list[(v + j * j) % updated_size].getNumEdges();
          }
          j++;

          if(j == 10) //A base case of 10 iterations and cant find the node
          {
              run = 0; //Breaks out of this while loop
          }
      }
      throw runtime_error("Vertex requested not found!");
    }

/******************************************************************************/
    //Returns the weight of the edge connecting two Vertices.
    double adjacent(char v1 , char v2)
    {
       if(v1 == v2) //check if same vertices
       {
           return 0; //Returns zero if vertices are the same
       }

       Vertex<Type> temp1;
       Vertex<Type> temp2;
       int run = 1, run2 = 1, i = 0, j = 0;

       while (run)
       {
           if (hash_list[(v1 + j * j) % updated_size].getData()==v1) //found first vertex
           {
               temp1 = hash_list[(v1+j*j)% updated_size];
               run = 0; //end loop
           }
           j++;
           if(j == 10) //a base case of 10 loops and cant find the node
           {
               throw runtime_error("One of your vertices do not exist!");
           }
       }

       while (run2)
       {
           if (hash_list[(v2 + i * i) % updated_size].getData()==v2) //found second vertex
           {
               temp2 = hash_list[(v2+i*i)% updated_size];
               run2 = 0; //end loop
           }
           i++;
           if(i == 10) //a base case of 10 loops and cant find the node
           {
               throw runtime_error("One of your vertices do not exist!");
           }
       }

       //FOUND BOTH VERTEX IN HASH TABLE
       //Loop through all outgoing edges from Vertex1 and find the edge that connects to Vertex2
       for(int k = 0; k < temp1.getNumEdges(); k++)
       {
         //IF Vertex1 -> Vertex2 == Vertex2
         if(temp1.outgoing[k].vertex_two->getData() == temp2.getData()) //FOUND AN OUTGOING EDGE
         {
           return temp1.outgoing[k].weight; //return the weight of the edge
         }
       }
       return -1; //could not find edges and return weight therefore not adjacent and return -1
    }

/******************************************************************************/
    //Performs Depth First Search on requested Vertex and prints the order visited
    void DFS(char v)
    {

    }

/******************************************************************************/
    //Performs a Breadth First Search on requested Vertex and prints order visited
    void BFS(char v)
    {

    }

/******************************************************************************/
    //Returns the Minimum Spanning Tree using Prim's Alogrithm
    void MST(char v)
    {

    }

/******************************************************************************/
    //Builds an undirected weighted graph from a provided text file
    void buildGraph(string file_name)
    {
      cout << "buildGraph CALLED" << endl;
      ifstream file; //Create the input file object
      file.open(file_name.c_str()); //Open the file object

      if(file.fail()) //Checks for errors opening the file;
      {
        throw runtime_error("Requested file not found! Terminating program.");
      }

      string text;
      int linecount = 0, vertexCount =0;
      //char vertex, vertex_one, vertex_two;
      //double weight;

      //First run through the file to find how many lines of text and how many vertices in the first line
      if(file.is_open())
      {
        while(getline(file,text)) //While we can get a new line from the file
        {
          if(linecount==0) //If we're reading the first line of the text file
          {
            vertexCount = text.length(); //counts number of characters in first line of text read in text file
            cout << "Vertex Count is: " << vertexCount << endl;
          }
          linecount++; //counts how many lines read from the text file
        }
        file.close();
      }
      file.clear();

      //THIS CODE IS NEEDED FOR COMPILERS THAT READ LINE COUNTS DIFFERENTLY
      if(vertexCount%2 == 0) //even count
      {
          vertexCount = (vertexCount/2);
          cout << "Vertex Count was EVEN and is now: " << vertexCount << endl;
      }
      else
      {
          vertexCount = (vertexCount/2)+1;
          cout << "Vertex Count was ODD and is now: " << vertexCount << endl;
      }

      cout << "buildGraph ENDED" << endl;
    }






/******************************************************************************/
    //Default Destructor
    ~Graph()
    {

    }

//===========================HELPER FUNCTIONS BELOW===========================//
    //Finds the requested Vertex
    Vertex<Type> * findVertex(char v)
    {
      int run = 1, j = 0;

      //Performs 10 iterations searching for requested Vertex before quitting
      for(j; j < 10; j++)
      {
        if (hash_list[(v + j * j) % updated_size].getData() == v) //make sure we found our correct vertex
        {
            return hash_list[(v + j * j) % updated_size].getData();
        }
      }
/*
      while (run)
      {
        if (hash_list[(v + j * j) % updated_size].getData() == v) //make sure we found our correct vertex
        {
            return hash_list[(v + j * j) % updated_size].getData();
        }
        j++;

        if(j == 10) //A base case of 10 iterations and cant find the node
        {
            run = 0; //Breaks out of this while loop
        }
      }
*/
      throw runtime_error("Vertex requested not found!");
    }

};

#endif
