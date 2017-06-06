#ifndef QUEUE_H
#define QUEUE_H

#include<stdio.h>
#include<iostream>
#include<stdexcept>

using namespace std;

template <class Type>
class Queue
{
  private:
    Type *array; //An array of int, double, or whatever type
    int count, myTop; //Tracks # of items in array and where the top of the stack is
    int initialSize; //Keeps track of our initial size - never go below this
    int currentSize; //Keeps track of the current size of our array

  public:
    Queue() : count(0), myTop(0), initialSize(10), currentSize(10)
    {
      //Might implement with malloc. But not needed. This is just a test.
      array = (Type*)malloc(initialSize * sizeof(Type));
    }

};

#endif
