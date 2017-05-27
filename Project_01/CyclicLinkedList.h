#ifndef CYCLIC_LINKED_LIST_H
#define CYCLIC_LINKED_LIST_H

#include <iostream>

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
    CyclicLinkedList() : mySize(0),head_ptr(NULL),tail_ptr(NULL)  //default size=0, both head and tail NULL pointers
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
    bool empty() const //
    {
        return head_ptr==NULL;
    }
    //FRONT
    //Retrieves the object store in the node pointed to by head pointer
    Type front() const
    {
        return head_ptr->data;
        //NEED UNDERFLOW ERROR DETECTION HERE
    }
    //BACK
    //Retrieves the object store in the node pointed to by tail pointer
    Type back() const
    {
        return tail_ptr->data;
        //NEED UNDERFLOW ERROR DETECTION HERE
    }
    //HEAD
    //Returns head pointer
    SingleNode<Type> * head() const
    {
        if(mySize>=1)
            return head_ptr;
    }
    //TAIL
    //Returns tail pointer
    SingleNode<Type> * tail() const
    {
        if(mySize>=1)
            return tail_ptr;
    }
    //COUNT
    //Returns # of nodes in linked list storing a value equal to argument
    int count(Type const & value) const {
        int item_count=0;
        SingleNode<Type> *temp;
        temp = head_ptr;
        for (int i = 0; i < mySize; i++)
        {
            if((temp->data)== value)
                {
                    item_count++;
                }
                temp=temp->next;
        }
        return item_count;
    }
    //PUSH_FRONT
    //Creates a new SingleNode< Type > storing the argument, the next pointer of which is set to the current head pointer.
    // The head pointer is set to this new node.
    // If the list was originally empty,the tail pointer is set to point to the new node
    void push_front(Type const & value)
    {
        //SingleNode<Type> * create_node;
        SingleNode<Type> * our_node = new SingleNode<Type>(value, NULL);         //create new singlenode and set data value
//        SingleNode<Type> * our_node = new SingleNode<Type>(value, head_ptr);
//        head_ptr = our_node;
//        tail_ptr->next = head_ptr;
        if(mySize==0)                                                //is list empty?
        {
            our_node -> next = our_node;                             //points to itself
            tail_ptr = our_node->next;                               //tail and head ptr point to same (just one node in list)
            head_ptr = our_node->next;
            mySize++;
        }
        else                                                    //list not empty
        {
            our_node->next = head_ptr;                          //head now front
            head_ptr = our_node;                                //head_ptr is our node;
            tail_ptr->next = head_ptr;                          //LAST NODE POINTS TO FIRST NODE
            mySize++;
        }
    }
    //PUSH_BACK
    //Similar to push front but places a new node at the back of list
    void push_back(Type const & value)
    {
        SingleNode<Type> * our_node = new SingleNode<Type>(value, NULL);         //create new singlenode and set data value
//        SingleNode<Type> * create_node;
//        SingleNode<Type> * our_node = new SingleNode<Type>(value, create_node);
        if(mySize==0)                                           //is list empty?
        {
            our_node -> next = our_node;                        //points to itself
            tail_ptr = our_node->next;                          //tail and head ptr point to same (just one node in list)
            head_ptr = our_node->next;
            mySize++;
        }
        else
        {
            tail_ptr->next = our_node;
            tail_ptr = our_node;
            our_node -> next = head_ptr;                        //end points to head
            mySize++;
        }

    }
    //POP_FRONT
    //Delete the node at the front of the linked list and, as necessary, update the head and tail pointers.
    //Return the object stored in the node being popped
    Type pop_front()
    {
        if(mySize>=2)
        {
            Type stored_value;
            SingleNode<Type> *old_node;          //use to make copy of node
            old_node = head_ptr;                 //copy of head pointer
            head_ptr = old_node->next;           //head pointer now points to the next node
            tail_ptr->next = head_ptr;           //the last node now points to the head
            stored_value = old_node->getData();  //getting data before we delete
            delete old_node;                     //delete the head node
            mySize--;
            return stored_value;
        }
        if(mySize == 1)
        {
            Type stored_value;
            SingleNode<Type> *old_node;          //use to make copy of node
            old_node = head_ptr;                 //copy of head pointer
            head_ptr = NULL;                     //head pointer now points to the next node
            //tail_ptr->next = head_ptr;           //the last node now points to the head
            tail_ptr = NULL;
            stored_value = old_node->getData();  //getting data before we delete
            delete old_node;                     //delete the head node
            mySize--;
            return stored_value;
        }
        else
        {
          //Block that will take care of returning a dummy value to clear warnings
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
        if(mySize>=1)
        {
            Type stored_value;                           //use to return value
            stored_value = tail_ptr->data;
            SingleNode<Type> *old_node;                  //use to make copy of old node
            old_node = tail_ptr;                         //copy of tail node

            SingleNode<Type> *temp;                      //create temp and start at head
            temp = head_ptr;

            for (int i = 0; i < mySize; i++)
            {
              if (temp->next == tail_ptr)
              {
                  temp->next = head_ptr;               //seting the tail node to point to head
                  tail_ptr = temp;                     //set tail to other node
                  delete old_node;                     //delte the old tail
                  mySize--;                            //change size
                  return stored_value;                 //return type
              }
               temp = temp->next;
            }
        }

        return 0; //Need this here in case we don't enter IF block. Clears warnings
    }
    //ERASE
    //Delete the node(s) (from the front) in the linked list that contains the element equal to the argument
    //(use == to to test for equality with the retrieved element).
    //As necessary, update the head and tail pointers and the next pointer of any other node within the list.
    //Return the number of nodes that were deleted
    int erase(Type const & value) {
        int erase_count = 0;
        int total_size = mySize;                  //make a copy of our size so we can adjust mysize in loop and not affect it
        SingleNode<Type> *temp;
        if(mySize==1){if(head_ptr->data==value) { pop_front();return erase_count+1; } else { return erase_count; }} //check if size is 1 and use popfront to delete
        temp = head_ptr;
        while(head_ptr->data==value)
        {
            if(mySize==1){if(head_ptr->data==value) { pop_front();return erase_count+1; } else { return erase_count; }}//check if size is 1 and use popfront to delete
            temp = temp->next;
            pop_front();
            erase_count++;
        }
        while(tail_ptr->data==value)
        {
            if(mySize==1){if(head_ptr->data==value) { pop_front();return erase_count+1; } else { return erase_count; }}//check if size is 1 and use popfront to delete
            pop_back();
            erase_count++;
        }
        temp=head_ptr;
        for (int i = 0; i < total_size; i++)
        {
            if(mySize==1){if(head_ptr->data==value) { pop_front();return erase_count+1; } else { return erase_count; }}//check if size is 1 and use popfront to delete
            if(temp->next->data==value)
            {
                if(temp->next != tail_ptr) {
                    SingleNode<Type> *old;
                    old = temp->next;               //copy so we can delete
                    temp->next = old->next;         //skipped the node with the value;
                    delete old;
                    mySize--;
                    erase_count++;
                }
            }
            else
            {
                temp=temp->next;
            }
        }
        return erase_count;
    }
    void print_list()
    {
        SingleNode<Type> *temp;
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
    ~CyclicLinkedList(){}; //NEED TO MAKE DESTRUCTOR STILL
};

#endif
