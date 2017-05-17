#ifndef SINGLE_NODE_H
#define SINGLE_NODE_H

#include <iostream>

typedef int ElementType; //Change type of data here

class SingleNode
{
  private:
    ElementType testData; //Programmer defined variable type
    SingleNode * nextPtr;
  public:
    SingleNode();

    ~SingleNode();
};

#endif
