/*
 * @file item_factory.h 
 * 
 * @brief A class to represent a ItemFactory. The ItemFactory 
 *	  decouples the abstraction of what derived types of Items 
 *	  are instantiated. A hash table is used to map a key  
 *	  to its respected derived type of Item.
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
 * 	- Allows adding a derived type of Item to the factory.
 *	- Allows getting a new instance of a derived type of Item
 *	  from the factory.
 * Assumptions:
 *	- When an Item is added to the factory the factory takes 
 * 	  ownership of that object.
 * 	- When getNewItem returns a pointer to a new Item the
 *	  client takes ownership of the object.
 * 	- The file stream used to create a new Item is open and 
 *	  contains correct format according to lab 4 specs.
 *	- The first character in the file is the type of Item to 
 * 	  instantiate. 
 *	- The second parameter is the number of the Items, which 
 *	  will be set to the count reference paramater of getItem. 
 */
//--------------------------------------------------------------------

#ifndef ITEM_FACTORY_H
#define ITEM_FACTORY_h

#include <fstream>
#include <iostream>
#include <string>
#include "hash_table.h"
#include "item.h"
#include "classical.h"
#include "rock.h"
#include "dvd.h"

/**
 * @namespace std
 */
using namespace std;

/**
 * @class ItemFactory
 */
class ItemFactory {

/**
 * @public
 */
public:

	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a ItemFactory with default values.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This ItemFactory was instantiated with 
	 *		   default values.
	 */
	ItemFactory ();
	 

	//---------------------Copy-Constructor-----------------------
	/**
	 * @brief Copies the other factory into this.
	 * 
	 * Preconditions: The other factory is non-NULL.
	 * 
	 * Postconditions: The other factory was copied into this.
	 *
	 * @param other The other to copy into this.
	 */
	ItemFactory (const ItemFactory &other);


	//---------------------Destructor-----------------------------
	/**
	 * @brief Deletes all dynamical memory obtained by this 
	 *	  ItemFactory.
	 *
	 * Preconditions: None.
	 *
 	 * Postconditions: my_items was been initialized.
	 */
	~ItemFactory ();


	//---------------------addItem--------------------------------
	/**
	 * @brief Adds the Item and its'key to the factory.
	 *
	 * Preconditions: The key and value non-NULL.
 	 *
 	 * Postconditions: The Item and its' key has been added to the
	 *		   factory.
	 * 
	 * @param key The key associated with the Item.
	 * @param value The Item to add to the factory.
	 */
	void addItem (const string key, const Item *value);


	//---------------------getNewItem-----------------------------
	/**
	 * @brief Returns a new instance of a derived type of Item.
	 *	  Uses the file to determine which type of object
	 *	  to instantiate.
	 *
 	 * Preconditions: The Item object has a getNewInstance method. 
	 *
	 * Postconditions: A pointer to a new Item object was 
	 *		   returned.
	 *
	 * @param input The input stream to extract from.
	 * @param count The number of items.
 	 * @return Returns a pointer to a new Item object.
	 */
	Item * getNewItem (ifstream &input, int &count) const;	


/**
 * @private 
 */
private:

	/**
	 * @brief The hashtable of different derived types of Item.
	 */	
	HashTable<Item> *my_items; 
};
#endif /* ITEM_FACTORY_H */

