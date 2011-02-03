/*
 * @file hash_table.cpp
 * 
 * @brief This class implements a hashtable, which maps char keys to 
 *	  values. Any non NULL Objects can be used as a value.
 *
 * @brief CSS 343 - Lab 4
 *
 * @author John Steele  \<steelejr@u.washington.edu\> 
 *  
 * @version 1.0.0
 * @date December 5, 2010
 */ 
//--------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows creating a HashTable with a specified size.
 * 	- Allows adding an key / value pair.
 *	- Allows getting the value of associated with a specific key.
 *	- Allows making the hashtable empty.
 * 
 * Assumptions:
 * 	- The objects stored in the hashtable are non-NULL.
 */
//--------------------------------------------------------------------
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
#include "purchase_transaction.h"

/**
 * @namespace std
 */
using namespace std;

/**
 * @class HashTable
 */
class HashTable {

/**
 * @public 
 */
public:

	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a hashtable with a default capacity.
	 *
	 * Preconditions: None.
	 * 
	 * Postconditions: This hashtable was created with the default
	 *		   size.
	 */
	HashTable ();


	//---------------------put------------------------------------
	/**
	 * @brief Maps the specified key to the specified value in 	
 	 *	  this hashtable. Neither the key or the value can be
	 *	  NULL.
	 *
	 * Preconditions: The key is valid.
	 * 	
 	 * Postconditions: The value was added to this hashtable.
	 * 	
 	 * @param key The hashtable key.
	 * @param value The value to insert.
	 */
	void add (char key, Object *value);

	
	//---------------------get------------------------------------
	/**
	 * @brief Retuns a pointer to the value which the specified
	 *	  key is mapped in this hashtable.
	 *
	 * Preconditions: The key is valid.
	 *
	 * Postconditions: A pointer to the value was returned.
	 *
	 * @param key A key in the hashtable.
	 * @return The value to which the key is mapped in this 
	 *	   hashtable; NULL if the key is not mapped to any 
	 *	   value in this hashtable.
	 */
	Object * get (char key) const; 

/**
 * @private
 */
private:

	//---------------------hashCode-------------------------------
	/**
	 * @brief Returns the hash code for the provided key.
	 * 
	 * Preonditions: None.
	 * 
	 * Postconditions: A hash code was returned.
	 * 
	 * @param key The key to hash.
	 * @return The hash code for the key.
	 */	
	int hashCode (char key) const;


	//---------------------resize---------------------------------
	/**
	 * @brief Creates a bigger array and copies over the data.
	 *
 	 * Preconditions: size is bigger than my_size.
	 * 
	 * Postconditions: my_array has been increased to size, and
 	 * 		   the data has been copied over. 
	 */
	void makeBigger (int size);


	//---------------------init_table-----------------------------
	/**
	 * @brief Initializes the values of the table. 
	 *
	 * Preconditions: my_size is the size of the table array.
	 *
	 * Postconditions: The values of each index have been 
 	 *		   initialized.
	 */
	void init_table();

	/**
	 * @brief The size of the array. 
	 */
	int my_size;
	
	/**
	 * @brief The array of stored objects.
	 */	
	Object **my_array;

	/**
  	 * @brief Default size of table array.
	 */
	const static int DEFAULT_SIZE = 10;
};
#endif

