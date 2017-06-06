#ifndef QUEUE_H
#define QUEUE_H
#define DEFAULT_SIZE 5

#include<stdio.h>
#include<iostream>
#include<stdexcept>

using namespace std;

template <class Type>
class Queue
{
  private:
    Type *array; //An array of int, double, or whatever type
    int count; //Tracks # of items in array
    int initialSize; //Keeps track of our initial size - never go below this
    int currentSize; //Keeps track of the current size of our array
    int theFront, theBack; //Index to front and back of the queue. Back should always be the next empty index

  public:
    Queue() : count(0), initialSize(DEFAULT_SIZE), currentSize(DEFAULT_SIZE), theFront(0), theBack(0)
    {
      //Might implement with malloc. But not needed. This is just a test.
      array = (Type*)malloc(initialSize * sizeof(Type));
      if(array == NULL)
      {
        //Allocation failed
        throw out_of_range("Allocation failed!");
      }
    }

    Queue(int value) : count(0), initialSize(value), currentSize(value), theFront(value), theBack(value)
    {
      if(value <= 0)
      {
        cout << "Invalid container size!" << endl;
        cout << "Container size set to: 1" << endl;

        array = (Type*)malloc(1 * sizeof(Type));
      }

      else
      {
        array = (Type*)malloc(value * sizeof(Type));
      }
    }

    ~Queue()
    {
      delete array;
      free(array); //Is it needed since we're using malloc or does delete take care of it?
    }

    //If Front and Back index are equal then the queue is empty
    bool empty() const
    {
      return theFront == theBack;
    }

    //Returns the element that's in the front of the queue
    Type front() const
    {
      //Empty queue returns an out of range exception
      if(empty())
      {
        throw out_of_range("Queue is empty!");
      }
      else
      {
        return array[theFront];
      }
    }

    //Returns the element that's in the back of the queue
    Type back() const
    {
      //Empty queue returns an out of range exception
      if(empty())
      {
        throw out_of_range("Queue is empty!");
      }
      else
      {
        return array[theBack];
      }
    }

    //Returns the number of elements currently in our queue
    int size()
    {
      int i;
      for(i = 0; i < theBack; i++)
      {
        //Increments counter up to the last item in our queue
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

    //Prints out the content of our queue
    void display()
    {
      int i; //Start from the front of the queue
      cout << "List of items stored in the Queue:" << endl;
      cout << "Front\n" << "  |\n" << "  V" << endl; //Arrow that points down
      for(i = theFront; i > theBack; i++)
      {
        cout << " [" << array[i] << "]";
      }
      cout << endl;
    }

    //Add an item to the Queue as long as there is room
    void enqueue(Type & data)
    {
      cout << "\nPlacing " << data << " at the back of the Queue" << endl;
      //If incrementing the Back by 1 is equal to the size of the array then resize
      if(theBack + 1 == currentSize)
      {
        currentSize *= 2; //Double the size of the array
        //Use realloc here to increase the size of the array. Realloc should maintain the current elements.
        array = (Type *)realloc(array, currentSize * sizeof(Type));
      }

      //Places the item into the queue
      array[theBack] = data;
      theBack++; //Increments theBack to the next empty position in the queue

    }

    //Removes an item from the Queue and halves the size if there's a lot of room
    Type dequeue()
    {
      theBack--; //Simiply decreasing the back index should suffice since this data will be overwritten

      //If after removing item array is now 1/4 full & currentSize is bigger than initialSize
      if((size() % 4 == 0) && currentSize > initialSize)
      {
        if(empty())
        {
          throw out_of_range("Queue is empty!");
        }

        else
        {
          //Halves the size of the array the reallocates the space. Should keep the items
          currentSize /= 2;
          array = (Type *)realloc(array, currentSize * sizeof(Type));
        }
      }

      return array[theBack];
    }

    //Removes all items from the queue by dequeue'ing them until empty
    void clear()
    {
      while(!empty())
      {
        dequeue();
      }
    }

};

#endif
