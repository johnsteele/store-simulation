/**
 * @file purchase_transaction.h 
 * 
 * @brief  A class to represent a PurchaseTransaction. A Purchase
 *	   Transaction has the customer's ID associated with this
 *	   transaction. A Purchase Transaction also has-a Item that 
 *	   is being purchased.  
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
 *	- Allows printing a  PurchaseTransaction.
 * 	- Allows creating a  PurchaseTransaction using a specified 
 *	  file.  
 *	- Allows getting the Item associated with this transaction. 
 *	- Allows getting the customer's ID associated with this
 *	  transaction. 
 * Assumptions:
 *	- The file stream passed to createNewInstance is open and 
 *	  constains correct format according to Lab 4 specifications.  
 */
//--------------------------------------------------------------------

#ifndef PURCHASE_TRANSACTION_H
#define PURCHASE_TRANSACTION_H

#include "transaction.h"
#include "item.h"

/**
 * @class PurchaseTransaction
 */
class PurchaseTransaction : public Transaction {

/**
 * @public 
 */
public:
	
	//--------------------Default-Constructor---------------------
	/**
	 * @brief Creates a PurchaseTransaction with default values. 
	 * 
	 * Preconditions: None. 
	 * 
	 * Postconditions: This transaction was instantiated with 
	 *		   default customer Id and type. 
	 */
	PurchaseTransaction ();	


	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a PurchaseTransaction with the specified
	 *	  customer ID and type.
	 * 
	 * Preconditions: None. 
	 * 
	 * Postconditions: This customer's ID and type of transaction
	 *		   have been set to the provided params.  
	 * 
	 * @param cust_id The customer's ID. 
	 * @param item The item assocaited with the transaction.
	 * @param type The type of transaction.
	 */
	PurchaseTransaction (int cust_id, Item *item, char type);

	
	//---------------------Destructor-----------------------------
	/**
	 * @brief Deallocates the item associated with this 
	 *	  transaction. 
	 * 
	 * Preconditions: my_item is NULL or points to a dynamic 
	 * 		  Item object.
 	 *
	 * Postconditions: my_item was deleted. 
	 */
	virtual ~PurchaseTransaction ();


	//---------------------getItem--------------------------------
	/**
	 * @brief Returns a pointer to the Item associated with this
	 *	  transaction. The caller of this function does NOT
 	 *	  take ownership of the object. 
	 *
 	 * Preconditions: my_item points to an Item or NULL.
	 *
	 * Postconditions: A pointer to my_item was returned. 
	 *
	 * @return A pointer to the Item associated with this
	 *	   Transaction.
	 */
	const Item * getItem () const;


	//---------------------print----------------------------------
	/**
	 * @brief Prints this transaction.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: my_item was printed to the standard output 
 	 *		   stream.  
	 */
	virtual void print () const;


	//---------------------getNewInstance-------------------------
	/**
	 * @brief Retuns a pointer to a new PurchaseTransaction. 
 	 *	  The data of the new object will be set using the 
 	 *	  provided file stream.
	 *	
 	 * Preconditions: The file stream is open and correctly 
	 *		  formatted according to Lab 4 specs.  	
	 *
	 * Postconditions: A new object was created using the provided
	 *		   file to set its data. A pointer to the 
	 *		   object was then returned.
	 *
	 * @param input The input stream to extract from.
	 * @return A pointer to the new instance.
	 */
	virtual PurchaseTransaction * getNewInstance 
					(ifstream &input) const = 0;


	//---------------------getCustomerId--------------------------
	/**
	 * @brief Returns the customer's ID associated with this 
	 *	  transaction. 
	 * 
	 * Preconditions: None. 
	 * 
	 * Postconditions: The customer ID was returned. 
	 *
	 * @return The customer ID.
	 */
	int getCustomerId () const;

/**
 * @private
 */
private:

	/**
 	 * @brief The Item being purchased. 
	 */
	Item *my_item;

	/**
	 * @brief The customer's ID associated with this transaction. 
	 */
	int my_cust_id;	
};
#endif /* PURCHASE_TRANSACTION_H */

