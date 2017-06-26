#ifndef DATAPROJ_MYTREENODE_H
#define DATAPROJ_MYTREENODE_H
#include <cstdlib>
#include <iostream>

using namespace std;

template <class Type>
class LinkedTree;
template <class Type>
class MaxHeapTree;

template <class Type>
class TreeNode
{
private:
    int key;                                  //For Heap tree only
    short int balanceFactor;                  //For AVL tree only
    Type value;
    TreeNode * parent;
    TreeNode * left;
    TreeNode * right;
public:
    TreeNode(): key(0), value(0) , parent(NULL) , left(NULL) , right(NULL) {}
    friend class LinkedTree<Type>;
    friend class MaxHeapTree<Type>;
    //NEED GETTER FUNCTIONS
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
};

#endif //DATAPROJ_MYTREENODE_H
