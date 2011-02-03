/*
 * @file hash_table.h 
 * 
 * @brief This class implements a hashtable, which maps keys to 
 *	  values. Integers can be used as a key, and any non-NULL
 *	  objects can be used as a value.
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

/**
 * @namespace std
 */
using namespace std;

/**
 * @class HashTable
 */
template <typename NodeData>
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


	//---------------------Copy-Constructor-----------------------
	/**
	 * @brief Copies the other hash table into this.
	 *
	 * Preconditions: The other hash table is not NULL.
	 * 
	 * Postconditions: The other was copied into this.
	 *
	 * @param other The other hash table to copy.
	 */
	HashTable (const HashTable &other);


	//---------------------Destructor-----------------------------
	/**
	 * @brief Deallocates all dynamic memory obtained by this
	 * 	  hashtable.
	 *	
 	 * Preconditions: makeEmpty is implemented.
	 *	
	 * Postconditions: All dynamic memory has been released.
	 */	
	~HashTable ();


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
	void add (int key, const NodeData *value);

	
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
	NodeData * get (int key) const;

	
	//---------------------makeEmpty------------------------------
	/**
	 * @brief Empties this hashtable by deleting all the hashtable 
	 *	  entries and their associated NodeData objects.
	 *
	 * Preconditions: If an index does not contain a data it is 
	 *		  set to NULL.
	 * 
	 * Postconditions: All table entries have been deleted.
	 */
	void makeEmpty ();


/**
 * @private
 */
private:

	//---------------------hashCode-------------------------------
	/**
	 * @brief Returns the hash code index for the specified key.
	 *
	 * Preconditions: The key exists within the table.
	 *
	 * Postconditions: The index of the hashed key is returned.
	 *
	 * @param key The key to hash for the index.
	 * @return The index of the hashtable for the key.
	 */
	int hashCode (int key) const;


	//---------------------findPosition---------------------------
	/**
	 * @brief A helper method that performs the quadradic proping 
	 * 	  resolution. 
 	 * 
	 * Preconditions: The hash function is implemented.
	 * 
	 * Postconditions: Returns the position that the provided 
	 *		   character hashes to.
	 * 
	 * @param key The key to find the position for.
	 * @return The index of the array the key hashed to.
	 */
	int findPosition (int key) const;


	//---------------------rehash---------------------------------
	/**
	 * @brief Increases the capacity of and internally reorganizes
	 *	  this hashtable, in order to accomodate and access
	 *	  its entries more efficiently
	 *
	 * Preconditions: None.
	 * 
	 * Postconditions: The hashtable has been doubled in size and
	 *		   the keys have been rehashed.
	 */
	void rehash ();


	//---------------------getPrime-------------------------------
	/**
	 * @brief Returns a prime number of that is at least as large
	 *	  as the provided integer.
	 *
	 * Preconditions: The provided integer is greater that zero.
	 *
	 * Postconditions: The prime number is returned.
	 * 
	 * @param The value to use as the lowest value.
	 * @return The prime number.
	 */
	int getPrime (int n) const;


	//---------------------isActive-------------------------------
	/**
	 * @brief Checks if the provided index of the hashtable array
	 *	  exists and is active.
	 *
	 * Preconditions: All active indexes of the hashtable must
	 *		  set the their info to ACTIVE if active.
	 *
	 * Postconditions: Returns true if the index is active.
	 *
	 * @param position The position of the hashtable to check.
	 * @return True if active, false otherwise.
	 */
	bool isActive (int position) const;


	/**
	 * @brief The status of an index of the hashtable. 
	 */	
	enum EntryType { ACTIVE, EMPTY, DELETED };

	
	/**
	 * @brief A hashtable entry structure.
	 */
	struct HashEntry 
	{
		NodeData *element;
	 	EntryType info;
	};


	/**
	 * @brief The hashtable array.
	 */	
	vector<HashEntry> my_array;

	/**
	 * @brief The number of occupied indexes in the hashtable.
	 */
	int my_occupied;	
};
#endif /* HASH_TABLE_H */

