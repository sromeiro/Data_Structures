#ifndef DOUBLE_NODE_H
#define DOUBLE_NODE_H

#include <iostream>

template <class Type>      //let compiler know DoublyLinkedList is a class template of TYPE for friend class
class DoublyLinkedList;

template <class Type>
class DoubleNode
{
  private:
    Type data;
    DoubleNode<Type> * next;
    DoubleNode<Type> * previous;
  public:
    DoubleNode(Type const & our_data,DoubleNode * our_next,DoubleNode * our_prev) : data(0), next(NULL), previous(NULL)
    {
        data = our_data;
        next = our_next;
        previous = our_prev;
    }
    //Get function for our data
    Type getData() const
    {
        return data;
    }
    //Get function for our next pointer
    DoubleNode * getNext() const
    {
        return next;
    }
    //Get function for our previous pointer
    DoubleNode * getPrevious() const
    {
        return previous;
    }
    ~DoubleNode()
    {

    }
    friend class DoublyLinkedList<Type>;          //DoublyLinkedList is a friend class
};

#endif
