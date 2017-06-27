#ifndef AVLTREE_H
#define AVLTREE_H
#include<stdexcept>


template <class Type>
class avlTree
{
  private:
    int mySize; //For easy access to size of the tree
    treeNode<Type> * root; //Pointer to the root of the tree
  public:
    avlTree() : mySize(0) , root(NULL){};
    treeNode<Type> * getRoot()
    {
        //RETURNS THE ROOT OF THE TREE
    }
    int getSize()
    {
        //RETURNS THE NUMBER OF ELEMENTS IN THE TREE
    }
    //Returns the height of the tree
    int getHeight()
    {
        return root->height;
    }

    //Returns height of a particular node
    int getHeight(treeNode<Type> * node)
    {
        return node->height;
    }
    bool empty()
    {
        return root==NULL;
    }
    int leaves()
    {
        //RETURNS NUMBER OF LEAVES
    }
    int siblings(treeNode<Type> * node)
    {
        //RETURNS NUMBER OF SIBLINGS OF THE NODE IN THE ARGUMENT
    }
//    treeNode<Type> * find(Type & data)
//    {
//        //RETURNS A POINTER TO A NODE THAT HOLDS THE DATA IN THE ARGUMENT
//    }
    treeNode<Type> * find(Type data)
    {
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
    /****************************************      MUTATORS    ********************************************************/
    void clear()
    {
        //REMOVES ALL ELEMENTS IN THE TREE
    }
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
    void singleRight(treeNode<Type> * node)
    {
        treeNode<Type> * temp;
        temp = node->leftChild;
        node->left = temp->right;
        temp->right = node;
    }
    void singleLeft(treeNode<Type> * node)
    {
        treeNode<Type> * temp;
        temp = node->rightChild;
        node->right = temp->left;
        temp->left = node;
    }
    void del(Type & data)
    {
        //REMOVES DATA AND MUST BE KEPT BALANCED
    }

};

#endif
