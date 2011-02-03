/*
 * @file rock.h 
 * 
 * @brief This class represents a Rock item. It is a derived type of
 * 	  Item. 
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
 * 	- Allows clients to get a pointer to a new instance of a 
 *	  Rock by calling getNewInstance.
 *	- Allows clients to compare Rock Items for equality.
 *	- Allows clients to compare Rock Items for less than value.
 *	- Allows clients to print the Rock Item. 
 *      - Allows clients to clone a Rock Item. 
 * Assumptions:
 * 	- The file stream is open and correctly formatted according to
 *	  Lab 4 specifications. 
 */
//--------------------------------------------------------------------

#ifndef ROCK_H
#define ROCK_H

#include "item.h"

/**
 * @class Rock
 */
class Rock: public Item {

/**
 * @public
 */
public:

	//---------------------Default Constructor--------------------
	/**
	 * @brief Create a Rock object with default values. 
	 *
	 * Preconditions: None.
	 *	
 	 * Postconditions: This Rock Item was instantiated with 
	 *		   default values. 
	 */
	Rock ();


	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a Rock object with the specified 
	 *	  values.
	 *
	 * Preconditions: None.
	 * 
 	 * Postconditions: The Item super class constructor was called
 	 *		   with the specified values.
	 *
	 * @param type  The type.
	 * @param name  The name of the Rock.
	 * @param title The title of the Rock. 
	 * @param year  The year of the Rock.
	 * @param count The occurence count of the Rock Item.
	 */
	Rock (char type, string name, string title, 
					int year, int count);


	//---------------------Destructor-----------------------------
	/**
	 * @brief Deletes dynamically allocated memory.
	 *
	 * Preconditions: None.
	 *	
 	 * Postconditions: All resources have been released. 
	 */
	virtual ~Rock ();

	
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
	 * 
	 * @param output The output stream. 
	 */
	virtual	void print (ostream &output) const;


	//---------------------getNewInstance-------------------------
	/**
	 * @brief Retuns a pointer to a new Rock object. 
	 *	  The objects' data will be set using the provided
 	 *	  file stream.
	 *	
 	 * Preconditions: The file stream is open and correctly 
	 *	 	  formatted according to Lab 4 specs.
	 *	
	 * Postconditions: A new Rock object was created using
	 *		   the provided file stream, and a pointer
	 *		   to it is returned. 
	 *
	 * @param input The input stream to extract from.
	 * @return Returns a pointer to a new instance of a Rock.
	 */
	virtual Rock * getNewInstance (ifstream &input) const;


	//---------------------clone----------------------------------
	/**
	 * @brief Clones this Rock.
	 * 
	 * Preconditions: None.
	 * 
 	 * Postconditions: A pointer to a Rock is returned.
	 * 
	 * @return The pointer to the cloned object.
	 */
	virtual Rock * clone () const;

	//---------------------operator<------------------------------
	/**
	 * @brief Compares this Rock Item with the_other for less 
	 *	  than value. Comparisons are first made by the
	 *	  artist name, then by year, then by title.
	 *
	 * Preconditions: The data members of the base class have 
	 *		  been initialized, and accessor methods are 	
 	 *		  available from the base class to the members 
	 *		  needed for comparisons.
 	 *
	 * Prostconditions: Returns true if this Rock Item is less
	 *		    than the_other.
	 *	 
 	 * @param the_other The other Rock Item to compare with. 
	 * @return Returns true if this Rock Item is less than 
	 *	   the_other, false otherwise. 
 	 */
	virtual bool operator< (const Object &the_other) const; 


	//---------------------operator==-----------------------------
	/**
	 * @brief Compares this Rock Item with the_other Rock Item. 
	 *
	 * Preconditions: The data members of the base class have
 	 *		  been initialized, and accessor methods are
	 *		  available from the base class to the members
	 *		  needed for comparisons.
	 *
	 * Postconditions: Returns true if this Rock Item is equal
	 *		   to the_other.  
	 *
	 * @param the_other The other Rock Item to compare with this 
	 *		    Rock Item.
	 * @return Returns true if the_other is equal to this, false
	 *		   otherwise.
 	 */
	virtual bool operator== (const Object &the_other) const; 
};
#endif /* ROCK_H */

