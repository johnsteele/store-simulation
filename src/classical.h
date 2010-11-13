/*
 * @file classical.h 
 * 
 * @brief This class represents a Classical. It is a derived type of
 *	  CD.
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
 * 	- Allows clients to create a new instance of Classical by 
 *	  by calling getNewInstance. getNewInstance will return a 
 * 	  pointer to a new Classical object with its data set using
 *	  the provided file stream.
 * 
 * Assumptions:
 * 	- The file stream is open and correctly formatted according
 *	  to Lab 4 specifications. 
 */
//--------------------------------------------------------------------

#ifndef CLASSICAL_H
#define CLASSICAL_H

#include "cd.h"

/**
 * @class Classical
 */
class Classical: public CD {

/**
 * @public
 */
public:

	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a Classical object with default values.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This Classical object was instantiated with
	 *		   default values.
 	 */
	Classical ();


	//----------------------------Destructor----------------------
	/**
	 * @brief Deletes all dynamic memory owned by this Classical
	 *	  object.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: All dynamic memory has been deleted.
	 */
	virtual ~Classical (); 


	//----------------------------getNewInstance------------------
	/**
	 * @brief Returns a pointer to a new Classical object with its
	 *	  data set using the provided file stream.
	 *
	 * Preconditions: The file stream is open and correctly 
	 *		  formatted according to Lab 4 specifications.
	 *
	 * Postconditions: A pointer to a new Classical object is 
	 *		   returned. The data of the object was set
	 *		   using the provided file stream. 
	 */
	virtual Classical * getNewInstance (ifstream &) const;

};
#endif /* CLASSICAL_H */
 
