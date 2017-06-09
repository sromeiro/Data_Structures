#include "DynStack.h"
#include "DynQueue.h"
#include <iostream>

using namespace std;

typedef string dataType; //Change the data type here if needed

int main() {
  //Instantiate a Queue
  DynStack <dataType> myStack;
  //DynQueue <dataType> myQueue;

  char option; //Used to select between Stacks 's' or 'q' Queues
  int run_menu = 1;
  cout << "Welcome!\nPlease select from the following options which type of";
  cout << " container you would like to create:" << endl << endl;

  cout << "***********************************" << endl;
  cout << "*                                 *" << endl;
  cout << "*    Enter the desired character  *" << endl;
  cout << "*    (s). Stacks                  *" << endl;
  cout << "*    (q). Queues                  *" << endl;
  cout << "*                                 *" << endl;
  cout << "***********************************" << endl;
  cout << endl;
  cout << "Selection: ";
  cin >> option;
  cout << "\nYou selected: \'" << option << "\'" << endl;

  switch (option) {
    case 's':
      //HMMMM
      break;
    case 'q':
      //Any code needed here?
      break;
    default:
      cout << "This is an invalid option. Please restart the program";
          cout << " and try again." << endl;
          return 1; //Early termination of program
  }

  //Block that will handle the menu selection for Stacks
  if (option == 's') {
    int num_select; //Used to select from the menu options below
    cout << "For your new Stack, please select from the following options\n" << endl;

    cout << "******************************************" << endl;
    cout << "*                                        *" << endl;
    cout << "*    Enter the desired number            *" << endl;
    cout << "*    1.  Return capacity                 *" << endl;
    cout << "*    2.  Number of items in the Stack    *" << endl;
    cout << "*    3.  View the first item             *" << endl;
    cout << "*    4.  Insert an item                  *" << endl;
    cout << "*    5.  Remove an item                  *" << endl;
    cout << "*    6.  Display items                   *" << endl;
    cout << "*    7.  Clear Stack                     *" << endl;
    cout << "*    8.  Exit                            *" << endl;
    cout << "*                                        *" << endl;
    cout << "******************************************" << endl;
    cout << endl;
    while (run_menu) {
      cout << "Selection: ";
      cin >> num_select;
      cout << endl;

      switch (num_select) {
        case 1:
          //Capacity of Stack
          cout<<"Capacity : "<<myStack.capacity()<<endl;
              break;
        case 2:
          //Size of Stack
          cout<<"Current Size : " <<myStack.size()<<endl;
              break;
        case 3:
          //Top of the Stack
          cout<<"Top :  ["<<myStack.top()<<"]"<<endl;
              break;
        case 4: {
          //****** NEEDS TO BE FIXED ******//
          //Push an item on the Stack
          dataType item;
          cout << "Please enter the number you want to put into the Stack" << endl;
          cout << "Number: ";
          cin >> item;
          myStack.push(item);
          break;
        }
        case 5: {
          //****** NEEDS TO BE FIXED ******//
          //Pop item from the Stack
          cout<<"Popped :  ["<<myStack.pop()<<"]"<<endl;
          break;
        }
        case 6:
          //Display items in the Stack
          myStack.display();
              break;
        case 7:
          //****** NEEDS TO BE FIXED ******//
          //Clears items from Stack
          myStack.clear();
              break;
        case 8:
          cout << "\nExiting program" << endl;
              run_menu = 0; //Successful termination of program
              break;

        default:
          cout << "This is an invalid option. Please restart the program";
              cout << " and try again." << endl;
              run_menu = 0; //Early termination of program
      }
    }
  }

    //Block that will handle the menu selection for Queues
  else {
    int num_select; //Used to select from the menu options below
    cout << "For your new Queue, please select from the following options\n" << endl;

    cout << "******************************************" << endl;
    cout << "*                                        *" << endl;
    cout << "*    Enter the desired number            *" << endl;
    cout << "*    1.  Return capacity                 *" << endl;
    cout << "*    2.  Number of items in the Queue    *" << endl;
    cout << "*    3.  View the first item             *" << endl;
    cout << "*    4.  Insert an item                  *" << endl;
    cout << "*    5.  Remove an item                  *" << endl;
    cout << "*    6.  Display items                   *" << endl;
    cout << "*    7.  Clear Queue                     *" << endl;
    cout << "*    8.  Exit                            *" << endl;
    cout << "*                                        *" << endl;
    cout << "******************************************" << endl;
    cout << endl;
    while (run_menu) {
      cout << "Selection: ";
      cin >> num_select;
      cout << endl;

//            switch (num_select) {
//                case 1:
//                    //Capacity of Queue
//                    myQueue.capacity();
//                    break;
//                case 2:
//                    //Size of Queue
//                    myQueue.size();
//                    break;
//                case 3:
//                    //Front item of Queue
//                    myQueue.front();
//                    break;
//                case 4: {
//                    //Pushes an item to the end of the Queue
//                    dataType item;
//                    cout << "Please enter the number you want to put into the Queue" << endl;
//                    cout << "Number: ";
//                    cin >> item;
//                    myQueue.enqueue(item);
//                    break;
//                }
//                case 5: {
//                    //Removes an item from the back of the Queue
//                    cout << "Removed " << myQueue.dequeue() << " from the Queue" << endl;
//                    break;
//                }
//                case 6:
//                    //Display items in the Queue
//                    myQueue.display();
//                    break;
//                case 7:
//                    //Clears all items in the Queue
//                    myQueue.clear();
//                    break;
//                case 8:
//                    cout << "\nExiting program" << endl;
//                    run_menu = 0; //Successful termination of program
//                    break;
//
//                default:
//                    cout << "This is an invalid option. Please restart the program";
//                    cout << " and try again." << endl;
//                    run_menu = 0; //Early termination of program
//            }
    }
  }

  cout << "\nSuccessful termination of program" << endl;
  return 0;
}