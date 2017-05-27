#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

using namespace std;

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
      return 0; //Temporary return statement
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

            if (mySize == 1)                                                                    //only 1 item in list
            {
                Type value_return = head_ptr->data;                                              //storing so we can return value
                delete head_ptr;
                head_ptr = NULL;
                tail_ptr = NULL;
                mySize--;
                return value_return;
            }
            if (mySize == 2)                                                               //if only two items in list
            {
                Type value_return = head_ptr->data;                                              //storing so we can return value
                DoubleNode<Type> *temp = head_ptr;                                          //need to copy to delete
                head_ptr = head_ptr->next;                                                   //head pointer now points to next node
                head_ptr->previous = NULL;                                                   //previous set to null of new head node
                head_ptr->next = NULL;                                                       //because there were only two items in list this is now only node
                mySize--;
                delete temp;
                return value_return;
            }
            if(mySize >= 2)                                                                          //more than two items in list
            {
                Type value_return = head_ptr->data;                                              //storing so we can return value
                DoubleNode<Type> *temp = head_ptr;                                          //need to copy to delete
                head_ptr = head_ptr->next;                                                   //head pointer now points to next node
                head_ptr->previous = NULL;                                                   //previous set to null of new head node
                mySize--;
                delete temp;
                return value_return;
            }
        //NEED UNDERFLOW EXCEPTION
            else
            {
              cout << "mySize is: " << mySize << endl;
              cout << "List is empty" << endl;
              Type dummy_value;   //Dummy value of Type for returning puposes
              int dummy_int = 0;
              dummy_value = dummy_int;
              return dummy_value;
            }
    }
    //POP BACK
    //delete node at the end of the linked list and, as necessary, update the head and tail pointers.
    //Return the object stored in the node being popped
    Type pop_back()
    {
      cout << "\nInside pop_back, mySize is: " << mySize << endl;
        if(mySize==1)
        {
            return pop_front();                                                                   //if only one item we can just call pop front since it will be same
        }
        else if(mySize==2)                                                                 //only two items in list
        {
            Type value_return = tail_ptr->data;                                                //Store of data to return at end
            DoubleNode<Type> * temp = tail_ptr;
            tail_ptr = tail_ptr->previous;                                                 //tail pointer now points to previous node
            tail_ptr->previous = NULL;                                                     //previous now NULL because only one in list
            tail_ptr->next = NULL;                                                         //next is now NULL since its last node
            mySize--;
            delete temp;
            return value_return;
        }
        else                                                                               //more than two items in list
        {
            Type value_return = tail_ptr->data;                                                //Store of data to return at end
            DoubleNode<Type> * temp = tail_ptr;
            tail_ptr = tail_ptr->previous;                                                 //tail now points to previous node
            tail_ptr->next = NULL;                                                         //tails next points to NULL
            mySize--;
            delete temp;
            return value_return;
        }
        //NEEED UNDERFLOW EXCEPTION
    }
    //ERASE
    //Delete the node(s) (from the front) in the linked list that contains the element equal to the argument
    //(use == to to test for equality with the retrieved element).
    //As necessary, update the head and tail pointers and the next pointer of any other node within the list.
    //Return the number of nodes that were deleted
    int erase(Type const &)
    {
      return 0; //Temporary return statement
    }
    void print()
    {
        DoubleNode<Type> *temp;                           //create temp to go through nodes
        temp = head_ptr;                                  //start at head node
        cout<<"Head ---> ";
        for(int i = 0 ;i<mySize;i++)                      //loop through size of list
        {
            cout << temp->data << " ";
            temp = temp->next;                            //go to next node
        }
        cout<<"<---Tail"<<endl;
    }
    ~DoublyLinkedList()
    {
        //NEED TO IMPLEMENT
    };
};

#endif
