/**
 * @file inventory_transaction.h 
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
 *	- Allows cloning an InventoryTransaction.
 * Assumptions:
 *	- The file stream passed to createNewInstance is open and 
 *	  constains correct format according to Lab 4 specifications.  
 */
//--------------------------------------------------------------------
#ifndef INVENTORY_TRANSACTION_H
#define INVENTORY_TRANSACTION_H

#include "transaction.h"

/**
 * @class InventoryTransaction
 */
class InventoryTransaction : public Transaction {

/**
 * @public
 */
public:
	
	//---------------------Default-Constructor--------------------
	/**
	 * @brief Creates an InventoryTransaction with default type. 
	 * 
	 * Preconditions: None. 
	 * 
	 * Postconditions: This transaction was instantiated with 
	 *		   a default type.  
	 */
	InventoryTransaction ();


	//---------------------Constructor----------------------------
	/**
	 * @brief Creates an InventoryTransaction with the specified
	 *	  type.  
	 * 
	 * Preconditions: None. 
	 * 
	 * Postconditions: This transaction was instantiated with the
	 *		   specified type.
	 * 
	 * @param type The type of transaction. 
	 */
	InventoryTransaction (char type);

		
	//---------------------Destructor-----------------------------
	/**
	 * @brief Destructor
	 * 
	 * Preconditions: None. 
	 * 
	 * Postconditions: Resources obtained by this transaction were
	 * 	  	   released. 
	 */
	virtual ~InventoryTransaction ();

	
	//---------------------getNewInstance-------------------------
	/**
	 * @brief Retuns a pointer to a new instance of a Inventory 
	 *	  Transaction. The data of the new object will be set
  	 *	  using the provided file stream.
	 *	
 	 * Preconditions: The file stream is open and correctly 
	 *		  formatted according to Lab 4 specs.  	
	 *
	 * Postconditions: A new object was created using the provided
 	 *		   file to set its data. A pointer to the 
	 *	 	   object was then returned.
	 *
	 * @param input The input stream to extract from.
	 * @return A pointer to a new instance.
	 */
	virtual InventoryTransaction * getNewInstance 
					(ifstream &input) const;


	//---------------------clone----------------------------------
	/**
	 * @brief Clones this Transaction.
	 * 
	 * Preconditions: None.
	 * 
 	 * Postconditions: A pointer to a cloned Object is returned.
	 * 
	 * @return The pointer to the cloned Transaction.
	 */
	virtual InventoryTransaction * clone () const; 

	
	//---------------------execute--------------------------------
	/**
	 * @brief Calls the appropriate method on the store manager.
	 * 
	 * Preconditions: The storemanager is not NULL.
	 *
	 * Postconditions: The storemanager's method has been called.
	 *
	 * @param mgr The store manager.
	 */
	virtual void execute (StoreManager *mgr) const;

};
#endif /* INVENTORY_TRANSACTION */

