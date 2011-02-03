/**
 * @file store_manager.h 
 * 
 * @brief StoreManager class is responsible for managing the stores'
 *	  customer, inventory, and transaction objects. The 
 *	  StoreManager also processes the transactions. The 
 *	  StoreManager has a hashtable. The hashtable holds 
 *	  pointers to the customer within a binary tree. 
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
 * 	- Allows adding a Customer object.
 *	- Allows adding a Item object to the inventory.
 * 	- Allows adding a Transaction object.
 *	- Allows processing the Transactions.  
 * 
 * Assumptions:
 * 	- The Customers, Transactions, and Items are not NULL when 
 *	  adding them.
 */
//--------------------------------------------------------------------

#ifndef STORE_MANAGER_H
#define STORE_MANAGER_H

#include <iostream>
#include <queue>
#include <iomanip>
#include "customer.h"
#include "item.h"
#include "rock.h"
#include "dvd.h"
#include "classical.h"
#include "bstree.h"
#include "hash_table.h"
#include "trade_transaction.h"
#include "purchase_transaction.h"
#include "processable.h"

const static char BANNER[] = "==============================================================================================";
/**
 * @brief Inventory output name.
 */
const static char INVENTORY[] = "Inventory"; 
/**
 * @brief History output name.
 */
const static char HISTORY[] = "Customer History";
/**
 * @breif All history output name.
 */
const static char ALL_HIS[] = "All Customer History";


/*
 * @namespace std
 */
using namespace std; 

class Transaction;
/**
 * @class StoreManager
 */
class StoreManager {

/**
 * @public
 */
public:
	//---------------------Constructor----------------------------
	/**
 	 * @brief Creates a StoreManager object with default valuse.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This StoreManager was instantiated with 
	 *		   default values. 
 	 */
	StoreManager ();

	//---------------------Destructor-----------------------------
	/**
 	 * @brief Deletes all dynamic memory obtained.
	 * 	 
	 * Preconditions: None.
	 * 
	 * Postconditions: All dynamic memory has been released. 
 	 */
	~StoreManager ();
 
	
	//---------------------addTransaction-------------------------
	/**
	 * @brief Adds the provided Transaction object to the 	
  	 * 	  queue of pending transactions.
	 * 
	 * Preconditions: The queue of pending Transactions has been 
	 * 		  initialized. 
	 * 
	 * Postconditions: The provided Transaction was added to the
	 *		   pending transaction queue.
	 * 
	 * @param transaction The transaction to add to the pending
	 *	  	      transaction queue.
	 */
	void addTransaction (Object *transaction);
	
	
	//---------------------addCustomer----------------------------
	/**
	 * @brief Adds the provided Customer to the collection of 
	 *	  customers.	
	 *
	 * Preconditions: The collection used for storing the 
	 *		  customers has been initialized.
	 * 
	 * Postconditions: The provided Customer was addded to the 	
	 *		   collection of customers.
	 *
	 * @param customer The Customer to add.
 	 * @param id The customer Id.
	 */
	void addCustomer (Object *customer, int id);


	//---------------------addItem--------------------------------
	/**
	 * @brief Adds the provided store inventory Item to the 
	 *	  tree of store inventory items.
	 *
	 * Preconditions: 
	 * 
	 * Postconditions: The provided Item has been added to the 
	 *		   collection of inventory items.
 	 *
 	 * @param type The type of item.
	 * @param item The Item to add.
	 */
	void addItem (Object *item, char type);


	//---------------------processTransactions--------------------
	/**
	 * @brief Processes the pending transaction queue.
	 * 
	 * Preconditions: The pending transaction queue has been 
	 * 		  initialized and contains all the
	 *		  pending transactions.
	 *
	 * Postconditions: The pending transactions have been 
	 *		   processed.
	 */
	void processTransactions (); 


	//---------------------purchase-------------------------------
	/**
	 * @brief Processese the purchase transaction. 
	 *
	 *	
 	 * Preconditions: The Item exists in the Item tree. 
	 *
	 * Postconditions: The purchase has been processed.
	 */
	void purchase ();


	//---------------------trade----------------------------------
	/**
	 * @brief Adds the Item to the collection of store inventory,
 	 *	  and adds the transaction to the associated 
 	 *	  customers' history.
 	 *
	 * Preconditions: The Item exists in the item tree. 
	 * 
	 * Postconditions: The trade-in has been processed.
	 */
	void trade ();


	//---------------------printInventory-------------------------
	/**
	 * @brief Prints each inventory Item including the number of 
 	 *	  each item in in inventory.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The inventory has been displayed.
	 */
	void printInventory () const;


	//---------------------printHistory---------------------------
	/**
	 * @brief Prints the specified customer's transaction history. The 
	 *
	 * Preconditions: The customer id is valid. 
	 * 
	 * Postconditions: The specified customer's transaction history was
	 *		   printed.
 	 *
	 * @param id The customer ID who's hitory is to be printed.
	 */ 
	void printHistory (int id) const;


	//---------------------printAllHistory------------------------
	/**
	 * @brief Prints all customers' and their transactions.
	 * 
	 * Preconditions: None. 
	 * 	
 	 * Postconditions: The transaction history for all customers 
	 * 		   has been printed.
	 */
	void printAllHistory () const; 

	
	//--------------------mapToTree-------------------------------
	/**
	 * @brief Maps the provided key to the the provided tree.
	 * 
	 * Preconditions: The tree is not NULL.
	 * 
	 * Postconditions: The key is mapped to the tree.
	 *
	 * @param key The key.
	 * @param tree The tree to map the key to. 
	 */
	void mapToTree (char key, BSTree *tree);


/**
 * @private:
 */
private:

	//---------------------evaluateTransaction--------------------
	/**
	 * @brief Evaluate the transaction by first getting the 
	 *	  transaction type, and then calling the appropriate 
	 * 	  method for processing. 
	 *
	 * Preconditions: The transaction is not NULL.
	 * 
	 * Postconditions: The transaction has been evaluated.
	 * 
	 * @param transaction The transaction to evaluate.
	 */
	void evaluateTransaction (const Transaction *transaction);


	//---------------------init_trees-----------------------------
	/**
	 * @brief Initializes the array of trees.
	 *
	 * Preconditions: None.
	 * 
	 * Postconditions: The array has been initialized.
	 */
	void init_trees ();


	//---------------------makeBigger-----------------------------
	/**
	 * @brief Increase size of tree array.
	 *
	 * Preconditions: size is bigger than my_tree_size.
	 * 
	 * Postconditions: The array was expanded and data copied.
	 *
 	 * @param size The size of the new array.
	 */
	void makeBigger (int size);


	/**
	 * @brief The customers.
	 */	
	BSTree *my_customers;

	/**
	 * @brief The store pending transactions.
	 */
	queue <Object *> *my_transactions;
	
	/**
	 * @brief The customer fast access array.
	 */
	Object **my_customer_table;

	/**
	 * @brief Array of the inventory trees. 
	 */
	BSTree **my_item_trees;	

	/**
	 * @brief The size of the trees array.
	 */
	int my_size;
	
	/**
 	 * @brief THe default number of customers.
	 */
	const static int DEFAULT_N_CUSTOMERS = 1000; 

	/**
 	 * @brief THe default number of Items.
	 */
	const static int DEFAULT_N_ITEMS = 28; 
};
#endif /* STORE_MANGER_H */

