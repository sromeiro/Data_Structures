#include "stack.h"
#include "queue.h"
#include <string>
#include <iostream>

using namespace std;

typedef string dataType; //Change the data type here if needed

int main() {
  int size;
  string random_garbage;
  cout<< "Welcome!\nPlease set the size of your new container. ";
  cout << "Enter a non-integer for the default size." << endl;
  cout<<"SIZE : ";
  cin >> size;
  if (cin.fail())
  {
    cin.clear();
    size = 15;
    cin >> random_garbage;
    cout<< "Default capacity set to 15." << endl << endl;
  }

  DynStack<dataType> myStack(size);
  DynQueue<dataType> myQueue(size);
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
      break;
    case 'q':
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
      cout << "\nSelection: ";
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
          try
          {
            cout<<"Top :  ["<<myStack.top()<<"]"<<endl;
          }
          catch (const out_of_range& underflow_error)
          {
            cerr << underflow_error.what() << endl;
          }
              break;
        case 4: {
          //Push an item on the Stack
          dataType item;
          cout << "Please enter the number you want to put into the Stack" << endl;
          cout << "Number: ";
          cin >> item;
          if(cin.fail()) { cin.clear();break; } //Inline that handles inputs that aren't of requested type
          myStack.push(item);
          break;
        }
        case 5: {
          //Pop item from the Stack
          try
          {
            cout<<"Popped :  ["<<myStack.pop()<<"]"<<endl;
          }
          catch(const out_of_range& underflow_error)
          {
            cerr <<underflow_error.what() << endl;
          }
          break;
        }
        case 6:
          //Display items in the Stack
          try
          {
            myStack.display();
          }
          catch(const out_of_range& underflow_error)
          {
            cerr <<underflow_error.what() << endl;
          }
              break;
        case 7:
          //****** NEEDS TO BE FIXED ******//
          //Clears items from Stack
          try
          {
            myStack.clear();
          }
          catch(const out_of_range& underflow_error)
          {
            cerr <<underflow_error.what() << endl;
          }
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
      cout << "\nSelection: ";
      cin >> num_select;
      cout << endl;

      switch (num_select) {
        case 1:
          //Capacity of Queue
          cout<<"Capacity : "<<myQueue.capacity()<<endl;
              break;
        case 2:
          //Size of Queue
          cout<<"Current Size : " <<myQueue.size()<<endl;
              break;
        case 3:
          //Front item of Queue
          try
          {
            cout<<"Front :  ["<<myQueue.front()<<"]"<<endl;
          }
          catch (const out_of_range& underflow_error)
          {
            cerr << underflow_error.what() << endl;
          }
              break;
        case 4: {
          //Pushes an item to the end of the Queue
          dataType item;
          cout << "Please enter the number you want to put into the Queue" << endl;
          cout << "Number: ";
          cin >> item;
          if(cin.fail()) { cin.clear();break; } //Inline that handles inputs that aren't of requested type
          myQueue.enqueue(item);
          break;
        }
        case 5: {
          //Removes an item from the back of the Queue
          try
          {
            cout << "Dequeued: [" << myQueue.dequeue() << "]" << endl;
          }
          catch(const out_of_range& underflow_error)
          {
            cerr <<underflow_error.what() << endl;
          }
          break;
        }
        case 6:
          //Display items in the Queue
          try
          {
            myQueue.display();
          }
          catch(const out_of_range& underflow_error)
          {
            cerr <<underflow_error.what() << endl;
          }
              break;
        case 7:
          //Clears all items in the Queue
          try
          {
            myQueue.clear();
          }
          catch(const out_of_range& underflow_error)
          {
            cerr <<underflow_error.what() << endl;
          }
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

  cout << "\nSuccessful termination of program" << endl;
  return 0;
}