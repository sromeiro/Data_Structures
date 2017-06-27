#ifndef TREENODE_H
#define TREENODE_H
#include<stdexcept>
#include<iostream>

using namespace std;

template <class Type> //Template "Type" definition for friend linkedTree class
class linkedTree; //Needed for Friend Class definition inside the class
template <class Type>
class maxHeapTree;
template <class Type>
class avlTree;

template <class Type> //Template "Type" definition for treeNode class
class treeNode
{
  private:
    Type value; //Data type stored in the Node
    int height; //Tracks height of each node
    short int balanceFactor; //-1 Left High, 0 Balanced, 1 Right High
    int key;
    treeNode * parent;
    treeNode * leftChild;
    treeNode * rightChild;

  public:
    //Default constructor initialized to default values
    treeNode(): height(0), balanceFactor(0), key(0) , parent(NULL) , leftChild(NULL) , rightChild(NULL) {}
    treeNode(Type data) :  height(0), balanceFactor(0), key(0), parent(NULL), leftChild(NULL), rightChild(NULL)
    {
      //Set parameters and initialize user data here if needed
      value = data;
    }
    void setKey(int key_to_set)
    {
        key = key_to_set;
    }
    void setValue(Type value_to_set)
    {
        value = value_to_set;
    }
    Type getValue()
    {
        return value;
    }
    int getKey()
    {
        return key;
    }

    //Updates height of the node. Relies on the height of its children
    void updateHeight()
    {
      height = 1; //Set height initially to 1 before updating regardless of what it is

      if(leftChild == NULL && rightChild == NULL)
      {
        height = 0; //No children then height is 0
      }

      else if(leftChild == NULL)
      {
        //If no left child exists. Height should only access right child
        height += rightChild->height;
      }

      else if(rightChild == NULL)
      {
        //If no right child exists. Height should only access left child
        height += leftChild->height;
      }

      else
      {
        //Both childs exist. Height should only update based on the highest one.
        height += (leftChild->height >= rightChild->height ? leftChild->height : rightChild->height);
      }
    }

    //Default destructor
    ~treeNode()
    {

    }

    //Friend class to have access to all private members
    friend class linkedTree<Type>;
    friend class maxHeapTree<Type>;
    friend class avlTree<Type>;
};


#endif
