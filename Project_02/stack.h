#ifndef STACK_H
#define STACK_H
#define DEFAULT_SIZE 5

#include<iostream>
#include<stdexcept>

using namespace std;

template <class Type>
class Stack
{
  private:
    Type *array; //An array of int, double, or whatever type
    int count, myTop; //Tracks # of items in array and where the top of the stack is
    int initialSize; //Keeps track of our initial size - never go below this
    int currentSize; //Keeps track of the current size of our array

  public:


    //Default Constructor
    Stack() : count(0), myTop(-1), initialSize(DEFAULT_SIZE), currentSize(DEFAULT_SIZE)
    {
      Type stackArray[initialSize]; //Need to create new array here?
      array = stackArray; //Point our array pointer to this array and use pointer?
    }

    //Overloaded Constructor that accepts a value from the user
    Stack(int value) : count(0), myTop(-1), initialSize(value), currentSize(value)
    {
      if(value <= 0)
      {
        cout << "Invalid container size!" << endl;
        cout << "Container size set to: 1" << endl;

        Type stackArray[1]; //Need to create new array here?
        array = stackArray; //Point our array pointer to this array and use pointer?
      }

      else
      {
        Type stackArray[value]; //Need to create new array here?
        array = stackArray; //Point our array pointer to this array and use pointer?
      }
    }

    //Destructor that deallocates memory assigned to array
    ~Stack()
    {
      cout << "Destructor called" << endl;
      delete array;
    }

    //If our top is index 0 in our array then the Stack is emtpy
    bool empty() const
    {
      return myTop == -1;
    }

    //Returns the value at the top of our Stack
    Type top() const
    {
      if(empty())
      {
        //If our stack is emtpy, throw an exception
        throw out_of_range("Stack is empty!");
      }

      else
      {
        return array[myTop];
      }
    }

    //Returns the number of elements currently in our Stack
    int size() const
    {
      int i = 0;
      for(i; i <= myTop; i++)
      {
        //Increments counter up to the top of the stack
      }

      //Assigns the value we counted up to, to variable "count". Needed? Not sure.
      //If not needed then what is variable "count" for?
      count = i;
      return count;
    }

    //Returns the current size of the array. How many elements it can store
    int capacity() const
    {
      return currentSize;
    }

    //Prints out the content of our Stack
    void display()
    {
      int i = myTop; //Start from the top and work down the Stack
      cout << "List of items stored in the Stack:" << endl;
      cout << "[" << array[i--] << "] " << "<-- Top" << endl; //Top element
      for(i; i >= 1; i--)
      {
        cout << "i is: " << i << endl;
        cout << "[" << array[i] << "]" << endl; //Middle elements
      }
      cout << "[" << array[i-1] << "] " << "<-- Bottom" << endl; //Bottom element
    }

    //Pushes a new item to the top of the Stack
    void push(Type const & data)
    {
      if(size() == currentSize - 1)
      {
        Type oldArray = array; //Backup the old Stack
        currentSize *= 2; //Double currentSize of Stack
        Type newArray[currentSize] = oldArray; //New Stack with double the size and copied elements?
        array = newArray; //array now contains the copied elements and double the size
      }

      //Push new item onto the Stack
      myTop++; //Increments top to new vacant index
      array[myTop] = data;
    }

    //Pops a value from the top of the Stack
    Type pop()
    {
      //Decrementing myTop turns original stored value into garbage
      myTop--;

      //If stack is 1/4 full and bigger than original size. Halve the Stack size
      if((count() == currentSize % 4) && currentSize > initialSize)
      {
        //*****Need to account for possible underflow errors*****
        Type oldArray = array; //Backup the old Stack
        currentSize /= 2; //Halves currentSize of Stack
        Type newArray[currentSize] = oldArray; //New Stack with double the size and copied elements?
        array = newArray; //array now contains the copied elements and double the size
      }

      return array[myTop];

    }

    //Removes all the elements in the stack
    void clear()
    {
      while(!empty())
      {
        pop();
      }
    }
    
};

#endif
