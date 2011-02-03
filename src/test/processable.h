/**
 * @file processable.h 
 * 
 * @brief  A class to represent a Processable Transaction. 
 *	   A processable transaction is one that will need an 
 *	   inventory Item (e.g., purchase, trade, etc.)
 *
 * @brief CSS 343 - Lab 4
 *
 * @author John Steele  \<steelejr@u.washington.edu\> 
 *  
 * @version 1.0.0
 * @date December 9, 2010
 */ 
//--------------------------------------------------------------------
/**
 * Includes following features:
 *	- Allows printing a  Processable.
 *	- Allows getting the Item associated with this transaction. 
 *	- Allows getting the customer's ID associated with this
 *	  transaction. 
 * Assumptions:
 *	- The file stream passed to createNewInstance is open and 
 *	  constains correct format according to Lab 4 specifications.  
 */
//--------------------------------------------------------------------

#ifndef PROCESSABLE_H
#define PROCESSABLE_H

#include "transaction.h"
#include "item.h"

/**
 * @class Processable
 */
class Processable : public Transaction {

/**
 * @public
 */
public:

	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a Processable object with default values.
	 * 
	 * Preconditions: None.
	 * 
	 * Postconditions: my_item and my_id were set to their default
 	 *		   values. 
	 */
	Processable ();

		
	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a Processable object with the specified
	 * 	  values. 
	 * 
	 * Preconditions: None.
	 * 
	 * Postconditions: The members were set respectively. 
	 * 
	 * @param cust_id The customer ID.
	 * @param type The type of transaction. 
	 * @param item The Item associated with this transaction. 
	 */
	Processable (int cust_id, char type, Item *item);

	
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
	virtual ~Processable();


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
	 * 
	 * @param output The output stream. 
	 */
	virtual void print (ostream &output) const;


	//---------------------getNewInstance-------------------------
	/**
	 * @brief Retuns a pointer to a new Processable. 
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
	virtual Processable * getNewInstance (ifstream &input) const = 0;


	//---------------------clone----------------------------------
	/**
	 * @brief Clones this Processable.
	 * 
	 * Preconditions: None.
	 * 
	 * Postconditions: A pointer to a cloned Object is returned.
	 * 
	 * @return The pointer to the cloned Transaction.
	 */
	virtual Processable * clone () const = 0;


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
	virtual void execute (StoreManager *mgr) const = 0;

		
	//---------------------setItem--------------------------------
	/**
	 * @brief Sets the item.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: my_item was set to the item.
	 * 
	 * @param item The Item.
	 */
	void setItem (Item *item);

/**
 * @private 
 */
private:

	/**
	 * @brief The item associated with this transaction. 
	 */
	Item *my_item;

	/**
	 * @brief The customer ID associated with this transaction.
	 */
	int my_id; 

	item *tem = new Item;
	item *tem = new item;
};
#endif /* PROCESSABL_H */

