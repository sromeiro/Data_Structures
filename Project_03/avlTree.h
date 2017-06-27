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
          return 0;
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
/****************************************      MUTATORS    ********************/
    void clear()
    {
        //REMOVES ALL ELEMENTS IN THE TREE
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
        }
        else if(data >= node->value)                                           //right child  >= incase there is duplicate
        {
            node->rightChild = insertNode(node->rightChild,data);                       //node->right is new node returned
        }
        return node;
    }

    void balance(treeNode<Type> * node) // FOUR CASES (RIGHT - LEFT) FOR HEIGHT DIFFERENCE
    {
        int tempRight=0, tempLeft=0 , left_factor=0, right_factor=0 , second_factor=0;                    //Holds values of right and left child

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
        temp->rightChild = node;
        root=temp;
    }
    //right of right subtree case root (1,3) = -2 and child (1,2) = -1
    void right_of_right(treeNode<Type> * node)
    {
        treeNode<Type> * temp;
        temp = node->rightChild;
        node->rightChild = temp->leftChild;
        temp->leftChild = node;
        root = temp;
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
        temp2->leftChild = temp1;
        node->leftChild = temp2;
        //SECOND ROTATE
        temp1 = node->leftChild;
        node->leftChild = temp1->rightChild;
        temp1->rightChild = node;
        root = temp1;
    }
    //right of left root (1,3) = -2  and child (2,1) = 1
    void right_of_left(treeNode<Type> * node)
    {
        treeNode<Type> * temp1;
        treeNode<Type> * temp2;
        temp1 = node->rightChild;
        temp2 = temp1->leftChild;
        temp1->leftChild = temp2->rightChild;
        temp2->rightChild = temp1;
        node->rightChild = temp2;
        //SECOND ROTATE
        temp1 = node->rightChild;
        node->rightChild = temp1->leftChild;
        temp1->leftChild = node;
        root = temp1;
    }
    void del(Type & data)
    {
        //REMOVES DATA AND MUST BE KEPT BALANCED
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

    //Simple function to give information on requested node.
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
