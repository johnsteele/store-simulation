/**
 * @file store_manager.h 
 * 
 * @brief StoreManager class is responsible for managing the stores'
 *	  customer, inventory, and transaction objects. The 
 *	  StoreManager also processes the transactions. The 
 *	  StoreManager has two hashtables. The first hashtable is
 *	  holds pointers to the inventory trees. The second hashtable
 *	  holds pointers to functions associated with the different
 *	  types of transactions.
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
#include "customer.h"
#include "transaction.h"
#include "item.h"
#include "rock.h"
#include "classical.h"
#include "bstree.h"
#include "hash_table.h"


/*
 * @namespace std
 */
using namespace std; 

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


	//---------------------Copy-Constructor-----------------------
	/**
	 * @brief Copies the other StoreManager into this.
	 *
	 * Preconditions: The other is not NULL.
	 * 
	 * Postconditions: The other was copied into this.
	 *
	 * @param other The other StoreManager to copy.
	 */
	StoreManager (const StoreManager &other);

	
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
	void addTransaction (const Transaction *transaction)
	{
		my_transactions->push (*transaction);
	}

	
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
	 */
	void addCustomer (const Customer *customer)
	{
		my_customers->add(customer->getId(), customer);
	}


	//---------------------addItem--------------------------------
	/**
	 * @brief Adds the provided store inventory Item to the 
	 *	  tree of store inventory items.
	 *
	 * Preconditions: The collection used for storing the Items
 	 * 		  has been intialized.
	 * 
	 * Postconditions: The provided Item has been added to the 
	 *		   collection of inventory items.
 	 *
	 * @param item The Item to add.
	 */
	void addItem (const Item *item);


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
	void processTransactions () 
	{
		Transaction *ptr;
		while (!my_transactions->empty()) {
			ptr = &my_transactions->peek(); 
			evaluateTransaction(ptr);
			my_transactions->pop();
		}	
	}


/**
 * @private:
 */
private:

	//---------------------purchaseHelper-------------------------
	/**
	 * @brief Processes a purchase transaction. Returns false if
	 *	  the Item is not in stock, returns true and adds 
	 *	  the transaction to the associated customer if the 
	 *	  purchase was successful. 
	 * 
	 * Preconditions: The transaction is of type purchase.
	 *
	 * Postconditions: The purchase has been processed.
	 */
	bool purchaseHelper ();


	//---------------------tradeHelper----------------------------
	/**
	 * @brief Processes a trade transaction. Adds the Item to the
	 *	  collection of store inventory, and adds the 
	 *	  transaction to the associated customers' history.
 	 *
	 * Preconditions: The transaction is of type trade-in.
	 * 
	 * Postconditions: The trade-in has been processed.
	 */
	void tradeHelper ();


	//---------------------printInventory-------------------------
	/**
	 * @brief Process a print inventory transaction. Prints each
	 *	  inventory Item including the number of each item in
	 *	  in inventory.
	 *
	 * Preconditions: The transaction is of type inventory.
	 *
	 * Postconditions: The inventory has been displayed.
	 */
	void printInventory () const;


	//---------------------printHistory---------------------------
	/**
	 * @brief Process a print customer history transaction. Prints
	 *	  the specified customer's transaction history. The
	 *	  transaction is then added to the customers' history.
	 *
	 * Preconditions: The transaction is of type history.
	 * 
	 * Postconditions: The specified customer's transaction 
	 *	  	   history was printed.
	 *
	 * @param customer The customer who's hitory is to be printed.
	 * @param tansaction The Transaction being processed.
	 */
	void printHistory ();


	//---------------------printAllHistory------------------------
	/**
	 * @brief Process a print all history transaction. Prints all
	 * 	  customers' and their transactions.
	 * 
	 * Preconditions: The transaction if of type print all 
	 *		  history.
	 * 	
 	 * Postconditions: The transaction history for all customers 
	 * 		   has been printed.
	 */
	void printAllHistory () const;


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
	void evaluateTransaction (const Transaction *transaction) {
		f_ptr func = my_functions->get (transaction->getType());	
		(*this.*func)();
	}


	/**
	 * @brief The store Rock CD's.
	 */	
	BSTree<Rock> *my_rock_cds;

	/**
	 * @brief The store Classical CD's.
	 */	
 	BSTree<Classical> *my_classic_cds;
	
	/**
	 * @brief The store DVD's.
	 */
	BSTree<DVD> *my_dvds;

	/**
	 * @brief The store pending transactions.
	 */
	queue<Transaction> *my_transactions;

	/**
	 * @brief The hash table of Item trees.
	 */
	HashTable<BSTree> *my_items_table;

	/**
	 * @brief Hashtable with function poiners associated with 
	 *   	  transaction types.
	 */
	typedef void (StoreManager::*f_ptr)();
	HashTable<f_ptr> *my_functions;
	
	/**
	 * @brief The customer hashtable.
	 */
	HashTable<Customer> *my_customers;
};
#endif /* STORE_MANGER_H */

