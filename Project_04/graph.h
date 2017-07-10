#ifndef GRAPH_H
#define GRAPH_H
#include<stdexcept>
#include<iostream>
#include<stack>
#include<queue>
#include<fstream>
#include<limits>
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
    char start;

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
        if(total_vertex_count <= 1)
        {
            return 0;
        }
        int total = ConnectHelp(start);
        if(total == total_vertex_count)
        {
            return 1;
        }
        return 0;
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
        stack<Vertex<Type> *> the_stack;
        Vertex<Type> * found_vertex;
        //Vertex<Type> * temp1; Not needed?
        int run = 1,j = 0,num_in_stack = 0;
        while (run)
        {
            if (hash_list[(v + j * j) % updated_size].getData()==v) //found our vertex
            {
                found_vertex = &hash_list[(v+j*j)% updated_size];
                run = 0; //end loop
            }
            j++;
            if(j==10) //a base case of 10 loops and cant find the node
            {
                cout<<"CANT FIND VERTEX 1"<<endl;
                break;
            }
        }
        cout<<"["<<found_vertex->getData()<<"] ";  //output first node visited
        found_vertex->visisted = 1;     //node has been visisted
        the_stack.push(found_vertex);
        num_in_stack++;
        int run2 = 1;
        int checker = 0;
        while(run2)
        {
            //if(found_vertex.data != NULL)
//            found_vertex = found_vertex->lowestEdgeVertexNotVisited();  //find adjacent lowest
            checker = found_vertex->BoolVisted();
            if(checker)
            {
                found_vertex = found_vertex->lowestEdgeVertexNotVisited();  //find adjacent lowest
                cout <<"["<<found_vertex->getData()<<"] ";                    //print vertex
                found_vertex->visisted = 1;                                 //make as visited
                the_stack.push(found_vertex);                              //push vertex onto stack
                found_vertex = the_stack.top();
            }
            else
            {
                if(!the_stack.empty())
                {
                    found_vertex = the_stack.top();                            //vertex is now top of stack since previous node had no other adjacent
                }
                checker = found_vertex->BoolVisted();
                if(!checker) {
                    the_stack.pop();                                           //pop it off
                }
            }
            if(the_stack.empty())                                          //empty stack so we have goen through all vertexs possible
            {
                cout<<endl;
                run2 = 0;
            }
        }
    }

/******************************************************************************/
    //Performs a Breadth First Search on requested Vertex and prints order visited
    void BFS(char v)
    {
        queue<Vertex<Type> *> the_queue;
        Vertex<Type> * found_vertex;
        //Vertex<Type> * temp1; Not needed?
        int run = 1, j = 0, num_in_queue = 0;
        while (run) {
            if (hash_list[(v + j * j) % updated_size].getData() == v) //found our vertex
            {
                found_vertex = &hash_list[(v + j * j) % updated_size];
                run = 0; //end loop
            }
            j++;
            if (j == 10) //a base case of 10 loops and cant find the node
            {
                cout << "CANT FIND VERTEX 1" << endl;
                break;
            }
        }
        if (found_vertex->visisted == 0)
        {
            cout << "[" << found_vertex->getData() << "] ";  //output first node visited
        }
        found_vertex->visisted = 1;     //node has been visisted
        the_queue.push(found_vertex);
        num_in_queue++;
        int run2 = 1;
        Vertex<Type> * temp;
        temp = found_vertex;
        int checker = 0;
        while(run2)
        {
            //if(found_vertex.data != NULL)
            //found_vertex = temp->lowestEdgeVertexNotVisited();  //find adjacent lowest
            checker = temp->BoolVisted();
            if(checker)
            {
                found_vertex = temp->lowestEdgeVertexNotVisited();  //find adjacent lowest
                cout <<"["<<found_vertex->getData()<<"] ";                    //print vertex
                found_vertex->visisted = 1;                                   //make as visited
                the_queue.push(found_vertex);                              //push vertex into queue
            }
            else
            {
                the_queue.pop();                                           //pop it off
                temp = the_queue.front();                                  //vertex is now front of queue
            }
            if(the_queue.empty())                                          //empty stack so we have goen through all vertexs possible
            {
                cout<<endl;
                run2 = 0;
            }
        }
    }

/******************************************************************************/
    //Returns the Minimum Spanning Tree using Prim's Alogrithm
    double MST(char v)
    {
        queue<Vertex<Type> *> the_queue;
        queue<Vertex<Type> *> the_queue2;
        Vertex<Type> *found_vertex;
        //Vertex<Type> *temp1; Not needed?
        //Vertex<Type> *temp2; Not needed?
        int run = 1, j = 0, num_in_queue = 0;
        double total_to_return = 0, lowest_weight = 0;
        //FIND THE VERTEX FOR STARTING POINT HERE
        while (run)
        {
            if (hash_list[(v + j * j) % updated_size].getData() == v) //found our vertex
            {
                found_vertex = &hash_list[(v + j * j) % updated_size];
                run = 0; //end loop
            }
            j++;
            if (j == 10) //a base case of 10 loops and cant find the node
            {
                cout << "CANT FIND VERTEX 1" << endl;
                break;
            }
        }
        found_vertex->visisted = 1;     //node has been visisted
        the_queue.push(found_vertex);
        num_in_queue++;
        int run2 = 1;
        Vertex<Type> *temp;
        Edge<Type> the_edge;
        Edge<Type> lowest_edge;
        temp = found_vertex;
        int checker = 0,g=0;
        int fail_checker = 0;
        while (run2) {
            //THIS WILL DEQUEUE THEN ENQUE AFTER GOING THROUGH ALL AND ENDING WITH SAME VERTEXS IN QUEUE
            fail_checker = 0;
            g=the_queue.size();
            for (int k = 0; k < g; k++) //LOOP THROUGH ARE VERTEX IN STORED IN QUEUE TO FIND LOWEST WEIGHT
            {
                temp = the_queue.front(); //get our front
                the_queue.pop();          //pop it
                the_queue2.push(temp);     //PUSH IT TO OUR SPARE QUEUE!
                checker = temp->BoolVisted();               //checker returns a bool if there is unvisited edges in vertex
                if (checker)
                {
                    the_edge = temp->lowestWeightNotVisited();  //get the vertex with the lowest weight
                    if (k == 0) //FIRST PASS NOTHING TO COMPARE (the found lowest should be set for base)
                    {
                        if(the_edge.vertex_two->visisted == 1)
                        {
                            lowest_weight = 10000;
                        }
                        else
                        {
                            lowest_weight = the_edge.weight;
                            lowest_edge = the_edge;
                        }
                    }
                    else
                    {

                        if(the_edge.weight < lowest_weight)
                        {
                            lowest_edge = the_edge;
                            lowest_weight = the_edge.weight;
                        }
                    }
                }
                else
                {
                    fail_checker++;

                    if(fail_checker==g)
                    {
                        return total_to_return;
                    }

                }

                if(the_queue.empty())
                {

                    the_queue2.push(lowest_edge.vertex_two); //push our new lowest weighted edge / vertex into queue
                    lowest_edge.vertex_two->visisted = 1;   //set its visisted to 1
                    cout<<"["<<lowest_edge.vertex_one->data<<"] "<<"["<<lowest_edge.vertex_two->data<<"] "<<lowest_weight<<endl;
                    total_to_return += lowest_weight;        //add our weights at end of each for loop
                    lowest_weight = 100000; //reset lowest weight here
                    int z = the_queue2.size();
                    for(int v = 0; v < z;v++)
                    {
                        the_queue.push(the_queue2.front());  //PUSH EVERYTHING BACK TO OUR ORIGINAL QUE
                        the_queue2.pop();                    //EMPTY SECOND QUEUE
                    }
                }
            }
        }
        return 0; //Fixing end of control warning. Should never reach this level.

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
              //cout << vertex << " HAS BEEN PLACED IN HASH AT : " << (vertex + j * j) % updated_size << endl;
              vertices[total_vertex_count] = new_vertex.data;                                                                //place our vertex in seperate array to reset visisted
              start = new_vertex.data;                                                                                       //using this for is connected so we know atleast one vertex to start from
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
                  //cout << "NEW EDGE CREATED FOR " << hash_list[one_loc].data;
                  //cout << " ---TO---> " << hash_list[two_loc].data;
                  //cout << ", AND FROM " << hash_list[two_loc].data;
                  //cout << " ---TO---> " << hash_list[one_loc].data;
                  //cout << " WITH WEIGHT OF : "<<new_edge.getWeight()<<endl;
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
    //Adds an edge between existing vertices. If weight = 0, remove that edge
    void insert(char v1, char v2, double weight)
    {
      if(weight < 0 || weight >= numeric_limits<double>::max())
      {
        throw runtime_error("Invalid weight entered!");
      }

      cout << "Called INSERT" << endl;

      Vertex<Type> * fromVertex;
      Vertex<Type> * toVertex;

      fromVertex = findVertex(v1);
      toVertex = findVertex(v2);
      cout << "Passed" << endl;
      if(weight == 0)
      {
        //Remove the edge between the listed VERTICES
        fromVertex->remove_edge(toVertex->getData());
        cout << "Weight was zero so edge was removed" << endl;
        return;
      }

      //cout << "fromVertex received \'" << fromVertex->getData() << "\'" << endl;
      //cout << "toVertex received \'" << toVertex->getData() << "\'" << endl;



      cout << "Ending INSERT" << endl;
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
    int ConnectHelp(char v)
    {
        stack<Vertex<Type> *> the_stack;
        Vertex<Type> * found_vertex;
        int total_to_return = 0;
        //Vertex<Type> * temp1; Not needed?
        int run = 1,j = 0,num_in_stack = 0;
        while (run)
        {
            if (hash_list[(v + j * j) % updated_size].getData()==v) //found our vertex
            {
                found_vertex = &hash_list[(v+j*j)% updated_size];
                total_to_return++;
                run = 0; //end loop
            }
            j++;
            if(j==10) //a base case of 10 loops and cant find the node
            {
                cout<<"CANT FIND VERTEX 1"<<endl;
                break;
            }
        }
        found_vertex->visisted = 1;     //node has been visisted
        the_stack.push(found_vertex);
        num_in_stack++;
        int run2 = 1;
        int checker = 0;
        while(run2)
        {
            //if(found_vertex.data != NULL)
//            found_vertex = found_vertex->lowestEdgeVertexNotVisited();  //find adjacent lowest
            checker = found_vertex->BoolVisted();
            if(checker)
            {
                found_vertex = found_vertex->lowestEdgeVertexNotVisited();  //find adjacent lowest
                found_vertex->visisted = 1;                                 //make as visited
                the_stack.push(found_vertex);                              //push vertex onto stack
                found_vertex = the_stack.top();
                total_to_return++;
            }
            else
            {
                if(!the_stack.empty())
                {
                    found_vertex = the_stack.top();                            //vertex is now top of stack since previous node had no other adjacent
                }
                checker = found_vertex->BoolVisted();
                if(!checker) {
                    the_stack.pop();                                           //pop it off
                }
            }
            if(the_stack.empty())                                          //empty stack so we have goen through all vertexs possible
            {
                cout<<endl;
                reset(); // reset our visited
                return total_to_return;
                run2 = 0;
            }
        }
    }

};

#endif
