/**
 * @file customer.cpp 
 * 
 * @brief This class represents a Customer. A Customer has an ID,
 * 	  name, and a list of Transaction objects. 
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
 * 	- Allows creating a customer and specifying their ID and name.
 *	- Allows adding a Transaction object to the customers' 
 *	  transaction history. 
 *	- Allows clients to << a Customer.
 *      - Allows clients to clone a Customer.
 *	- Allows getting a customer ID.
 * Assumptions:
 * 	- The file stream that is passed when creating the customers
 *        is open, and it contains a valid format according to the
 *	  Lab 4 specifications.  
 *	- The Transaction object has print method which is used by 
 *	  this class when displaying the transaction history.
 *	- When adding a Transaction to a customers' transaction list
 *	  the customer takes ownership of the object.
 */
//--------------------------------------------------------------------

#include "customer.h"


//---------------------Constructor------------------------------------
/**
 * @brief Creates a Customer object with its' name and ID set to NULL,
 *	  and an empty transaction history list.
 *
 * Preconditions:  None.
 * 
 * Postconditions: my_first, my_name, and my_id have been set to NULL, 
 *		   my_transactions was instantiated.
 */
Customer::Customer () : Object ()
{
	my_name    = ""; 
	my_id      = 0;
	my_history = new vector<Transaction *>();
}


//---------------------Constructor------------------------------------
/**
 * @brief Creates a Customer object with the specified values.
 * 
 * Preconditions: None. 
 * 
 * Postconditions: my_name and my_id have been set to the provided 
 *		   values. 
 * 
 * @param the_id The customer ID.
 * @param the_name The customer name.
 */
Customer::Customer (int the_id, string the_name) : Object ()
{
	my_id      = the_id;
	my_name    = the_name;
	my_history = new vector<Transaction *>();
}

//---------------------Constructor------------------------------------
/**
 * @brief Creates a Customer object using the specified file.
 *
 * Preconditions:  None.
 * 
 * Postconditions: my_name and my_id have been set using the file.
 */
Customer::Customer (ifstream &input)
{
	input >> my_id;
	input.ignore (2);
	getline (input, my_name);	
	my_history = new vector<Transaction *>(); 
}


//---------------------Constructor----------------------------
/**
 * @brief Creates a Customer object with the specified values.
 * 
 * Preconditions: None. 
 * 
 * Postconditions: my_name, my_id, and my_history have been 
 *		   set to the provided values. 
 * 
 * @param the_id   The customer ID.
 * @param the_name The customer name.
 * @param the_hist The history transactions.
 */
Customer::Customer (int the_id, string the_name, 
				vector<Transaction *> *the_hist)
				: Object ()
{
	my_id = the_id;
	my_name = the_name;
	my_history = the_hist;
}


//---------------------Destructor-------------------------------------
/**
 * @brief Deallocates the transaction list and my_name. 
 *
 * Preconditions:  my_transactions points to the list of transactions 
 *		   or NULL. my_id points to a dynamically allocated 
 *		   array. my_name points to a string object. 
 * 
 * Postconditions: my_transactions and my_name were deleted.
 */
Customer::~Customer ()
{
	delete my_history;
	my_history = NULL;
}

	
//---------------------getNewInstance---------------------------------
/**
 * @brief Returns a pointer to a Customer object with its ID and name
 *	  set to the values within the provided file stream.
 *
 * Preconditions:  input is open, and contains a valid format 
 *		   according to the Lab 4 specs. The characters 
 *		   leading up to the first comma are set to the ID, 
 *		   and the remaining characters leading up to the end 
 *		   of line are set to the name. 
 * 
 * Postconditions: my_id was set to the characters leading up to the
 *	           first comma, and my_name was set to the remaining
 *		   characers on that line.
 *	
 * @param input The stream to extract my_id and my_name.
 * @return A pointer to a new instance of a Customer.
 */
Customer * Customer::getNewInstance (ifstream &input) const
{
	int id;
	string name;
	input >> id;
	input.ignore (2);
	getline (input, name); 
	return new Customer (id, name);	
}


//---------------------clone------------------------------------------
/**
 * @brief Returns a pointer to a clone of this Customer. 
 * 
 * Preconditions: None.
 * 
 * Postconditions: A pointer to a cloned Object is returned.
 * 
 * @return The pointer to the cloned object.
 */
Customer * Customer::clone () const
{
	int i;
	Transaction *t;
	vector<Transaction *> *hist = new vector<Transaction *>();

	// First copy the transactions.
	for (i = 0; i < (long)my_history->size(); i++) {
		hist->push_back (my_history->at(i)->clone());
	}
	return new Customer (my_id, my_name, hist);
}


//---------------------print------------------------------------------
/** 
 * @brief Sends the data members of this Customer to the standard 
 *	  output stream.
 * 
 * Preconditions: None.
 *
 * Postconditions: my_id, my_name, and my_history have been sent to 
 *	 	   the output stream. 
 * 
 * @param output The output stream. 
 */
void Customer::print (ostream &output) const
{
	int i;
	output << "Customer Name       :" << my_name << endl;
	output << "Customer ID         :" << my_id << endl;
	output << "Transaction History :" << endl;
	for (i = 0; i < (long)my_history->size(); i++) {
		output << i + 1 << ".) ";	
		output << *my_history->at(i) << endl;
	}
}


//---------------------getId------------------------------------------
/**
 * @brief Returns this customers ID. 
 * 
 * Preconditions: The ID has been set.
 *
 * Postconditions: This customer ID was returned.
 *
 * @return This customer ID.
 */
int Customer::getId () const
{
	return my_id;
}


//---------------------addTransaction---------------------------------
/**
 * @brief Adds a the provided Transaction object to this Customer.
 *
 * Preconditions: None.
 *
 * Postconditions: The Transaction object is added to the end of the 
 *		   Transaction list.
 *	
 * @param transaction The Transaction to add.
 */
void Customer::addTransaction (Transaction *transaction)
{
	if (transaction != NULL) {
		my_history->push_back (transaction);
	}
}

	
//---------------------operator<--------------------------------------
/**
 * @brief Compares this Customer with the_other for less than value. 
 *	  Comparisons are made with first name.
 * 
 * Preconditions: my_name has been initialized.
 *
 * Postconditions: True was returned if this customer was less than 
 *		   the_other.
 *
 * @param the_other The other customer to compare with.
 * @return True if this customer was less than the_other, false 
 *	   otherwise.
 */
bool Customer::operator< (const Object &the_other) const
{
	try {
		const Customer &c = 
			dynamic_cast<const Customer&>(the_other);
		
		return (my_name.compare (c.my_name)<0?true:false);

	} catch (exception &e) {
		cout << "Exception: " << e.what() << endl;
	} 
	return false;
}
	

//---------------------operator==-------------------------------------
/**
 * @brief Compares this Customer with the_other for equality.
 *
 * Preconditions: my_name, my_id, and my_transactions have been 
 *		  initialized.
 * 
 * Postconditions: True was retuned if this is equal to the_other, 
 *		   false otherwise.
 * 
 * @param the_other The other customer to compare with.
 * @return True if equal, false otherwise.
 */
bool Customer::operator== (const Object &the_other) const 
{
	try {
		const Customer &c = 
			dynamic_cast<const Customer&>(the_other);
		
		return (my_name.compare (c.my_name)==0?true:false);

	} catch (exception &e) {
		cout << "Exception: " << e.what() << endl;
	}
	return false; 
}


//---------------------operator<<-------------------------------------
/**
 * @brief Overloaded output operator.
 * 
 * Preconditions customer is not NULL.
 * 
 * Postconditions: my_id, my_name, and  my_transactions have
 *	  	   been sent to the outupt stream.
 * 
 * @param output The output stream.
 * @param customer The customer to output.
 * @return The output sream.
 */
ostream& operator<< (ostream &output, const Customer &customer)
{
	customer.print (output);
	return output;
}

