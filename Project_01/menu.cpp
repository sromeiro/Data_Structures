#include "SingleNode.h"
#include "CyclicLinkedList.h"
#include "DoubleNode.h"
#include "DoublyLinkedList.h"
#include <cstdlib>
#include <ctime>

int main()
{
  srand(time(NULL));
  CyclicLinkedList<int> singleList;
  for(int i=0;i<3;i++)
  {
    int num = (rand() %3 +1);
    singleList.push_front(num);
  }

  DoublyLinkedList<int> doubleList;
  for(int i=0;i<3;i++)
  {
    int num = (rand() %3 +1);
    doubleList.push_front(num);
  }


  char option; //Used to select between Single 's' or Doubly 'd' lists
  int run_menu = 1;
  cout << "Welcome!\nPlease select from the following options which type of list";
  cout << " you would like to create:" << endl << endl;

  cout << "***********************************" << endl;
  cout << "*                                 *" << endl;
  cout << "*    Enter the desired character  *" << endl;
  cout << "*    (s). Singly Linked List      *" << endl;
  cout << "*    (d). Doubly Linked List      *" << endl;
  cout << "*                                 *" << endl;
  cout << "***********************************" << endl;
  cout << endl;
  cout << "Selection: ";
  cin >> option;
  cout << "\nYou selected: \'" << option << "\'" << endl;

  switch(option)
  {
    case 's':
      cout << "We're in CASE \'s\'" << endl;
          //Instantiate Singly Linked List here
          break;
    case 'd':
      cout << "We're in CASE \'d\'" << endl;
          //Instantiate Doubly Linked List here
          break;

    default:
      cout << "This is an invalid option. Please restart the program";
          cout << " and try again." << endl;
          return 1; //Early termination of program
  }

  //Block that will handle the menu selection for Singly Linked Lists
  if(option == 's')
  {
    int num_select; //Used to select from the menu options below
    cout << "\nEntered first IF block" << endl;

    cout << "For your new list, please select from the following options\n" << endl;

    cout << "******************************************" << endl;
    cout << "*                                        *" << endl;
    cout << "*    Enter the desired number            *" << endl;
    cout << "*    1.  Create List                     *" << endl;
    cout << "*    2.  Count number of items           *" << endl;
    cout << "*    3.  Retrieve first item             *" << endl;
    cout << "*    4.  Retrieve last item              *" << endl;
    cout << "*    5.  Count instances of an item      *" << endl;
    cout << "*    6.  Push front                      *" << endl;
    cout << "*    7.  Push back                       *" << endl;
    cout << "*    8.  Pop front                       *" << endl;
    cout << "*    9.  Pop back                        *" << endl;
    cout << "*    10. Delete instance(s) of an item   *" << endl;
    cout << "*    11. Print list                      *" << endl;
    cout << "*    12. Exit                            *" << endl;
    cout << "*                                        *" << endl;
    cout << "******************************************" << endl;
    cout << endl;
    while(run_menu)
    {
      cout << "Selection: ";
      cin >> num_select;
      cout<<endl;

      switch (num_select) {
        case 1:
        if(singleList.size() >= 1)
        {
          cout << "List has already been generated randomly." << endl;
          cout << "Please pop all items from the current list to generate a new one" << endl;
        }
        else
        {
          for(int i=0;i<3;i++)
          {
            int num = (rand() %3 +1);
            singleList.push_front(num);
          }
          cout << "New list created!" << endl;
        }
              break;
        case 2:
          cout << "Number of items in list : " << singleList.size() << endl;
              break;
        case 3:
          cout << "First item: "<< singleList.front() << endl;
              break;
        case 4:
          cout << "Last item: " << singleList.back() << endl;
              break;
        case 5:
          int num_to_count;
              cout << "Enter item to count : ";
              cin >> num_to_count;
              cout <<"Item : "<<num_to_count<<" appears : "<< singleList.count(num_to_count) << " times." <<endl;
              break;
        case 6:
          int num_to_push;
              cout << "Enter item to push to front : ";
              cin >> num_to_push;
              singleList.push_front(num_to_push);
              cout << "Pushed : "<<num_to_push<<" to front" << endl;
              break;
        case 7:
          int num_to_back;
              cout << "Enter item to push back : ";
              cin >> num_to_back;
              singleList.push_back(num_to_back);
              cout << "Pushed back : "<<num_to_back<<" to back" << endl;
              break;
        case 8:
          if(singleList.size() >= 1)
          {
            cout << "Popped front! Item Popped : ";
            cout << singleList.pop_front() <<endl;
          }

          else
          {
            cout << "List is empty, no items to pop." << endl;
          }

          break;
        case 9:
          if(singleList.size() >= 1)
          {
            cout << "Popped back! Item Popped : ";
            cout << singleList.pop_back() <<endl;
          }

          else
          {
            cout << "List is empty, no items to pop." << endl;
          }

          break;
        case 10:
          int to_delete;
              int num_deleted;
              cout << "Enter item to delete : ";
              cin >> to_delete;
              num_deleted = singleList.erase(to_delete);
              cout << "All instances of item : " << to_delete <<" have been deleted"<<endl;
              cout << "Deleted : " <<num_deleted << " times" <<endl;
              break;
        case 11:
          cout<<"PRINTING LIST"<<endl;
              cout<<endl;
              singleList.print_list();
              break;
        case 12:
          cout << "We are in CASE 12" << endl;
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

    //Block that will handle the menu selection for Double` Linked Lists
  else
  {
    int num_select; //Used to select from the menu options below
    cout << "\nEntered ELSE block" << endl;

    cout << "For your new list, please select from the following options\n" << endl;

    cout << "******************************************" << endl;
    cout << "*                                        *" << endl;
    cout << "*    Enter the desired number            *" << endl;
    cout << "*    1.  Create List                     *" << endl;
    cout << "*    2.  Count number of items           *" << endl;
    cout << "*    3.  Retrieve first item             *" << endl;
    cout << "*    4.  Retrieve last item              *" << endl;
    cout << "*    5.  Count instances of an item      *" << endl;
    cout << "*    6.  Push front                      *" << endl;
    cout << "*    7.  Push back                       *" << endl;
    cout << "*    8.  Pop front                       *" << endl;
    cout << "*    9.  Pop back                        *" << endl;
    cout << "*    10. Delete instance(s) of an item   *" << endl;
    cout << "*    11. Print list                      *" << endl;
    cout << "*    12. Exit                            *" << endl;
    cout << "*                                        *" << endl;
    cout << "******************************************" << endl;
    cout << endl;
    while(run_menu) {
      cout << "Selection: ";
      cin >> num_select;
      cout<<endl;

      switch (num_select) {
        case 1:
          cout << "We are in CASE 1" << endl;
          if(doubleList.size() >= 1)
          {
            cout << "List has already been generated randomly." << endl;
            cout << "Please pop all items from the current list to generate a new one" << endl;
          }
          else
          {
            for(int i=0;i<3;i++)
            {
              int num = (rand() %3 +1);
              doubleList.push_front(num);
            }
            cout << "New list created!" << endl;
          }
              //Call appropriate function here
              break;
        case 2:
          cout << "We are in CASE 2" << endl;
              //Call appropriate function here
              break;
        case 3:
          cout << "We are in CASE 3" << endl;
              //Call appropriate function here
              break;
        case 4:
          cout << "We are in CASE 4" << endl;
              //Call appropriate function here
              break;
        case 5:
          cout << "We are in CASE 5" << endl;
              //Call appropriate function here
              break;
        case 6:
          int num_to_push;
              cout << "Enter item to push to front : ";
              cin >> num_to_push;
              doubleList.push_front(num_to_push);
              cout << "Pushed : "<<num_to_push<<" to front" << endl;
              break;
        case 7:
          int num_to_back;
              cout << "Enter item to push back : ";
              cin >> num_to_back;
              doubleList.push_back(num_to_back);
              cout << "Pushed back : "<<num_to_back<<" to back" << endl;
              break;
        case 8:
          if(doubleList.size() >= 1)
          {
            cout << "Popped front! Item Popped : ";
            cout << doubleList.pop_front() <<endl;
          }

          else
          {
            cout << "List is empty, no items to pop." << endl;
          }

          break;

        case 9:
          if(doubleList.size() >= 1)
          {
            cout << "Popped back! Item Popped : ";
            cout << doubleList.pop_back() <<endl;
          }

          else
          {
            cout << "List is empty, no items to pop." << endl;
          }

          break;
        case 10:
          cout << "We are in CASE 10" << endl;
              //Call appropriate function here
              break;
        case 11:
              doubleList.print();
              break;
        case 12:
          cout << "We are in CASE 12" << endl;
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
