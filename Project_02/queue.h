#ifndef PORJ2PRAC_DYNQUEUE_H
#define PORJ2PRAC_DYNQUEUE_H
#include<stdexcept>
template <class Type>
class DynQueue
{
private:
    Type * array;
    int Head;
    int Tail;
    int count;
    int initialSize;
    int arraySize;
public:
    DynQueue(int n = 15) : Head(0),Tail(-1),count(-1),initialSize(15),arraySize(15)
    {
        if(n<=0)                                               //if arguement is 0 or a negative integer
        {
            arraySize = 1;
            array = new Type[arraySize];                       //new array size 1
            initialSize = 1;
        }
        else
        {
            array = new Type[n];                               //new array is number entered by user or default 15
            arraySize = n;
            initialSize = n;
        }

    }
    Type front() const
    {
        if(empty())
        {
            throw out_of_range("Queue is empty!");
        }
        else
        {
            return array[Head];
        }
    }
    Type back() const
    {
        if(empty())
        {
            throw out_of_range("Queue is empty!");
        }
        else
        {
            return array[Tail];
        }
    }
    int size() const
    {
        return (count+1);
    }
    bool empty() const
    {
        return count == -1;
    }
    int capacity() const
    {
        return arraySize;
    }
    void display()
    {
        if(empty())
        {
            throw out_of_range("Queue is empty!");
        }
        int i;
        cout << "List of items stored in the Queue:" << endl;
        cout << "Front\n" << "  |\n" << "  V" << endl;
        if(Head<=Tail)                                                      //If queue has not wrapped around
        {
            for (i = Head; i <= Tail; i++) {
                cout << " [" << array[i] << "]";
            }
        }else                                                               //Tail has wrapped around back to beginning
        {
            cout << "List of items stored in the Queue:" << endl;
            cout << "Front\n" << "  |\n" << "  V" << endl;
            for(i=Head;i<arraySize;i++)
            {
                cout << " [" << array[i] << "]";
            }
            for(i=0;i<=Tail;i++)
            {
                cout << " [" << array[i] << "]";
            }
        }
        cout << endl;
    }
    void enqueue(Type const & data)
    {
        if((size())==arraySize)                                             //if full we double
        {
            int tracker = 0;
            Type * temp_increase = new Type[arraySize*2];                   //new array double the size
            if(Head<=Tail)                                                  //if queue has not wrapped around
            {
                for (int i = Head; i <= Tail; i++) {                        //copy elements from head to tail
                    temp_increase[tracker++] = array[i];
                }
                Head=0;
                Tail=(tracker-1);
            }else                                                           //Tail has wrapped around back to beginning
            {
                for(int i=Head;i<arraySize;i++)                             //copy elements from head to end
                {
                    temp_increase[tracker++] = array[i];
                }
                for(int j=0;j<=Tail;j++)                                    //copy elements from 0 to tail
                {
                    temp_increase[tracker++] = array[j];
                }
                Head=0;
                Tail=(tracker-1);
            }
            delete []array;                                                 //delete old array
            array = temp_increase;                                          //array is now new doubled array
            arraySize*=2;
            array[++Tail] = data;
            count++;
            return;
        }
        else if((Tail+1) == arraySize )                                     //case where reach end of array but not full
        {
            Tail = 0;                                                       //place tail at start
            array[Tail] = data;                                             //place data at 0
            count++;
            return;
        }else
        {
            array[++Tail] = data;
            count++;
            return;
        }

    }
    Type dequeue()
    {
        if(empty())
        {
            throw out_of_range("Queue is empty!");
        }
        --count;                                                            //one less from count
        Type to_return = array[Head];
        if(count<(arraySize/4) && arraySize>initialSize)                    //CASE 1 : if 1/4 full and size large than the initial O(n)
        {
            int restart = 0;
            int tail_count = -1;
            Type * temp_change = new Type[arraySize/2];                     //new array double the size
            if(Head<=Tail)                                                  //if queue has not wrapped around
            {
                for(int i=Head;i<=Tail;i++)                                 //loop and copy elements in the array
                {
                    temp_change[restart++] = array[i];
                }
                Tail = (restart-1);
            }else                                                           //Tail has wrapped around back to beginning
            {
                for(int i=Head;i<arraySize;i++)                             //copy elements from head to end
                {
                    temp_change[restart++] = array[i];
                    tail_count++;
                }
                for(int j=0;j<=Tail;j++)                                    //copy elements from 0 to tail
                {
                    temp_change[restart++] = array[j];
                    tail_count++;
                }
                Tail = tail_count;
            }
            delete []array;                                                 //delete old array
            array = temp_change;                                            //array is now new doubled array
            arraySize/=2;
            Head = 1;
            return array[0];
        }
        else if((Head+1) == arraySize )                                     //Case 2 : Heads at end of array O(1)
        {
            Head = 0;                                                       //Head now back at beginning of array
            return to_return;
        }
        else                                                                //Case 3: Majority of time O(1)
            Head++;                                                         //go to next in line
        return to_return;
    }
    void clear()
    {
        if(empty())
        {
            throw out_of_range("Queue is empty!");
        }
        delete []array;                                                      //delete all elements in array
        array = new Type[initialSize];                                       //new array of initial size
        arraySize = initialSize;                                             //set our array size to the initialsize
        count = -1;
        Head = 0;
        Tail = -1;
    }
    ~DynQueue(){ delete []array;};
};

#endif //PORJ2PRAC_DYNQUEUE_H
