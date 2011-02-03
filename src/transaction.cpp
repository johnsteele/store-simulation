/**
 * @file transaction.cpp 
 * 
 * @brief  A class to represent a Transaction. A transaction has a 
 * 	   type. Depending on the type of the transaction it might 
 * 	   also have a customer ID, and an associated Item.
 *
 * @brief CSS 343 - Lab 4
 *
 * @author John Steele  \<steelejr@u.washington.edu\> 
 *  
 * @version 1.0.0
 * @date November 9, 2010
 */ 
//--------------------------------------------------------------------
/**
 * Includes following features:
 *	- Allows printing a Transaction.
 *	- Allows getting the Transaction type. 
 * 	- Allows getting the Item associated with the Transaction.
 * Assumptions:
 * 	- The Item returned from getItem is not modified. 
 */
//--------------------------------------------------------------------

#include "transaction.h"


//---------------------Constructor------------------------------------
/**
 * @brief Creates a default Transaction object with my_type set to 
 *	  zero, my_customer_id set to NULL, an my_item set to NULL.
 * 
 * Preconditions: None.	
 *
 * Postconditions: my_type is zero, my_customer_id is NULL, and 
 *		   my_item is NULL.
 */
Transaction::Transaction ()
{
	cout << "Transaction::Transaction()" << endl;
}

//---------------------Constructor------------------------------------
/**
 * @brief Creates a Transaction object with the specified values.
 * 
 * Preconditions: cust_id contains a terminating character at the end 
 *		  of the string. item points to an Item object that 
 *		  this class will take ownership of.
 *
 * Postconditions: my_type, my_customer_id, and my_item have been 
 *		   assigned the appropriate values.
 *
 * @param type The type of transaction.
 * @param cust_id The customer ID.
 * @param item The Item associated with this transaction.
 */
Transaction::Transaction (char type, int cust_id, const Item *item) 
{
	cout << "Transaction::Transaction(...)" << endl;
}


//---------------------Copy-Constructor-------------------------------
/**
 * @brief Copies the other transaction into this.
 * 
 * Preconditions: The other transaction is not NULL.
 *
 * Postconditions: The other transction was copied into this.
 *
 * @param other The other Transaction to copy.
 */
Transaction::Transaction (const Transaction &other)
{
	cout << "Transaction::Transaction(T &other)" << endl;
}


//---------------------destructor-------------------------------------
/**
 * @brief Deletes all dyncamic memory obtained by this Transaction.
 * 
 * Preconditions: my_item points to dynamically allocated memory or 
 *		  NULL.	
 *
 * Postconditions: my_item and my_customer_id have been deleted, and 
 *		   set to NULL. 
 */
Transaction::~Transaction ()
{
	cout << "Transaction::~Transaction()" << endl;
}


//---------------------print------------------------------------------
/**
 * @brief Prints this transaction's type, customer ID, and the Item to
 *  	  the standard output stream.	 
 *
 * Preconditions: The my_customer_id string contains a terminating 
 *		  character at the end. Item object must also contain
 *		  a print method for which will be used to print 
 *		  my_item.
 *
 * Postconditions: This transaction's type, customer ID, and Item have 
 *		   been printed to the output stream.
 */
void Transaction::print () const
{
	cout << "Transaction::print()" << endl;
}


//---------------------getType----------------------------------------
/**
 * @brief Retuns the transaction type.	
 *
 * Preconditions: my_type is set to the transaction type.
 *
 * Postconditions: my_type is returned.
 *
 * @return The Transaction type is returned.	
 */
char Transaction::getType () const
{
	cout << "Transaction::getType()" << endl;
}


//---------------------getItem----------------------------------------
/**
 * @brief Returns a pointer to Item associated with this Transaction. 
 *	  The caller of this fuction takes ownership of the object. 
 *
 * Preconditions: my_item points to an Item or NULL.
 *
 * Postconditions: A pointer to the Item my_item pointed to was 
 *		   returned, and my_item was set to NULL. 
 *
 * @return A pointer to the Item associated with this Transaction.
 */
const Item * Transaction::getItem () const
{
	cout << "Transaction::getItem()" << endl;
}

