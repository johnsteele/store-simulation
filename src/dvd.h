/*
 * @file dvd.h 
 * 
 * @brief This class represents a DVD. A DVD is a derived type of
 *	  of Item.  
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
 * 	- Allows clients to create a new instance of a DVD by calling
 *	  getNewInstance. getNewInstance will return a pointer to a 
 *	  newly created DVD object. The objects data will be set 
 *	  using the provided file stream.
 * 
 * Assumptions:
 * 	- The file stream passed to createNewInstance is open and 
 *	  contains correct format according to Lab 4 specifications. 
 */
//--------------------------------------------------------------------

#ifndef DVD_H
#define DVD_H

#include "item.h"

/**
 * @class DVD
 */
class DVD: public Item {

/**
 * @public 
 */
public:

	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a DVD object with default values.	 	
 	 */
	DVD ();
	
	//---------------------Destructor-----------------------------
	/**
	 * @brief Deletes all dynamically allocated memory.
	 */
	virtual ~DVD ();
	

	//---------------------getNewInstance-------------------------
	/**
	 * @brief Returns a pointer to a new instance of a DVD object.
	 *	  The data of the object will be set using the 
	 *	  provided file stream.
	 *
	 * Preconditions: The file stream is open and correctly
 	 *		  formatted according to Lab 4 specifications.
	 *
	 * Postconditions: A pointer to a new DVD obect is returned.
	 *		   The data of the object is set using the
 	 *		   provided file stream.
	 *
	 * @return Returns a pointer to a new DVD object.
	 */
	virtual DVD * getNewInstance (ifstream &) const; 


/**
 * @private
 */
private:

	/**
	 * @brief The composer of this DVD. 
	 */
	char *my_composer;
};
#endif /* DVD_H */

