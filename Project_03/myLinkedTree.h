#ifndef DATAPROJ_MYLINKEDTREE_H
#define DATAPROJ_MYLINKEDTREE_H

#include <cstdlib>
#include <iostream>

using namespace std;

template <class Type>
class LinkedTree
{
private:
    TreeNode<Type> * root;                        //pointer to our root node
    int count;                                    //number of nodes
public:
    LinkedTree() : root(NULL) , count(0) {};      //constructor
    TreeNode<Type> * getRoot()
    {
        if(root != NULL)
        {
            return root;
        }
    }
    int getSize()
    {
        return count;
    }
    /********************************   IMPLEMENT *******************************************/
    int getHeight()  //RETURNS HEIGHT OF TREE
    {
        return getHeight(root); // this is wrong   //NEED TO HAVEWHOLE NEW IMPLEMENTATION   <-----------------------------------------NEEDS TO BE DONE
    }
    /********************************   IMPLEMENT *******************************************/
    int getHeight(TreeNode<Type> * node) //RETURNS HEIGHT OF NODE FROM THE ROOT  <----------------------------------------------------NEEDS TO BE DONE
    {
    }
    bool empty()
    {
        if(count>0)
        {
            return 0;
        }
        return 1;
    }
    int leaves()
    {
        if(root==NULL){ return 0;}                                          //empty root
        else
            return leavesRec(root);
    }
    int leavesRec(TreeNode<Type> * node)
    {
        if(node == NULL){return 0;}
        if(node->left == NULL && node->right == NULL)
        {
            return 1;
        }
        return leavesRec(node->left) + leavesRec(node->right);
    }
    int siblings(TreeNode<Type> * node)
    {
        if(node == NULL){ return 0;}                                         //empty node, no siblings
        if(node->parent == NULL) { return 0;}                                //node is the root
        TreeNode<Type> * temp = node->parent;                                //temp is pointer to the parent of the node
        int num_siblings = 0;
        if(temp->left)
        {
            num_siblings++;
        }
        if(temp->right)
        {
            num_siblings++;
        }
        return num_siblings - 1;                                             //-1 becase only possible to have 0 or 1 siblings
    }
    TreeNode<Type> * findNode(Type data)
    {
        //NEED CATCH THROW STATEMENT IF TREE IS EMPTY
        if(root==NULL){return NULL;}
        TreeNode<Type> * temp = root;                                        //using temp to search for data
        while(temp != NULL)
        {
            if(temp->value == data) { return temp;}                          //found our data
            if(data <= temp->value)                                          //less than we search to the left
            {
                temp = temp->left;
            }
            else if(data >= temp->value)                                     //greater than we search to the right
            {
                temp = temp->right;
            }
        }
    }
    void preorder()
    {
        cout<<"Preorder :";
        preorderRec(root);
        cout<<endl;
    }
    //PREORDER HELPER FUNCTION FOR RECURSIVE
    void preorderRec(TreeNode<Type> * node)
    {
        if(node==NULL)
        {
            return;
        }
        cout<<" ["<<node->value<<"]";
        preorderRec(node->left);
        preorderRec(node->right);
    }
    void postorder()
    {
        cout<<"Postoder :";
        postorderRec(root);
        cout<<endl;
    }
    //POSTORDER HELPER FUNCTION FOR RECURSIVE
    void postorderRec(TreeNode<Type> * node)
    {
        if(node==NULL)
        {
            return;
        }
        postorderRec(node->left);
        postorderRec(node->right);
        cout<<" ["<<node->value<<"]";
    }
    void inorder()
    {
        cout<<"Inorder :";
        inorderRec(root);
        cout<<endl;
    }
    //INORDER HELPER FUNCTION FOR RECURSIVE
    void inorderRec(TreeNode<Type> * node)
    {
        if(node==NULL)
        {
            return;
        }
        inorderRec(node->left);
        cout<<" ["<<node->value<<"]";
        inorderRec(node->right);
    }
    //MUTATORS
    void clear(){}; /********************************   IMPLEMENT *******************************************/ //<------------------------NEEDS TO BE DONE
    void insert(Type data)
    {
        if(root == NULL)
        {
            TreeNode<Type> * node = new TreeNode<Type>();                    //create new node (will be our root)
            node->value = data;
            root = node;
            count++;                                                         //count + 1 for total number of elements
            return;
        }
        else {
            insertNode(root, data);                                          //else call recursive helper function to add node
        }
    }
    //INSERT NODE HELPER FUNCTION FOR RECURSIVE
    TreeNode<Type> * insertNode(TreeNode<Type> * node, Type data)
    {
        if(node == NULL)                                                     //empty spot so we create new node and return it
        {
            TreeNode<Type> * node = new TreeNode<Type>();
            node->value = data;
            count++;
            return node;
        }
        if(data < node->value)                                                //left child
        {
            node->left = insertNode(node->left,data);                         //node->left is new node returned
            node->left->parent = node;
        }
        else if(data > node->value)                                           //right child
        {
            node->right = insertNode(node->right,data);                       //node->right is new node returned
            node->right->parent = node;
        }
        return node;
    }
    /********************************   IMPLEMENT *******************************************/ //<---------------------------------------------NEEDS TO BE DONE
    void del(Type data)
    {

    }
    Type rootData()
    {
        if(root!=NULL)
        {
            return root->value;
        }
    }
    ~LinkedTree(){};                              //DESTRUCTOR NEEDS IMPLEMENTATION
};

#endif //DATAPROJ_MYLINKEDTREE_H
