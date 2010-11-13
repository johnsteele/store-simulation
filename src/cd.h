/*
 * @file cd.h 
 * 
 * @brief This clas represents a CD. It is a derived type of Item, 
 *	  and it is also an abstract class. It serves as a common 
 *	  interface for all CD types. 
 *
 * @brief CSS 343 - Lab 4
 *
 * @author John Steele  \<steelejr@u.washington.edu\> 
 *  
 * @version 1.0.0
 * @date November 12, 2010
 */ 
//--------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows clients to get a pointer to a new instance of a 
 *	  derived type of CD by calling getNewInstance. getNewInstance
 *	  will be called on the derived type at run-time, thus
 *	  allowing dynamic binding. The data of the new object will be
 *	  set using the provided file.
 * 
 * Assumptions:
 * 	- All derived types of CD implement getNewInstance, and 
 *	  within the method return a pointer to a dynamically 
 *	 allocated object of that derived type.
 */
//--------------------------------------------------------------------
 
#ifndef CD_H
#define CD_H

#include "item.h"

/**
 * @class CD
 */
class CD: public Item {

/**
 * @public
 */
public: 

	//---------------------Constructor----------------------------
	/**
 	 * @brief Creates a CD object with default values.
 	 */
	CD ();


	//---------------------Constructor----------------------------
	/**
 	 * @brief Deletes any dynamically allocated memory. 
	 */
	virtual ~CD ();

	
	//---------------------getNewInstance----------------------------
	/**
	 * @brief Retuns a pointer to a new instance of the derived 
 	 *	  CD. The new objects' data will be set using the
 	 *	  provided file stream.
	 *	
 	 * Preconditions: The file stream is open and correctly 
	 *	 	  formatted according to Lab 4 specs.
	 *	
	 * Postconditions: A new object of the derived type is created
 	 *		   using the provided file stream, and a 
	 *		   pointer to it is returned. 
	 *
	 * @return Returns a pointer to a new instance of the derived
	 *	   CD.
	 */
	virtual Item * getNewInstance (ifstream &) const = 0;

};
#endif /* CD_H */

