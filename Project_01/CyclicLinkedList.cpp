#include "CyclicLinkedList.h"

using namespace std;

//Default constructor
template <class Type>
CyclicLinkedList<Type>::CyclicLinkedList() : mySize(0),head_ptr(NULL),tail_ptr(NULL)  //default size=0, both head and tail NULL pointers
{

}
//SIZE
//return # of items on list
template <class Type>
int CyclicLinkedList<Type>::size() const
{

}
//EMPTY
//Returns true if list empty (otherwise return false)
template <class Type>
bool CyclicLinkedList<Type>::empty() const //
{

}
//FRONT
//Retrieves the object store in the node pointed to by head pointer
template <class Type>
Type CyclicLinkedList<Type>::front() const
{

}
//BACK
//Retrieves the object store in the node pointed to by tail pointer
template <class Type>
Type CyclicLinkedList<Type>::back() const
{

}
//HEAD
//Returns head pointer
template <class Type>
SingleNode<Type> * CyclicLinkedList<Type>::head() const
{

}
//TAIL
//Returns tail pointer
template <class Type>
SingleNode<Type> * CyclicLinkedList<Type>::tail() const
{

}
//COUNT
//Returns # of nodes in linked list storing a value equal to argument
template <class Type>
int CyclicLinkedList<Type>::count(Type const &) const
{

}
//PUSH_FRONT
//Creates a new SingleNode< Type > storing the argument, the next pointer of which is set to the current head pointer.
// The head pointer is set to this new node.
// If the list was originally empty,the tail pointer is set to point to the new node
template <class Type>
void CyclicLinkedList<Type>::push_front(Type const &)
{

}
//PUSH_BACK
//Similar to push front but places a new node at the back of list
template <class Type>
void CyclicLinkedList<Type>::push_back(Type const &)
{

}
//POP_FRONT
//Delete the node at the front of the linked list and, as necessary, update the head and tail pointers.
//Return the object stored in the node being popped
template <class Type>
Type CyclicLinkedList<Type>::pop_front()
{

}
//ERASE
//Delete the node(s) (from the front) in the linked list that contains the element equal to the argument
//(use == to to test for equality with the retrieved element).
//As necessary, update the head and tail pointers and the next pointer of any other node within the list.
//Return the number of nodes that were deleted
template <class Type>
int CyclicLinkedList<Type>::erase(Type const &)
{

}



