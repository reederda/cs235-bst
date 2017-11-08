#include "NodeInterface.h"
#include "Node.h"
#include "BST.h"
//segfaulting at remove 2 true in file 4
using namespace std;

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * BST::getRootNode() const
  {
    return root;
  }

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool BST::add(int data)
  {
/*    Node * currentNode;
    currentNode = NULL;
    currentNode = root;*/
    add_function(root, data);
  }

	bool BST::add_function(Node*& n, int value)
  {
    if (n == NULL)
    {
      n = new Node(value);
      return true;
    }

    if (n->data > value)
    {
      return add_function(n->leftChild, value);
    }

    if (n->data < value)
    {
      return add_function(n->rightChild, value);
    }
    return false;
  }
	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool BST::remove(int data)
  {
    remove_function(root, data);
  }
  bool BST::remove_function(Node*& n, int value)
  {
    if (n == NULL)
    {
      return false;
    }
    if (n->data > value)
    {
      return remove_function(n->leftChild, value);
    }
    if (n->data < value)
    {
      return remove_function(n->rightChild, value);
    }
    if (n->rightChild == NULL && n->leftChild == NULL) //No next of kin
    {
      delete n;
      n = NULL;
      return true;
    }

    if (n->rightChild == NULL || n->leftChild == NULL) //one child
    {
      Node* temp;
      temp = n->leftChild;
      if (n->leftChild == NULL)
      {
        temp = n->rightChild;
      }
      delete n;
      n = temp;
      return true;
    }
    Node* temp = n->leftChild;
    Node* parent = NULL;

    while (temp->rightChild != NULL) //two children. Problem children. Twins, with too much energy.
    {
      parent = temp;
      temp = temp->rightChild;
    }
    parent->rightChild = temp->leftChild;
    temp->leftChild = n->leftChild;
    temp->rightChild = n->rightChild;
    delete n;
    n = temp;

    return true;
  }

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void BST::clear()
  {
    clear_function(root);
    root = NULL;
  }
  void BST::clear_function(Node* n)
  {
    if (n == NULL)
    {
      return;
    }
    if (n->leftChild != NULL)
    {
        clear_function(n->leftChild);
    }
    if (n->rightChild != NULL)
    {
      clear_function(n->rightChild);
    }

    delete n;
    return;
  }
