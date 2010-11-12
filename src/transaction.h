/**
 * @file transaction.h 
 * 
 * @brief  A class to represent a Transaction. A transaction has a 
 * 	   type. Depending on the type of the transaction it might 
 * 	   also have a customer ID, and an associated Item.
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
 * 	- Allows creating a Transaction with its values set to from 
 *	  the a provided file stream.
 * 
 * Assumptions:
 * 	- The file stream passed to the constructor has correct format
 *	  according to the Lab 4 specifications.  
 *	- A Item is only needed if the transaction type is not A, I, 
 *	  or H. 
 */
//--------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <fstream.h>
#include <string.h>

/**
 * @namespace std 
 */
using namespace std;


/** 
 * @class Transaction
 */
class Transaction {

/**
 * @public
 */
public:

	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a default Transaction object with my_type
	 *	  set to zero, my_customer_id set to NULL, an my_item 
	 *	  set to NULL.
	 * 
 	 * Preconditions: None.	
	 *
 	 * Postconditions: my_type is zero, my_customer_id is NULL, 
	 * 		   and my_item is NULL.
	 */
	Transaction ();


	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a Transaction object with its values set 
	 * 	  from the provided file.
	 * 
 	 * Preconditions: the_stream is open and is correctly 
	 *		  formatted according to Lab 4 specs. 	
	 *
 	 * Postconditions: my_type is set to the first character 
	 *		   leading up to the first comma. If there is
	 *	 	   not a comma after the first character then 	
	 *	 	   my_customer_id and my_item are set to NULL.
	 *	 	   If there is a comma my_customer_id is set to 
	 *		   the characters leading up to the scond comma.
	 *		   If there is not a second comma then my_item 
	 *		   is set to NULL. If there is a second comma
	 *		   then an Item object is created using the 
	 *		   remaining characters. 
 	 *
	 * @param the_stream The input stream to load the data from.
	 */
	Transaction (istream &);

	
	//---------------------destructor-----------------------------
	/**
	 * @brief 
	 * 
 	 * Preconditions: None.	
	 *
 	 * Postconditions: my_item has been deleted. 
	 */
	~Transaction ();


/**
 * @private
 */
private:

	/**
 	 * @brief The type of transaction. 
	 */
	char my_type;


	/**
	 * @brief The customers' ID associated with this Tranaction.
	 *
	 * @todo  This might be bad design having this since some
	 *  	  transactions don't have customer ID. Sure we could 
	 *	  just set it to NULL, which is our plan, but is that
	 *	  good practice?
	 */	
	int *my_customer_id;	

 
	/**
 	 * @brief A pointer to the Item associated with this
	 *	  transaction.
 	 *	 
	 * @todo Again, this might be bad design since not every 
	 *	 Transaction has an associated Item. 
 	 *	
 	 * @example If (my_type == 'H' || my_type == 'I' || 
	 *	         my_type == 'A') we will not need a 
	 *	    Item object for these transactions, so it 
	 *	    might be bad design to have this, for now
	 *	    the plan is to set it NULL if not used.
	 */
	Item *my_item;
};
#endif /* TRANSACTION_H */

