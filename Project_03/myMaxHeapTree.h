#ifndef DATAPROJ_MYMAXHEAPTREE_H
#define DATAPROJ_MYMAXHEAPTREE_H

/***********************************************************************************************************************
 *                                               IMPORTANT                                                             *
 *                                   INDEX OF ARRAY STARTS FROM 1 NOT 0                                                *
 ***********************************************************************************************************************/
template <class Type>
class MaxHeapTree
{
private:
    TreeNode<Type> * array;                                               //array of tree nodes for heap
    int count;                                                            //number of elements(tree nodes) in array
    int capacity;
    int origCapacity;
public:
    MaxHeapTree(int n = 15) : count(0) //default size 15 for array
    {
        array = new TreeNode<Type>[n];                                    //create an tree node array of default size 15
        capacity = n;
        origCapacity = n;                                                 //
    }
    TreeNode<Type> * getMax()
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
            // TreeNode<Type> * temp = new TreeNode<Type>();                                 //create new node set our key and our value     //WILL BE DELETEING SINCE WE DONT NEED NEW
            TreeNode<Type> temp;                                //create new node set our key and our value
            temp.setKey(key_to_insert);
            temp.setValue(data);
            array[1] = temp;                                                            //place pointer to our first node in array
            count++;                                                                      //our count is now 1
            return;
        }
        //TreeNode<Type> * node = new TreeNode<Type>();                                     //first create our new node and set value and key //WILL BE DELETEING SINCE WE DONT NEED NEW
        TreeNode<Type>  node;                                    //first create our new node and set value and key
        node.setKey(key_to_insert);
        node.setValue(data);
        array[++count] = node;                                                          //place our node in last position in array
        int temp_count = count;                                                           //need a temp count so we dont alter our original count
        while(array[temp_count].getKey() > array[temp_count/2].getKey() && temp_count>=2) //IF CHILD IS GREATER THAN PARENT WE SWAP (COUNT >= 2 or will go out of bounds)
        {
            TreeNode<Type> temp;                                                         //temp for swap
            temp = array[temp_count/2];                                                   //copy parent
            array[temp_count/2] = array[temp_count];                                      //parent swapped with greater child
            array[temp_count] = temp;                                                     //previous parent is now the child node
            temp_count = temp_count/2;                                                    //temp count is now at the parent and will traverse up
            if (temp_count==1)
            {
                break;
            }
        }
    }
    void delMax() {
        int index = 1;                                                                    //used for sorting after swap
        //NEED CATCH THROW HERE
        if (count == 0)                                                                      //empty heap
        {
            return;
        }
        if (count == 1) {
//            TreeNode<Type>  temp;
//            temp = array[1];
            //delete temp;

            count--;
            return;

        }                                          //if only one node delete root and count goes back to 0
        //FIRST SWAP LAST AND FIRST NODE IN ARRAY
        TreeNode<Type>  temp;
        temp = array[1];
        array[1] = array[count];                                                            //swapped the root node
        count--;                                                                          //count is one less
        while (index <= count) {
            if (count >= (index * 2) + 1)                                                        //check if it has a left and right child
            {
                if (array[index * 2].getKey() > array[(index * 2) + 1].getKey() && array[index].getKey() < array[index * 2].getKey())  //compare our child keys ( left > right ) and ( parent < left )
                {
                    TreeNode<Type>  temp;                                                  //swap our parent and child
                    temp = array[index];                                                  //copy of parent
                    array[index] = array[index * 2];                                              //parent is now the left child
                    array[index * 2] =  temp;                                                      //previous parent is now left child
                    index = index * 2;                                                            //change our index where we swapped
                }
                else if (array[index].getKey() < array[(index * 2) + 1].getKey())                                 //parent key is less than right child
                {
                    TreeNode<Type>  temp;                                                  //swap parent and child
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
                    TreeNode<Type>  temp;                                                  //swap our parent and child
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
        array = new TreeNode<Type>[capacity];                                    //create an tree node array of default capacity 15
        count=0;
    }
    ~MaxHeapTree()
    {
        delete []array;
    }
};

#endif //DATAPROJ_MYMAXHEAPTREE_H
