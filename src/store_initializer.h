/**
 * @file store_initializer.h 
 * 
 * @brief StoreInitializer class initializes the store. 
 * @brief CSS 343 - Lab 4
 *
 * @author John Steele  \<steelejr@u.washington.edu\> 
 * @author Sean Wessels \<seanwes@uw.edu\>
 *  
 * @version 1.0.0
 * @date November 9, 2010
 * 
 * @brief The StoreInitializer class is responsible for initializing
 *	  the stores' inventory, customers, and pending transaction
 *	  commands.
 * @brief The StoreInitializer has-a StoreManager. The StoreManager
 *	  stores the inventory, customer, and command objects after 
 *	  they are instantiated in this class. After the pending
 *	  transaction commands are loaded, control is passed to the 
 *	  StoreManager to process the transactions.
 */ 
//--------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows initialization of inventory.
 *	- Allows initialization of customers.
 * 	- Allows initialization of transactions.
 * 
 * Assumptions:
 * 	- The inventory, customer, and transaction files are valid
 *	  directories, and properly formatted. 
 */
//--------------------------------------------------------------------

#ifndef STOREINITIALIZER_H
#define STOREINITIALIZER_H

#include <fstream>
#include <string>
#include <queue>  
#include <iostream>

#include "store_manager.h"
#include "store_customer.h"
#include "store_equipment.h"
#include "store_transaction.h"

/**
 * @namespace std
 */
using namespace std;

/**
 * @class StoreInitializer
 */
class StoreInitializer {

/** 
 * @public
 */
public:
	// --------------------Default Constructor--------------------
	/**
	 * @brief Default Constructor.
	 *
	 * @brief Creates a StoreInitializer object with a NULL 
	 * 	  StoreManager. 
	 */ 
	StoreInitializer ();

	
	// --------------------Destructor-----------------------------
	/**
	 * @brief Destructor.
	 *
	 * @brief Releases resources and deletes allocated memory. 
	 *
	 * Preconditions:  None.
	 * Postconditions: my_manager was deallocated and set to NULL.
	 */ 
	~StoreInitializer ();


	// ----------------------------run----------------------------
	/**
	 * @brief Starts the process of initializing the store 
	 *  	  inventory, customers, and transactions.  
	 * 
	 * Preconditions: This method is bound to init(...), therefore
	 *		  it must be available.  
 	 * 
	 * Postconditions: The store inventory, customers, and 
	 *		   transactions have been initialized. 
	 */ 
	void run ();

/**
 * @private
 */	
private:

	//---------------------init_store-----------------------------	
	/**
	 * @brief initializes the store.
	 *
 	 * Preconditions: 
	 * Postconditions: 
	 */
 	void inti_store ();	

	

	/**
 	 * @brief For storing items and processing transactions. 
 	 */
	StoreManager *my_manager;	

};
#endif /* STOREINITIALIZER_H */

