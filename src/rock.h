/*
 * @file rock.h 
 * 
 * @brief This class represents a Rock cd. It is a derived type of
 * 	  CD. 
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
 * 	- Allows clients to create a new instance of a Rock cd by 
 *	  calling getNewInstance. getNewInstance will return a pointer
 * 	  to a newly created Rock cd object. The objects data will be
 *	  set using the provided file stream.
 * 
 * Assumptions:
 * 	- The file stream is open and correctly formatted according to
 *	  Lab 4 specifications. 
 */
//--------------------------------------------------------------------

#ifndef ROCK_H
#define ROCK_H

#include "cd.h"

/**
 * @class Rock
 */
class Rock: public CD {

/**
 * @public
 */
public:

	//---------------------Constructor----------------------------
	/**
 	 * @brief Creates a Rock object with default values.
 	 */
	Rock ();


	//---------------------Destructor-----------------------------
	/**
 	 * @brief Deletes any dynamically allocated memory. 
	 */
	virtual ~Rock ();

	
	//---------------------getNewInstance-------------------------
	/**
	 * @brief Retuns a pointer to a new instance of a Rock object.
	 *	  The data of the object will be set using the 
	 *	  provided file stream.
	 *
	 * Preconditions: The file stream is open and correctly 
	 *		  formatted according to Lab 4 secifications.
	 *	
 	 * Postconditions: A pointer to a new Rock object is returned. 
	 *		   The data of the object is set using the
	 *		   provided file stream.
	 *
	 * @return Returns a pointer to a new Rock object.
	 */
	virtual Rock * getNewInstance (ifstream &) const;

};
#endif /* ROCK_H */

