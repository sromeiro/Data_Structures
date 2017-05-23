#include "SingleNode.h"

using namespace std;
/****************************************************************
                                NOTE:
 Each function must have template<class Type> before the function
       dont use SingleNode:: but use SingleNode<Type> after
 ****************************************************************/
//Default constructor
template <class Type>
SingleNode<Type>::SingleNode(Type const &,SingleNode *) : data(0),next(NULL) //data by default int, next by default NULL
{

}
//GETDATA
//get our data
template <class Type>
Type SingleNode<Type>::getData() const
{

}
//GETNEXT
//returns next pointer
template <class Type>
SingleNode<Type>* SingleNode<Type>::getNext() const
{

}
//Default destructor
template <class Type>
SingleNode<Type>::~SingleNode()
{

}
