/**
 * @file all_history_transaction.cpp 
 * 
 * @brief  A class to represent AllHistoryTransaction. 
 *
 * @brief CSS 343 - Lab 4
 *
 * @author John Steele  \<steelejr@u.washington.edu\> 
 *  
 * @version 1.0.0
 * @date December 5, 2010
 */ 
//-------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows creating a AllHistoryTransaction using a specified 
 *	  file.  
 *	- Allows cloning a AllHistoryTransaction.
 * Assumptions:
 *	- The file stream passed to createNewInstance is open and 
 *	  constains correct format according to Lab 4 specifications.  
 */
//--------------------------------------------------------------------

#include "all_history_transaction.h"
#include "store_manager.h"

//---------------------Default-Constructor----------------------------
/**
 * @brief Creates an AllHistoryTransaction with default values.
 * 
 * Preconditions: None. 
 * 
 * Postconditions: This transaction was instantiated with a default
 *	  	   type. 
 */
AllHistoryTransaction::AllHistoryTransaction () : Transaction() {}


//---------------------Constructor------------------------------------
/**
 * @brief Creates an AllHistoryTransaction with the specified type.
 * 
 * Preconditions: None. 
 * 
 * Postconditions: This transaction was instantiated with the secified
 *		   type.
 * 
 * @param type The type of transaction. 
 */
AllHistoryTransaction::AllHistoryTransaction (char type)
 			 : Transaction (type) {}


//---------------------Deconstructor----------------------------------
/**
 * @brief Deconstructor
 *
 * Preconditions: None. 
 * 
 * Postconditions: Resources obtained by this transaction were
 *		   released. 
 */
AllHistoryTransaction::~AllHistoryTransaction () {}


//---------------------getNewInstance---------------------------------
/**
 * @brief Retuns a pointer to a new AllHisotryTransaction. The data of
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
AllHistoryTransaction * AllHistoryTransaction::getNewInstance 
				(ifstream &input) const
{
	char type;
	input >> type;
	input.ignore (INT_MAX, '\n');
	return new AllHistoryTransaction (type);
}


//---------------------clone------------------------------------------
/**
 * @brief Clones this HistoryTransaction.
 * 
 * Preconditions: None.
 * 
 * Postconditions: A pointer to a cloned Object is returned.
 * 
 * @return The pointer to the cloned transaction.
 */
AllHistoryTransaction * AllHistoryTransaction::clone () const
{
	return new AllHistoryTransaction (getType());
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
void AllHistoryTransaction::execute (StoreManager *mgr) const
{
	mgr->printAllHistory ();
}

