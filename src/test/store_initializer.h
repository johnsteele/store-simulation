/**
 * @file store_initializer.h 
 * 
 * @brief StoreInitializer class initializes the stores' Customers, 
 * 	  Transactions, and Inventory. 
 *
 * @brief StoreInitializer has two object factories; one for transactions
 *	  and the other for inventory items. The StoreInitializer also
 *	  has-a StoreManager.
 *
 * @brief After the store has been initialized control is passed to
 *	  the StoremManager for processing the transactions.
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
 * 	- Allow clients to run the process of initializing the store,
 *	  and start processing the transactions.
 * 
 * Assumptions:
 * 	- The file directories exist and contain valid format 
 *	  according to Lab 4 specifications.
 */
//--------------------------------------------------------------------

#ifndef STOREINITIALIZER_H
#define STOREINITIALIZER_H

#include <fstream>
#include <iostream> 
#include <iomanip>
#include "store_manager.h" 
#include "object_factory.h"
#include "trade_transaction.h" 
#include "history_transaction.h"
#include "purchase_transaction.h"
#include "inventory_transaction.h"
#include "all_history_transaction.h"

/**
 * @namespace std
 */
using namespace std; 

/**
 * @brief The customer file.
 */	
char const CUSTOMERS_FILE[] = "hw4customer.txt"; 
/**
 * @brief The inventory file.
 */
char const INVENTORY_FILE[] = "hw4inventory.txt";
/**
 * @brief The transactions file.
 */
char const TRANSACTIONS_FILE[] = "hw4commands.txt"; 
/** 
 * @brief The failed open file error message.  
 */ 
string const FILE_O_ERROR = "Error: Failed to open file - "; 
/** 
 * @brief The failed close file error message.  
 */ 
string const FILE_C_ERROR = "Error: Failed to close file - "; 
/**
 * @brief The Rock CD unique identifer. 
 */
char const ROCK_ID = 'R';
/**
 * @brief The Classical CD unique identifer. 
 */
char const CLASSIC_ID = 'C';
/**
 * @brief The DVD unique identifier.
 */
char const DVD_ID = 'D';
/**
 * @bief The Purchase Transaction identifier.
 */
char const PURCHASE_ID = 'P';
/**
 * @brief The Trade Transaction identifier.
 */
char const TRADE_ID = 'T';
/**
 * @brief The History Transaction identifier. 
 */
char const HISTORY_ID = 'H';
/**
 * @brief The All History Transaction identifier.  
 */
char const ALL_ID = 'A';
/**
 * @brief The Inventory Transaction identifier.
 */
char const INVENTORY_ID = 'I';


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
	 * @brief Creates a StoreInitializer object with default 
	 *	  values. 
	 * 	
	 * Preconditions: None.
	 *
	 * Postconditions: The manager and factories have been 
 	 * 		   initialized. 
	 */
	StoreInitializer ();

	
	//---------------------Copy-Constructor-----------------------
	/**
	 * @brief Copies the other StoreInitializer into this.
	 * 
	 * Preconditions: The other StroreInitializer is non-NULL.
	 * 
	 * Postconditions: The other StoreInitializer was copied into
	 *		   this.
	 *
	 * @param other The other to copy into this.
	 */
	StoreInitializer (const StoreInitializer &other);


	// --------------------Destructor-----------------------------
	/**
	 * @brief Deallocates my_manager and the factories and sets 
	 * 	  their pointers to NULL.
	 *
	 * Preconditions: my_manager and the factories point to 	
	 *		  dynamically allocated objects or NULL. 
	 *
	 * Postconditions: my_manager and the factories were 
 	 *	  	   deallocated and set to NULL.
	 */ 
	~StoreInitializer ();


	// --------------------run------------------------------------
	/**
	 * @brief Starts the process of initializing the store 
	 *  	  Items, Customers, and Transactions.  
	 * 
	 * Preconditions: The factories and my_manager have been	
	 *	 	  initialized.
 	 * 
	 * Postconditions: The store Items, Customers, and 
	 *		   Transactions have been initialized. 
	 */ 
	void run ();


/**
 * @private
 */	
private:
	//---------------------init_item_factory----------------------
 	/**
	 * @brief Sets up the ObjectFactory with the different types
 	 *	  of Items in the store.
	 *
	 * Preconditions: my_factory has already been instantiated.
	 *
	 * Postconditions: my_factory constains the types of Items
	 *		   used in the store.
	 */
	void init_item_factory ();
	

	//---------------------init_transaction_factory---------------
 	/**
	 * @brief Sets up the ObjectFactory with the different types
 	 *	  of Transactions in the store.
	 *
	 * Preconditions: The factories has already been instantiated.
	 *
	 * Postconditions: my_factory constains the types of
 	 *	 	   Transactions used in the store.
	 */
	void init_transaction_factory ();


	//---------------------init_customers-------------------------
	/**
	 * @brief Initializes the store customers.
	 *
	 * Preconditions: The file associated with the customers is 
	 *	 	  in the correct directory and contains the 
	 *		  correct format according to Lab 4 specs.
	 *
 	 * Postconditions: The customers have been intialized and 
	 *		   stored in my_manager.
	 *
	 * @param file The customer file.
	 */
	void init_customers (const char file[]);
	

	//---------------------init_inventory-------------------------
	/**
	 * @brief Initializes the store inventory Items.
	 *
	 * Preconditions: The file associated with the inventory is 
	 *	 	  in the correct directory and contains a 
	 *		  correct format according to Lab 4 specs.
	 *
 	 * Postconditions: The inventory Items have been intialized
 	 *		   and stored in my_manager.
	 * 
	 * @param file The inventory file.
	 */
	void init_inventory (const char file[]);


	//---------------------init_transactions----------------------
	/**
	 * @brief Initializes the store pending transactions.
	 *
	 * Preconditions: The file associated with the transactions
	 *		  is in the correct directory and contains a 
	 *		  correct format according to Lab 4 specs.
	 *
 	 * Postconditions: The transactions have been intialized and 
	 *		   stored in my_manager.
	 * 	
	 * @param file The transactions file.
	 */
	void init_transactions (const char file[]);


	//---------------------openFile-------------------------------
	/**
	 * @brief A helper method that opens the file associated with
	 *	  the provided string.
	 *
	 * Preconditions: The provided file string is a valid 
	 *		  directory.
	 * 
	 * Postconditions: If the file is successfully opened true
	 *		   is returned, false otherwise.
	 *
	 * @param file The file to open.
	 * @param infile The file stream.
	 * @return True if opened, false otherwise.
	 */
	bool openFile (const char *file, ifstream &infile);


	/**
 	 * @brief Stores inventory, transactions, customers and
	 * 	  processes transactions. 
 	 */
	StoreManager *my_manager;	
 
	/**
	 * @brief Allocates appropriate  inventory items.
	 */
	ObjectFactory *my_item_factory; 

	/**
	 * @brief Allocates appropriate transaction items.
	 */
	ObjectFactory *my_transaction_factory; 
};
#endif /* STOREINITIALIZER_H */

