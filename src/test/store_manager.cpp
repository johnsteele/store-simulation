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

#include "store_manager.h"

//---------------------Constructor------------------------------------
/**
 * @brief Creates a StoreManager object with default valuse.
 *
 * Preconditions: None.
 *
 * Postconditions: This StoreManager was instantiated with default
 *		   values. 
 */
StoreManager::StoreManager ()
{
	my_item_trees      = new BSTree   *[DEFAULT_N_ITEMS];
	my_customer_table  = new Object *[DEFAULT_N_CUSTOMERS];
	my_customers       = new BSTree ();
	my_transactions    = new queue <Object *> ();
	my_size = DEFAULT_N_ITEMS;
	init_trees ();
}


//---------------------Destructor-------------------------------------
/**
 * @brief Deletes all dynamic memory obtained.
 * 	 
 * Preconditions: None.
 * 
 * Postconditions: All dynamic memory has been released. 
 */
StoreManager::~StoreManager ()
{
	// Get rid of the blood sucking leaches.
	delete my_item_trees;
	delete my_customer_table;
	delete my_customers;
	my_item_trees      = NULL;
	my_customer_table  = NULL;
	my_customers       = NULL; 
}


//---------------------addTransaction---------------------------------
/**
 * @brief Adds the provided Transaction object to the queue of pending 
 *	  transactions.
 * 
 * Preconditions: The queue of pending Transactions has been 
 *		  initialized. 
 * 
 * Postconditions: The provided Transaction was added to the pending
 *		   transaction queue.
 * 
 * @param transaction The transaction to add to the pending 
 *		      transaction queue.
 */
void StoreManager::addTransaction (Object *transaction)
{
	my_transactions->push (transaction);	
}


//---------------------addCustomer------------------------------------
/**
 * @brief Adds the provided Customer to the collection of customers.	
 *
 * Preconditions: The collection used for storing the customers has
 *		  been initialized.
 * 
 * Postconditions: The provided Customer was addded to the collection
 *		   of customers.
 *
 * @param customer The Customer to add.
 * @param id The customer Id.
 */
void StoreManager::addCustomer (Object *customer, int id)
{
	// Add the customer to the tree and look-up table.
	my_customers->insert (customer);
	my_customer_table [id] = customer;
}


//---------------------addItem----------------------------------------
/**
 * @brief Adds the provided store inventory Item to the tree of store
 *	  inventory items.
 *
 * Preconditions: 
 * 
 * Postconditions: The provided Item has been added to the collection
 *		   of inventory items.
 *
 * @param item The Item to add.
 * @param type The type of item.
 */
void StoreManager::addItem (Object *item, char type)
{
	int count;
	try {
		Item *tem = dynamic_cast <Item *> (item);
		count = tem->getCount ();
	} catch (exception &e) {
		cout << "Exception: " << e.what () << endl;
	}
	int i;
        int index = type - 'A';
	
	for (i = 0; i < count; i++)
        	my_item_trees [index]->insert (item); 
}


//---------------------processTransactions----------------------------
/**
 * @brief Processes the pending transaction queue.
 * 
 * Preconditions: The pending transaction queue has been initialized
 *		  and contains all the pending transactions.
 *
 * Postconditions: The pending transactions have been processed.
 */
void StoreManager::processTransactions () 
{
	try {
		Transaction *ptr;
		while (!my_transactions->empty()) {
     ptr = dynamic_cast<Transaction *> (my_transactions->front());
			ptr->execute (this);	
			my_transactions->pop();
		} 
	} catch (exception &e) {
		cout << "Exception: " << e.what () << endl;
	} 
}


//---------------------purchase---------------------------------------
/**
 * @brief Processes the purchase transaction. 
 * 
 * Preconditions: The Item exists in the Item tree.
 *
 * Postconditions: The purchase has been processed.
 */
void StoreManager::purchase ()
{
	PurchaseTransaction *ptr;
	try { 
		// Get the derived type.
		ptr = dynamic_cast<PurchaseTransaction *> 
					(my_transactions->front());
	} catch (exception &e) {
		cout << "Exception: " << e.what () << endl;
	}

	// Get the Item.
	const Item *item = ptr->getItem ();

	if (item) {	
		// Check valid customer Id.
		if (ptr->getCustomerId() > 0 && ptr->getCustomerId() < DEFAULT_N_CUSTOMERS) {

			// Get the Item tree. 
			BSTree *p_tree = my_item_trees [(item->getType() - 'A')]; 

			// Query the tree for the item.
			if (p_tree->remove (*item)) { 

				Customer *c;
				try { 
					// Get the customer.
					c = dynamic_cast<Customer *> (my_customer_table [ptr->getCustomerId ()]);	
				} catch (exception &e) {
					cout << "Exception: " << e.what () << endl;
				}

				// Add to customer history.
				c->addTransaction (ptr);
				c = NULL;

			// Otherwise, display not available.
			} else {
				cout << "Product not in stock: " << *item << endl;
				delete ptr;
			}
		
			p_tree = NULL; 

		// Customer doesn't exist 
		}  else {
			cout << "Customer ( " 
			<< ptr->getCustomerId() 
			<< " )" 
			<< " does not exist." 
			<< endl;
			delete ptr; 
		} 
	} 
	
	else { // Transaction item is NULL.
		delete ptr;
	} 
	ptr    = NULL;
	item   = NULL; 
}


//---------------------trade------------------------------------------
/**
 * @brief Adds the Item to the collection of store inventory, and adds
 *	  the transaction to the associated customers' history.
 *
 * Preconditions: The Item exists in the item tree. 
 * 
 * Postconditions: The trade-in has been processed.
 */
void StoreManager::trade ()
{
	TradeTransaction *ptr;
	try { 
		ptr = dynamic_cast<TradeTransaction *> (my_transactions->front());
	} catch (exception &e) {
		cout << "Exception: " << e.what () << endl;
	}
	
	// Make a copy to insert. 
	Object *item = ptr->getItem ()->clone ();
	if (item) {
		const Item *tem = ptr->getItem ();

		// Try inserting item. 
		if (my_item_trees[(tem->getType () - 'A')]-> insert (item)) {
			// If success, add transaction to the customer.	
			Customer *c;	

			// Get the customer.
			c = dynamic_cast<Customer *> (my_customer_table [ptr->getCustomerId ()]);	
		
			// Add transaction to customer history.
			c->addTransaction (ptr);

			// No dingleberries in my tree.
			c = NULL;
		} 
		
		// Otherwise, display not available.
		else {
			cout << "Unable to Trade Product: " << *item << endl;
			
			// The transaction wasn't stored with a customer.
			// So kill it.
			delete ptr; // We have to do it for them. 

			// Kill the copy.
			delete item;
		}
		tem = NULL;
	}
	else { // Ite trade Item is NULL.
		delete ptr;
	}
	ptr  = NULL;
	item = NULL; 
}


//---------------------printInventory---------------------------------
/**
 * @brief Prints each inventory Item including the number of each item
 *	  in in inventory.
 *
 * Preconditions: None. 
 *
 * Postconditions: The inventory has been displayed.
 */
void StoreManager::printInventory () const
{
	cout << BANNER << endl;
	cout << setw (45) << INVENTORY << endl;
	cout << BANNER << endl;
	cout << *my_item_trees ['R' - 'A'] << endl << endl;
	cout << *my_item_trees ['C' - 'A'] << endl << endl;
	cout << *my_item_trees ['D' - 'A'] << endl << endl;
}


//---------------------printHistory-----------------------------------
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
void StoreManager::printHistory (int id) const
{
	if (my_customer_table [id]) {
		cout << BANNER << endl;
		cout << setw (49) << HISTORY << endl;
		cout << BANNER << endl; 
		cout << *my_customer_table [id];
		cout << endl << endl;
	}
	else {
		cout << "Unable to Print Customer ( " 
	     	<< id 
	        << " )." 
	        << "Does not exist." 
	        << endl; 
	}
}


//---------------------printAllHistory--------------------------------
/**
 * @brief Prints all customers' and their transactions.
 * 
 * Preconditions: None. 
 * 	
 * Postconditions: The transaction history for all customers has been
 *		   printed.
 */
void StoreManager::printAllHistory () const
{
	cout << BANNER << endl;
	cout << setw (55) << ALL_HIS << endl;
	cout << BANNER << endl << endl; 
	cout << *my_customers;
	cout << endl << endl;
}


//--------------------mapToTree---------------------------------------
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
void StoreManager::mapToTree (char key, BSTree *tree)
{
	int index = key - 'A';

        // Do we need to resize?
        if (index > my_size)
                makeBigger (index);

        my_item_trees [index] = tree; 
}


//---------------------init_trees-------------------------------------
/**
 * @brief Initializes the array of trees.
 *
 * Preconditions: None.
 * 
 * Postconditions: The array has been initialized.
 */
void StoreManager::init_trees ()
{
	for (int i = 0; i <= my_size; i++)
		my_item_trees [i] = NULL;
}


//---------------------makeBigger-------------------------------------
/**
 * @brief Increase size of tree array.
 *
 * Preconditions: size is bigger than my_tree_size.
 * 
 * Postconditions: The array was expanded and data copied.
 *
 * @param size The size of the new array.
 */
void StoreManager::makeBigger (int size)
{
        int index;

        // The bigger array.
        BSTree **copy = new BSTree *[size + 1];

        // Initialize the pointers.
        for (index = 0; index <= size; index++)
                copy [index] = NULL;

        // Transfer over old data.
        for (index = 0; index <= my_size; index++)
                copy [index] = my_item_trees [index];

        // Delete the old array.        
        delete my_item_trees;

        // Now hold her hand.
        my_item_trees = copy;

        // Now set our new size.
        my_size = size + 1;

        // Stay away dangly leaches!
        copy = NULL; 
}

