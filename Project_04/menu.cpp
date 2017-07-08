#include"graph.h"
#include"vertex.h"
#include"edge.h"
#include"dirGraph.h"
#include <fstream>
#include <iostream>

#define FILENAME "graph.txt" //Change file name here if needed.
//#define FILENAME "C:\\Users\\Brett\\ClionProjects\\Project3_sub\\Project_04\\graph.txt"

using namespace std;
int main()
{
  DirGraph<int> my_dir;
  try
  {
    //Try to build the graph with requested file name
    my_dir.buildGraph(FILENAME);
  }
  catch(const runtime_error& notFound)
  {
    //Terminate if file fails to open
    cerr << notFound.what() << endl;
    return 1; //Early termination of program
  }


  try
  {
    //Try getting information for the requested vertex
    cout<<my_dir.getVertex('B').getData()<<": number of edges "<<my_dir.getVertex('B').getNumEdges()<<endl;
  }
  catch(const runtime_error& notFound)
  {
    //Failed getting information for requested vertex
    cerr << notFound.what() << endl;
  }
  cout << "\nSuccesfull Termination of program" << endl;
  return 0;
}
