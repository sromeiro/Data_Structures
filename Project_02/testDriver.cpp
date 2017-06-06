#include<cstdlib>
#include<iostream>

using namespace std;

int main()
{
  cout << "****** Testing functionality ******" << endl;

  //int *array;
  int array[3] = {5,6,7};
  //array[3];
  array[0] = 1;
  cout << "array[1] is: " << array[1] << endl;


  return 0;
}
