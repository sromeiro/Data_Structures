#include<cstdlib>
#include<iostream>

using namespace std;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Simple test driver file for small code snippets.
 *  Can be used to test some simple code functionality before implementation
 *  into a file with lots of code. This should be an easy and simple way
 *  to test small concepts.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


int main()
{
  cout << "****** Testing functionality ******" << endl;

  //int *array;
  int array[5] = {5,6,7,8,9};
  //array[3];
  array[0] = 1;
  int i = 0; //Start from the front of the queue
  cout << "List of items stored in the Queue:" << endl;
  cout << "Front\n" << "  |\n" << "  V" << endl; //Arrow that points down
  for(i; i <= 5; i++)
  {
    cout << " [" << array[i] << "]";
  }
  cout << endl;


  return 0;
}
