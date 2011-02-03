/**
 * @file store_initializer.cpp
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
#include "store_initializer.h"

// --------------------Default Constructor----------------------------
/**
 * @brief Creates a StoreInitializer with default values. 
 * 	
 * Preconditions: None.
 *
 * Postconditions: The manager and factories have been initialized. 
 */
StoreInitializer::StoreInitializer ()
{
	my_item_factory	       = new ObjectFactory ();
	my_transaction_factory = new ObjectFactory ();
	my_manager  	       = new StoreManager ();
	init_item_factory (); 
	init_transaction_factory ();
}


// --------------------Destructor-------------------------------------
/**
 * @brief Deallocates my_manager and the factories and sets their 
 *	  pointers to NULL.
 *
 * Preconditions: my_manager and my_item_factory point to dynamically 
 *		  allocated objects or NULL. 
 *
 * Postconditions: my_manager and the factories were deallocated and
 *		   set to NULL.
 */ 
StoreInitializer::~StoreInitializer ()
{
	delete my_item_factory;
	delete my_transaction_factory;
	delete my_manager;
	my_item_factory        = NULL;
	my_transaction_factory = NULL;
	my_manager             = NULL;
}


//---------------------init_item_factory------------------------------
/**
 * @brief Sets up the ObjectFactory with the different types of Items
 *	  in the store.
 *
 * Preconditions: my_item_factory has already been instantiated.
 *
 * Postconditions: my_item_factory constains the types of Items used 
 *		   in the store.
 */
void StoreInitializer::init_item_factory ()
{
	my_item_factory->addObject (ROCK_ID,    new Rock ());
	my_item_factory->addObject (CLASSIC_ID, new Classical ());
	my_item_factory->addObject (DVD_ID,     new Dvd ()); 
	my_manager->mapToTree      (ROCK_ID,    new BSTree ());
	my_manager->mapToTree      (CLASSIC_ID, new BSTree ());
	my_manager->mapToTree      (DVD_ID,     new BSTree ());
}


//---------------------init_transaction_factory-----------------------
/**
 * @brief Sets up the ObjectFactory with the different types of 
 *	  Transactions in the store.
 *
 * Preconditions: my_item_factory has already been instantiated.
 *
 * Postconditions: my_item_factory constains the types of Transactions 
 *		   used in the store.
 */
void StoreInitializer::init_transaction_factory ()
{ 
	my_transaction_factory->
		addObject (PURCHASE_ID, new PurchaseTransaction ());
	my_transaction_factory->
		addObject (TRADE_ID,    new TradeTransaction ());
	my_transaction_factory->
		addObject (HISTORY_ID,  new HistoryTransaction ());
	my_transaction_factory->
		addObject (INVENTORY_ID,new InventoryTransaction ());
	my_transaction_factory->
		addObject (ALL_ID,      new AllHistoryTransaction());
}



// --------------------run--------------------------------------------
/**
 * @brief Starts the process of initializing the store Items, 
 *	  Customers, and Transactions.  
 * 
 * Preconditions: my_item_factory and my_manager have been initialized.
 * 
 * Postconditions: The store Items, Customers, and Transactions have 
 *		   been initialized. 
 */ 
void StoreInitializer::run ()
{
	init_inventory    (INVENTORY_FILE);
	init_transactions (TRANSACTIONS_FILE);
	init_customers    (CUSTOMERS_FILE); 
	// Now pass control to manager to process the transactions.  
	my_manager->processTransactions (); 
}


//---------------------init_customers---------------------------------
/**
 * @brief Initializes the store customers.
 *
 * Preconditions: The file associated with the customers is in the 
 *		  correct directory and contains the correct format 
 *		  according to Lab 4 specs.
 *
 * Postconditions: The customers have been intialized and stored in
 *		   my_manager.
 *
 * @param file The customer file.
 */
void StoreInitializer::init_customers (const char file[])
{
	ifstream infile;
	Customer *cust;
	int cust_id; 
	if (openFile(file, infile)) {
		for (;;) {
			cust = new Customer (infile); 
			if (infile.eof()) {
				delete cust;
				cust = NULL;
				break;	
			}			
			cust_id = cust->getId ();	
			my_manager->addCustomer (cust, cust_id);
		}
	} 
	cust = NULL;
}


//---------------------init_inventory---------------------------------
/**
 * @brief Initializes the store inventory Items.
 *
 * Preconditions: The file associated with the inventory is in the 
 *		  correct directory and contains a correct format 
 *		  according to Lab 4 specs.
 *
 * Postconditions: The inventory Items have been intialized and stored 
 *		   in my_manager.
 * 
 * @param file The inventory file.
 */
void StoreInitializer::init_inventory (const char file[])
{ 
	// The input file stream.
	ifstream infile;

	char item_type;
	Object *item;

	if (openFile (file, infile)) {
		for (;;) {
			// Get item type.
			item_type = infile.peek ();

			// Get item from factory.
			item = my_item_factory->
				getNewObject (infile); 

			// Handle end of file.
			if (infile.eof()) {
				if (item) delete item;
				break;
			} 
			// If valid item type.
			if(item) my_manager->	
				addItem(item, item_type);	
		} 
	}
	item = NULL;
}


//---------------------init_transactions------------------------------
/**
 * @brief Initializes the store pending transactions.
 *
 * Preconditions: The file associated with the transactions is in the 
 *		  correct directory and contains a correct format 
 *		  according to Lab 4 specs.
 *
 * Postconditions: The transactions have been intialized and stored in
 * 	 	   my_manager.
 * 	
 * @param file The transactions file.
 */
void StoreInitializer::init_transactions (const char file[])
{
	// The input file stream.
	ifstream infile;

	Object *obj = NULL;
	Object *tem = NULL;
	if (openFile (file, infile)) {
		for (;;) {
			// Get item from factory.
			obj = my_transaction_factory-> 
				getNewObject (infile); 

			// Handle end of file.
			if (infile.eof()) {
				if (obj) delete obj;
				break;
			} 

			// If valid item type.
			if(obj) {
				// Check for processable transaction.	
				tem = my_item_factory->		
					getNewObject (infile);		

				if (tem) { // Link item in.  
					try {
					Processable *cast = 
					dynamic_cast<Processable *>(obj);
					Item *pt = dynamic_cast<Item *> (tem);
					cast->setItem (pt);	
					cast = NULL;
					} catch (exception &e) {
						cout << "Exception: "
					 	<< e.what () << endl;	
					} 
				} 
				my_manager->addTransaction(obj);	
			}
		}
	}
	obj = NULL;
	tem = NULL;
}


//---------------------openFile---------------------------------------
/**
 * @brief A helper method that opens the file associated with the 
 *	  provided string.
 *
 * Preconditions: The provided file string is a valid directory.
 * 
 * Postconditions: If the file is successfully opened true is 
 *	 	   returned, false otherwise.
 *
 * @param file The file to open.
 * @param infile The file stream.
 * @return True if opened, false otherwise.
 */
bool StoreInitializer::openFile (const char *file, 
					ifstream &infile) 
{
	// See if the file opens.
	infile.open(file);
	if (!infile) {
		cout << FILE_O_ERROR << file << endl;
		return false;
	}
	return true;	
}

