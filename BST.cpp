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
		//cout << "Starting Add" << endl;
    add_function(root, data);
  }

	bool BST::add_function(Node*& n, int value)
  {
		//cout << "Starting Add_Function" << endl;
    if (n == NULL)
    {
		  n = new Node(value);
			if (value == 2)
			{
				cout << "Adding 2" << endl;
				cout << "n's left child" << n->leftChild << endl;
				cout << "n's right child" << n->rightChild << endl;
			}

      return true;
    }

		if (n->data == 2)
		{
			cout << "n leftchild" << n->leftChild << "n rightChild" << n->rightChild << endl;
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
		cout << "Starting remove" << endl;
    return remove_function(root, data);
  }
  bool BST::remove_function(Node*& n, int value)
  {
		//cout << "Starting remove_function" << endl;
    if (n == NULL)
    {
			cout << "N is NULL" << endl;
      return false;
    }
		if (n->data == 2)
		{
		cout << "n = " << n->data << endl;
		cout << "n left" << n->leftChild << endl;
		cout << "n right" << n->rightChild << endl;
	}
    if (n->data > value)
    {
			if (n->data == 2)
			cout << "n->data > value" << endl;
      return remove_function(n->leftChild, value);
    }
    if (n->data < value)
    {
			if (n->data == 2)
			cout << "n->data < value" << endl;
      return remove_function(n->rightChild, value);
    }
    if (n->rightChild == nullptr && n->leftChild == nullptr) //No next of kin
    {
			if (n->data == 2)
			cout << "No next of kin" << endl;
      delete n;
      n = NULL;
      return true;
    }

    if (n->rightChild == NULL || n->leftChild == NULL) //one child
    {
			if (n->data == 2)
			cout << "one child" << endl;
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
    Node* parent = n;
		if (n->data == 2)
		cout << "two children" << endl;
    while (temp->rightChild != NULL) //two children. Problem children. Twins, with too much energy.
    {
      parent = temp;
      temp = temp->rightChild;
    }
		if (n->data == 2)
		cout << "testing stuff Left " << temp->leftChild << endl;
		if (n->data == 2)
		cout << "testing stuff Right " << temp->rightChild << endl;
		if (n->data != parent->data)
		{
    parent->rightChild = temp->leftChild;
	}
	else parent->leftChild = temp->leftChild;
		cout << "Temp->Data" << temp->data << endl;
    //temp->leftChild = n->leftChild;
    //temp->rightChild = n->rightChild;
		n->data = temp->data;
    delete temp;
    //n = temp;
		if (n->data == 2)
		cout << "more stuff" << endl;
    return true;
  }

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void BST::clear()
  {
		cout << "Starting clear" << endl;
    clear_function(root);
    root = NULL;
  }
  void BST::clear_function(Node* n)
  {
		cout << "Starting clear_function" << endl;
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
