#ifndef AVLTREE_H
#define AVLTREE_H
#include <stdexcept>

template <class Type>
class avlTree
{
private:
    int mySize; //For easy access to size of the tree
    treeNode<Type> * root; //Pointer to the root of the tree
public:
    avlTree() : mySize(0) , root(NULL){};

    //Returns the root node
    treeNode<Type> * getRoot()
    {
        if(empty())
        {
            throw runtime_error("Tree is empty!");
        }
        return root;
    }

    //Returns the size of the tree
    int getSize()
    {
        if(empty())
        {
            throw runtime_error("Tree is empty!");
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
        return getHeight(root);
    }

    //Returns height of a particular node
    int getHeight(treeNode<Type> * node)
    {
        if(empty())
        {
            throw runtime_error("Tree is empty!");
        }
        if(node==NULL)
        {
            return -1;
        }
        return max(getHeight(node->leftChild),getHeight(node->rightChild))+1;
    }

    //Returns true if the tree is empty
    bool empty()
    {
        return root == NULL;
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

    treeNode<Type> * find(Type data)
    {
        if(empty())
        {
            throw runtime_error("Tree is empty!");
        }

        if(root->value == data)
        {
            //Root contains desired value
            return root;
        }

        treeNode<Type> * currentNode = root;

        //While data hasn't been found. Check for children and move down
        while(currentNode->value != data)
        {
            if(countChildren(currentNode) != 0)
            {
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
                throw runtime_error("Data you were looking for was not found!");
                return NULL;
            }
        }

        //Data found in currentNode
        return currentNode;
    }

    //Traverses tree in Preorder. Parent -> Left -> Right
    void preorder()
    {
        if(empty())
        {
            throw runtime_error("Tree is empty!");
        }
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
        if(empty())
        {
            throw runtime_error("Tree is empty!");
        }
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
        if(empty())
        {
            throw runtime_error("Tree is empty!");
        }
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
/****************************************      MUTATORS    ********************/
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
        if(root==NULL)
        {

        }
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
    void insert(Type  data)
    {
        if(root == NULL)
        {
            treeNode<Type> * node = new treeNode<Type>(data);                    //create new node (will be our root)
            root = node;
            mySize++;                                                         //count + 1 for total number of elements
            return;
        }
        else {
            insertNode(root, data);                                          //else call recursive helper function to add node
            balance(root);
        }
    }

    //INSERT NODE HELPER FUNCTION FOR RECURSIVE
    treeNode<Type> * insertNode(treeNode<Type> * node, Type data)
    {
        if(node == NULL)                                                     //empty spot so we create new node and return it
        {
            treeNode<Type> * node = new treeNode<Type>(data);
            mySize++;
            return node;
        }
        if(data < node->value)                                                //left child
        {
            node->leftChild = insertNode(node->leftChild,data);                         //node->left is new node returned
            node->leftChild->parent = node;
        }
        else if(data > node->value)                                           //right child  >= incase there is duplicate
        {
            node->rightChild = insertNode(node->rightChild,data);                       //node->right is new node returned
            node->rightChild->parent = node;
        }
        return node;
    }

    void balance(treeNode<Type> * node) // FOUR CASES (RIGHT - LEFT) FOR HEIGHT DIFFERENCE
    {
        int tempRight=0, tempLeft=0 , left_factor=0, right_factor=0 , second_factor=0;                    //Holds values of right and left child
        if(empty())//if empty
        {
            return;
        }
        tempRight = getHeight(node->rightChild);        //get height of right
        tempLeft = getHeight(node->leftChild);          //get height of left

        node->balanceFactor = tempLeft - tempRight;     //set the balance factor of the node

        treeNode<Type> * L_temp = node->leftChild;
        treeNode<Type> * R_temp = node->rightChild;
        //NEED TO CHECK TO SEE IF NEEDS TO BE BALANCED
        if(node->balanceFactor > 1)                     //LEFT SIDE 2 POSSIBLE CASES
        {
            //NEED TO GET OUR CHILD BALANCE FACTORS TO SEE WHICH SUB CASE ALSO
            left_factor = getHeight(L_temp->leftChild);
            right_factor = getHeight(L_temp->rightChild);
            second_factor = left_factor - right_factor;
            if(second_factor > 0)                            //if height of left child greater than 0 (its left side)
            {
                left_of_left(node);
            }
            else
            {
                left_of_right(node);
            }
        }
        else if (node->balanceFactor < -1)
        {
            //NEED TO GET OUR CHILD BALANCE FACTORS TO SEE WHICH SUB CASE ALSO
            left_factor = getHeight(R_temp->leftChild);
            right_factor = getHeight(R_temp->rightChild);
            second_factor = left_factor - right_factor;
            if(second_factor > 0)
            {
                right_of_left(node);
            }
            else
            {
                right_of_right(node);
            }
        }
    }
    //OUTSIDE ROTATIONS
    //left subtree of left child case root (3,1) = 2 and child (2,1) = 1
    void left_of_left(treeNode<Type> * node)
    {
        treeNode<Type> * temp;
        temp = node->leftChild;
        node->leftChild = temp->rightChild;
        if(temp->rightChild != NULL)
        {
            temp->rightChild->parent = node;//update parent
        }
        temp->rightChild = node;
        node->parent = temp; //update parent
        root=temp;
        root->parent = NULL; //update parent
    }
    //right of right subtree case root (1,3) = -2 and child (1,2) = -1
    void right_of_right(treeNode<Type> * node)
    {
        treeNode<Type> * temp;
        temp = node->rightChild;
        node->rightChild = temp->leftChild;
        if(temp->leftChild != NULL)
        {
            temp->leftChild->parent = node; //update parent
        }
        temp->leftChild = node;
        node->parent = temp; //update parent
        root = temp;
        root->parent = NULL; //update parent
    }
    //INSIDE ROTATIONS
    //left of right  root (3,1) = 2 and child (1,2) = -1
    void left_of_right(treeNode<Type> * node)
    {
        treeNode<Type> * temp1;
        treeNode<Type> * temp2;
        temp1 = node->leftChild;
        temp2 = temp1->rightChild;
        temp1->rightChild = temp2->leftChild;
        if(temp2->leftChild != NULL)
        {
            temp2->leftChild->parent = temp1; //update parent
        }
        temp2->leftChild = temp1;
        temp1->parent = temp2; //update parent
        node->leftChild = temp2;
        temp2->parent = node; //update parent
        //SECOND ROTATE
        temp1 = node->leftChild;
        node->leftChild = temp1->rightChild;
        if(temp1->rightChild != NULL)
        {
            temp1->rightChild->parent = node;//update parent
        }
        temp1->rightChild = node;
        node->parent=temp1;//update parent
        root = temp1;
        root->parent = NULL; //update parent
    }
    //right of left root (1,3) = -2  and child (2,1) = 1
    void right_of_left(treeNode<Type> * node)
    {
        treeNode<Type> * temp1;
        treeNode<Type> * temp2;
        temp1 = node->rightChild;
        temp2 = temp1->leftChild;
        temp1->leftChild = temp2->rightChild;
        if(temp1->leftChild != NULL)
        {
            temp2->rightChild->parent = temp1;//update parent
        }
        temp2->rightChild = temp1;
        temp1->parent = temp2;//update parent
        node->rightChild = temp2;
        temp2->parent = node;//update parent
        //SECOND ROTATE
        temp1 = node->rightChild;
        node->rightChild = temp1->leftChild;
        if(temp1->leftChild != NULL)
        {
            temp1->leftChild->parent = node;//update parent
        }
        temp1->leftChild = node;
        node->parent = temp1;//update parent
        root = temp1;
        root->parent = NULL; //update parent
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
      currentNode = find(data);
      currentParent = currentNode->parent;

      treeNode<Type> * successorNode = currentNode->rightChild;
      treeNode<Type> * successorParent = currentNode;
      if(countChildren(currentNode) == 2) //Node to delete has 2 children.
      {
        //Find successor, the smallest of the rightChild

        while(successorNode->leftChild)
        {
          //Find smallest of larger values
          successorParent = successorNode;
          successorNode = successorNode->leftChild;
        }

        currentNode->value = successorNode->value; //Copy successor value over to current
        currentNode = successorNode; //Copy pointer address
        currentParent = successorParent;
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
        if(subtree != NULL)
        {
          subtree->parent = currentParent;
        }
      }
      else
      {
        //If saved parent right child is being deleted, point right child to new subtree
        currentParent->rightChild = subtree;

        if(subtree != NULL)
        {
          subtree->parent = currentParent;
        }

      }

      while(subtree != NULL)
      {
        subtree->updateHeight();
        subtree = subtree->parent;
      }

      delete currentNode;
      balance(root);
      mySize--;
    }

    //Destructor. Deletes all pointers within tree
    ~avlTree()
    {
      if(mySize!=0)
        {
          clear();
        }
        delete[] root;
    }
//============================================================================//
//                    AUXILARY FUNCTIONS BELOW                                //
//============================================================================//

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

    //Auxilary function that tells us how many children a node has
    int countChildren(treeNode<Type> * node)
    {
        if(node==NULL)
        {
            return 0;
        }
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
};

#endif
