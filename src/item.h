/*
 * @file item.h 
 * 
 * @brief An Item is an abstract base class that can be inherited to
 *	  share a common interface type and allow poloymorphic
 *	  behavior of the different Item types. 
 *
 * @brief CSS 343 - Lab 4
 *
 * @author John Steele  \<steelejr@u.washington.edu\> 
 *  
 * @version 1.0.0
 * @date November 11, 2010
 */ 
//--------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows clients to create a new instance of a derived type 
 *	  by calling getNewInstance. 
 * 	- Allows clients to compare Items for equality.
 * 	- Allows clients to compare Items for less than value.
 *	- Allows clients to print the Item.
 * 
 * Assumptions:
 * 	- All derived classes of Item implement getNewInstance, and 
 *	  within the method return a dynamically allocated object of
 *	  the derived type. 
 *	- The file stream passed to createNewInstance is open and 
 *	  constains correct format according to Lab 4 specifications.
 */
//--------------------------------------------------------------------

#ifndef ITEM_H
#define ITEM_H

#include <fstream> 
#include <string>
#include <iostream>

/**
 * @namespace std
 */
using namespace std;

/**
 * @class Item
 */
class Item {

/**
 * @public
 */
public:

	//---------------------Default Constructor--------------------
	/**
 	 * @brief Creates an Item object with default values.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The data members of this Item have been 
	 *		   initialized with default values.
 	 */
	Item ();


	//---------------------Constructor----------------------------
	/**
 	 * @brief Creates an Item object with the specified values.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The data members of this Item have been set
	 *		   to the specified values.
	 *
	 * @param type  The type of Item.
	 * @param name  The name of this Item.
	 * @param title The title of this Item.
	 * @param year  The year of this Item.
 	 */
	Item (char type, string name, string title, int year);


	//---------------------Destructor-----------------------------
	/**
 	 * @brief Deletes all dynamically allocated memory. 
	 *
 	 * Preconditions: my_name and my_title are NULL or point to
	 *		  dynamically allocated data.
	 *
 	 * Postconditions: my_name and my_title have been deleted.
	 */
	virtual ~Item ();

	
	//---------------------getNewInstance-------------------------
	/**
	 * @brief Retuns a pointer to a new instance of the derived
 	 *	  Item. The data of the new object will be set using
 	 *	  the provided file stream.
	 *	
 	 * Preconditions: The file stream is open and correctly 
	 *		  formatted according to Lab 4 specs.  *	
	 * Postconditions: A new object of the derived type is created
	 *		   using the provided file to set its data.	
 	 *		   A pointer to the object is then returned.
	 *
	 * @param intput The input stream to extract from.
	 * @return Returns a pointer to a  new instance of the derived
	 *	   Item.
	 */
	virtual Item * getNewInstance (ifstream &input) const = 0;

	
	//---------------------operator<------------------------------
	/**
	 * @brief Compares this Item with the_other for less than 
	 *	  value.
	 *
	 * Preconditions: The data members of this Item have been 
	 *	  	  initialized.
 	 *
	 * Prostconditions: Returns true if this Item is less than
	 *		    the_other.
	 *	 
 	 * @param the_other The other Item to compare with this Item. 
	 * @return Returns true if this Item is less than the_other, 
	 *	   false otherwise. 
 	 */
	virtual bool operator< (const Item &the_other) const = 0; 


	//---------------------operator==-----------------------------
	/**
	 * @brief Compares this Item with the_other Item. 
	 *
	 * Preconditions: The data members of this Item have been 
	 *		  initialized.
	 *
	 * Postconditions: Returns true if this Item is equal to 
	 *		   the_other.
	 *
	 * @param the_other The other Item to compare with this Item.
	 * @return Returns true if the_other is equal to this Item, 
	 *	   false otherwise.
 	 */
	virtual bool operator== (const Item &the_other) const = 0; 


	//---------------------print----------------------------------
	/** 
	 * @brief Prints the data members of this Item to the output
	 *	  stream.
	 * 
	 * Preconditions: my_name and my_title have a terminating 
	 *		  character at the end of their strings.
	 *
	 * Postconditions: my_type, my_count, my_name, my_title, 
	 *		   and my_year have been printed to the 
	 *		   output stream.
 	 */
	virtual void print () const; 


/**
 * @protected
 */
protected:
	
	//---------------------getName--------------------------------
	/**
	 * @brief An accessor method for derived classes to use for 
	 * 	  comparisons.
	 *
	 * Preconditions: my_name is initialized.
	 *
	 * Postconditions: my_name is returned.
	 *
	 * @return Returns the name of this Item.	
	 */
	const string getName () const;

	
	//---------------------getTitle-------------------------------
	/**
	 * @brief An accessor method for derived classe to use for 
	 *	  comparisons.
 	 *
	 * Preconditions: my_title is initialized.
	 *
 	 * Postconditions: my_title is returned.
	 * 
	 * @return Returns the title of this Item.
	 */	
	const string getTitle () const;


	//---------------------getYear--------------------------------
	/**
	 * @brief An accessor method for derived classe to use for 
	 *	  comparisons.
 	 *
	 * Preconditions: my_year is initialized.
	 *
 	 * Postconditions: my_year is returned.
	 * 
	 * @return Returns the year of this Item.
	 */	
	int getYear () const;


/**
 * @private
 */
private:

-	/**
	 * @brief The type of Item.
	 */
	char my_type;

	/**
 	 * @brief The name or director of this Item.
	 */
	string my_name;	

	/**
	 * @brief The title of this Item.
	 */
	string my_title;

	/**
	 * @brief The year of this Item.
	 */	
	int my_year;
  
};
#endif /* ITEM_H */

