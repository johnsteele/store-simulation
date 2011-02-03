/*
 * @file object_factory.h 
 * 
 * @brief A class to represent a ObjectFactory. The ObjectFactory 
 *	  decouples the abstraction of what derived types of Objects 
 *	  are instantiated. A hash table is used to map a key  
 *	  to its respected derived type of Object.
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
 * 	- Allows adding a derived type of Object to the factory.
 *	- Allows getting a new instance of a derived type of Object 
 *	  from the factory.
 * Assumptions:
 *	- When an Object is added to the factory the factory takes 
 * 	  ownership of that object.
 * 	- When getNewItem returns a pointer to a new Object the
 *	  client takes ownership of the object.
 * 	- The file stream used to create a new Object is open and 
 *	  contains correct format according to lab 4 specs.
 *	- The first character in the file is the type of Object to 
 * 	  instantiate. 
 *	- The second parameter is the number of the Objects, which 
 *	  will be set to the count reference paramater of getObject. 
 */
//--------------------------------------------------------------------

#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_h

#include <fstream>
#include <iostream>
#include <string>
#include "hash_table.h"
#include <vector>
#include <cctype>

/**
 * @namespace std
 */
using namespace std; 

/**
 * @class ObjectFactory
 */
class ObjectFactory {

/**
 * @public
 */
public:

	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a ObjectFactory with default values.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This ObjectFactory was instantiated with 
	 *		   default values.
	 */
	ObjectFactory ();
	
 
	//---------------------Destructor-----------------------------
	/**
	 * @brief Deletes all dynamical memory obtained by this 
	 *	  ObjectFactory.
	 *
	 * Preconditions: None.
	 *
 	 * Postconditions: my_objects and my_table have been deleted.
	 */
	~ObjectFactory ();


	//---------------------addObject------------------------------
	/**
	 * @brief Adds the Object and its'key to the factory. The 
 	 *	  factory takes ownership of the object.
	 *
	 * Preconditions: The value is non-NULL.
 	 *
 	 * Postconditions: The Object and its' key have been added to
  	 *		   the factory.
	 * 
	 * @param key The key associated with the Object.
	 * @param value The Object to add to the factory.
	 */
	void addObject (char key, Object *value);


	//---------------------getNewObject---------------------------
	/**
	 * @brief Returns a new instance of a derived type of Object.
	 *	  Uses the file to determine which type of object
	 *	  to instantiate.
	 *
 	 * Preconditions: The Object class has a getNewInstance 
 	 *		  method. 
	 *
	 * Postconditions: A pointer to a new Object was returned.
	 *
	 * @param input The input stream to extract from.
 	 * @return Returns a pointer to a new object.
	 */
	Object * getNewObject (ifstream &input) const;	

/**
 * @private 
 */
private:

	/**
	 * @brief The look-up hashtable for objects.
	 */	
	HashTable *my_table; 

	/**
	 * @brief The list of objects in the factory.
	 */
	vector<Object *> *my_objects;
};
#endif /* OBJECT_FACTORY_H */

