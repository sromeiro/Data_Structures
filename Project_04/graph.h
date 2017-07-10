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
    //Determines if the graph is Connected
    bool isConnected()
    {
      return false; //NEEDS WORK
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
      char vertex, vertex_one, vertex_two;
      double weight;

      //First run through the file to find how many lines of text and how many vertices in the first line
      if(file.is_open())
      {
        while(getline(file,text)) //While we can get a new line from the file
        {
          if(linecount==0) //If we're reading the first line of the text file
          {
            vertexCount = text.length(); //counts number of characters in first line of text read in text file
            //cout << "Vertex Count is: " << vertexCount << endl;
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
          //cout << "Vertex Count was EVEN and is now: " << vertexCount << endl;
      }
      else
      {
          vertexCount = (vertexCount/2)+1;
          //cout << "Vertex Count was ODD and is now: " << vertexCount << endl;
      }

      //--------------Initialization section below----------------------------//
      file.open(file_name.c_str());

      //this is the second pass of our file since we know the number of vertex on first line of file
      if(file.is_open())
      {
        //FIRST LINE OF TEXT FILE WILL READ IN EACH INDIVIDUAL CHARACTER (where we initialize vertex in our hash table)
        for(int i=0; vertexCount> i; i++)
        {
          file >> vertex;
          //int vertexNumber = vertex;
          //cout << "Vertex " << vertex << " number is: " << vertexNumber << endl;
          //cout << vertexNumber << " % " << updated_size << " = " << vertex % updated_size << endl;
          //cout << vertex;
          Vertex<Type> new_vertex = Vertex<Type>(vertex); //create a new vertex
          int run = 1; //reset our run
          int j = 0;   //reset our j for algorithm

          while(run)
          {
            if (!hash_list[(vertex + j * j) % updated_size].getData()) //check for empty spot in the array
            {
              hash_list[(vertex + j * j) % updated_size] = new_vertex; //place the new vertex in empty spot
              cout << vertex << " HAS BEEN PLACED IN HASH AT : " << (vertex + j * j) % updated_size << endl;
              vertices[total_vertex_count] = new_vertex.data;                                                                //place our vertex in seperate array to reset visisted
              total_vertex_count++; // +1 to total vertex count
              run = 0; //break our while loop since we placed our vertex in our array
            }
            else
            {
              //VERTEX HAS ALREADY BEEN PLACED IN GRAPH
              if(hash_list[(vertex + j * j) % updated_size].getData() != vertex)
              {
                cout << "------------------------------" << endl;
                cout << "Vertex: " << vertex << endl;
                throw runtime_error("Vertex listed above already exists in the graph.\nPlease use unique Vertices. Terminating!");
              }
              else
              {
                j++;
              }
            }
          }
        }

        //EACH OTHER LINE HAS FIRST & SECOND VERTEX AND WEIGHT (call what functions we need to set these variables
        while(file>>vertex_one>>vertex_two>>weight)
        {
          int one_loc , two_loc;
          for(int i = 0 ; i <10 ; i++)
          {
            one_loc = (vertex_one + i * i) % updated_size;
            if(hash_list[one_loc].data == vertex_one)
            {
              for(int j = 0 ; j <10 ; j++)
              {
                two_loc = (vertex_two + j * j) % updated_size;

                //FOUND BOTH ARE VERTEX IN HAS LIST (THIS SHOULD NEVER REALLY RUN MORE THAN JUST 2 TIMES
                if(hash_list[two_loc].data == vertex_two)
                {
                  Edge<Type> new_edge = Edge<Type>(&hash_list[one_loc],&hash_list[two_loc],weight);         //create new edge from ONE to TWO
                  Edge<Type> new_edge2 = Edge<Type>(&hash_list[two_loc],&hash_list[one_loc],weight);        //create new edge from TWO to ONE
                  hash_list[one_loc].add_edge(new_edge);                                                    //add new edge to vertex ONE
                  hash_list[two_loc].add_edge(new_edge2);                                                   //add new edge to vertex TWO
                  cout << "NEW EDGE CREATED FOR " << hash_list[one_loc].data;
                  cout << " ---TO---> " << hash_list[two_loc].data;
                  cout << ", AND FROM " << hash_list[two_loc].data;
                  cout << " ---TO---> " << hash_list[one_loc].data;
                  cout << " WITH WEIGHT OF : "<<new_edge.getWeight()<<endl;
                  j=11; //edge has been set and we can break our two for loops
                  i=11;
                  total_edge_count++; //add one to our total edge count
                }
              }
            }
          }
        }
        file.close();
      }
      cout << "buildGraph ENDED" << endl;
    }

/******************************************************************************/
    //Removes all the elements in the undirected Graph
    void clear()
    {

    }

/******************************************************************************/
    //Iterates over all vertices in the graph and marks them as unviisted
    void reset()
    {
      char temp;
      for(int i = 0; i < total_vertex_count;i++)
      {
        temp = vertices[i];                                   //loop for all vertices to reset our visited to 0
        for(int j = 0; j <total_vertex_count;j++)
        {
          if(hash_list[(temp+j*j)%updated_size].data==temp) //found are vertex in hash table
          {
            hash_list[(temp+j*j)%updated_size].visisted = 0; //reset visited to zero
          }
        }
      }
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
      //Performs 10 iterations searching for requested Vertex before quitting
      for(int j = 0; j < 10; j++)
      {
        if (hash_list[(v + j * j) % updated_size].getData() == v) //make sure we found our correct vertex
        {
          return &hash_list[(v + j * j) % updated_size];
        }
      }
      throw runtime_error("Vertex requested not found!");
    }

};

#endif
