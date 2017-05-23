#ifndef CYCLIC_LINKED_LIST_H
#define CYCLIC_LINKED_LIST_H

#include <iostream>
#include "SingleNode.h"

template <class Type>
class CyclicLinkedList
{
  private:
    Type * head_ptr;                                            //head pointer
    Type * tail_ptr;                                            //tail pointer
    int mySize;                                                 //Size of linked list
  public:
    CyclicLinkedList();
    int size() const;                                           //return # of items on list
    bool empty() const;                                         //Returns true if list empty (otherwise return false)
    Type front() const;                                         //Retrieves the object store in the node pointed to by head pointer
    Type back() const;                                          //Retrieves the object store in the node pointed to by tail pointer
    SingleNode<Type> *head() const;                             //Returns head pointer
    SingleNode<Type> *tail() const;                             //Returns tail pointer
    int count(Type const &) const;                              //Returns # of nodes in linked list storing a value equal to
    //MUTATORS
    void push_front(Type const &);                              //refer to cpp for explanation
    void push_back(Type const &);                               //Similar to push front but places a new node at the back of list
    Type pop_front();                                           //refer to cpp for explanation
    int erase(Type const &);                                    //refer to cpp for explanation
};

#endif
