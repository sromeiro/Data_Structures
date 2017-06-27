#include"treeNode.h"
#include"linkedTree.h"
#include"maxHeapTree.h"
#include"avlTree.h"
#include <string>
#include <iostream>

using namespace std;

typedef string dataType; //Change the data type here if needed

int main()
{
  // int size;
  // string random_garbage;
  // cout<< "Welcome!\nPlease set the size of your new container. ";
  // cout << "Enter a non-integer for the default size." << endl;
  // cout<<"SIZE : ";
  // cin >> size;
  // if (cin.fail())
  // {
  //   cin.clear();
  //   size = 15;
  //   cin >> random_garbage;
  //   cout<< "Default capacity set to 15." << endl << endl;

  linkedTree<dataType> myTree;
  maxHeapTree<dataType> myHeapTree;
  avlTree<dataType> myAvlTree;

  char option; //Used to select between General 'g', Heaps 'h' or AVL 'a'
  int run_menu = 1;
  cout << "Welcome!\nPlease select from the following options which type of";
  cout << " tree you would like to create:" << endl << endl;

  cout << "***********************************" << endl;
  cout << "*                                 *" << endl;
  cout << "*    Enter the desired character  *" << endl;
  cout << "*    (g). General Trees           *" << endl;
  cout << "*    (h). Heaps                   *" << endl;
  cout << "*    (a). AVL Trees               *" << endl;
  cout << "*                                 *" << endl;
  cout << "***********************************" << endl;
  cout << endl;
  cout << "Selection: ";
  cin >> option;
  cout << "\nYou selected: \'" << option << "\'" << endl;

  switch (option)
  {
    case 'g':
      break;
    case 'h':
      break;
    case 'a':
      break;
    default:
      cout << "This is an invalid option. Please restart the program";
      cout << " and try again." << endl;
      return 1; //Early termination of program
  }

//****************************************************************************//
//===================BLOCK THAT HANDLES GENERAL TREES=========================//
//****************************************************************************//


//==============================================================================
//Most of the cases below are being used to test functions from LinkedTree class
//They don't reflect what menu needs to be doing. Testing purposes only.
//==============================================================================
  if (option == 'g')
  {
    int num_select; //Used to select from the menu options below
    cout << "For your new tree, please select from the following options\n" << endl;

    cout << "**********************************************" << endl;
    cout << "*                                            *" << endl;
    cout << "*    Enter the desired number                *" << endl;
    cout << "*    1.  Return root                         *" << endl;
    cout << "*    2.  Return size                         *" << endl;
    cout << "*    3.  Return height                       *" << endl;
    cout << "*    4.  Return height (node)                *" << endl;
    cout << "*    5.  Is tree empty?                      *" << endl;
    cout << "*    6.  Return number of leaves             *" << endl;
    cout << "*    7.  Return number of siblings (node)    *" << endl;
    cout << "*    8.  Find node (data)                    *" << endl;
    cout << "*    9.  Print Preorder                      *" << endl;
    cout << "*    10. Print Postorder                     *" << endl;
    cout << "*    11. Print Inorder                       *" << endl;
    cout << "*    12. Clear tree                          *" << endl;
    cout << "*    13. Insert (data)                       *" << endl;
    cout << "*    14. Delete (data)                       *" << endl;
    cout << "*    15. Exit                                *" << endl;
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
        {
          try
          {
            treeNode<dataType> * myRoot;
            myRoot = myTree.getRoot();
            cout << "Returned root: [" << myRoot->getValue() << "]" << endl;
          }
          catch(const runtime_error& empty)
          {
            cerr << empty.what() << endl;
          }
        }
          break;
        case 2:
          {
            try
            {
              cout << "Size of this tree is: " << myTree.getSize() << endl;
            }
            catch(const runtime_error& empty)
            {
              cerr << empty.what() << endl;
            }
          }
          break;
        case 3:
          {
            try
            {
              cout << "Height of root is: " << myTree.getHeight() << endl;
            }
            catch(const runtime_error& empty)
            {
              cerr << empty.what() << endl;
            }
          }
          break;
        case 4:
          {
            cout << "What node would you like the height for?" << endl;
            cout << "node: ";
            dataType node;
            cin >> node;
            treeNode<dataType> * found;
            try
            {
              found = myTree.findNode(node);
              cout << "Height of node [" << node << "] is: " << myTree.getHeight(found) << endl;
            }
            catch(const runtime_error& notFound)
            {
              cerr << notFound.what() << endl;
            }
          }
          break;
        case 5:
          {
            myTree.empty() ? cout << "Empty!" << endl : cout << "Not empty!" << endl;
          }
          break;
        case 6:
          {
            cout << "Number of leaves in tree is: " << myTree.leaves() << endl;
          }
          break;
        case 7:
          {
            cout << "Enter the node to check for siblings: ";
            dataType node;
            cin >> node;
            treeNode<dataType> * found;
            try
            {
              found = myTree.findNode(node);
              cout << "Number of sibling is: " << myTree.siblings(found) << endl;
            }
            catch(const runtime_error& notFound)
            {
              cerr << notFound.what() << endl;
            }
          }
          break;
        case 8:
          {
            dataType data;
            cout << "Enter the data item you're looking for: ";
            cin >> data;
            treeNode<dataType> * found;
            try
            {
              found = myTree.findNode(data);
              cout << "Returned data item: [" << found->getValue() << "] has been found!" << endl;
            }
            catch(const runtime_error& notFound)
            {
              cerr << notFound.what() << endl;
            }
          }
          break;
        case 9:
          myTree.preorder();
          break;
        case 10:
          myTree.postorder();
          break;
        case 11:
          myTree.inorder();
          break;
        case 12:
          {
            try
            {
              myTree.clear();
              cout << "Tree has been cleared" << endl;
            }
            catch(const runtime_error& notFound)
            {
              cerr << notFound.what() << endl;
            }
          }
          break;
        case 13:
          {
            cout << "Please enter a data value to enter into the tree: ";
            dataType data;
            cin >> data;
            myTree.insert(data);
            cout << "Value: " << data << " inserted" << endl;
          }
          break;
        case 14:
          {
            cout << "Please enter a data value to delete from the tree: ";
            dataType data;
            cin >> data;
            try
            {
              myTree.del(data);
              cout << "Value: " << data << " deleted" << endl;
            }
            catch(const runtime_error& notFound)
            {
              cerr << notFound.what() << endl;
            }
          }
          break;
        case 15:
          cout << "\nExiting program" << endl;
          run_menu = 0; //Successful termination of program
          break;
        case 16:
          {
            dataType data;
            cout << "Print info for? ";
            cin >> data;
            treeNode<dataType> * found;
            try
            {
              found = myTree.findNode(data);
              myTree.printing(found);
            }
            catch(const runtime_error& notFound)
            {
              cerr << notFound.what() << endl;
            }
          }
          break;
        default:
          cout << "This is an invalid option. Please restart the program";
          cout << " and try again." << endl;
          run_menu = 0; //Early termination of program
      }
    }
  }

//****************************************************************************//
//=====================BLOCK THAT HANDLES HEAPS===============================//
//****************************************************************************//

  else if (option == 'h')
  {
    int num_select; //Used to select from the menu options below
    cout << "For your new ####, please select from the following options\n" << endl;

    cout << "******************************************" << endl;
    cout << "*                                        *" << endl;
    cout << "*    Enter the desired number            *" << endl;
    cout << "*    1.  Return root                     *" << endl;
    cout << "*    2.  Return size                     *" << endl;
    cout << "*    3.  Return height                   *" << endl;
    cout << "*    4.  Is tree empty?                  *" << endl;
    cout << "*    5.  Return number of leaves         *" << endl;
    cout << "*    6.  Print                           *" << endl;
    cout << "*    7.  Clear tree                      *" << endl;
    cout << "*    8.  Insert (key,data)               *" << endl;
    cout << "*    9.  Delete                          *" << endl;
    cout << "*    10. Exit                            *" << endl;
    cout << "*                                        *" << endl;
    cout << "******************************************" << endl;
    cout << endl;
    while (run_menu)
    {
      cout << "\nSelection: ";
      cin >> num_select;
      cout << endl;

      switch (num_select)
      {
        case 1:
          try
          {
            cout << "Root is : " << myHeapTree.getMax() << endl;
          }
          catch(const runtime_error& empty)
          {
            cerr << empty.what() << endl;
          }
          break;
        case 2:
          try
          {
            cout << "Size is : " << myHeapTree.getSize() << endl;
          }
          catch(const runtime_error& empty)
          {
            cerr << empty.what() << endl;
          }
          break;
        case 3:
          try
          {
            cout << "Tree Height is : " << myHeapTree.height() << endl;
          }
          catch(const runtime_error& empty)
          {
            cerr << empty.what() << endl;
          }
          break;
        case 4:
          myHeapTree.empty() ? cout << "Empty!" << endl : cout << "Not empty!" << endl;
          break;
        case 5:
          try
          {
            cout << "Number of Leaves : " << myHeapTree.leaves() << endl;
          }
          catch(const runtime_error& empty)
          {
            cerr << empty.what() << endl;
          }
          break;
        case 6:
          try
          {
            myHeapTree.print();
          }
          catch(const runtime_error& empty)
          {
            cerr << empty.what() << endl;
          }
          break;
        case 7:
          try
          {
            myHeapTree.clear();
            cout<<"Tree Cleared"<<endl;
          }
          catch(const runtime_error& empty)
          {
            cerr << empty.what() << endl;
          }
          break;
        case 8:
        {
          cout << "Please enter a key (integer) : ";
          int key;
          cin >> key;
          cout << endl;
          cout << "Please enter data : ";
          dataType data;
          cin >> data;
          myHeapTree.insert(key, data);
          cout << "Key : " << key << " Value: " << data << " inserted" << endl;
        }
          break;
        case 9:
          try
          {
            cout<<"Deleting Max : "<<myHeapTree.getMax()<<endl;
            myHeapTree.delMax();
            cout<<"Delete Successful"<<endl;
          }
          catch(const runtime_error& empty)
          {
            cerr << empty.what() << endl;
          }
          break;
        case 10:
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

//****************************************************************************//
//=====================BLOCK THAT HANDLES AVL TREES===========================//
//****************************************************************************//

else if (option == 'a')
{
  int num_select; //Used to select from the menu options below
  cout << "For your new tree, please select from the following options\n" << endl;

  cout << "**********************************************" << endl;
  cout << "*                                            *" << endl;
  cout << "*    Enter the desired number                *" << endl;
  cout << "*    1.  Return root                         *" << endl;
  cout << "*    2.  Return size                         *" << endl;
  cout << "*    3.  Return height                       *" << endl;
  cout << "*    4.  Return height (node)                *" << endl;
  cout << "*    5.  Is tree empty?                      *" << endl;
  cout << "*    6.  Return number of leaves             *" << endl;
  cout << "*    7.  Return number of siblings (node)    *" << endl;
  cout << "*    8.  Find node (data)                    *" << endl;
  cout << "*    9.  Print Preorder                      *" << endl;
  cout << "*    10. Print Postorder                     *" << endl;
  cout << "*    11. Print Inorder                       *" << endl;
  cout << "*    12. Clear tree                          *" << endl;
  cout << "*    13. Insert (data)                       *" << endl;
  cout << "*    14. Delete (data)                       *" << endl;
  cout << "*    15. Exit                                *" << endl;
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
        {
          try
          {
            treeNode<dataType> * myRoot;
            myRoot = myAvlTree.getRoot();
            cout << "Returned root: [" << myRoot->getValue() << "]" << endl;
          }
          catch(const runtime_error& empty)
          {
            cerr << empty.what() << endl;
          }
        }
        break;
      case 2:
        {
          try
          {
            cout << "Size of this tree is: " << myAvlTree.getSize() << endl;
          }
          catch(const runtime_error& empty)
          {
            cerr << empty.what() << endl;
          }
        }
        break;
      case 3:
        {
          try
          {
            cout << "Height of root is: " << myAvlTree.getHeight() << endl;
          }
          catch(const runtime_error& empty)
          {
            cerr << empty.what() << endl;
          }
        }
        break;
      case 4:
        {
          cout << "What node would you like the height for?" << endl;
          cout << "node: ";
          dataType node;
          cin >> node;
          treeNode<dataType> * found;
          try
          {
            found = myAvlTree.find(node);
            cout << "Height of node [" << node << "] is: " << myAvlTree.getHeight(found) << endl;
          }
          catch(const runtime_error& notFound)
          {
            cerr << notFound.what() << endl;
          }
        }
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
        {
          dataType data;
          cout << "Enter the data item you're looking for: ";
          cin >> data;
          treeNode<dataType> * found;
          try
          {
            found = myAvlTree.find(data);
            cout << "Returned data item: [" << found->getValue() << "] has been found!" << endl;
          }
          catch(const runtime_error& notFound)
          {
            cerr << notFound.what() << endl;
          }
        }
        break;
      case 9:
        myAvlTree.preorder();
        break;
      case 10:
        myAvlTree.postorder();
        break;
      case 11:
        myAvlTree.inorder();
        break;
      case 12:
        //Code
        break;
      case 13:
        {
          cout << "Please enter a data value to enter into the tree: ";
          dataType data;
          cin >> data;
          myAvlTree.insert(data);
        }
        break;
      case 14:
        //Code
        break;
      case 15:
        //Code
        break;
      case 16:
        {
          dataType data;
          cout << "Print info for? ";
          cin >> data;
          treeNode<dataType> * found;
          try
          {
            found = myAvlTree.find(data);
            //myAvlTree.printing(found);
          }
          catch(const runtime_error& notFound)
          {
            cerr << notFound.what() << endl;
          }
        }
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
