/**
 * @file store_initializer.h 
 * 
 * @brief StoreInitializer class initializes the stores' Customer, 
 * 	  Transaction, and Inventory. 
 *
 * @brief The StoreInitializer has-a Factory. The factory 


 *	  StoreManager, which stores the Customer, Inventory and 
 *	  Transaction objects after they have been instantiated. 
 *	  The instantiation for Customer and Transaction objects 
 *	  happen within this class. The StoreInitializer has-a
 *	  ItemFactory, which is used to create the Inventory 
 *	  objects. The ItemFactory is used to abstract the type
 *	  of Inventory objects being instantiated. 
 *
 * @brief After the stores' Customer, Transaction, and Inventory 
 *	  has been initialized, control is passed to the 
 *	  StoremManager for processing the transactions.
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
 * 	- Allows running the initialization of the stores' customers,
 *	  transactions, and inventory.
 * 
 * Assumptions:
 * 	-  
 */
//--------------------------------------------------------------------

#ifndef STOREINITIALIZER_H
#define STOREINITIALIZER_H

#include <fstream>
#include <string>
#include <iostream>

#include "store_manager.h"
#include "storeable.h"

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
	 * @brief Creates a StoreInitializer object with a NULL 
	 * 	  StoreManager. 
	 * 	
	 * Preconditions: None.
	 *
	 * Postconditions: my_manager has been set to NULL.
	 */
	StoreInitializer ();

	
	// --------------------Destructor-----------------------------
	/**
	 * @brief Deallocates my_manager and sets pointer to NULL.
	 *
	 * Preconditions:  None.
	 *
	 * Postconditions: my_manager was deallocated and set to NULL.
	 */ 
	~StoreInitializer ();


	// --------------------run------------------------------------
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

	//---------------------init_customers-------------------------
	/**
	 * @brief Initializes the store customers.
	 *
	 * Preconditions: The file associated with the customers is 
	 *	 	  in its correct directory and contains a 
	 *		  correct format according to Lab 4 specs.
	 *
 	 * Postconditions: The customers have been intialized and 
	 *		   stored in my_manager.
	 */
	void init_customer ();


	//---------------------init_inventory-------------------------
	/**
	 * @brief Initializes the store inventory.
	 *
	 * Preconditions: The file associated with the inventory is 
	 *	 	  in its correct directory and contains a 
	 *		  correct format according to Lab 4 specs.
	 *
 	 * Postconditions: The inventory have been intialized and 
	 *		   stored in my_manager.
	 */
	void init_inventory ();

	//---------------------init_transactions----------------------
	/**
	 * @brief Initializes the store pending transactions.
	 *
	 * Preconditions: The file associated with the transactions
	 *		  is in its correct directory and contains a 
	 *		  correct format according to Lab 4 specs.
	 *
 	 * Postconditions: The transactions have been intialized and 
	 *		   stored in my_manager.
	 */
	void init_transactions ();


	/**
 	 * @brief For storing items and processing transactions. 
 	 */
	StoreManager *my_manager;	

};
#endif /* STOREINITIALIZER_H */

