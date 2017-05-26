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
        return head_ptr==NULL;                                                  //if head pointer is NULL then list is empty
    }
    //FRONT
    //returns object pointed to by head pointer
    Type front() const
    {
        if(mySize>=1)                                                           //check if item is in list
        {
            return head_ptr->data;
        }
    }
    //BACK
    //returns object pointed to by tail pointer
    Type back() const
    {
        if(mySize>=1)
        {
            return tail_ptr->data;
        }
    }
    //HEAD
    //returns head pointer
    DoubleNode<Type> *head() const
    {
        return head_ptr;
    }
    //TAIL
    //returns tail pointer
    DoubleNode<Type> *tail() const
    {
        return tail_ptr;
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
        DoubleNode<Type> * our_node = new DoubleNode<Type>(value,NULL,NULL);             //create a new node to push to front
        if(empty())                                                                      //if empty list
        {
            head_ptr = our_node;                                                         //our nodes previous and next our initialized as NULL already
            tail_ptr = our_node;
            mySize++;
        }
        else                                                                             //more than one item in list
        {
            our_node->next = head_ptr;                                                   //our node points to the previous first node
            head_ptr->previous = our_node;                                               //the last heads previous points to our node now
            head_ptr = our_node;                                                         //head ptr is now our node
            mySize++;
        }
    }
    //PUSH_BACK
    //Similar to push front but places a new node at the back of list
    void push_back(Type const & value)
    {
        DoubleNode<Type> * our_node = new DoubleNode<Type>(value,NULL,NULL);             //create a new node to push to front
        if(empty())                                                                      //if empty list
        {
            head_ptr = our_node;                                                         //our nodes previous and next our initialized as NULL already
            tail_ptr = our_node;
            mySize++;
        }
        else
        {
            our_node->previous = tail_ptr;                                               //our nodes previous points to the last tail node
            tail_ptr->next = our_node;                                                   //the last tail node now points to our new node
            tail_ptr = our_node;                                                         //tail pointer now points to our new node
            mySize++;
        }
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
    void print()
    {
        DoubleNode<Type> *temp;
        cout<<"Head ---> ";
        for(int i = 0 ;i<mySize;i++)
        {
            if (i == 0) {
                cout << head_ptr->data <<" ";
                temp = head_ptr->next;
            }
            else {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        cout<<"<---Tail"<<endl;
    }
    ~DoublyLinkedList()
    {
        //NEED TO IMPLEMENT
    };
};

#endif
