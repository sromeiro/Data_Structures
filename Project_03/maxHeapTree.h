#ifndef MAXHEAPTREE_H
#define MAXHEAPTREE_H
#include<stdexcept>

/***********************************************************************************************************************
 *                                               IMPORTANT                                                             *
 *                                   INDEX OF ARRAY STARTS FROM 1 NOT 0                                                *
 ***********************************************************************************************************************/
template <class Type>
class maxHeapTree
{
private:
    treeNode<Type> * array;                                               //array of tree nodes for heap
    int count;                                                            //number of elements(tree nodes) in array
    int capacity;
    int initCapacity;
public:
    maxHeapTree(int n = 5) : array(NULL) , count(0) //default size 15 for array
    {
        capacity = n;
        initCapacity = n;
        array = new treeNode<Type>[capacity+1];                                    //create an tree node array of default size 15//
    }
    treeNode<Type> * getMax()
    {
        if(count==0)                                                      //if empty
        {
            //NEED CATCH THROW HERE
            cout<<"empty"<<endl;
            return & array[1];                 //NEED TO DELETE THIS IN CATCH THROW STATEMENT
        }
        else
        {
            return & array[1];
        }
    }
    int getSize()
    {
        return count;
    }
    //USED TO TEST DYNAMIC ARRAY SIZE CHANGE
    int getCapacity()
    {
        return capacity;
    }
    bool empty()
    {
        return !count;
    }
    int leaves()
    {
        if(empty()){return 0;}
        else
        {
            if(count%2 == 0) //IS EVEN
            {
                return count / 2;
            }
            else             //IS ODD
            {
                return (count / 2) + 1;                                     //roof of count/2 is # of leaves (if count is odd)
            }
        }
    }
    int height()
    {
        int height = 0;
        if(empty())
        {
            return 0;
        }
        else
        {
            int i = count;
            while(i!=1)
            {
                i = i / 2;                                                                  //each row in a tree is halfed by 2 to get to previous (count number of times halved until equals 1)
                height++;
            }
        }
        return height;
    }
    void insert(int key_to_insert, Type data)   //KEY WILL BE USED FOR SORTING MAX , data is arbitrary but must be stored
    {
        if(count == 0) // no nodes in array
        {
            treeNode<Type> temp;                                //create new node set our key and our value
            temp.setKey(key_to_insert);
            temp.setValue(data);
            count++;                                                                      //our count is now 1
            array[count] = temp;                                                            //place pointer to our first node in array
            return;
        }
        if(count == capacity)
        {
            treeNode<Type> * temp_increase = new treeNode<Type>[(capacity*2)+1];
            for(int i=0;i<=count;i++)
            {
                temp_increase[i] = array[i];
            }
            delete []array;
            array = temp_increase;
            capacity*=2;
        }
        treeNode<Type>  node;                                    //first create our new node and set value and key
        node.setKey(key_to_insert);
        node.setValue(data);
        count++;
        array[count] =  node;                                                          //place our node in last position in array
        int temp_count = count;                                                           //need a temp count so we dont alter our original count
        while(array[temp_count].getKey() > array[temp_count/2].getKey() && temp_count>=2) //IF CHILD IS GREATER THAN PARENT WE SWAP (COUNT >= 2 or will go out of bounds)
        {
            treeNode<Type> temp;                                                         //temp for swap
            temp = array[temp_count/2];                                                   //copy parent
            array[temp_count/2] = array[temp_count];                                      //parent swapped with greater child
            array[temp_count] = temp;                                                     //previous parent is now the child node
            temp_count = temp_count/2;                                                    //temp count is now at the parent and will traverse up
        }
    }
    void delMax() {
        int index = 1;                                                                    //used for sorting after swap
        //NEED CATCH THROW HERE
        if (count == 0)                                                                      //empty heap
        {
            return;
        }
        if((count-1)<(capacity/4)&&capacity>initCapacity)  //if size is going to be 1/4 after the delete and the capacity and greater than initialsize set
        {
            treeNode<Type> * temp_change = new treeNode<Type>[(capacity/2)+1]; //new array of 1/2 size
            for(int i=0;i<=count;i++)
            {
                temp_change[i] = array[i]; //copy over elements
            }
            delete []array;              //delete old array
            array = temp_change;
            capacity/=2;                 //capacity now have the size
        }
        if (count == 1) {
            count--;
            return;
        }                                          //if only one node delete root and count goes back to 0
        //FIRST SWAP LAST AND FIRST NODE IN ARRAY
        treeNode<Type>  temp;
        temp = array[1];
        array[1] = array[count];                                                            //swapped the root node
        count--;                                                                          //count is one less
        while (index <= count) {
            if (count >= (index * 2) + 1)                                                        //check if it has a left and right child
            {
                if (array[index * 2].getKey() > array[(index * 2) + 1].getKey() && array[index].getKey() < array[index * 2].getKey())  //compare our child keys ( left > right ) and ( parent < left )
                {
                    treeNode<Type> temp;                                                  //swap our parent and child
                    temp = array[index];                                                  //copy of parent
                    array[index] = array[index * 2];                                              //parent is now the left child
                    array[index * 2] =  temp;                                                      //previous parent is now left child
                    index = index * 2;                                                            //change our index where we swapped
                }
                else if (array[index].getKey() < array[(index * 2) + 1].getKey())                                 //parent key is less than right child
                {
                    treeNode<Type>  temp;                                                  //swap parent and child
                    temp = array[index];                                                  //copy the parent
                    array[index] = array[(index * 2) + 1];                                //parent is now the right child
                    array[(index * 2) + 1] = temp;                                        //previous parent is now the right child
                    index = (index * 2) + 1;                                              //update the index
                }else{index++;}
            }
            else if(count>= index*2)                                                      //has just one left child
            {
                if(array[index].getKey() < array[index*2].getKey())
                {
                    treeNode<Type>  temp;                                                  //swap our parent and child
                    temp = array[index];                                                  //copy of parent
                    array[index] = array[index * 2];                                              //parent is now the left child
                    array[index * 2] = temp;                                                      //previous parent is now left child
                    index = index * 2;                                                            //change our index where we swapped
                }else{index++;}
            }
            else
            {
                index++;
            }
        }
    }
    void print()
    {
        if(count==0) //NEED CATCH THROW HERE
        {
            cout<<"empty"<<endl;
            return;
        }
        cout<<"Val : ";
        for(int i = 1; i <=count; i++)
        {
            cout<<"["<<array[i].getValue()<<"] ";
        }
        cout<<endl;
        cout<<"Key : ";
        for(int i = 1; i <=count; i++)
        {
            cout<<"["<<array[i].getKey()<<"] ";
        }
        cout<<endl;
    }
    void clear()
    {
        delete []array;
        array = new treeNode<Type>[capacity+1];                                    //create an tree node array of default capacity 15
        count=0;
    }
    ~maxHeapTree()
    {
        delete []array;
    }
};

#endif
