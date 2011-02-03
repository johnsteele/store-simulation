/**
 * @file inventory_transaction.cpp
 * 
 * @brief  A class to represent a InventoryTransaction. 
 *
 * @brief CSS 343 - Lab 4
 *
 * @author John Steele  \<steelejr@u.washington.edu\> 
 *  
 * @version 1.0.0
 * @date December 3, 2010
 */ 
//--------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows creating a  Transaction using a specified file.  
 * Assumptions:
 *	- The file stream passed to createNewInstance is open and 
 *	  constains correct format according to Lab 4 specifications.  
 */
//--------------------------------------------------------------------

#include "inventory_transaction.h"
#include "store_manager.h"

//---------------------Default-Constructor----------------------------
/**
 * @brief Creates an InventoryTransaction with default type. 
 * 
 * Preconditions: None. 
 * 
 * Postconditions: This transaction was instantiated with a default
 *	 	   type.  
 */
InventoryTransaction::InventoryTransaction () : Transaction () {}


//---------------------Constructor------------------------------------
/**
 * @brief Creates an InventoryTransaction with the specified type.  
 * 
 * Preconditions: None. 
 * 
 * Postconditions: This transaction was instantiated with the
 *		   specified type.
 * 
 * @param type The type of transaction. 
 */
InventoryTransaction::InventoryTransaction (char type) 
	: Transaction (type) {}

	
//---------------------Destructor-------------------------------------
/**
 * @brief Destructor
 * 
 * Preconditions: None. 
 * 
 * Postconditions: Resources obtained by this transaction were
 *	 	   released. 
 */
InventoryTransaction::~InventoryTransaction () {}


//---------------------getNewInstance---------------------------------
/**
 * @brief Retuns a pointer to a new instance of a Inventory 
 *	  Transaction. The data of the new object will be set using 
 *	  the provided file stream.
 *	
 * Preconditions: The file stream is open and correctly formatted 
 *		  according to Lab 4 specs.  	
 *
 * Postconditions: A new object was created using the provided file 
 *		   to set its data. A pointer to the object was then
 *		   returned.
 *
 * @param input The input stream to extract from.
 * @return A pointer to a new instance.
 */
InventoryTransaction * InventoryTransaction::getNewInstance 
				(ifstream &input) const 
{
	char type;
	input >> type;
	input.ignore (INT_MAX, '\n');
	return new InventoryTransaction (type);
}


//---------------------clone------------------------------------------
/**
 * @brief Clones this Transaction.
 * 
 * Preconditions: None.
 * 
 * Postconditions: A pointer to a cloned Object is returned.
 * 
 * @return The pointer to the cloned Transaction.
 */
InventoryTransaction * InventoryTransaction::clone () const
{
	return new InventoryTransaction (getType());
}
	

//---------------------execute----------------------------------------
/**
 * @brief Calls the appropriate method on the store manager.
 * 
 * Preconditions: The storemanager is not NULL.
 *
 * Postconditions: The storemanager's method has been called.
 *
 * @param mgr The store manager.
 */
void InventoryTransaction::execute (StoreManager *mgr) const
{
	mgr->printInventory ();
}

