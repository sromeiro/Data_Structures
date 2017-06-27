#include <cstdlib>
#include <iostream>
#include "myTreeNode.h"
#include "myLinkedTree.h"
#include "myMaxHeapTree.h"

using namespace std;

int main()
{
    MaxHeapTree<int> myHeap;

//
    myHeap.insert(7,51);
    myHeap.insert(0,4);


//    //cout<<"Max: "<<myHeap.getMax()->getValue()<<endl;
//    cout<<"Number of elements: "<<myHeap.getSize()<<endl;
//    cout<<"is empty: "<<myHeap.empty()<<endl;
//    cout<<"Height: "<<myHeap.height()<<endl;
//    cout<<"Leaves: "<<myHeap.leaves()<<endl;
//    myHeap.delMax();
//    myHeap.delMax();
//    myHeap.delMax();
//    myHeap.delMax();
//    myHeap.delMax();
//    myHeap.insert(7,15);
//    myHeap.insert(0,7);
//    myHeap.insert(2,3);
//    myHeap.insert(34,9);
//    myHeap.delMax();
//    myHeap.delMax();
//    myHeap.delMax();
//    myHeap.delMax();
//    myHeap.delMax();
//    myHeap.delMax();
//    myHeap.delMax();
//    myHeap.insert(7,51);
//    myHeap.insert(0,4);

//    myHeap.delMax();
    myHeap.delMax();
    myHeap.delMax();
    myHeap.print();
    cout<<"Number of elements: "<<myHeap.getSize()<<endl;
    myHeap.clear();
    myHeap.insert(3,7);
    myHeap.insert(2,4);
    myHeap.insert(5,1);
    myHeap.insert(8,9);
    myHeap.insert(8,9);
    myHeap.insert(8,9);
    myHeap.insert(8,9);

    cout<<"Max: "<<myHeap.getMax()->getValue()<<endl;

    myHeap.print();

    cout<<"Max: "<<myHeap.getMax()->getValue()<<endl;










//	LinkedTree<int> myTree;
//	myTree.insert(5);
//	myTree.insert(3);
//	myTree.insert(4);
//	myTree.insert(6);
//	myTree.insert(9);
//	myTree.insert(10);
//
//
//	myTree.inorder();
//	myTree.preorder();
//	myTree.postorder();
//
//	cout<<"size: "<<myTree.getSize()<<endl;
//
//	cout<<myTree.siblings(myTree.findNode(6))<<endl;
//
//	cout<<"number or leaves: "<<myTree.leaves()<<endl;
//
//	cout<<"HEIGHT FROM ROOT : "<<myTree.getHeight()<<endl;


    return 0;
}