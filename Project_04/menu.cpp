#include"graph.h"
#include"vertex.h"
#include"edge.h"
#include"dirGraph.h"

//#define FILENAME "graph.txt" //Change file name here if needed.
#define FILENAME "C:\\Users\\Brett\\ClionProjects\\Project3_sub\\Project_04\\graph.txt"

using namespace std;
int main()
{
  DirGraph<int> my_dir;
  Graph<int> myGraph;

//-------------------------BUILDS DirGraph------------------------------------//

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
//    Vertex<int> *testVertex = new Vertex<int>();
//    testVertex = myGraph.findVertex('A');
//    cout << "Found vertex: " << testVertex->getData() << endl;
//    cout << "This vertex has: " << testVertex->getNumEdges() << " edges" << endl;
//
//    myGraph.insert('A', 'B', 16);
//
//    cout << "This vertex NOW has: " << testVertex->getNumEdges() << " edges" << endl;

    //Vertex<int> *testVertex = new Vertex<int>();
    //testVertex = myGraph.findVertex('S');
    //cout << "Found vertex: " << testVertex->getData() << endl;
//    cout<<"TESTING DIRECTED GRAPH"<<endl;
//    cout<<"DIRECTED RUNNNING DFS"<<endl;
//    my_dir.DFS('A');
//    my_dir.reset();
//    cout<<"DIRECTED RUNNING BFS"<<endl;
//    my_dir.BFS('A');
//    my_dir.reset();
//    cout<<"RUNNING BFS"<<endl;
//    myGraph.BFS('A');
//    myGraph.reset();
//    cout<<"RUNNNING DFS"<<endl;
//    myGraph.DFS('C');
//    myGraph.reset();
//    cout<<"RUNNIN MST (PRIM'S ALGORITHM)"<<endl;
//    cout<<"TOTAL : "<<myGraph.MST('A')<<endl;
//    myGraph.reset();
//    cout<<"IS CONNECTED : "<<myGraph.isConnected()<<endl;
//    cout<<"INCOMING : "<<my_dir.inDegree('S')<<endl;
//    cout<<"OUTGOING : "<<my_dir.outDegree('S')<<endl;

      //my_dir.shortPath('A','E');


//      myGraph.insert('A','B',16);
//      myGraph.MST('A');

      my_dir.shortPath('A','H');
      my_dir.distance('A','H');
  }
  catch(const runtime_error& notFound)
  {
    //Failed getting information for requested vertex
    cerr << notFound.what() << endl;
  }



//============================================================================//
//                         MENU SECTION                                       //
//============================================================================//
/*//      <----------REMOVE THIS COMMENT FOR PROPER MENU
  char option; //Used to select between Undirected 'u' and Directed 'd' graphs
  int run_menu = 1;
  cout << "Welcome!\nPlease select from the following options which type of";
  cout << " graph you would like to create:" << endl << endl;

  cout << "********************************************" << endl;
  cout << "*                                          *" << endl;
  cout << "*    Enter the desired character           *" << endl;
  cout << "*    (u). Undirected graph - Prim's        *" << endl;
  cout << "*    (d). Directed graph  -  Dijkstra's    *" << endl;
  cout << "*                                          *" << endl;
  cout << "********************************************" << endl;
  cout << endl;
  cout << "Selection: ";
  cin >> option;

  switch (option)
  {
    case 'u':
      break;
    case 'd':
      break;
    default:
      cout << "This is an invalid option. Please restart the program";
      cout << " and try again." << endl;
      return 1; //Early termination of program
  }
*///      <----------REMOVE THIS COMMENT FOR PROPER MENU
//****************************************************************************//
//=================BLOCK THAT HANDLES UNDIRECTED GRAPHS=======================//
//****************************************************************************//
/*//      <----------REMOVE THIS COMMENT FOR PROPER MENU
  if (option == 'u')
  {
    int num_select; //Used to select from the menu options below
    cout << "For your new Undirected Graph, please select from the following options\n" << endl;

    cout << "**********************************************" << endl;
    cout << "*                                            *" << endl;
    cout << "*    Enter the desired number                *" << endl;
    cout << "*    1.  Empty?                              *" << endl;
    cout << "*    2.  Degree (v)                          *" << endl;
    cout << "*    3.  Edge Count                          *" << endl;
    cout << "*    4.  Connected?                          *" << endl;
    cout << "*    5.  Adjacent (u, v)?                    *" << endl;
    cout << "*    6.  DFS (v)                             *" << endl;
    cout << "*    7.  BFS (v)                             *" << endl;
    cout << "*    8.  Print MST (v)                       *" << endl;
    cout << "*    9.  Clear                               *" << endl;
    cout << "*    10. Insert (u, v, w)                    *" << endl;
    cout << "*    11. Exit                                *" << endl;
    cout << "*                                            *" << endl;
    cout << "**********************************************" << endl;
    cout << endl;
    while (run_menu)
    {
      cout << "\nSelection: ";
      cin >> num_select;
      cout << endl;

      switch (num_select)
      {
        case 1:
          //Code
          break;
        case 2:
          //Code
          break;
        case 3:
          //Code
          break;
        case 4:
          //Code
          break;
        case 5:
          //Code
          break;
        case 6:
          //Code
          break;
        case 7:
          //Code
          break;
        case 8:
          //Code
          break;
        case 9:
          //Code
          break;
        case 10:
          //Code
          break;
        case 11:
          cout << "\nExiting program" << endl;
          run_menu = 0; //Successful termination of program
          break;
        default:
          cout << "This is an invalid option. Please restart the program";
          cout << " and try again." << endl;
          return 1; //Early termination of program
      }
    }
  }
*///      <----------REMOVE THIS COMMENT FOR PROPER MENU
//****************************************************************************//
//=====================BLOCK THAT DIRECTED GRAPHS=============================//
//****************************************************************************//
/*//      <----------REMOVE THIS COMMENT FOR PROPER MENU
  else
  {
    int num_select; //Used to select from the menu options below
    cout << "For your new Directed Graph, please select from the following options\n" << endl;

    cout << "**********************************************" << endl;
    cout << "*                                            *" << endl;
    cout << "*    Enter the desired number                *" << endl;
    cout << "*    1.  Empty?                              *" << endl;
    cout << "*    2.  InDegree (v)                        *" << endl;
    cout << "*    3.  OutDegree (v)                       *" << endl;
    cout << "*    4.  Edge Count                          *" << endl;
    cout << "*    5.  Adjacent (u, v)?                    *" << endl;
    cout << "*    6.  DFS (v)                             *" << endl;
    cout << "*    7.  BFS (v)                             *" << endl;
    cout << "*    8.  Print Short Path (v)                *" << endl;
    cout << "*    9.  Clear                               *" << endl;
    cout << "*    10. Insert (u, v, w)                    *" << endl;
    cout << "*    11. Exit                                *" << endl;
    cout << "*                                            *" << endl;
    cout << "**********************************************" << endl;
    cout << endl;
    while (run_menu)
    {
      cout << "\nSelection: ";
      cin >> num_select;
      cout << endl;

      switch (num_select)
      {
        case 1:
          //Code
          break;
        case 2:
          //Code
          break;
        case 3:
          //Code
          break;
        case 4:
          //Code
          break;
        case 5:
          //Code
          break;
        case 6:
          //Code
          break;
        case 7:
          //Code
          break;
        case 8:
          //Code
          break;
        case 9:
          //Code
          break;
        case 10:
          //Code
          break;
        case 11:
          cout << "\nExiting program" << endl;
          run_menu = 0; //Successful termination of program
          break;
        default:
          cout << "This is an invalid option. Please restart the program";
          cout << " and try again." << endl;
          return 1; //Early termination of program
      }
    }
  }
*///      <----------REMOVE THIS COMMENT FOR PROPER MENU
  cout << "\nSuccesfull Termination of program" << endl;
  return 0;
}
