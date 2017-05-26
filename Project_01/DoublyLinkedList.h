#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

template <class Type>
class DoublyLinkedList
{
  private:
    int mySize;                                //size of the list
    DoubleNode<Type> * head_ptr;                   //head pointer
    DoubleNode<Type> * tail_ptr;                   //tail pointer
  public:
    DoublyLinkedList() : mySize(0), head_ptr(NULL), tail_ptr(NULL){};           //default constructor
    //SIZE
    //returns size of linked list
    int size() const
    {
        return mySize;
    }
    //EMPTY
    //returns 1 or 0 depending if list empty or not
    bool empty() const
    {

    }
    //FRONT
    //returns object pointed to by head pointer
    Type front() const
    {

    }
    //BACK
    //returns object pointed to by tail pointer
    Type back() const
    {

    }
    //HEAD
    //returns head pointer
    DoubleNode<Type> *head() const
    {

    }
    //TAIL
    //returns tail pointer
    DoubleNode<Type> *tail() const
    {

    }
    //COUNT
    //returns number of nodes in list storing the same value in argument
    int count(Type const & value) const
    {

    }
    //PUSH_FRONT
    //Creates a new DoubleNode< Type > storing the argument, the next pointer of which is set to the current head pointer.
    // The head pointer is set to this new node.
    // If the list was originally empty,the tail pointer is set to point to the new node
    void push_front(Type const & value)
    {

    }
    //PUSH_BACK
    //Similar to push front but places a new node at the back of list
    void push_back(Type const & value)
    {

    }
    //POP FRONT
    //Deletes the node at the front of the linked list and, as necessary, update the head and tail pointers.
    //Return the object stored in the node being popped.
    Type pop_front()
    {
        //NEED UNDERFLOW EXCEPTION
    }
    //POP BACK
    //delete node at the end of the linked list and, as necessary, update the head and tail pointers.
    //Return the object stored in the node being popped
    Type pop_back()
    {
        //NEEED UNDERFLOW EXCEPTION
    }
    //ERASE
    //Delete the node(s) (from the front) in the linked list that contains the element equal to the argument
    //(use == to to test for equality with the retrieved element).
    //As necessary, update the head and tail pointers and the next pointer of any other node within the list.
    //Return the number of nodes that were deleted
    int erase(Type const &)
    {

    }
    ~DoublyLinkedList()
    {
        //NEED TO IMPLEMENT
    };
};

#endif
