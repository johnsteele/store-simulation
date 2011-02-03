/**
 * @file transaction.h 
 * 
 * @brief  A class to represent a base class of Transaction. 
 *	   A Transaction has a type. 
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
 *	- Allows printing a  Transaction.
 *	- Allows getting the Transaction type. 
 * 	- Allows creating a  Transaction using a specified file.  
 *	- Allows clients to  compare Transaction for equality.
 * 	- Allows clients to  compare Transaction for less than value.
 *	- Allows clients to  display a Transaction using <<. 
 * Assumptions:
 * 	- All derived classes of Item implement getNewInstance, and 
 *	  within the method return a dynamically allocated object of
 *	  the derived type. 
 *	- The file stream passed to createNewInstance is open and 
 *	  constains correct format according to Lab 4 specifications.  
 */
//--------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "object.h" 

/** 
 * @class Transaction
 */
class Transaction : public Object {

/**
 * @public
 */
public:

	//---------------------Default-Constructor--------------------
	/**
	 * @brief Creates a Transaction with a default type.
	 * 
 	 * Preconditions: None.	
	 *
 	 * Postconditions: my_type was set to default value. 
	 */
	Transaction ();


	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a Transaction object with the specified 
	 *	  type.
	 * 
 	 * Preconditions: None. 
	 *
 	 * Postconditions: my_type was set to the type.
 	 *
	 * @param type The type of transaction.
	 */
	Transaction (char type);

	
	//---------------------Destructor-----------------------------
	/**
	 * @brief Deletes all dyncamic memory obtained by this 	
 	 *	  Transaction.
	 * 
 	 * Preconditions: None. 
	 *
 	 * Postconditions: Recources have been released. 
	 */
	virtual ~Transaction ();


	//---------------------print----------------------------------
	/**
	 * @brief Prints this transaction's type.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This transaction type was printed to the
	 *		   standard output stream.  
	 */
	virtual void print () const;


	//---------------------getType--------------------------------
	/**
	 * @brief Retuns the transaction type.	
 	 *
 	 * Preconditions: my_type is set to the transaction type.
	 *
	 * Postconditions: my_type is returned.
	 *
	 * @return The Transaction type is returned.	
	 */
	char getType () const;


	//---------------------getNewInstance-------------------------
	/**
	 * @brief Retuns a pointer to a new instance of the derived
 	 *	  Transaction. The data of the new object will be set
  	 *	  using the provided file stream.
	 *	
 	 * Preconditions: The file stream is open and correctly 
	 *		  formatted according to Lab 4 specs.  	
	 *
	 * Postconditions: A new object of the derived type was 
	 *		   created using the provided file to set 
	 *		   its data. A pointer to the object was then
	 *		   returned.
	 *
	 * @param input The input stream to extract from.
	 * @return A pointer to a  new instance of the derived
	 *	   Transaction.
	 */
	virtual Transaction * getNewInstance 
					(ifstream &input) const = 0;


	//---------------------operator<------------------------------
	/**
	 * @brief Compares this Object with the_other for less than 
	 *	  value.
	 *
	 * Preconditions: The data members of this Object have been 
	 *	  	  initialized.
 	 *
	 * Prostconditions: Returned true if this Object was less than
	 *		    the_other.
	 *	 
 	 * @param the_other The other Object to compare with this 
 	 *	            Object. 
	 * @return True if this Object is less than the_other, 
	 *	   false otherwise. 
 	 */
	virtual bool operator< (const Object &the_other) const;


	//---------------------operator==-----------------------------
	/**
	 * @brief Compares this Object with the_other Object. 
	 *
	 * Preconditions: The data members of this Object have been 
	 *		  initialized.
	 *
	 * Postconditions: Returned true if this Object was equal to 
	 *		   the_other.
	 *
	 * @param the_other The other Object to compare with this
	 *		    Object.
	 * @return True if the_other is equal to this Object, 
	 *	   false otherwise.
 	 */
	virtual bool operator== (const Object &the_other) const; 

/**
 * @private
 */
private:

	/**
 	 * @brief The type of transaction. 
	 */
	char my_type; 
};
#endif /* TRANSACTION_H */

