/**
 * @file all_history_transaction.h 
 * 
 * @brief  A class to represent AllHistoryTransaction. 
 *
 * @brief CSS 343 - Lab 4
 *
 * @author John Steele  \<steelejr@u.washington.edu\> 
 *  
 * @version 1.0.0
 * @date November 9, 2010
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

#ifndef ALL_HISTORY_TRANSACTION_H
#define ALL_HISTORY_TRANSACTION_H

#include "transaction.h"

/**
 * @class AllHistoryTransaction
 */
class AllHistoryTransaction : public Transaction {

/**
 * @public 
 */
public:

	//---------------------Default-Constructor--------------------
	/**
	 * @brief Creates an AllHistoryTransaction with default 
	 *	  values.
	 * 
	 * Preconditions: None. 
	 * 
	 * Postconditions: This transaction was instantiated with 
	 *		   a default type. 
	 */
	AllHistoryTransaction ();


	//---------------------Constructor----------------------------
	/**
	 * @brief Creates an AllHistoryTransaction with the 
	 *	  specified type.
	 * 
	 * Preconditions: None. 
	 * 
	 * Postconditions: This transaction was instantiated with the
	 *		   secified type.
	 * 
	 * @param type The type of transaction. 
	 */
	AllHistoryTransaction (char type);

	
	//---------------------Deconstructor--------------------------
	/**
	 * @brief Deconstructor
	 *
	 * Preconditions: None. 
	 * 
	 * Postconditions: Resources obtained by this transaction were
	 *		   released. 
	 */
	virtual ~AllHistoryTransaction (); 


	//---------------------getNewInstance-------------------------
	/**
	 * @brief Retuns a pointer to a new AllHisotryTransaction. The
	 *	  data of the new object will be set using the 
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
	virtual AllHistoryTransaction * getNewInstance 
					(ifstream &input) const; 


	//---------------------clone----------------------------------
	/**
	 * @brief Clones this HistoryTransaction.
	 * 
	 * Preconditions: None.
	 * 
 	 * Postconditions: A pointer to a cloned Object is returned.
	 * 
	 * @return The pointer to the cloned transaction.
	 */
	virtual AllHistoryTransaction * clone () const;

	
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
#endif

