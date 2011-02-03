/**
 * @file store_initializer.cpp 
 * 
 * @brief StoreInitializer class initializes the stores' Customers, 
 * 	  Transactions, and Inventory. 
 *
 *
 * @brief StoreInitializer has-a ItemFactory and a StoreManager.
 *	  The ItemFactory is used to instantiate the correct Item 
 *	  inventory objects. After each Customer, Transaction, 
 *	  and Item object are created they are added to the 
 *	  StoreManager. 
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
 * @brief Creates a StoreInitializer object with a NULL StoreManager 
 *	  and ItemFactory. 
 * 	
 * Preconditions: None.
 *
 * Postconditions: my_manager and my_factory have been set to NULL.
 */
StoreInitializer::StoreInitializer ()
{
	
}

	
//---------------------Copy-Constructor-------------------------------
/**
 * @brief Copies the other StoreInitializer into this.
 * 
 * Preconditions: The other StroreInitializer is non-NULL.
 * 
 * Postconditions: The other StoreInitializer was copied into this.
 *
 * @param other The other to copy into this.
 */
StoreInitializer::StoreInitializer (const StoreInitializer &other)
{

	
}


// --------------------Destructor-------------------------------------
/**
 * @brief Deallocates my_manager and my_factory and sets their 
 *	  pointers to NULL.
 *
 * Preconditions: my_manager and my_factory point to dynamically 
 *		  allocated objects or NULL. 
 *
 * Postconditions: my_manager and my_factory were deallocated and set
 *		   to NULL.
 */ 
StoreInitializer::~StoreInitializer ()
{

}


// --------------------run--------------------------------------------
/**
 * @brief Starts the process of initializing the store Items, 
 *	  Customers, and Transactions.  
 * 
 * Preconditions: my_factory and my_manager have been initialized.
 * 
 * Postconditions: The store Items, Customers, and Transactions have 
 *		   been initialized. 
 */ 
void StoreInitializer::run ()
{
	Item *tem; 

	cout << "StoreInitializer::run()" << endl;
	
/*	init_factory(); */
	init_customers(CUSTOMERS);
/*	init_transactions(TRANSACTIONS);	
	init_inventory(INVENTORY);
	my_manager->processTransactions();
*/
}


//---------------------init_factory-----------------------------------
/**
 * @brief Sets up the ItemFactory with the different types of Items in
 *	  the store.
 *
 * Preconditions: my_factory has already been instantiated.
 *
 * Postconditions: my_factory constains the types of Items used in the 
 *		   store.
 */
void StoreInitializer::init_factory () 
{
	cout << "StoreInitializer::init_factory()" << endl;

	my_factory->add('R' - '0', new Rock());
	my_factory->add('C', new Classical());
	my_factory->add('D', new DVD());

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
	cout << "StoreInitializer::init_customer()" << endl;
	ifstream infile;
	Customer *cust;
	if (openFile(file, infile)) {
		cout << file << " Open." << endl;	
		for (;;) {
			cust = new Customer (infile);
			if (infile.eof()) {
				delete cust;
				cust = NULL;
				break;	
			}				
			break;
		//	my_manager->addCustomer (cust);
		}
		closeFile (file, infile);
	} 
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
	cout << "StoreInitializer::init_inventory()" << endl;
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
	cout << "StoreInitializer::init_transactions()" << endl;
	/*
	 *
	 */
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
bool StoreInitializer::openFile (const char file[], 
					ifstream &infile) const
{
	cout << "StoreInitializer::openFile()" << endl;
}


//---------------------closeFile--------------------------------------
/**
 * @brief A helper method that closes the file associated with the
 *	  provided string.
 *
 * Preconditions: The provided file string is a valid directory.
 * 
 * Postconditions: If the file is successfully closed true is 
 *		   returned, false otherwise.
 *
 * @param file The file to close.
 * @param infile The file stream.
 * @return True if closed, false otherwise.
 */
bool StoreInitializer::closeFile (const char file[], ifstream &infile) const
{
	cout << "StoreInitiailizer::closeFile()" << endl;
}

