#include"graph.h"
#include"vertex.h"
#include"edge.h"
#include"dirGraph.h"

#define FILENAME "graph.txt" //Change file name here if needed.
//#define FILENAME "C:\\Users\\Brett\\ClionProjects\\Project3_sub\\Project_04\\graph.txt"

using namespace std;
int main()
{
  DirGraph<int> my_dir;
  Graph<int> myGraph;

//-------------------------BUILDS DirGraph------------------------------------//
/*
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
*/
//-------------------------BUILDS Graph---------------------------------------//
  try
  {
    //Try to build the graph with requested file name
    myGraph.buildGraph(FILENAME);
  }
  catch(const runtime_error& notFound)
  {
    //Terminate if file fails to open
    cerr << notFound.what() << endl;
    return 1; //Early termination of program
  }

//-------------------------Test Block for DirGraph----------------------------//
/*
  try
  {
    //Try getting information for the requested vertex
    cout<<my_dir.getVertex('B').getData()<<": number of edges "<<my_dir.getVertex('B').getNumEdges()<<endl;
    cout<<"Check for D : "<<my_dir.getVertex('D').getData()<<" and degree: "<<my_dir.degree('D')<<endl;
    Vertex<int> testvertex;
    testvertex = my_dir.getVertex('C');
    cout<<"test vertex C : "<<testvertex.getData()<<" and number of edges : "<<testvertex.getNumEdges()<<endl;

    cout<<"B TO E TEST FOR WEIGHT : "<<my_dir.adjacent('B','E')<<endl;
    cout<<"D TO F TEST FOR WEIGHT : "<<my_dir.adjacent('D','F')<<endl;
    cout<<"C TO F TEST FOR WEIGHT : "<<my_dir.adjacent('C','F')<<endl;
    cout<<"B TO B TEST FOR WEIGHT (SHOULD RETURN 0): "<<my_dir.adjacent('B','B')<<endl;
    cout<<"B TO Z TEST FOR WEIGHT (SHOULD RETURN -1): "<<my_dir.adjacent('B','Z')<<endl;

//    cout<<"TEST LOWEST VERTEX FOR D : "<<my_dir.getVertex('D').lowestEdgeVertexNotVisited().getData()<<endl;
//    cout<<"TEST LOWEST VERTEX FOR A : "<<my_dir.getVertex('A').lowestEdgeVertexNotVisited().getData()<<endl;
//    cout<<"TEST LOWEST VERTEX FOR C : "<<my_dir.getVertex('C').lowestEdgeVertexNotVisited().getData()<<endl;
    cout<<"TEST DFS BELOW"<<endl;
    my_dir.DFS('A');
    cout<<"RESETING"<<endl;
    my_dir.reset();
    cout<<"TEST BFS BELOW"<<endl;
    my_dir.BFS('A');
    cout<<"RESETING"<<endl;
    my_dir.reset();
////
      cout<<"RUNNING MST : "<<my_dir.MST('A')<<endl;
//    my_dir.DFS('A');
//    cout<<"RESETING VISITED VERTICES"<<endl;
//    my_dir.reset();
//    cout<<"RUNNING DFS AGAIN"<<endl;
//    my_dir.DFS('A');
////    cout<<"TEST EDGE COUNT FOR B : "<<my_dir.getVertex('B').getNumEdges()<<endl;
//    my_dir.reset();
//    cout<<"TESTING BFS"<<endl;
//    my_dir.BFS('A');
  }
  catch(const runtime_error& notFound)
  {
    //Failed getting information for requested vertex
    cerr << notFound.what() << endl;
  }
*/


//-------------------------Test Block for Graph-------------------------------//

  try
  {

  }
  catch(const runtime_error& notFound)
  {
    //Failed getting information for requested vertex
    cerr << notFound.what() << endl;
  }

  cout << "\nSuccesfull Termination of program" << endl;
  return 0;
}
