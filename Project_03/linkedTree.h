#ifndef LINKEDTREE_H
#define LINKEDTREE_H
#include<stdexcept>
#include<iostream>

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

    Type getValue()
    {
      return root->value;
    }

    //Returns root pointer
    treeNode<Type> * getRoot()
    {
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
      else if(countChildren(root) == 0)
      {
        //Root is the only node
        return mySize = 1;
      }

      mySize = 1; //Tree contains at least 1 node
      treeNode<Type> * parent = root;     //Temporary node to hold parent
      treeNode<Type> * currentNode = root; //Temporary node to hold current node

      while(parent != NULL) //while not at root
      {
        if(countChildren(currentNode))
        {
          parent = currentNode; //Update parent before moving currentNode down
          if(currentNode->leftChild)
          {
            //Left child exists. Increment mySize
            mySize++;
            currentNode = currentNode->leftChild;
          }
          else if(currentNode->rightChild)
          {
            //No left child but right child exists. Increment mySize
            mySize++;
            currentNode = currentNode->rightChild;
          }
        }

        else
        {
          //No children exist. Check siblings
          if(currentNode.sibling())
          {
            //Sibling exists check if it's left or right child of parent
            while(currentNode == parent->rightChild)
            {
              //I'm the right child and have already been counted. Move up the tree
              currentNode = parent;
              parent = parent->parent;
            }

            //I'm the left child, move to right and increment mySize
            currentNode = currentNode.getSibling();
            mySize++;
          }

          else
          {
            //While no siblings exists OR I'm the right child. Move up the tree.
            while(currentNode.siblings() == 0 || currentNode == parent->rightChild)
            {
              currentNode = parent;
              parent = parent->parent;
            }

            if(parent != NULL) //Not at root yet
            {
              //Found a left child node with a sibling. Move over and increment.
              currentNode = currentNode.getSibling();
              mySize++;
            }
          }
        }
      }

      return mySize;
    }

    //Returns the height of the tree
    int getHeight()
    {
      return root->height;
    }

    //Returns height of a particular node
    int getHeight(treeNode<Type> & node)
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
      int leaves = 0;
      treeNode<Type> * currentNode = root; //temporary node for traversing

      while(currentNode != NULL)
      {
        if(countChildren(currentNode) != 0)
        {
          //Children exist.
          if(currentNode->leftChild)
          {
            //Left child exists. Descend left.
            currentNode = currentNode->leftChild;
          }
          else if(currentNode->rightChild)
          {
            //No left child. Right child exists. Descend right.
            currentNode = currentNode->rightChild;
          }
        }

        else
        {
          //No children. I'm a leaf.
          leaves++;

          while(currentNode.siblings() == 0 && currentNode != NULL)
          {
            /*
            * Only evaluates if no siblings exist and I'm not NULL.
            * Keep going up the tree until a sibling is found or NULL reached
            */
            currentNode = currentNode->parent;
          }
          if(currentNode->value < currentNode.getSibling()->value)
          {
            /*
            * If a sibling exists with a higher value then it is the right sibling.
            * Make currentNode that right sibling and continue checks.
            */
            currentNode = currentNode.getSibling();
          }
          else
          {
            /*
            * If a sibling exists but with a lower value, then we need to move
            * up the tree until we find a sibling with a higher value or we reach NULL
            */
            while(currentNode != NULL && currentNode->value > currentNode.getSibling()->value)
            {
              currentNode = currentNode->parent;
            }
            //Sibling with higher value found. Move there.
            currentNode = currentNode.getSibling();
          }

          //End else. Return to while loop.
        }

      }

      return leaves;
    }

    //Returns the number of siblings of a given node
    int siblings(treeNode<Type> & node)
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
      if(root->value == data)
      {
        cout << "Value is in root!" << endl;
        //Root contains desired value
        return root;
      }

      //cout << "Value is NOT in root" << endl;
      treeNode<Type> * currentNode = root;
      //treeNode<Type> * currentParent = root; //Probably don't need parent*************************

      //While data hasn't been found. Check for children and move down
      while(currentNode->value != data)
      {
        cout << "WHILE currentNode->value != data" << endl;
        if(countChildren(currentNode) != 0)
        {
          cout << "IF Children exist" << endl;
          //currentParent = currentNode; //Update parent to current before descent****************
          if(currentNode->value > data)
          {
            cout << "currentNode->value LESS than data. Descend LEFT" << endl;
            //Data is smaller than currentNode. Descend left.
            currentNode = currentNode->leftChild;
          }
          else if(currentNode->value < data)
          {
            cout << "currentNode->value GREATER than data. Descend RIGHT" << endl;
            //Data is larger than currentNode. Descend right.
            currentNode = currentNode->rightChild;
            cout << "Going to access currentNode->value now" << endl;
          }
        }

        else
        {
          //Data not in tree
          cout << "Data you were looking for was not found!" << endl;
          return NULL;
        }
      }

      //Data found in currentNode
      return currentNode;
    }

    //Traverses tree in Preorder. Parent -> Left -> Right
    void preorder()
    {
      cout << "Preorder traversal is:" << endl;



    }

    //Traverses tree in Postorder. Left -> Right -> Parent
    void postorder()
    {
      if(empty())
      {
        throw runtime_error("Tree is empty!");
        return;
      }

      treeNode<Type> * parent = root;     //Temporary node to hold parent
      treeNode<Type> * currentNode = root; //Temporary node to hold current node

      while(parent != NULL) //while not at root
      {
        if(countChildren(currentNode))
        {
          parent = currentNode; //Update parent before moving currentNode down
          if(currentNode->leftChild)
          {
            //Left child exists. Descend left
            currentNode = currentNode->leftChild;
          }
          else if(currentNode->rightChild)
          {
            //No left child. Right exists. Descend right
            currentNode = currentNode->rightChild;
          }
        }

        else
        {
          //No children exist. Begin printing
          auxPostorder(parent);
          //=======================WORKING HERE==============================//
        }
      }
    }

    //Traverses tree in Inorder. Left -> Parent -> Right
    void inorder()
    {
      cout << "Inorder traversal is:" << endl;



    }

    //Clears the tree of all nodes
    void clear()
    {

    }

    //Inserts requested data item into the tree
    void insert(Type data)
    {
      cout << "Insert called" << endl;
      if(empty())
      {
        cout << "It's empty" << endl;
        //New item is root
        treeNode<Type> * newNode = new treeNode<Type>(data);
        root = newNode;
        return;
      }

      treeNode<Type> * currentNode = root;

      while(data < currentNode->value)
      {
        cout << "Data is LESS than current value" << endl;
        if(currentNode->leftChild == NULL)
        {
          //Left child does not exist and data is less than current. Create node
          cout << "No left child exists. Creating Node." << endl;
          treeNode<Type> * newNode = new treeNode<Type>(data);
          currentNode->leftChild = newNode;
          newNode->parent = currentNode;
          currentNode = newNode; //Breaks out of the While loop
        }

        else
        {
          cout << "Left child exists. Descending left" << endl;
          currentNode = currentNode->leftChild;
        }
      }

      /*
      currentNode = findNode(data);
      cout << "Need to create the NODE" << endl;
      if(currentNode == NULL)
      {
        cout << "Entered IF Current node is NULL" << endl;
        //Data item is not in the tree. Add the item.
        currentNode = root; //Set currentNode to root to begin search
        parent = root->parent;

        while(parent == NULL)
        {
          cout << "WHILE parent == NULL" << endl;
          while(currentNode->leftChild && currentNode->value < data)
          {
            cout << "WHILE LESS" << endl;
            //Left child exists and data is less than current. Descend left
            currentNode = currentNode->leftChild;
          }
          if(currentNode->value < data)
          {
            cout << "IF LESS" << endl;
            //Left child does not exist and data is less than current. Create node
            treeNode<Type> * newNode = new treeNode<Type>(data);
            currentNode->leftChild = newNode;
            newNode->parent = currentNode;
            parent = currentNode;
          }

          while(currentNode->rightChild && currentNode->value > data)
          {
            cout << "WHILE LARGE" << endl;
            //Right child exists and data is greater than current. Descend right
            currentNode = currentNode->rightChild;
          }
          if(currentNode->value > data)
          {
            cout << "IF LARGE" << endl;
            //Right child does not exist and data is greater than current. Create node
            treeNode<Type> * newNode = new treeNode<Type>(data);
            currentNode->rightChild = newNode;
            newNode->parent = currentNode;
            parent = currentNode;
          }
        }
      }

      else
      {
        //Data item found in the tree
        cout << "The data item [" << data << "] is already in the tree!" << endl;
      }
      */
      cout << "Function insert ENDED" << endl;
    }

    //Deletes the requested data item from the tree
    void del(Type data)
    {

    }

    //Destructor. Deletes all pointers within tree
    ~linkedTree()
    {
      //Needs to delete all nodes
    }

    //Auxilary function to assist with Postorder traversal
    void auxPostorder(treeNode<Type> & node)
    {
      if(node == NULL)
      {
        //Node does not exist
        cout << "Node does not exist!" << endl;
        return;
      }

      //Print Left
      if(node->leftChild)
      {
        cout << "[" << node->leftChild->value << "] ";
      }
      //Print Right
      if(node->rightChild)
      {
        cout << "[" << node->rightChild->value << "] ";
      }

      //Print Parent
      cout << "[" << node->value << "]" << endl;
    }

};

#endif
