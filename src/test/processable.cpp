/**
 * @file processable.cpp 
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
#include "processable.h"
//---------------------Constructor------------------------------------
/**
 * @brief Creates a Processable object with default values.
 * 
 * Preconditions: None.
 * 
 * Postconditions: my_item and my_id were set to their default
 */
Processable::Processable () : Transaction () 
{
	my_item = NULL;
	my_id = 0;
}

	
//---------------------Constructor------------------------------------
/**
 * @brief Creates a Processable object with the specified values. 
 * 
 * Preconditions: None.
 * 
 * Postconditions: The members were set respectively. 
 * 
 * @param cust_id The customer ID.
 * @param type The type of transaction. 
 * @param item The Item associated with this transaction. 
 */
Processable::Processable (int cust_id, char type, Item *item)
				: Transaction (type)
{
	my_item = item;
	my_id = cust_id;
}


//---------------------Destructor-------------------------------------
/**
 * @brief Deallocates the item associated with this transaction. 
 * 
 * Preconditions: my_item is NULL or points to a dynamic Item object.
 *
 * Postconditions: my_item was deleted. 
 */
Processable::~Processable()
{
	if (my_item) delete my_item;
	my_item = NULL;
}


//---------------------getItem----------------------------------------
/**
 * @brief Returns a pointer to the Item associated with this
 *	  transaction. The caller of this function does NOT take
 *	  ownership of the object. 
 *
 * Preconditions: my_item points to an Item or NULL.
 *
 * Postconditions: A pointer to my_item was returned. 
 *
 * @return A pointer to the Item associated with this Transaction.
 */
const Item * Processable::getItem () const
{
	return my_item;
}


//---------------------print------------------------------------------
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
void Processable::print (ostream &output) const
{
	if (my_item) output << *my_item;
}


//---------------------getCustomerId----------------------------------
/**
 * @brief Returns the customer's ID associated with this transaction. 
 * 
 * Preconditions: None. 
 * 
 * Postconditions: The customer ID was returned. 
 *
 * @return The customer ID.
 */
int Processable::getCustomerId () const
{
	return my_id;
}


//---------------------setItem----------------------------------------
/**
 * @brief Sets the item.
 *
 * Preconditions: None.
 *
 * Postconditions: my_item was set to the item.
 * 
 * @param item The Item.
 */
void Processable::setItem (Item *item)
{
	my_item = item;
}

