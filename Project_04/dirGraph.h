#ifndef DIRGRAPH_H
#define DIRGRAPH_H
#include<stdexcept>
#include<iostream>
#include<stack>
#include<queue>
#include<fstream>
#include<limits>
#include "vertex.h"

#define PRIMENUMBER 31

using namespace std;

template <class Type>
class DirGraph
{
  private:
    int orig_size;
    int updated_size;
    int total_edge_count;
    int total_vertex_count;
    Vertex<Type> * hash_list;             //used to store our vertex
    char vertices[PRIMENUMBER];           //used to store vertices characters for reset visited
  public:
    DirGraph(int n = 31)
    {
        hash_list = new Vertex<Type>[PRIMENUMBER]; //size of 31 (prime number better for hash table)
        orig_size = PRIMENUMBER;                   //set our original size
        updated_size = PRIMENUMBER;
        total_edge_count = 0;
        total_vertex_count = 0;
    }
    bool empty()
    {
        return !total_vertex_count;                           //if no vertex in hask then empty
    }
    int outDegree(char v)
    {
        int run = 1,j=0;
        while (run)
        {
            if (hash_list[(v + j * j) % updated_size].getData()==v) //make sure we found our correct vertex
            {
                return hash_list[(v+j*j)% updated_size].getNumEdges();
            }
            j++;
            if(j==10) //a base case of 10 loops and cant find the node
            {
              throw runtime_error("Requested Vertex was not found!");
            }
        }
        return 0;
    }
    int inDegree(char v)
    {
        int run = 1,j=0;
        while (run)
        {
            if (hash_list[(v + j * j) % updated_size].getData()==v) //make sure we found our correct vertex
            {
                return hash_list[(v+j*j)% updated_size].incoming;
            }
            j++;
            if(j==10) //a base case of 10 loops and cant find the node
            {
              throw runtime_error("Requested Vertex was not found!");
            }
        }
        return 0;
    }
    int edgeCount()
    {
        return total_edge_count;
    }
    double adjacent(char v1 , char v2)
    {
       if(empty())
       {
        throw runtime_error("Graph is empty. Please restart the program to build a fresh graph.");
       }

       if(v1 == v2) //check if same vertices
       {
           throw runtime_error("Vertices entered were the same. Not adjacent.");
       }

       Vertex<Type> * temp1;
       Vertex<Type> * temp2;
       temp1 = findVertex(v1);
       temp2 = findVertex(v2);

       //FOUND BOTH VERTEX IN HASH TABLE
       for(int k = 0; k < temp1->getNumEdges();k++) //loop all edges in first vertex
       {
           if(temp1->outgoing[k].vertex_two->getData()==temp2->getData()) //FOUND AN OUTGOING EDGE
           {
               return temp1->outgoing[k].weight; //return the weight of the edge
           }
       }
       return -1;//could not find edges and return weight therefore not adjacent and return -1
    }
    //DEPTH FIRST SEARCH -----PRINT ORDER OF VERTICES VISITED
    void DFS(char v)
    {
        stack<Vertex<Type> *> the_stack;
        Vertex<Type> * found_vertex;
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
              throw runtime_error("Requested Vertex was not found!");
            }
        }
        cout<<"["<<found_vertex->getData()<<"] ";  //output first node visited
        found_vertex->visited = 1;     //node has been visited
        the_stack.push(found_vertex);
        num_in_stack++;
        int run2 = 1;
        int checker = 0;
        while(run2)
        {
            checker = found_vertex->BoolVisted();
            if(checker)
            {
                found_vertex = found_vertex->lowestEdgeVertexNotVisited();  //find adjacent lowest
                cout <<"["<<found_vertex->getData()<<"] ";                    //print vertex
                found_vertex->visited = 1;                                 //make as visited
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
    void BFS(char v) {
        queue<Vertex<Type> *> the_queue;
        Vertex<Type> * found_vertex;
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
              throw runtime_error("Requested Vertex was not found!");
            }
        }
        if (found_vertex->visited == 0)
        {
        cout << "[" << found_vertex->getData() << "] ";  //output first node visited
        }
        found_vertex->visited = 1;     //node has been visited
        the_queue.push(found_vertex);
        num_in_queue++;
        int run2 = 1;
        Vertex<Type> * temp;
        temp = found_vertex;
        int checker = 0;
        while(run2)
        {
            checker = temp->BoolVisted();
            if(checker)
            {
                found_vertex = temp->lowestEdgeVertexNotVisited();  //find adjacent lowest
                cout <<"["<<found_vertex->getData()<<"] ";                    //print vertex
                found_vertex->visited = 1;                                   //make as visited
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

    void buildGraph(string file_name) //pass our file to build graph
    {
        string text;
        int linecount = 0, vertexCount =0;
        char vertex,vertex_one,vertex_two;
        double weight;
        ifstream file;
        file.open(file_name.c_str());

        if(file.fail()) //Checks for errors opening the file;
        {
          throw runtime_error("Requested file not found! Terminating program.");
        }

        //THIS FIRST RUN IS JUST TO FIND OUT HOW MANY VERTEX TO CREATE THEN WE RUN THROUGH FILE AGAIN
        if(file.is_open())
        {
            while(getline(file,text))
            {
                if(linecount==0)
                {
                    vertexCount = text.length(); //counts number of characters in first line of text read in text file
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
        }
        else
        {
            vertexCount = (vertexCount/2)+1;
        }

        file.open(file_name.c_str());
        /***************************************************************************************************************
         *                                WHERE WE WILL START TO INITIALIZE EVERYTHING
         ***************************************************************************************************************/
        //this is the second pass of our file since we know the number of vertex on first line of file
        if(file.is_open())
        {
            //FIRST LINE OF TEXT FILE WILL READ IN EACH INDIVIDUAL CHARACTER (where we initialize vertex in our hash table)
            for(int i=0; vertexCount> i; i++)
            {
                file>>vertex;
                Vertex<Type> new_vertex = Vertex<Type>(vertex); //create a new vertex
                int run = 1; //reset our run
                int j = 0;   //reset our j for algorithm
                while(run)
                {
                    if (!hash_list[(vertex + j * j) % updated_size].getData()) //check for empty spot in the array
                    {
                        hash_list[(vertex + j * j) % updated_size] = new_vertex; //place the new vertex in empty spot
                        vertices[total_vertex_count] = new_vertex.data;                                                                //place our vertex in seperate array to reset visited
                        total_vertex_count++; // +1 to total vertex count
                        run = 0; //break our while loop since we placed our vertex in our array
                    }
                    else
                    {
                        //VERTEX HAS ALREADY BEEN PLACED IN GRAPH
                        if(hash_list[(vertex + j * j) % updated_size].getData() != vertex)
                        {
                            run=0;
                        }
                        else
                        {
                            j++;
                        }
                    }
                    //EITHER NEED TO MAKE DYNAMIC SO IT CAN CHANGE SIZES OR HAVE A SEPERATE COUNTER THAT WHEN REACHED BREAKS AND SAYS TOO MANY ENTRYS ETC. (probably should just double array etc)
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
                                insert(hash_list[one_loc].data,hash_list[two_loc].data,weight);
                                j=11; //edge has been set and we can break our two for loops
                                i=11;
                            }
                        }
                    }
                }
            }
            file.close();
        }
    }
    //RESET ALL VERTICES VISITED TO ZERO
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
                    hash_list[(temp+j*j)%updated_size].visited = 0; //reset visited to zero
                }
            }
        }
    }
    //Adds an edge between existing vertices. If weight = 0, remove that edge
    void insert(char v1, char v2, double weight)
    {
      if(weight <= 0 || weight >= numeric_limits<double>::max())
      {
        throw runtime_error("Invalid weight entered!");
      }
      Vertex<Type> * fromVertex;
      Vertex<Type> * toVertex;
      fromVertex = findVertex(v1);
      toVertex = findVertex(v2);
      if(!fromVertex->findEdge(toVertex->getData()))
      {
        //Edge between FROM ---> TO does NOT exist. Create one.
        Edge<Type> new_edge = Edge<Type>(fromVertex, toVertex, weight);
        fromVertex->add_edge(new_edge);
          toVertex->incomingInc();//add new edge to the adj list
          total_edge_count++; //add one to our total edge count
      }

      else if(fromVertex->findEdge(toVertex->getData()))
      {
        //Edge between FROM ---> TO exists. Update its weight.
        Edge<Type> * changeWeight = fromVertex->returnEdge(toVertex->getData());
        changeWeight->weight = weight;
      }
    }
    void shortPath(char v1)
    {
        int size = NumberConnected(v1); //get total size of of vertices for array
        char vertex_array[size];
        int size_tracker=1;
        stack<Vertex<Type> *> the_stack;
        Vertex<Type> * found_vertex;
        int run = 1,j = 0,num_in_stack = 0;
        while (run)
        {
            if (hash_list[(v1 + j * j) % updated_size].getData()==v1) //found our vertex
            {
                found_vertex = &hash_list[(v1+j*j)% updated_size];
                run = 0; //end loop
            }
            j++;
            if(j==10) //a base case of 10 loops and cant find the node
            {
              throw runtime_error("Requested Vertex was not found!");
            }
        }
        vertex_array[0] = found_vertex->getData();
        found_vertex->visited = 1;     //node has been visited
        the_stack.push(found_vertex);
        num_in_stack++;
        int run2 = 1;
        int checker = 0;
        while(run2)
        {
            checker = found_vertex->BoolVisted();
            if(checker)
            {
                found_vertex = found_vertex->lowestEdgeVertexNotVisited();  //find adjacent lowest
                vertex_array[size_tracker++] = found_vertex->getData();
                found_vertex->visited = 1;                                 //make as visited
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
        int final[size];                //final array signals 0 or 1 for final distance or not
        double tot_distance[size];      //array to track the min total distance of the vertices
        for(int i = 0;i<size;i++)       //preset all to defaults
        {
            final[i] = 0;               //set all to 0 since not final
            tot_distance[i] = 1000000;  //set all total disnances to "infinity"
        }
        Vertex<Type> * temp = findVertex(v1); //first find our original
        tot_distance[0] = 0;                  //first is total distance of zero
        int run3 = 1;
        int lowest = 0 ;
        int last_vert;
        while(run3)
        {

            for(int p = 0; p<size ;p++)
            {
                if(tot_distance[p]<=tot_distance[lowest] && final[p]==0)   //total distance is less and final marker is 0
                {
                    lowest = p ;                               //lowest is p in array
                }
            }
            temp = findVertex(vertex_array[lowest]);
            for(int y = 0;y<size;y++)
            {
                if(temp->data == vertex_array[y])
                {
                    last_vert = y;
                }
            }
            final[lowest] = 1;
            for(int j = 0; j < temp->edgeCount;j++) //go through all edges of the current vertex and update our arrays
            {
                for(int z = 0; z<=size ; z++)
                {
                    if(vertex_array[z] == temp->outgoing[j].vertex_two->data && final[z]!=1)
                    {
                        if((tot_distance[last_vert] + temp->outgoing[j].weight) < tot_distance[z] )
                        {
                            tot_distance[z] = (tot_distance[last_vert] + temp->outgoing[j].weight); //if it has a lower weight
                        }
                    }
                }
            }
            int to_break=0;
            for(int a=0;a<size;a++)
            {
                if(final[a]==1)
                {
                    to_break++;
                }
            }
            for(int z= 0;z<size;z++)
            {
                if(final[z]==0)
                {
                    lowest = z;
                }
            }
            if(to_break==size-1)
            {
                run3 = 0;
            }
        }
        reset();
        for(int s = 0;s<size;s++)
        {
            cout<<"["<<vertex_array[s]<<"] "<<tot_distance[s]<<endl;
        }
    }

    int NumberConnected(char v)
    {
        stack<Vertex<Type> *> the_stack;
        Vertex<Type> * found_vertex;
        int total_to_return = 0;
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
                throw runtime_error("Requested Vertex was not found!");
            }
        }
        found_vertex->visited = 1;     //node has been visited
        the_stack.push(found_vertex);
        num_in_stack++;
        int run2 = 1;
        int checker = 0;
        while(run2)
        {
            checker = found_vertex->BoolVisted();
            if(checker)
            {
                found_vertex = found_vertex->lowestEdgeVertexNotVisited();  //find adjacent lowest
                found_vertex->visited = 1;                                 //make as visited
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
        return total_to_return; //Fixes warnings. Should never reach this level
    }

    void clear()
    {
        if(empty())
        {
          throw runtime_error("Can't clear an empty graph. Please restart the program to build a fresh graph.");
        }
        delete[] hash_list;
        hash_list = new Vertex<Type>[PRIMENUMBER]; //size of 31 (prime number better for hash table)
        total_edge_count = 0;
        total_vertex_count = 0;
    }
    /******************************************************************************/
    //Default Destructor
    ~DirGraph()
    {
      if(!empty())
      {
        clear();
      }
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
      throw runtime_error("Requested Vertex was not found!");
      }
};

#endif
