/**
 * @file trade_transaction.h 
 * 
 * @brief  A class to represent TradeTransaction. A TradeTransaction
 *	   has-a Item being traded, and has-a customer ID.  
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
 *	- Allows printing a  TradeTransaction.
 * 	- Allows creating a  Transaction using a specified file.  
 *	- Allows getting the customer ID associated with this 
 *	  transaction. 
 *	- Allows getting the Item associated with this transaction.
 *	- Allows cloning a TradeTransaction.
 * Assumptions:
 *	- The file stream passed to createNewInstance is open and 
 *	  constains correct format according to Lab 4 specifications.  
 */
//--------------------------------------------------------------------

#ifndef TRADE_TRANSACTION_H
#define TRADE_TRANSACTION_H

#include "processable.h"
#include "item.h"

/**
 * @class TradeTransaction 
 */
class TradeTransaction : public Processable {

/**
 * @public
 */
public:

	//---------------------Default-Constructor--------------------
	/**
	 * @brief Creates a TradeTransaction with a default customer
 	 * 	  ID and type.
	 *
	 * Preconditions: None. 
	 * 
	 * Postconditions: The customer Id and type have been set to
	 *		   default values. 
	 */
	TradeTransaction ();


	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a TradeTransaction with the specified 
	 *	  customer ID and type.
	 *
	 * Preconditions: None. 	
 	 *
	 * Postconditions: The customer ID and type have been set to 
	 *		   the specified values.
	 *
	 * @param cust_id The customer ID.
	 * @param item The item associated with the transacion.
	 * @param type The type of transaction. 
	 */
	TradeTransaction (int cust_id, char type, Item *item);


	//---------------------Destructor-----------------------------
	/**
	 * @brief Deallocates the item associated with this 
	 *	  transaction. 
	 *
	 * Preconditions: None. 	
 	 * 
	 * Postconditions: Dynamic memory has been released. 
	 */
	virtual ~TradeTransaction ();


	//---------------------print----------------------------------
	/**
	 * @brief Prints this information. 
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This transaction was printed to the standard 
 	 *		   output stream.  
	 * 
	 * @param output The output stream. 
	 */
	virtual void print (ostream &output) const;


	//---------------------getNewInstance-------------------------
	/**
	 * @brief Retuns a pointer to a new TradeTransaction. 
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
	virtual TradeTransaction * getNewInstance 
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
	virtual TradeTransaction * clone () const; 


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
#endif /* TRADE_TRANSACTION_H */

