#ifndef SINGLE_NODE_H
#define SINGLE_NODE_H

#include <iostream>

template <class Type>   //need to tell compiler CyclicLinkedList is a template class before SingleNode to create friend class
class CyclicLinkedList; //(without this will generate compiler error)

template <class Type>
class SingleNode
{
private:
    //VARIABLES
    Type data;                                                    //Contains data of (Type)
    SingleNode * next;                                            //Pointer to a SingleNode object, referred to as next
public:

    //FUNCTIONS
    //Default constructor
    SingleNode(Type const & our_data,SingleNode * ptr) : data(0),next(NULL) //data by default int, next by default NULL
    {
        data = our_data;
        next = ptr;
    }
    //GETDATA
    //get our data
    Type getData() const
    {
        return data;
    }
    //GETNEXT
    //returns next pointer
    SingleNode<Type>* getNext() const
    {
        return next;
    }
    //Default destructor
    ~SingleNode()
    {

    }
    //FRIEND
    friend class CyclicLinkedList<Type>;                          //friend of CyclicLinkedList
};

#endif
