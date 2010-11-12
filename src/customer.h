/**
 * @file customer.h 
 * 
 * @brief This class represents a Customer. A Customer has an ID,
 * 	  name, and list of Transaction objects. 
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
 * 	- Allows creating a customer and specifying its' ID and name 
 *	  by passing it a file stream.
 *	- Allows adding a Transaction object to the customers' 
 *	  transaction history. 
 * 	- Allows displaying the customers ID and name using <<.
 *	- Allows displaying the customers transaction history.
 * 
 * Assumptions:
 * 	- The file stream that is passed when creating the customers
 *        is open, and it contains a valid format according to the
 *	  Lab 4 specifications.  
 *	- The Transaction object has its operator<< method overridden,
 *	  which is used by this class when displaying the transaction 
 *	  history.
 */
//--------------------------------------------------------------------
 

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <fstream>
#include <iostream>
#include <string.h>
#include <list.h>

/**
 * @namespace STD
 */ 
using namespace std;


/**
 * @class Customer
 */
class Customer {

	//---------------------operator<<-----------------------------
	/**
	 * @brief Overloaded operator<<. Sends the_customers' ID and
	 *	  name to the_output stream.
 	 *	
 	 * @param the_stream The output stream.
	 * @param the_customer The customer who's ID and name is to be
 	 *	  	       sent to the output stream.
	 */
	friend ostream& operator<< (ostream &, const Customer &);

/**
 * @public 
 */
public: 

	//---------------------Constructor----------------------------
	/**
 	 * @brief Creates a Customer object with a NULL name, an ID
 	 * 	  of zero, and an empty list of Transaction objects.
	 *
 	 * Preconditions:  None.
	 * 
 	 * Postconditions: my_name was set to NULL, my_id set to zero
	 *		   and my_transactions set to NULL.
 	 */
	Customer ();

 
	//---------------------Constructor----------------------------
	/**
 	 * @brief Creates a Customer object with its ID and name set
 	 * 	  the values within the provided file stream.
	 *
 	 * Preconditions:  the_stream is open, and contains a valid
	 *	  	   format according to the Lab 4 specs.	
	 *	 	   The characters leading up to the first 
	 *		   comma are set to the ID, and the remaining
	 *		   characters leading up to the end of line
	 *		   are set to the name.
	 * 
 	 * Postconditions: my_id was set to the characters leading up	
	 *		   to the first comma, and my_name was set to
	 *		   the remaining characers on that line.
	 *	
 	 * @param the_stream The stream to extract my_id and my_name.
 	 */
	Customer (ifstream &);


	//---------------------Destructor-----------------------------
	/**
 	 * @brief Deallocates transactions history list and my_name. 
	 *
 	 * Preconditions:  my_transactions points to the first Node 
 	 * 		   in the list of transactions, or NULL if 
	 *	 	   the list is empty. my_name points to a 
	 *	 	   dynamically allocated array.
	 * 
 	 * Postconditions: my_transactions were deleted. my_name was
	 *		   deleted.
 	 */
	~Customer (); 
	

	//---------------------displayHistory-------------------------
	/**
	 * @brief Prints this customers' Transaction objects to the
	 *	  output stream. 
 	 */
	void displayHistory () const;


/**
 * @private
 */
private:

	/**
	 * @brief The customer ID.
	 */	
	int *my_id;	

	/**
 	 * @brief The customer name.
	 */
	char *my_name;
	
	/**
 	 * @brief The Transaction history list.
	 */
	list<Transaction> my_history; 
};
#endif /* CUSTOMER_H */

