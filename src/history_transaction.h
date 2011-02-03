/**
 * @file history_transaction.h 
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
 * Assumptions:
 *	- The file stream passed to createNewInstance is open and 
 *	  constains correct format according to Lab 4 specifications.  
 */
//--------------------------------------------------------------------


#ifndef HISTORY_TRANSACTION_H
#define HISTORY_TRANSACTION_H

#include "transaction.h"

/**
 * @class HistoryTransaction
 */
class HistoryTransaction : public Transaction {

/**
 * @public
 */
public:

	//---------------------Default-Constructor--------------------
	/**
 	 * @brief Creates a HistoryTransaction object with default
	 *	  values.
	 * 
	 * Preconditions: None. 
	 * 
	 * Postconditions: this HistoryTransaction object has been 
	 * 		   instantiated with default type and ID.
	 */
	HistoryTransaction ();


	//---------------------Constructor----------------------------
	/**
 	 * @brief Creates a HistoryTransaction objec with the 
	 *	  specified customer ID and type. 
	 * 
	 * Preconditions: None. 
	 * 
	 * Postconditions: this HistoryTransaction object has been 
	 * 		   instantiated using the specified customer 
	 *		   ID and type. 
	 * 
	 * @param cust_id The customer ID. 
	 * @param type The type of transaction. 
	 */
	HistoryTransaction (int cust_id, char type);

	
	//---------------------Destructor-----------------------------
	/**
	 * @brief Deallocates resources obtained by this History
	 *	  Transaction.
	 *
	 * Preconditions: None. 
	 * 
	 * Postconditions: All resources have been released.
	 */
	virtual ~HistoryTransaction ();


	//---------------------getNewInstance-------------------------
	/**
	 * @brief Retuns a pointer to a new instance of a History
	 *	  Transaction. The data of the new object will be set
  	 *	  using the provided file stream.
	 *	
 	 * Preconditions: The file stream is open and correctly 
	 *		  formatted according to Lab 4 specs.  	
	 *
	 * Postconditions: A new HistoryTransaction object was created
 	 *		   using the provided file to set its data. A
 	 *		   pointer to the object was then returned.
	 *
	 * @param input The input stream to extract from.
	 * @return A pointer to the new instance. 
	 */
	virtual HistoryTransaction * getNewInstance 
					(ifstream &input) const;


	//---------------------getCustomerId--------------------------
	/**
	 * @brief Returns the customer ID. 
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
	 * @brief The customer's ID associated with this transaction.
	 */
	int my_cust_id;
}; 
#endif

