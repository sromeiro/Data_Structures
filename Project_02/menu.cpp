#include<cstdlib>
#include"stack.h"
#include"queue.h"

typedef int dataType; //Change the data type here if needed


int main()
{
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

  switch(option)
  {
    case 's':
    {
      //Instantiate a Stack
      Stack<dataType> myStack;
      break;
    }
    case 'q':
    {
      //Instantiate a Queue
      Queue<dataType> myQueue;
      break;
    }
    default:
      cout << "This is an invalid option. Please restart the program";
      cout << " and try again." << endl;
      return 1; //Early termination of program
  }

  //Block that will handle the menu selection for Stacks
  if(option == 's')
  {
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
    while(run_menu)
    {
      cout << "Selection: ";
      cin >> num_select;
      cout<<endl;

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
  else
  {
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
    while(run_menu)
    {
      cout << "Selection: ";
      cin >> num_select;
      cout<<endl;

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
