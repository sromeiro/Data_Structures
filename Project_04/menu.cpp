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

//============================================================================//
//                         MENU SECTION                                       //
//============================================================================//
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

//-------------------------BUILDS DirGraph------------------------------------//

  string changeName;
  cout << "\nDefault File Name is \"graph.txt\". Would you like to change that?" << endl;
  cout << "(Y)es or (N)o: ";
  cin >> changeName;
  if(changeName.compare("Y") == 0)
  {
    cout << "Please enter your new File Name. Include the extension .txt" << endl;
    cout << "File Name: ";
    cin >> changeName;
  }
  else
  {
    changeName = FILENAME;
  }
  cout << endl;

  try
  {
    //Try to build the graph with requested file name
    my_dir.buildGraph(changeName);
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
    myGraph.buildGraph(changeName);
  }
  catch(const runtime_error& notFound)
  {
    //Terminate if file fails to open
    cerr << notFound.what() << endl;
    return 1; //Early termination of program
  }

//----------------------------------------------------------------------------//

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
//****************************************************************************//
//=================BLOCK THAT HANDLES UNDIRECTED GRAPHS=======================//
//****************************************************************************//
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
          myGraph.empty() ? cout << "Empty!" << endl : cout << "Not empty!" << endl;
          break;
        case 2:
          try
          {
            char data;
            cout << "What vertex would you like the degree for?" << endl;
            cout << "Vertex: ";
            cin >> data;
            int degree = myGraph.degree(data);
            cout << "Degree: " << degree << endl;
          }
          catch(const runtime_error& notFound)
          {
            cerr << notFound.what() << endl;
          }
          break;
        case 3:
          int edges;
          edges = myGraph.edgeCount();
          cout << "Number of edges: " << edges << endl;
          break;
        case 4:
          myGraph.isConnected() ? cout << "Connected!" << endl : cout << "Not connected!" << endl;
          break;
        case 5:
          try
          {
            char fromVertex, toVertex;
            cout << "Please enter the Vertices you would like adjacency for" << endl;
            cout << "Starting Vertex: ";
            cin >> fromVertex;
            cout << "Ending Vertex: ";
            cin >> toVertex;
            double weight = myGraph.adjacent(fromVertex, toVertex);
            weight == -1 ? cout << "Not adjacent!" << endl : cout << "They are adjacent with an edge of weight " << weight << endl;
          }
          catch(const runtime_error& notFound)
          {
            cerr << notFound.what() << endl;
          }
          break;
        case 6:
          try
          {
            char data;
            cout << "Enter the starting vertex for Depth First Search" << endl;
            cout << "Starting Vertex: ";
            cin >> data;
            myGraph.DFS(data);
            myGraph.reset();
          }
          catch(const runtime_error& notFound)
          {
            myGraph.reset();
            cerr << notFound.what() << endl;
          }
          break;
        case 7:
          try
          {
            char data;
            cout << "Enter the starting vertex for Breadth First Search" << endl;
            cout << "Starting Vertex: ";
            cin >> data;
            myGraph.BFS(data);
            myGraph.reset();
          }
          catch(const runtime_error& notFound)
          {
            myGraph.reset();
            cerr << notFound.what() << endl;
          }
          break;
        case 8:
          try
          {
            char data;
            cout << "Enter the starting vertex for the Minimum Spanning Tree" << endl;
            cout << "Starting Vertex: ";
            cin >> data;
            myGraph.MST(data);
            myGraph.reset();
          }
          catch(const runtime_error& notFound)
          {
            myGraph.reset();
            cerr << notFound.what() << endl;
          }
          break;
        case 9:
          try
          {
            myGraph.clear();
            cout << "Cleared!" << endl;
          }
          catch(const runtime_error& empty)
          {
            cerr << empty.what() << endl;
          }
          break;
        case 10:
          try
          {
            char fromVertex, toVertex;
            double weight;
            cout << "Inserting a new edge. ";
            cout << "Please enter the Starting Vertex, ";
            cout << "the Ending Vertex and the weight of the Edge to be added" << endl;
            cout << "NOTE: Negative weights are not accepted" << endl << endl;
            cout << "Starting Vertex: ";
            cin >> fromVertex;
            cout << "Ending Vertex: ";
            cin >> toVertex;
            cout << "Weight: ";
            cin >> weight;

            myGraph.insert(fromVertex, toVertex, weight);

          }
          catch(const runtime_error& notFound)
          {
            cerr << notFound.what() << endl;
          }
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
//****************************************************************************//
//=====================BLOCK THAT DIRECTED GRAPHS=============================//
//****************************************************************************//
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
          my_dir.empty() ? cout << "Empty!" << endl : cout << "Not empty!" << endl;
          break;
        case 2:
          try
          {
            char data;
            cout << "What vertex would you like the inDegree for?" << endl;
            cout << "Vertex: ";
            cin >> data;
            int inDegree = my_dir.inDegree(data);
            cout << "inDegree: " << inDegree << endl;
          }
          catch(const runtime_error& notFound)
          {
            cerr << notFound.what() << endl;
          }
          break;
        case 3:
          try
          {
            char data;
            cout << "What vertex would you like the outDegree for?" << endl;
            cout << "Vertex: ";
            cin >> data;
            int outDegree = my_dir.outDegree(data);
            cout << "outDegree: " << outDegree << endl;
          }
          catch(const runtime_error& notFound)
          {
            cerr << notFound.what() << endl;
          }
          break;
        case 4:
          int edges;
          edges = my_dir.edgeCount();
          cout << "Number of edges: " << edges << endl;
          break;
        case 5:
          try
          {
            char fromVertex, toVertex;
            cout << "Please enter the Vertices you would like adjacency for" << endl;
            cout << "Starting Vertex: ";
            cin >> fromVertex;
            cout << "Ending Vertex: ";
            cin >> toVertex;
            double weight = my_dir.adjacent(fromVertex, toVertex);
            weight == -1 ? cout << "Not adjacent!" << endl : cout << "They are adjacent with an edge of weight " << weight << endl;
          }
          catch(const runtime_error& notFound)
          {
            cerr << notFound.what() << endl;
          }
          break;
        case 6:
          try
          {
            char data;
            cout << "Enter the starting vertex for Depth First Search" << endl;
            cout << "Starting Vertex: ";
            cin >> data;
            my_dir.DFS(data);
            my_dir.reset();
          }
          catch(const runtime_error& notFound)
          {
            my_dir.reset();
            cerr << notFound.what() << endl;
          }
          break;
        case 7:
          try
          {
            char data;
            cout << "Enter the starting vertex for Breadth First Search" << endl;
            cout << "Starting Vertex: ";
            cin >> data;
            my_dir.BFS(data);
            my_dir.reset();
          }
          catch(const runtime_error& notFound)
          {
            my_dir.reset();
            cerr << notFound.what() << endl;
          }
          break;
        case 8:
          try
          {
            char fromVertex;
            cout << "Enter the starting and ending vertex you would like the shortest path to" << endl;
            cout << "Starting Vertex: ";
            cin >> fromVertex;
            my_dir.shortPath(fromVertex);
            my_dir.reset();
          }
          catch(const runtime_error& notFound)
          {
            my_dir.reset();
            cerr << notFound.what() << endl;
          }
          break;
        case 9:
          try
          {
            my_dir.clear();
            cout << "Cleared!" << endl;
          }
          catch(const runtime_error& empty)
          {
            cerr << empty.what() << endl;
          }
          break;
        case 10:
          try
          {
            char fromVertex, toVertex;
            double weight;
            cout << "Inserting a new edge. ";
            cout << "Please enter the Starting Vertex, ";
            cout << "the Ending Vertex and the weight of the Edge to be added" << endl;
            cout << "NOTE: Negative weights are not accepted" << endl << endl;
            cout << "Starting Vertex: ";
            cin >> fromVertex;
            cout << "Ending Vertex: ";
            cin >> toVertex;
            cout << "Weight: ";
            cin >> weight;

            my_dir.insert(fromVertex, toVertex, weight);

          }
          catch(const runtime_error& notFound)
          {
            cerr << notFound.what() << endl;
          }
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
  cout << "\nSuccesfull Termination of program" << endl;
  return 0;
}
