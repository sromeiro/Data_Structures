#ifndef SINGLE_NODE_H
#define SINGLE_NODE_H

#include <iostream>

template <class Type>   //need to tell compiler CyclicLinkedList is a template class before SingleNode to create friend class
class CyclicLinkedList; //(without this will generate compiler error)

template <class Type>
class SingleNode
{
  private:

  public:
    SingleNode(Type const &,SingleNode *);                        //Constructor
    //I believe these must be public (can change later if needed)
    //VARIABLES
    Type data;                                                    //Contains data of (Type)
    SingleNode * next;                                            //Pointer to a SingleNode object, referred to as next
    //FUNCTIONS
    Type getData() const;                                         //get data
    SingleNode *getNext() const;                                  //return the next pointer
    ~SingleNode();
    //FRIEND
    friend class CyclicLinkedList<Type>;                          //friend of CyclicLinkedList
};

#endif
