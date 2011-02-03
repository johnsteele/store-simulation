/**
 * @file history_transaction.cpp 
 * 
 * @brief  A class to represent a HistoryTransaction. A 
 *	   HistoryTransaction has a customer ID who's history
 *   	   is to be printed.
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
 * 	- Allows creating a HistoryTransaction using a specified file.  
 *	- Allows getting the customer's ID associated with this 
 *	  transaction. 
 * 	- Allos cloning a HistoryTransaction.
 * Assumptions:
 *	- The file stream passed to createNewInstance is open and 
 *	  constains correct format according to Lab 4 specifications.  
 */
//--------------------------------------------------------------------

#include "history_transaction.h"
#include "store_manager.h"

//---------------------Default-Constructor----------------------------
/**
 * @brief Creates a HistoryTransaction object with default values.
 * 
 * Preconditions: None. 
 * 
 * Postconditions: this HistoryTransaction object has been 
 *	 	   instantiated with default type and ID.
 */
HistoryTransaction::HistoryTransaction () : Transaction ()
{ 
	my_cust_id = 0;
}


//---------------------Constructor------------------------------------
/**
 * @brief Creates a HistoryTransaction objec with the specified 
 *	  customer ID and type. 
 * 
 * Preconditions: None. 
 * 
 * Postconditions: this HistoryTransaction object has been 
 *		   instantiated using the specified customer ID and 
 *		   type. 
 * 
 * @param cust_id The customer ID. 
 * @param type The type of transaction. 
 */
HistoryTransaction::HistoryTransaction (int cust_id, char type)
 			 : Transaction(type)
{ 
	my_cust_id = cust_id;
}


//---------------------Destructor-------------------------------------
/**
 * @brief Deallocates resources obtained by this History Transaction.
 *
 * Preconditions: None. 
 * 
 * Postconditions: All resources have been released.
 */
HistoryTransaction::~HistoryTransaction () {}


//---------------------getNewInstance---------------------------------
/**
 * @brief Retuns a pointer to a new instance of a History Transaction.
 *	  The data of the new object will be set using the provided 
 *	  file stream.
 *	
 * Preconditions: The file stream is open and correctly formatted
 *		  according to Lab 4 specs.  	
 *
 * Postconditions: A new HistoryTransaction object was created using 
 *	 	   the provided file to set its data. A pointer to 
 *		   the object was then returned.
 *
 * @param input The input stream to extract from.
 * @return A pointer to the new instance. 
 */
HistoryTransaction * HistoryTransaction::getNewInstance
					 (ifstream &input) const
{
	int id;
	char type;	
	input >> type; input.ignore ();
	input >> id;   
	return new HistoryTransaction (id, type);
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
HistoryTransaction * HistoryTransaction::clone () const
{
	return new HistoryTransaction (my_cust_id, getType());
}


//---------------------getCustomerId----------------------------------
/**
 * @brief Returns the customer ID. 
 * 
 * Preconditions: None.
 * 
 * Postconditions: The customer ID was returned. 
 * 
 * @return The customer ID. 
 */
int HistoryTransaction::getCustomerId () const 
{
	return my_cust_id;
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
void HistoryTransaction::execute (StoreManager *mgr) const
{
	mgr->printHistory (my_cust_id);	
}
