#ifndef TREENODE_H
#define TREENODE_H
#include<stdexcept>

template <class Type> //Template "Type" definition for friend linkedTree class

class linkedTree; //Needed for Friend Class definition inside the class

template <class Type> //Template "Type" definition for treeNode class
class treeNode
{
  private:
    Type value; //Data type stored in the Node
    int height; //Tracks height of each node
    short int balanceFactor; //-1 Left High, 0 Balanced, 1 Right High
    treeNode * parent;
    treeNode * leftChild;
    treeNode * rightChild;

  public:
    //Default constructor initialized to default values
    treeNode(Type data) : value(0), height(0), balanceFactor(0), parent(NULL), leftChild(NULL), rightChild(NULL)
    {
      //Set parameters and initialize user data here if needed
      value = data;
    }

    //Updates height of the node. Relies on the height of its children
    void updateHeight()
    {
      height = 1; //Set height initially to 1 before updating regardless of what it is

      if(leftChild == NULL && rightChild == NULL)
      {
        height = 0; //No children then height is 0
      }

      else if(leftChild->height >= rightChild->height)
      {
        //height of both children is equal or left is greater
        height += leftChild->height;
      }

      else
      {
        //height of right child is greater
        height += rightChild->height;
      }
    }

    void balance()
    {
      int tempRight, tempLeft; //Holds values of right and left child

      if(leftChild == NULL)
      {
        tempLeft = -1;
      }
      else if(rightChild == NULL)
      {
        tempRight = -1;
      }
      else
      {
        tempRight = rightChild->height;
        tempLeft = leftChild->height;
      }

      balanceFactor = tempRight - tempLeft;
    }

    //Default destructor
    ~treeNode()
    {

    }

    //Friend class to have access to all private members
    friend class linkedTree<Type>;

};


#endif
