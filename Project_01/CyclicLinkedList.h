#ifndef CYCLIC_LINKED_LIST_H
#define CYCLIC_LINKED_LIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <class Type>
class CyclicLinkedList
{
private:
    int mySize;                                                 //Size of linked list
    SingleNode<Type> * head_ptr;                                //head pointer
    SingleNode<Type> * tail_ptr;                                //tail pointer

public:
    //Default constructor
    CyclicLinkedList() : mySize(0),head_ptr(NULL),tail_ptr(NULL)//default size=0, both head and tail NULL pointers
    {

    }
    //SIZE
    //return # of items on list
    int size() const
    {
        return mySize;
    }
    //EMPTY
    //Returns true if list empty (otherwise return false)
    bool empty() const
    {
        return head_ptr==NULL;
    }
    //FRONT
    //Retrieves the object store in the node pointed to by head pointer
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
    //BACK
    //Retrieves the object store in the node pointed to by tail pointer
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
    //Returns head pointer
    SingleNode<Type> * head() const
    {
      return head_ptr;
    }
    //TAIL
    //Returns tail pointer
    SingleNode<Type> * tail() const
    {
      return tail_ptr;
    }
    //COUNT
    //Returns # of nodes in linked list storing a value equal to argument
    int count(Type const & value) const
    {
        int item_count=0;
        SingleNode<Type> *temp;
        temp = head_ptr;                                                        //temp points to head pointer
        for (int i = 0; i < mySize; i++)
        {
            if((temp->data)== value)                                            //if temps value equals data we count+1
                {
                    item_count++;
                }
                temp=temp->next;                                                //temp points to next node
        }
        return item_count;
    }
    //PUSH_FRONT
    //Creates a new SingleNode< Type > storing the argument, the next pointer of which is set to the current head pointer.
    // The head pointer is set to this new node.
    // If the list was originally empty,the tail pointer is set to point to the new node
    void push_front(Type const & value)
    {
        SingleNode<Type> * our_node = new SingleNode<Type>(value, NULL);         //create new singlenode and set data value , NULL for next

        if(mySize==0)                                                            //is list empty?
        {
            our_node -> next = our_node;                                         //points to itself
            tail_ptr = our_node;                                                 //tail and head ptr point to same (just one node in list)
            head_ptr = our_node;
            mySize++;
        }
        else                                                                     //list not empty
        {
            our_node->next = head_ptr;                                           //new nodes next points to the head pointer
            head_ptr = our_node;                                                 //head_ptr is our node;
            tail_ptr->next = head_ptr;                                           //last node points to first node (loop)
            mySize++;
        }
    }
    //PUSH_BACK
    //Similar to push front but places a new node at the back of list
    void push_back(Type const & value)
    {
        SingleNode<Type> * our_node = new SingleNode<Type>(value, NULL);         //create new singlenode and set data value

        if(mySize==0)                                                            //is list empty?
        {
            our_node -> next = our_node;                                         //points to itself
            tail_ptr = our_node;                                                 //tail and head pointer point to same (just one node in list)
            head_ptr = our_node;
            mySize++;
        }
        else                                                                     //more than one node in list
        {
            tail_ptr->next = our_node;                                           //old tails nodes next now points to new node
            tail_ptr = our_node;                                                 //tail now points to our node
            our_node -> next = head_ptr;                                         //last node now points to head
            mySize++;
        }

    }
    //POP_FRONT
    //Delete the node at the front of the linked list and, as necessary, update the head and tail pointers.
    //Return the object stored in the node being popped
    Type pop_front()
    {
      if(empty())
      {
        throw out_of_range("List is empty!");
      }

      else
      {
        if(mySize>=2)                                      //two or more nodes in list
        {
            Type stored_value;
            SingleNode<Type> *old_node;                    //use to make copy of node
            old_node = head_ptr;                           //copy of head pointer
            head_ptr = old_node->next;                     //head pointer now points to the next node
            tail_ptr->next = head_ptr;                     //the last node now points to the new head
            stored_value = old_node->data;                 //getting data before we delete
            delete old_node;                               //delete the original head node
            mySize--;
            return stored_value;
        }
        if(mySize == 1)                                    //only one item in list
        {
            Type stored_value;
            SingleNode<Type> *old_node;                    //use to make copy of node
            old_node = head_ptr;                           //copy of head pointer
            head_ptr = NULL;                               //head and tail pointer now points to NULL
            tail_ptr = NULL;
            stored_value = old_node->getData();            //getting data before we delete
            delete old_node;                               //delete the head node
            mySize--;
            return stored_value;
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

      if(mySize==1)                                    //only one item in list
      {
          return pop_front();                          //we can call pop front since it already does this
      }

      else
      {
        if(mySize>=2)                                    //one or more items in list
        {
          Type stored_value;                           //use to return value
          stored_value = tail_ptr->data;
          SingleNode<Type> *old_node;                  //use to delete the old tail
          old_node = tail_ptr;

          SingleNode<Type> *temp;                      //create temp and start at head
          temp = head_ptr;

          for (int i = 0; i < mySize; i++)             //need to go through list the to find node just before tail
          {
            if (temp->next == tail_ptr)
            {
                temp->next = head_ptr;                 //setting the new tail node to point to head
                tail_ptr = temp;                       //set tail to other node
                delete old_node;                       //delete the old tail
                mySize--;                              //change size
                return stored_value;                   //return type
            }
             temp = temp->next;                        //go to next node
          }
        }

        return 0; //Eliminates warning of reaching end of function and not returning. Will never reach this line
      }
    }
    //ERASE
    //Delete the node(s) (from the front) in the linked list that contains the element equal to the argument
    //(use == to to test for equality with the retrieved element).
    //As necessary, update the head and tail pointers and the next pointer of any other node within the list.
    //Return the number of nodes that were deleted
    int erase(Type const & value) {

        int erase_count=0;
        SingleNode<Type> * temp;
        temp = head_ptr;
        while(head_ptr->data==value)                   //CASE 1 : head pointer and equals value
        {
            if(mySize==1){if(head_ptr->data==value) { pop_front();return erase_count+1; } else { return erase_count; }} //IN CASE WHOLE LIST IS SAME VALUE ,will immediately return value
            pop_front();                               //we call pop front to delete
            erase_count++;
        }
        while(tail_ptr->data==value)                   //CASE 2 : tail pointer and equals value
        {
                pop_back();                            //we call pop tail to delete
                erase_count++;
        }
        if(mySize>=3)                                  //CASE 3 : in the middle (only possible with three or more nodes)
        {
            int list_size = mySize;                    //because we change mySize in our loop we use this in for loop
            temp = head_ptr;
            for (int i = 0; i < list_size; i++)
            {
                if(temp->next->data == value)          //if the next nodes value is equal to value to delete
                {
                    SingleNode<Type> * old;            //keeping track of old node to be deleted
                    old = temp->next;
                    temp->next = old->next;            //skipping over node to be deleted
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
    //PRINT LIST
    void print_list()
    {
      if(empty())
      {
        cout << "List is empty!" << endl;
      }

      else
      {
        SingleNode<Type> *temp;                           //create temp to go through nodes
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
    ~CyclicLinkedList()
    {
        while(!empty())                                   //while the list is not empty we call pop front to delete
        {
            pop_front();
        }
    };
};

#endif
