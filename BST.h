#include "NodeInterface.h"
#include "Node.h"
#include "BSTInterface.h"

using namespace std;

class BST :
	public BSTInterface
{
public:
		Node * root;
	BST() {
		root = NULL;
	}
	~BST() {clear();}


	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * getRootNode() const;

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data);
	bool add_function(Node*& n, int value);
	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data);
	bool remove_function(Node*& n, int value);
	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();
	void clear_function(Node* n);
};
