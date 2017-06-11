#ifndef PORJ2PRAC_DYNSTACK_H
#define PORJ2PRAC_DYNSTACK_H
#include <iostream>
#include <stdexcept>

using namespace std;

template <class Type>
class DynStack
{
private:
    Type * array;
    int count;                                                           //current number of elements
    int initialSize;
    int arraySize;
public:
    DynStack(int n=15) : count(-1),initialSize(15),arraySize(15)         //count -1 becomes no elements in array
    {
        if(n<=0)                                                         //if arguement is 0 or a negative integer
        {
            arraySize = 1;
            array = new Type[arraySize];                                 //new array size 1
            initialSize = 1;
        }
        else
        {
            array = new Type[n];                                         //new array is number entered by user or default 15
            arraySize = n;
            initialSize = n;
        }
    }
    Type top() const
    {
        if(empty())
        {
            throw out_of_range("Stack is empty");
        }
        return array[count];                                             //return top of array
    }
    int size() const
    {
        return (count+1);                                                //return number of elements+1 (since it accounts for 0 as an element count)
    }
    bool empty() const
    {
        return count == -1;                                              //if -1 then empty
    }
    int capacity()
    {
        return arraySize;                                                //returns the total amount in which array can hold
    }
    void display()
    {
        if(empty())
        {
            throw out_of_range("Stack is empty");
        }
        cout<<"Top-->";
        for(int i=count;i>=0;i--)
        {
            if(i==count)
                cout<<"["<<array[i]<<"]"<<endl;
            else
                cout<<"      ["<<array[i]<<"]"<<endl;
        }
    }
    void push(Type const & data)
    {
        if((size())==arraySize)
        {
            Type * temp_increase = new Type[arraySize*2];                  //new array double the size
            for(int i=0;i<=count;i++)
            {
                temp_increase[i] = array[i];                               //copy all elements to new array
            }
            delete []array;
            array = temp_increase;
            arraySize*=2;                                                  //array size now doubled
        }
        array[++count] = data;                                             //pushing item onto stack
    }
    Type pop()
    {
        if(empty())
        {
            throw out_of_range("Stack is empty");
        }
        --count;
        Type to_return = array[count+1];
        if(count<(arraySize/4) && arraySize>initialSize)                   //size of array is greater than the initial size
        {
            Type * temp_change = new Type[arraySize/2];
            for(int i=0;i<=count;i++)                                  //loop and copy elements in the array
            {
                temp_change[i] = array[i];
            }
            delete []array;
            array = temp_change;                                       //set array to new one created
            arraySize/=2;                                              //half our array size
        }
        return to_return;                                                  //return the popped item
    }
    void clear()
    {
        if(empty())
        {
            throw out_of_range("Stack is empty!");
        }
        delete []array;                                                    //delete all elements in array
        array = new Type[initialSize];                                     //new array of initial size
        arraySize = initialSize;                                           //set our array size to the initialsize
        count = -1;                                                        //no items in our array;

        cout << "Stack has been cleared!" << endl;
    }
    ~DynStack()
    {
        delete []array;
    };
};





#endif //PORJ2PRAC_DYNSTACK_H
