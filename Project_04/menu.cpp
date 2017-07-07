#include"graph.h"
#include"vertex.h"
#include"edge.h"
#include"dirGraph.h"
#include <fstream>
#include <iostream>

using namespace std;
int main()
{
  /*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
   ********************************************************************************************************************/

  string file_one = "C:\\Users\\Brett\\ClionProjects\\Project3_sub\\Project_04\\graph.txt";                              //CHANGE DIRECTORY
  //string file_one = "graph.txt";                              //CHANGE DIRECTORY

  /*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
   ********************************************************************************************************************/
  DirGraph<int> my_dir;
  my_dir.buildGraph(file_one);

  //cout<<my_dir.getVertex('B').getData()<<": number of edges "<<my_dir.getVertex('B').getNumEdges()<<endl;
  cout << "\nSuccesfull Termination of program" << endl;
  return 0;
}
