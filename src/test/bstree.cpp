/*
 * @file bstree.cpp 
 * 
 * @brief This class represents a node-base binary search tree
 *	  data-structure, which has the following properties: The
 *	  left subtree of a node contains only nodes with keys less
 *	  than the node's key; The right subtree of a node contains
 *	  only nodes with keys greater than the nodes' key; Both the
 *	  left and right subtree must also be binary search trees.
 *
 * @brief CSS 343 - Lab 4
 *
 * @author John Steele  \<steelejr@u.washington.edu\> 
 *  
 * @version 1.0.0
 * @date November 16, 2010
 */ 
//--------------------------------------------------------------------
/**
 * Includes following features:
 *	- Allows displaying the contents of a BSTree using <<.
 * 	- Allows inserting an object into the tree.
 *	- Allows retrieving a specified object from the tree.
 *	- Allows removing an object from the tree.
 *	- Allows making the tree empty.
 * Assumptions:
 * 	- Data objects are not NULL when stored in the tree.
 *	- Data objects have overloaded operator<< for displaying.
 *	- Data objects have overloaded comparison operators for 
 *	  sorting.
 */
//--------------------------------------------------------------------

#include "bstree.h"


//---------------------Constructor------------------------------------
/**
 * @brief Creates a BSTree with a NULL root.
 * 
 * Preconditions: None.
 *
 * Postconditions: The BSTree was instantiated with its root set to 
 *		   NULL.
 */
BSTree::BSTree () 
{
	my_root = NULL;
}


//---------------------Copy-Constructor-------------------------------
/**
 * @brief Copies the other tree into this tree.
 *
 * Preconditions: The other trees' root points to NULL if it is empty,
 *		  otherwise the root of the tree.
 * 	
 * Postconditions: The other tree was copied into this tree.
 */ 
BSTree::BSTree (const BSTree &the_other)	
{	
	my_root = NULL;
	*this = the_other;
}


//---------------------Destructor-------------------------------------
/**
 * @brief Deletes all dynamically allocated objects within the tree.
 *
 * Preconditions: makeEmpty is implemented.
 * 
 * Postconditions: This BSTree is empty with a NULL root.	
 */
BSTree::~BSTree() 
{
	makeEmpty();
}



//---------------------retrieve---------------------------------------
/**
 * @brief Searches the tree for the given target, if found a pointer 
 *	  to the object is returned, NULL otherwise.
 * 
 * Preconditions: None.
 * 	
 * Postconditions: A pointer to the object was returned if it was 
 *		   found, NULL otherwise.
 * 
 * @param target The item to search for.
 * @return Pointer to the object if found, NULL otherwise.
 */ 
const Object * BSTree::retrieve (const Object &the_item) const
{
	return retrieveHelper(my_root, the_item);
}	


//---------------------retrieveHelper---------------------------------
/**
 * @brief A helper method for recursively finding the provided item in
 *	  the tree. Returns NULL if the item is not found.
 *
 * Preconditions: item is not NULL, and my_root points to the root of
 *		  the tree, or NULL if the tree is empty.
 *
 * Postconditions: A pointer to the found item is returned, NULL is 
 *		   returned otherwise.
 *
 * @param root The root of the subtree.
 * @param item The item being retrieved.  
 * @return A pointer to the found item, NULL otherwise.
 */ 
const Object * BSTree::retrieveHelper (const Node *root, 
					const Object &the_item) const  
{
	if (root == NULL) return NULL;
	
	else if (the_item == *root->item)	
		return root->item;
	
	else if (the_item < *root->item)
		return retrieveHelper (root->left, the_item);
	
	else 
		return retrieveHelper (root->right, the_item);
}


//---------------------insert-----------------------------------------
/**
 * @brief Inserts an item into the tree.
 *
 * Preconditions: The item is not NULL, and there must be enough
 *		  memory for allocating the new Node.
 *
 * Postconditions: The item was inserted into the tree.
 *
 * @param item The item to insert into the tree.
 * @return True if successfully inserted, false otherwise.
 */
bool BSTree::insert (Object *the_item)
{
	return insertHelper (my_root, the_item);
}


//---------------------insertHelper-----------------------------------
/**
 * @brief A helper method for recursively inserting an item into the 
 *	  tree. If the imem already exists in the tree the occurance
 *	  will will incremented. 
 *
 * Preconditions: item is not NULL, and  my_root points to the root of
 *	  	  the tree, or NULL if the tree is emtpy.
 *
 * Postconditions: Retuns true if the item was inerted, false
 *		   otherwise.
 *
 * @param root The root of the subtree.
 * @param item The item being inserted.
 * @return True if the item was inserted, false otherwise.
 */
bool BSTree::insertHelper (Node *&the_root, Object *the_item)	
{
	if (the_root == NULL) {
		the_root        = new Node;
		// We're taking ownership of the Object.	
		the_root->item  = the_item;
		the_root->left  = NULL;
		the_root->right = NULL;
		the_root->occurences = 1;
		return true;
	}	

	else if (*the_root->item == *the_item) {
		// Ownership of Object goes back to client.
		the_root->occurences++;
		return true;	
	} 
	
	else if (*the_item < *the_root->item)  
		return insertHelper(the_root->left, the_item); 

	 else  
		return insertHelper(the_root->right, the_item);
}


//---------------------remove-----------------------------------------
/**
 * @brief Removes one occurance of the provided item from the tree. 
 *	  If it is the last occurance, the objet is removed. Calls a 
 *	  helper recursive method.
 *
 * Preconditions: item is a reference to a non NULL object.
 * 	
 * Postconditions: True was returned if the item was was found and 
 *		   removed, false otherwise.
 *
 * @param item The item to remove from the tree.
 * @return True if removed, false otherwise.
 */
bool BSTree::remove (const Object &the_item)
{
	return removeHelper (my_root, the_item);
}	


//---------------------removeHelper-----------------------------------
/**
 * @brief Removes an occurance of the provided item from the tree. 
 *	  If it is its last occurance the Object it is removed.
 * 
 * Preconditions: item is a reference to a non-NULL Object.
 *	
 * Postconditions: True was retuned if the item was found and removed,
 *		   false otherwise.
 * 
 * @param root The root of the subtree.
 * @param item The item to remove from the tree.
 * @return True if item was removed, false otherwise.
 */
bool BSTree::removeHelper (Node *&root, const Object &the_item)
{
	if (root == NULL) return false;

	else if (the_item == *root->item) {
		// More than one occurance, so decrment one.
		if (root->occurences > 0)  {
			root->occurences--;
			return true;
		}
//		if (root->occurences > 1) 
//			root->occurences--;
			
		// Otherwise, there's one occurance, so delete it.
		else { 
			return false;
		}
//			deleteRoot (root);

		// We decremented the occurance or deleted the node.	
		return true; 
	}

	else if (the_item < *root->item) 
		return removeHelper (root->left, the_item);
	else 
		return removeHelper (root->right, the_item);	
}	


//---------------------deleteRoot-------------------------------------
/**
 * @brief Deletes the node the provided pointer points to. If the left 
 *	  and right pointers of the node are not NULL we delete the 
 *	  item in the node and replace it with the most left node in 
 *	  its right subtree.
 *
 * Preconditions: root is not NULL.
 * 
 * Postconditions: The root has been deleted. 
 *
 * @param root The root to delete. 
 */
void BSTree::deleteRoot (Node *&root)
{
	// Only node in the tree, or a leaf, so delete it.
	if (root->left == NULL && root->right == NULL) {
		delete root->item;
		delete root;
		root = NULL;	
	}

	else if (root->left == NULL) {
		Node *temp = root;
		root = root->right;
		delete temp->item;
		delete temp; 
	}

	else if (root->right == NULL) {
		Node *temp = root;
		root = root->left;
		delete temp->item;
		delete temp;
	}

	// We have a subtree on both sides, delete the root's item.
	// Replace it with the most left item in the right subtree.
	else {
		delete root->item;
		//root->item = findAndDeleteMostLeft(root->right);
		root->item = findAndDeleteMostLeft(root->right, root);
	}
}


//---------------------findAndDeleteMostLeft--------------------------
/**
 * @brief Returns the Object item from the node that is located at the
 *	  most left subtree of the give root.
 *
 * Preconditions: root is not NULL.
 * 
 * Postconditions: A pointer to the Object item of the most left node
 *		   is returned. That node that previously stored item 
 *		   is then deleted. The occurance cound is also 
 *		   handled.
 *
 * @param root The root of the subtree.
 * @param m_root The root of the tree being replaced. 
 * @return A pointer to the furthest left node.
 */
Object * BSTree::findAndDeleteMostLeft (Node *&root, Node *m_root)
{
	// If we reached the furthest left node.
	if (root->left == NULL) {
		// Get the item to return.
		Object *result = root->item;
		// Copy over the count.
		m_root->occurences = root->occurences; 
		// Keep a hold on the node to delete.
		Node *temp     = root; 
		// Move the root pointer to the right child.
		root           = root->right;
		delete temp;
		return result;
	}

	else  // Keep going left until we're NULL.
		return findAndDeleteMostLeft (root->left, m_root);
}
	

//---------------------makeEmpty--------------------------------------
/**
 * @brief Empties this tree.
 * 	
 * Preconditions: my_root points to the root of the tree or NULL if  
 *		  the tree is empty.
 *
 * Postconditions: The tree is empty.
 */
void BSTree::makeEmpty ()	
{
	makeEmptyHelper (my_root);
}


//---------------------makeEmptyHelper--------------------------------
/**
 * @brief Recursively empties the provided subtree.
 * 
 * Preconditions: root points to the first node in the tree, or NULL 
 *		  if the tree is empty.
 * 
 * Postconditions: The provided tree is empty with a NULL root.
 * 
 * @param root The root of the subtree.
 */
void BSTree::makeEmptyHelper (Node *&root) 
{
	if (root != NULL) {
		makeEmptyHelper (root->left);
		makeEmptyHelper (root->right);
		delete root->item;
		root->item = NULL;
		delete root; 
	}	
	root = NULL;
}


//---------------------operator(=)------------------------------------
/**
 * @brief Overloaded assignment operator.	
 *
 * Preconditions: the_other.my_root points to the first Node in the
 *		  tree, or NULL.
 * 
 * Postconditions: the_other is copied into this.
 *
 * @param the_other The other tree to copy into this.
 * @return this is returned. 
 */
const BSTree& BSTree::operator=  (const BSTree &the_other)	
{
	// Check for self assignment.
	if (this != &the_other) {
		// Delete our current memory.
		makeEmpty();
		// Now copy the other's tree.
		clone (my_root, the_other.my_root);		
	}
	return *this;
}


//---------------------clone------------------------------------------
/**
 * @brief Clones the given originalTree into the subtree of copy 
 *		 recursively.
 *
 * Preconditions: originalTree is not NULL. Object has a copy 
 *		  constructor. 
 * 
 * Postconditions: copy contains its own copy of the original tree.
 *
 * @param copy The tree to copy into.
 * @param originalTree The tree to copy from.
 */ 
void BSTree::clone (Node *&copy, const Node *originalTree)
{
	if (originalTree == NULL) {
		copy = NULL; 
	} 
	
	else { 
		// Our new Node.
		copy = new Node; 
		// Link the data into our new Node.
		//copy->item       = new Object (*originalTree->item); 
		// Clone the object.
		copy->item = originalTree->item->clone();
		copy->occurences = originalTree->occurences;
		// Now clone left and right subtrees.	
		clone(copy->left,  originalTree->left);	
		clone(copy->right, originalTree->right); 
	}
}


//---------------------operator<<-------------------------------------
/**
 * @brief Overloaded operator <<.
 *
 * Preconditions: The root pointer of the tree must point to the root
 *		  of the tree or NULL.
 *
 * Postconditions: The elements of the bstree were sent to the std 
 *		   output stream. 
 *
 * @param output The output stream.
 * @param the_other The BSTree to output. 
 * @return The output stream. 
 */
ostream& operator<< (ostream &output, const BSTree &the_other) 
{
	the_other.printHelper(output, the_other.my_root);	
	return output;
}


//---------------------printHelper------------------------------------
/**
 * A helper method that recursively prints the given tree in order.
 * 
 * Preconditions: root is not NULL.
 *
 * Postconditions: The tree is sent to the output. 
 * 
 * @param output The output stream to to send the data.
 * @param root The root of the subtree.
 */
void BSTree::printHelper (ostream &output, const Node *root) const
{
	if (root != NULL) {
		printHelper (output, root->left);
		output << *root->item << endl;
		printHelper (output, root->right);
	}
}


//---------------------getOccurrence----------------------------------
/* @brief Returns the occurence of the item.
 * 
 * Preconditions: item is not NULL.
 * 
 * Postconditions: occurrnce was returned. 
 * 
 * @return occurence count of the item.
 */
int BSTree::getOccurrence (const Object &item) const
{
	return occurrenceHelper (item, my_root); 
}


//---------------------occurrenceHelper-------------------------------
/**
 * @brief Returns the Node of the provided object.
 * 
 * Preconditions: The object is not NULL.
 * 
 * Postconditions: The node or NULL was returned. 
 * 
 * @param item The item being searched for.
 * @param root The root of the subtree. 
 */
int BSTree::occurrenceHelper (const Object &item, const Node *root) const
{
	if (root == NULL) return 0;
	
	else if (item == *root->item)	
		return root->occurences;
	
	else if (item < *root->item)
		return occurrenceHelper (item, root->left);
	
	else 
		return occurrenceHelper (item, root->right);
}

