#ifndef LINKEDTREE_H
#define LINKEDTREE_H
#include<stdexcept>

using namespace std;

template <class Type>
class linkedTree
{
  private:
    int mySize; //Key tied to the data node. Needed since some types can't be sorted
    treeNode<Type> * root; //Pointer to the root of the tree

  public:
    linkedTree() : mySize(0), root(NULL)
    {
      //Set parameters above and initialize them here if user values are needed
    }

    //Returns root pointer
    treeNode<Type> * getRoot() const
    {
      return root;
    }

    //Returns size of tree
    int getSize() const
    {
      return mySize;
    }

    //Returns the height of the tree
    int getHeight()
    {
      return root->height;
    }

    //Returns height of a particular node
    int getHeight(treeNode<Type> & node) const
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
    int countChildren(treeNode<Type> & node)
    {
      int children = 0;
      if(node->leftChild)
      {
        //Left child exists. Count up.
        children += 1;
      }
      if(node->rightChild)
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
        //Root contains desired value
        return root;
      }

      treeNode<Type> * currentNode = root;
      treeNode<Type> * currentParent = root;

      while(currentNode->value != data)
      {
        if(countChildren(currentNode) != 0)
        {
          currentParent = currentNode; //Update parent to current before descent
          if(currentNode->value > data)
          {
            //Data is smaller than currentNode. Descend left.
            currentNode = currentNode->leftChild;
          }
          else if(currentNode->value < data)
          {
            //Data is larger than currentNode. Descend right.
            currentNode = currentNode->rightChild;
          }
        }

        else
        {
          //Data not in tree
          throw runtime_error("Data you are looking for was not found!");
          return NULL;
        }
      }

      //Data found in currentNode
      return currentNode;
    }

    ~linkedTree()
    {
      //Needs to delete all nodes
    }

};

#endif
