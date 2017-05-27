#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

using namespace std;

template <class Type>
class DoublyLinkedList
{
  private:
    int mySize;                                    //size of the list
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
      if(empty())
      {
        throw out_of_range("List is empty!");
      }
      else
      {
        return head_ptr->data;
      }
    }
    //returns object pointed to by tail pointer
    Type back() const
    {
      if(empty())
      {
        throw out_of_range("List is empty!");
      }
      else
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
        int item_count=0;
        DoubleNode<Type> *temp;
        temp = head_ptr;                                                        //temp points to head pointer
        for (int i = 0; i < mySize; i++)
        {
            if((temp->data)== value)                                            //if temps value equals data we count+1
            {
                item_count++;
            }
            temp=temp->next;                                                    //temp points to next node
        }
        return item_count;
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
      if(empty())
      {
        throw out_of_range("List is empty!");
      }

      else
      {
        if (mySize == 1)                                                                //only 1 item in list
        {
            Type value_return = head_ptr->data;                                         //storing so we can return value
            delete head_ptr;
            head_ptr = NULL;
            tail_ptr = NULL;
            mySize--;
            return value_return;
        }
        if (mySize == 2)                                                                //if only two items in list
        {
            Type value_return = head_ptr->data;                                         //storing so we can return value
            DoubleNode<Type> *temp = head_ptr;                                          //need to copy to delete
            head_ptr = head_ptr->next;                                                  //head pointer now points to next node
            head_ptr->previous = NULL;                                                  //previous set to null of new head node
            head_ptr->next = NULL;                                                      //because there were only two items in list this is now only node
            mySize--;
            delete temp;
            return value_return;
        }
        if(mySize >= 2)                                                                 //more than two items in list
        {
            Type value_return = head_ptr->data;                                         //storing so we can return value
            DoubleNode<Type> *temp = head_ptr;                                          //need to copy to delete
            head_ptr = head_ptr->next;                                                  //head pointer now points to next node
            head_ptr->previous = NULL;                                                  //previous set to null of new head node
            mySize--;
            delete temp;
            return value_return;
        }

        return 0; //Eliminates warning of reaching end of function and not returning. Will never reach this line
      }
    }
    //POP BACK
    //delete node at the end of the linked list and, as necessary, update the head and tail pointers.
    //Return the object stored in the node being popped
    Type pop_back()
    {
      if(empty())
      {
        throw out_of_range("List is empty!");
      }
      else
      {
        cout << "mySize is: " << mySize << endl;
        if(mySize==1)
        {
            return pop_front();                                                            //if only one item we can just call pop front since it will be same
        }

        else if(mySize==2)                                                                 //only two items in list
        {
            Type value_return = tail_ptr->data;                                            //Store of data to return at end
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
            Type value_return = tail_ptr->data;                                            //Store of data to return at end
            DoubleNode<Type> * temp = tail_ptr;
            tail_ptr = tail_ptr->previous;                                                 //tail now points to previous node
            tail_ptr->next = NULL;                                                         //tails next points to NULL
            mySize--;
            delete temp;
            return value_return;
        }
        return 0; //Eliminates warning of reaching end of function and not returning. Will never reach this line
      }
    }
    //ERASE
    //Delete the node(s) (from the front) in the linked list that contains the element equal to the argument
    //(use == to to test for equality with the retrieved element).
    //As necessary, update the head and tail pointers and the next pointer of any other node within the list.
    //Return the number of nodes that were deleted
    int erase(Type const & value)
    {
        int erase_count=0;
        DoubleNode<Type> * temp;
        temp = head_ptr;
        while(head_ptr->data==value)                   //CASE 1 : head pointer and equals value
        {
            if(mySize==1){if(head_ptr->data==value) { pop_front();return erase_count+1; } else { return erase_count; }} //IN CASE WHOLE LIST IS SAME VALUE ,will immediately return value
            pop_front();                               //we call pop front to delete
            erase_count++;
        }
        while(tail_ptr->data==value)                   //CASE 2 : tail pointer and equals value
        {
            pop_back();                                //we call pop tail to delete
            erase_count++;
        }
        if(mySize>=3)                                  //CASE 3 : in the middle (only possible with three or more nodes)
        {
            int list_size = mySize;                    //because we change mySize in our loop we use this in for loop
            temp = head_ptr;
            for (int i = 0; i < (list_size-1); i++)    //LIST SIZE - 1 , since the tail is already handled and the next of tail points to NULL
            {
                if(temp->next->data == value)          //if the next nodes value is equal to value to delete
                {
                    DoubleNode<Type> * old;            //keeping track of old node to be deleted
                    old = temp->next;
                    temp->next = old->next;            //skipping over node to be deleted
                    old->next->previous = temp;        //the node after the skipped node , its previous now goes to temp
                    delete old;
                    erase_count++;
                    mySize--;                          //adjusts size of list
                }
                else
                {
                    temp = temp->next;
                }
            }
        }
        return erase_count;
    }
    //PRINT
    void print()
    {
      if(empty())
      {
        cout << "List is empty!" << endl;
      }

      else
      {
        DoubleNode<Type> *temp;                           //create temp to go through nodes
        temp = head_ptr;                                  //start at head node
        cout<<"Head ---> ";
        for(int i = 0 ;i<mySize;i++)                      //loop through size of list
        {
            cout <<"["<< temp->data << "] ";
            temp = temp->next;                            //go to next node
        }
        cout<<"<---Tail"<<endl;
      }
    }
    //DESTRUCTOR
    ~DoublyLinkedList()
    {
        while(!empty())                                   //while the list is not empty we call pop front to delete
        {
            pop_front();
        }
    };
};

#endif
