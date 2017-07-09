#ifndef DIRGRAPH_H
#define DIRGRAPH_H
#include<stdexcept>
#include<iostream>
#include<stack>
#include<queue>
#include <fstream>
#include "vertex.h"

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
    char vertices[100];                   //used to store vertices characters for reset visited
  public:
    DirGraph(int n = 31)
    {
        hash_list = new Vertex<Type>[n]; //size of 31 (prime number better for hash table)
        orig_size = n;                   //set our original size
        updated_size = n;
        total_edge_count = 0;
        total_vertex_count = 0;
    }
    bool empty()
    {
        return !total_vertex_count;                           //if no vertex in hask then empty
    }
    int degree(char v)
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
                run = 0;
            }
        }
        return 0;
    }

    double adjacent(char v1 , char v2)
    {
       if(v1 == v2) //check if same vertices
       {
           return 0;
       }
       Vertex<Type> temp1;
       Vertex<Type> temp2;
       int run = 1,run2 = 1,i=0, j = 0;
       while (run) {
           if (hash_list[(v1 + j * j) % updated_size].getData()==v1) //found first vertex
           {
               temp1 = hash_list[(v1+j*j)% updated_size];
               run = 0; //end loop
           }
           j++;
           if(j==10) //a base case of 10 loops and cant find the node
           {
               cout<<"CANT FIND VERTEX 1"<<endl;
               return -1;
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
           if(i==10) //a base case of 10 loops and cant find the node
           {
               cout<<"CANT FIND VERTEX 2"<<endl;
               return -1;
           }
       }
       //FOUND BOTH VERTEX IN HASH TABLE
       for(int k = 0; k < temp1.getNumEdges();k++) //loop all edges in first vertex
       {
           if(temp1.outgoing[k].vertex_two->getData()==temp2.getData()) //FOUND AN OUTGOING EDGE
           {
               return temp1.outgoing[k].weight; //return the weight of the edge
           }
       }
       return -1;//could not find edges and return weight therefore not adjacent and return -1
    }
    //DEPTH FIRST SEARCH -----PRINT ORDER OF VERTICES VISITED
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
    void BFS(char v) {
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
                cout<<vertex;
                Vertex<Type> new_vertex = Vertex<Type>(vertex); //create a new vertex
                int run = 1; //reset our run
                int j = 0;   //reset our j for algorithm
                //int k = 0; Not needed or used?
                while(run)
                {
                    if (!hash_list[(vertex + j * j) % updated_size].getData()) //check for empty spot in the array
                    {
                        hash_list[(vertex + j * j) % updated_size] = new_vertex; //place the new vertex in empty spot
                        cout << " HAS BEEN PLACED IN HASH AT : "<<(vertex + j * j) % updated_size<< endl;
                        vertices[total_vertex_count] = new_vertex.data;                                                                //place our vertex in seperate array to reset visisted
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
                                Edge<Type> new_edge = Edge<Type>(&hash_list[one_loc],&hash_list[two_loc],weight);         //create new edge
                                hash_list[one_loc].add_edge(new_edge);                                                  //add new edge to the adj list
                                cout<<"NEW EDGE CREATED FOR "<<hash_list[one_loc].data<<" ---TO---> "<<hash_list[two_loc].data<<" WITH WEIGHT OF : "<<new_edge.getWeight()<<endl;
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
                    hash_list[(temp+j*j)%updated_size].visisted = 0; //reset visited to zero
                }
            }
        }
    }

    Vertex<Type> getVertex(char vertex)
    {
        int ver_loc;
        for(int i = 0 ; i <10 ; i++)
        {
            ver_loc = (vertex + i * i) % updated_size;
            if(hash_list[ver_loc].data == vertex)
            {
                return hash_list[ver_loc];
            }
        }
        //return NULL; //THIS IS JUST A TEST FUCNTION (NEED CATCH/THROW)
        throw runtime_error("Vertex not found!"); //Fixes the warning
    }

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






















};

#endif
