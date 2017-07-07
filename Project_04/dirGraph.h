#ifndef DIRGRAPH_H
#define DIRGRAPH_H
#include<stdexcept>
#include<iostream>
#include <fstream>
#include "vertex.h"

using namespace std;

template <class Type>
class DirGraph
{
  private:
    int orig_size;
    int updated_size;
    int edge_count;
    Vertex<Type> * hash_list;                                              //used to store our vertex
  public:
    DirGraph(int n = 31)
    {
        hash_list = new Vertex<Type>[n];                                 //size of 31 (prime number better for hash table)
        orig_size = n;                                                     //set our original size
        updated_size = n;
        edge_count = 0;
    }
    void buildGraph(string file_name)                                      //pass our file to build graph
    {
        string text;
        int linecount = 0, vertexcount =0;
        char vertex,vertex_one,vertex_two;
        double weight;
        ifstream file;
        file.open(file_name.c_str());
        //THIS FIRST RUN IS JUST TO FIND OUT HOW MANY VERTEX TO CREATE THEN WE RUN THROUGH FILE AGAIN
        if(file.is_open())
        {
            while(getline(file,text))
            {
                if(linecount==0)
                {
                    vertexcount = text.length();                                          //counts number of characters in first line of text read in text file
                }
                linecount++;                                                              //counts how many lines read from the text file
            }
            file.close();
        }
        file.clear();
        //THIS CODE IS NEEDED FOR COMPILERS THAT READ LINE COUNTS DIFFERENTLY
        if(vertexcount%2 == 0) //even count
        {
            vertexcount = (vertexcount/2);
        }
        else
        {
            vertexcount = (vertexcount/2)+1;
        }
        file.open(file_name.c_str());
        /***************************************************************************************************************
         *                                WHERE WE WILL START TO INITIALIZE EVERYTHING
         ***************************************************************************************************************/
        //this is the second pass of our file since we know the number of vertex on first line of file
        if(file.is_open())
        {
            for(int i=0; vertexcount> i; i++)                                             //FIRST LINE OF TEXT FILE WILL READ IN EACH INDIVIDUAL CHARACTER (where we initialize vertex in our hash table)
            {
                file>>vertex;
                cout<<vertex;
                Vertex<Type> new_vertex = Vertex<Type>(vertex);                                    //create a new vertex
                int run = 1; //reset our run
                int j = 0;   //reset our j for algorithm
                while(run)
                {

                    if (!hash_list[(vertex + j * j) % updated_size].getData())             //check for empty spot in the array
                    {
                        hash_list[(vertex + j * j) % updated_size] = new_vertex;                  //place the new vertex in empty spot
                        cout << " HAS BEEN PLACED IN HASH AT : "<<(vertex + j * j) % updated_size<< endl;
                        run = 0; //break our while loop since we placed our vertex in our array
                    }
                    else {
                        if(hash_list[(vertex + j * j) % updated_size].getData() != vertex)  //VERTEX HAS ALREADY BEEN PLACED IN GRAPH
                        {
                            run=0;
                        }
                        else {
                            j++;
                        }
                    }
                    //EITHER NEED TO MAKE DYNAMIC SO IT CAN CHANGE SIZES OR HAVE A SEPERATE COUNTER THAT WHEN REACHED BREAKS AND SAYS TOO MANY ENTRYS ETC. (probably should just double array etc)
                }
            }
            while(file>>vertex_one>>vertex_two>>weight)                                   //EACH OTHER LINE HAS FIRST & SECOND VERTEX AND WEIGHT (call what functions we need to set these variables
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
                            if(hash_list[two_loc].data == vertex_two)     //FOUND BOTH ARE VERTEX IN HAS LIST (THIS SHOULD NEVER REALLY RUN MORE THAN JUST 2 TIMES
                            {
                                Edge<Type> new_edge = Edge<Type>(hash_list[one_loc],hash_list[two_loc],weight);         //create new edge
                                hash_list[one_loc].add_edge(new_edge);                                                  //add new edge to the adj list
                                cout<<"NEW EDGE CREATED FOR "<<hash_list[one_loc].data<<" ---TO---> "<<hash_list[two_loc].data<<" WITH WEIGHT OF : "<<new_edge.getWeight()<<endl;
                                j=11; //edge has been set and we can break our two for loops
                                i=11;
                                edge_count++; //add one to our total edge count
                            }
                        }
                    }
                }
            }
            file.close();
        }
    }
//    Vertex<Type> getVertex(char vertex)
//    {
//        int ver_loc;
//        for(int i = 0 ; i <10 ; i++)
//        {
//            ver_loc = (vertex + i * i) % updated_size;
//            if(hash_list[ver_loc].data == vertex)
//            {
//                return hash_list[ver_loc];
//            }
//        }
//        return NULL; //THIS IS JUST A TEST FUCNTION (NEED CATCH/THROW)
//    }

};

#endif
