/*
 * @file item.h 
 * 
 * @brief An Item is an abstract base class that can be inherited to
 *	  share a common interface type and allow poloymorphic
 *	  behavior of the different Item types. This class cannot be
 *	  instantiated.
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
 *	  by calling getNewInstance. getNewInstance will be 
 *	  called on the derived type, thus allowing dynamic binding.
 *	  The data of the new object will be set using the provided
 *	  file stream.
 * 
 * Assumptions:
 * 	- All derived types of Item implement getNewInstance, and 
 *	  within the method return a dynamically allocated object of
 *	  the derived type. The data of the new object will be set
 *	  using the provided file stream, so it must be open and 
 *	  correctly formatted according to Lab 4 specifications.
 */
//--------------------------------------------------------------------

#ifndef ITEM_H
#define ITEM_H

#include <fstream> 
#include <iostream>

/**
 * @namespace std
 */
using namespace std;

/**
 * @class Item
 */
class Item {

	//---------------------operator<<-----------------------------
	/**
	 * @brief Overloaded operator<<. Sends the data of this Item
 	 *	  to the provided output stream. 
 	 */
	friend ostream& operator<< (ostream &, const Item &); 

/**
 * @public
 */
public:

	//---------------------Constructor----------------------------
	/**
 	 * @brief Creates an Item object with default values.
 	 */
	Item ();


	//---------------------Destructor-----------------------------
	/**
 	 * @brief Deletes any dynamically allocated memory. 
	 */
	virtual ~Item ();

	
	//---------------------getNewInstance-------------------------
	/**
	 * @brief Retuns a pointer to a new instance of the derived
 	 *	  Item. The data of the new object will be set using
 	 *	  the provided file stream.
	 *	
 	 * Preconditions: The file stream is open and correctly 
	 *		  formatted according to Lab 4 specs.
	 *	
	 * Postconditions: A new object of the derived type is created
	 *		   using the provided file to set its data.	
 	 *		   A pointer to the object is then returned.
	 *
	 * @return Returns a pointer to a  new instance of the derived
	 *	   Item.
	 */
	virtual Item * getNewInstance (ifstream &) const = 0;
	
/**
 * @private
 */
private:

	/**
	 * @brief The type of Item.
	 */
	char my_type;

	/**
	 * @brief The number of Items.
	 */
	int my_count;

	/**
 	 * @brief The name or director of this Item.
	 */
	char *my_name;	

	/**
	 * @brief The title of this Item.
	 */
	char *my_title;

	/**
	 * @brief The year of this Item.
	 */	
	int my_year;
};
#endif /* ITEM_H */

