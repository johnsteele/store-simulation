/**
 * @file purchase_transaction.cpp
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

#include "purchase_transaction.h"
#include "store_manager.h"

//--------------------Default-Constructor-----------------------------
/**
 * @brief Creates a PurchaseTransaction with default values. 
 * 
 * Preconditions: None. 
 * 
 * Postconditions: This transaction was instantiated with default
 *		   customer Id and type. 
 */
PurchaseTransaction::PurchaseTransaction () : Processable () {}


//---------------------Constructor------------------------------------
/**
 * @brief Creates a PurchaseTransaction with the specified customer
 *	  ID and type.
 * 
 * Preconditions: None. 
 * 
 * Postconditions: This customer's ID and type of transaction have 
 *		   been set to the provided params.  
 * 
 * @param cust_id The customer's ID. 
 * @param item The item assocaited with the transaction.
 * @param type The type of transaction.
 */
PurchaseTransaction::PurchaseTransaction (int cust_id,
	 char type, Item *item) : Processable (cust_id, type, item) {}


//---------------------Destructor-------------------------------------
/**
 * @brief Deallocates the item associated with this transaction. 
 * 
 * Preconditions: my_item is NULL or points to a dynamic Item object.
 *
 * Postconditions: my_item was deleted. 
 */
PurchaseTransaction::~PurchaseTransaction () {} 


//---------------------print------------------------------------------
/**
 * @brief Prints this information. 
 *
 * Preconditions: None.
 *
 * Postconditions: This transaction was printed to the standard output
 *		   stream.  
 * 
 * @param output The output stream. 
 */
void PurchaseTransaction::print (ostream &output) const
{

	output << "Purchase - ";
	Processable::print (output);
}


//---------------------getNewInstance---------------------------------
/**
 * @brief Retuns a pointer to a new PurchaseTransaction. The data of
 *	  the new object will be set using the provided file stream.
 *	
 * Preconditions: The file stream is open and correctly formatted
 *		  according to Lab 4 specs.  	
 *
 * Postconditions: A new object was created using the provided file to
 *		   set its data. A pointer to the object was then 
 *		   returned.
 *
 * @param input The input stream to extract from.
 * @return A pointer to the new instance.
 */
PurchaseTransaction * PurchaseTransaction::getNewInstance 
				(ifstream &input) const
{
	char type;
	int id;
	string temp;
	input >> type; input.ignore ();
	input >> id;  input.ignore (); input.ignore (); 
	return new PurchaseTransaction (id, type, NULL);	
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
PurchaseTransaction * PurchaseTransaction::clone () const
{
	if (getItem()) {
	
	return new PurchaseTransaction (getCustomerId(), 
					getType(), 
					getItem()->clone());	
	}
	
	return new PurchaseTransaction (getCustomerId(),
					getType(),
					NULL);
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
void PurchaseTransaction::execute (StoreManager *mgr) const
{
	mgr->purchase ();	
}

