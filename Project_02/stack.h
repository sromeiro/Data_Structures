#ifndef PORJ2PRAC_DYNSTACK_H
#define PORJ2PRAC_DYNSTACK_H
#include <iostream>
using namespace std;

template <class Type>
class DynStack
{
private:
    Type * array;
    int count;                                                //current number of elements
    int initialSize;
    int arraySize;
public:
    DynStack(int n=15) : count(-1) ,initialSize(15)         //count -1 becomes no elements in array
    {
        if(n<=0)                                              //if arguement is 0 or a negative integer
        {
            arraySize = 1;
            array = new Type[arraySize];                       //new array size 1
            initialSize = 1;
        }
        else if(n>0)
        {
            array = new Type[n];                               //new array is number entered by user
            arraySize = n;
            initialSize = n;
        }
        else //DONT THINK WE EVEN NEED THIS <----------MAYBE
        {
            array = new Type[initialSize];                     //array initial size = 15
            arraySize = initialSize;
        }
    }
    Type top() const //NEED UNDERFLOW DETECTION
    {
        if(empty())       //this will need a throw statement
        {
            cout<<"EMPTY NEED CATCH THROW HERE"<<endl;
            return 0;
        }
        return array[count];                                    //return top of array
    }
    int size() const
    {
        return (count+1);                                       //return number of elements+1 (since it accounts for 0 as an element count)
    }
    bool empty() const
    {
        if(count<0)                                             //no elements in stack
        {
            return 1;
        }
        return 0;                                               //at least one item in stack
    }
    int capacity()
    {
        return arraySize;                                       //returns the total amount in which array can hold
    }
    void display()
    {
        cout<<"Top-->";
        for(int i=count;i>=0;i--)
        {
            if(i==count)
                cout<<"["<<array[i]<<"]"<<endl;
            else
                cout<<"      ["<<array[i]<<"]"<<endl;
        }
    }
    void push(Type const & data) //NEED TO CHECK IF FULL AND DOUBLE SIZE OF ARRAY
    {
        if((size())==arraySize)
        {
            Type * to_delete;
            Type * temp_increase = new Type[arraySize*2];                  //new array double the size
            for(int i=0;i<=count;i++)
            {
                temp_increase[i] = array[i];                               //copy all elements to new array
            }
            to_delete = array;
            array = temp_increase;
            delete to_delete;                                              //delete old array
            arraySize*=2;                                                  //arraysize now doubled
        }
        array[++count] = data;                                             //pushing item onto stack

    }
    Type pop() //NEED UNDERFLOW DETECTION HERE
    {
        if(empty())       //this will need a throw statement
        {
            cout<<"EMPTY NEED CATCH THROW HERE"<<endl;
            return 0;
        }
        --count;
        if(count<(arraySize/4) && arraySize>initialSize)                   //size of array is greater than the initial size
        {
            Type * to_delete;                                          //used to create copy of array to delete
            Type * temp_change = new Type[arraySize/2];
            for(int i=0;i<=count;i++)                                  //loop and copy elements in the array
            {
                temp_change[i] = array[i];
            }
            to_delete = array;
            array = temp_change;                                       //set array to new one created
            delete to_delete;                                          //delete the old array
            arraySize/=2;                                              //half our array size
        }
        return array[count+1];                                             //return the popped item
    }
    void clear()
    {
        delete array;                                                      //delete all elements in array
        array = new Type[initialSize];                                     //new array of initial size
        arraySize = initialSize;                                           //set our array size to the initialsize
        count = -1;                                                        //no items in our array;
    }
    ~DynStack()
    {
        delete array;
        cout<<"TEST STATEMENT DESTRUCTOR HAS EXECUTED"<<endl;
    };
};





#endif //PORJ2PRAC_DYNSTACK_H
