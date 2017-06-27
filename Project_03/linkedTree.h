#ifndef LINKEDTREE_H
#define LINKEDTREE_H
#include<stdexcept>
#include<iostream>
#include<string>

using namespace std;

template <class Type>
class linkedTree
{
  private:
    int mySize; //For easy access to size of the tree
    treeNode<Type> * root; //Pointer to the root of the tree

  public:
    linkedTree() : mySize(0), root(NULL)
    {
      //Set parameters above and initialize them here if user values are needed
    }



    //Returns root pointer
    treeNode<Type> * getRoot()
    {
      if(empty())
      {
        throw runtime_error("Tree is empty!");
      }
      return root;
    }

    //Returns size of tree
    int getSize()
    {
      if(empty())
      {
        throw runtime_error("Tree is empty!");
        return 0;
      }

      return mySize;
    }

    //Returns the height of the tree
    int getHeight()
    {
      if(empty())
      {
        throw runtime_error("Tree is empty!");
      }
      return root->height;
    }

    //Returns height of a particular node
    int getHeight(treeNode<Type> * node)
    {

      return node->height;
    }

    //Returns true if the tree is empty
    bool empty()
    {
      return root == NULL; //If root pointer is NULL, tree is empty
    }

    //Returns the number of nodes in a tree with no children
    int leaves()
    {
        if(root==NULL){ return 0;}                                          //empty root
        else
            return leavesRec(root);
    }

    //Auxilary function to be called by leaves()
    int leavesRec(treeNode<Type> * node)
    {
        if(node == NULL){return 0;}
        if(node->leftChild == NULL && node->rightChild == NULL)
        {
            return 1;
        }
        return leavesRec(node->leftChild) + leavesRec(node->rightChild);
    }

    //Returns the number of siblings of a given node
    int siblings(treeNode<Type> * node)
    {
      if(node->parent == NULL)
      {
        //Node requested is root
        return 0;
      }
      return countChildren(node->parent) - 1;
    }

    //Auxilary function that tells us how many children a node has
    int countChildren(treeNode<Type> * node)
    {
      int children = 0;
      if(node->leftChild != NULL)
      {
        //Left child exists. Count up.
        children += 1;
      }
      if(node->rightChild != NULL)
      {
        //Right child exists. Count up.
        children += 1;
      }

      return children;
    }

    //Auxilary function that returns a pointer to a sibling if it exists. Otherwise returns root
    treeNode<Type> * getSibling()
    {
      if(root->parent == NULL)
      {
        //This is the root node
        return root;
      }

      if(root->parent->leftChild->value != root->value)
      {
        //Sibling on the left is not me. Return him
        return root->parent->leftChild;
      }
      else if(root->parent->rightChild->value != root->value)
      {
        //Sibling on the right is not me. Return him
        return root->parent->rightChild;
      }
    }

    treeNode<Type> * findNode(Type data)
    {
      if(empty())
      {
        throw runtime_error("Tree is empty!");
      }

      if(root->value == data)
      {
        //cout << "Value is in root!" << endl;
        //Root contains desired value
        return root;
      }

      //cout << "Value is NOT in root" << endl;
      treeNode<Type> * currentNode = root;
      //treeNode<Type> * currentParent = root; //Probably don't need parent*************************

      //While data hasn't been found. Check for children and move down
      while(currentNode->value != data)
      {
        //cout << "WHILE currentNode->value != data" << endl;
        if(countChildren(currentNode) != 0)
        {
          //cout << "IF Children exist" << endl;
          //currentParent = currentNode; //Update parent to current before descent****************
          if(currentNode->value > data)
          {
            //cout << "currentNode->value LESS than data. Descend LEFT" << endl;
            //Data is smaller than currentNode. Descend left.
            currentNode = currentNode->leftChild;
          }
          else if(currentNode->value < data)
          {
            //cout << "currentNode->value GREATER than data. Descend RIGHT" << endl;
            //Data is larger than currentNode. Descend right.
            currentNode = currentNode->rightChild;
            //cout << "Going to access currentNode->value now" << endl;
          }
        }

        else
        {
          //Data not in tree
          throw runtime_error("Data you were looking for was not found!");
          return NULL;
        }
      }

      //cout << "Data found in current node" << endl;

      //Data found in currentNode
      return currentNode;
    }

    //Traverses tree in Preorder. Parent -> Left -> Right
    void preorder()
    {
        cout<<"Preorder :";
        preorderRec(root);
        cout<<endl;
    }

    //PREORDER HELPER FUNCTION FOR RECURSIVE
    void preorderRec(treeNode<Type> * node)
    {
        if(node==NULL)
        {
            return;
        }
        cout<<" ["<<node->value<<"]";
        preorderRec(node->leftChild);
        preorderRec(node->rightChild);
    }

    //Traverses tree in Postorder. Left -> Right -> Parent
    void postorder()
    {
        cout<<"Postoder :";
        postorderRec(root);
        cout<<endl;
    }

    //POSTORDER HELPER FUNCTION FOR RECURSIVE
    void postorderRec(treeNode<Type> * node)
    {
        if(node==NULL)
        {
            return;
        }
        postorderRec(node->leftChild);
        postorderRec(node->rightChild);
        cout<<" ["<<node->value<<"]";
    }

    //Traverses tree in Inorder. Left -> Parent -> Right
    void inorder()
    {
        cout<<"Inorder :";
        inorderRec(root);
        cout<<endl;
    }

    //INORDER HELPER FUNCTION FOR RECURSIVE
    void inorderRec(treeNode<Type> * node)
    {
        if(node==NULL)
        {
            return;
        }
        inorderRec(node->leftChild);
        cout<<" ["<<node->value<<"]";
        inorderRec(node->rightChild);
    }

    //Clears the tree of all nodes
    void clear()
    {
      if(empty())
      {
        throw runtime_error("Tree is empty!");
      }
      clearRec(root);
    }

    void clearRec(treeNode<Type> * node)
    {
      if(countChildren(node) == 2)
      {
        clearRec(node->leftChild);
        clearRec(node->rightChild);
        clearRec(node);
      }
      else if(countChildren(node) == 1 && node->leftChild)
      {
        clearRec(node->leftChild);
        clearRec(node);
      }
      else if(countChildren(node) == 1 && node->rightChild)
      {
        clearRec(node->rightChild);
        clearRec(node);
      }
      else
      {
        del(node->value);
      }
    }

    //Inserts requested data item into the tree
    void insert(Type data)
    {
      //cout << "Insert called" << endl;
      if(empty())
      {
        //cout << "It's empty" << endl;
        //New item is root
        treeNode<Type> * newNode = new treeNode<Type>(data);
        root = newNode;
        mySize++;
        return;
      }

      treeNode<Type> * currentNode = root;
      treeNode<Type> * currentParent = root; //Will keep track of parent to come back up

      while(currentNode->value != data) //While new node hasn't been created
      {
        while(data < currentNode->value) //Descend left until no left child is found
        {
          //cout << "Data: " << data << " is LESS than " << currentNode->value << endl;
          if(currentNode->leftChild == NULL)
          {
            //Left child does not exist and data is less than current. Create node
            //cout << "No left child exists. Creating Node." << endl;
            treeNode<Type> * newNode = new treeNode<Type>(data); //Creating the new node
            currentNode->leftChild = newNode; //leftChild is now the new node
            newNode->parent = currentNode;
            currentParent = currentNode;

            while(currentParent != NULL)
            {
              //From the parent of the new node up to root. Update all heights.
              //cout << "Updating height of node " << currentParent->value << " from: " << currentParent->height << endl;
              currentParent->updateHeight();
              //cout << "Height of node " << currentParent->value << " is now: " << currentParent->height << endl;
              currentParent = currentParent->parent;

            }
            currentNode = newNode; //Breaks out of the main while loop
            mySize++;
          }

          else
          {
            //cout << "Left child exists. Descending left" << endl;
            currentParent = currentNode;
            currentNode = currentNode->leftChild;
          }
        }

        while(data > currentNode->value) //Descend right until no right child is found
        {
          //cout << "Data: " << data << " is GREATER than " << currentNode->value << endl;
          if(currentNode->rightChild == NULL)
          {
            //Right child does not exist and data is greater than current. Create node
            //cout << "No right child exists. Creating Node." << endl;
            treeNode<Type> * newNode = new treeNode<Type>(data);
            currentNode->rightChild = newNode;
            newNode->parent = currentNode;
            currentParent = currentNode;

            while(currentParent != NULL)
            {
              //From the parent of the new node up to root. Update all heights.
              //cout << "Updating height of node " << currentParent->value << " from: " << currentParent->height << endl;
              currentParent->updateHeight();
              //cout << "Height of node " << currentParent->value << " is now: " << currentParent->height << endl;
              currentParent = currentParent->parent;

            }
            currentNode = newNode; //Breaks out of the While loop
            mySize++;
          }

          else
          {
            //cout << "Right child exists. Descending right" << endl;
            currentParent = currentNode;
            currentNode = currentNode->rightChild;
          }
        }
      }
      //cout << "Function ended" << endl;
    }

    //Deletes the requested data item from the tree
    void del(Type data)
    {
      if(empty())
      {
        throw runtime_error("Tree is empty!");
      }

      treeNode<Type> * currentNode;
      treeNode<Type> * currentParent;
      currentNode = findNode(data);
      currentParent = currentNode->parent;

      //cout << "Node to delete is: " << currentNode->value << endl;

      if(countChildren(currentNode) == 2) //Node to delete has 2 children.
      {
        cout << "Children of this node are: " << currentNode->leftChild->value << " and " << currentNode->rightChild->value << endl;
        //Find successor, the smallest of the rightChild
        treeNode<Type> * successorNode = currentNode->rightChild;
        currentParent = currentNode;

        while(successorNode->leftChild)
        {
          //Find smallest of larger values
          currentParent = successorNode;
          successorNode = successorNode->leftChild;
        }

        currentNode->value = successorNode->value; //Copy successor value over to current
        currentNode = successorNode; //Copy pointer address

      }

      //Case where there was only 1 or 0 children
      treeNode<Type> * subtree; //Subtree is the tree formed by the node being deleted
      subtree = currentNode->leftChild; //Originally set it to left child
      if(subtree == NULL)
      {
        //If left child subtree didn't exist, then set it to right child
        subtree = currentNode->rightChild;
      }
      if(currentParent == NULL)
      {
        //This is root that is being removed
        root = subtree;
        if(root != NULL)
        {
          root->parent = NULL;
        }
      }
      else if(currentParent->leftChild == currentNode)
      {
        //If saved parent left child is being deleted, point left child to new subtree
        currentParent->leftChild = subtree;
      }
      else
      {
        //If saved parent right child is being deleted, point right child to new subtree
        currentParent->rightChild = subtree;
      }

      while(currentNode != NULL)
      {
        currentNode->updateHeight();
        currentNode = currentNode->parent;
      }

      delete currentNode;
      mySize--;
    }

    //Destructor. Deletes all pointers within tree
    ~linkedTree()
    {
      clear();
    }



    void printing(treeNode<Type> * node)
    {
      cout << "Info on node: " << node->value << endl;
      cout << "Height of this node is: " << node->height << endl;
      if(node->parent != NULL)
      {
        cout << "Parent of this node is: " << node->parent->value << endl;
      }

      if(countChildren(node) == 2)
      {
        cout << "Children of this node are: " << node->leftChild->value << " and " << node->rightChild->value << endl;
      }
      else if(countChildren(node) == 1 && node->leftChild)
      {
        cout << "Node only has a left child and it is: " << node->leftChild->value << endl;
      }
      else if(countChildren(node) == 1 && node->rightChild)
      {
        cout << "Node only has a right child and it is: " << node->rightChild->value << endl;
      }
      else
      {
        cout << "This node has no children" << endl;
      }
    }

};

#endif
